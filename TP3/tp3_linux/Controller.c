#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"




//AGREGAR IF SI NO SE PUDO ABRIR loadfrombinary
//REVISAR APERTURA Y CREACION DE ARCHIVOS. ULTIMO

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)//MENSAJE ACA EN LUGAR DEL MAIN?
{
	int retorno = -1;
	FILE* pFile;
	pFile = fopen(path,"r");

	if(pFile!=NULL &&
			pArrayListEmployee!=NULL &&
			ll_len(pArrayListEmployee)==0 &&
			parser_EmployeeFromText(pFile,pArrayListEmployee)==0)
	{
		retorno = 0;
		printf("Archivo cargado!\n");
		fclose(pFile);
	}
	else
		printf("No fue posible cargar el archivo\n");
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pFile;

	pFile = fopen(path,"rb");
	if(pFile!=NULL)
	{
		if(pArrayListEmployee!=NULL &&
				ll_len(pArrayListEmployee)==0 &&
				parser_EmployeeFromBinary(pFile,pArrayListEmployee)==0)
		{
			retorno = 0;
			printf("Archivo cargado!\n");
		}
	}
	else if(fopen(path,"wb")!=NULL)
	{
		printf("Archivo creado!\n");
	}
	else
		printf("Archivo inexistente!\nNo hay memoria para crear el archivo!\n");
	fclose(pFile);
	return retorno;
}
/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int option;
	Employee* pEmployee;
	if(pArrayListEmployee!=NULL)
	{
		do
		{
			pEmployee = employee_new();
			pEmployee = employee_getDatosEmployee(pArrayListEmployee);
			if(pEmployee!=NULL && ll_add(pArrayListEmployee,pEmployee)==0)
			{
				retorno = 0;
				printf("Empleado creado correctamente!\n");
				emp_printAemployee(pEmployee);
			}
			else
			{
				printf("No fue posible agregar el empleado!\n");
				employee_delete(pEmployee);
			}
			if(getInt(&option,"\n1-Ingresar otro empleado\n2-Salir\n",
					"Opcion incorrecta!\n",1,2,2)!=0)
				break;
		}while(option==1);
	}
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;

	if(pArrayListEmployee!=NULL && ll_len(pArrayListEmployee)>0 && employee_EditEmployee(pArrayListEmployee)!=NULL)
	{
		retorno=0;
	}
	else
	{
		printf("No existen datos cargados a editar!\n");
	}
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;

	if(pArrayListEmployee!=NULL &&
			ll_len(pArrayListEmployee)>0)
	{
		if(employee_deleteEmployee(pArrayListEmployee)==0)
		{
			retorno=0;
		}
	}
	else
	{
		printf("No existen datos cargados a editar!\n");
	}
	return retorno;
}


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int i;
	int lenLL;
	Employee* bEmpleado;

	lenLL = ll_len(pArrayListEmployee);
	if(pArrayListEmployee!=NULL && lenLL>0)
	{
		for(i=0;i<lenLL;i++)
		{
			bEmpleado = ll_get(pArrayListEmployee,i);
			printf("ID: %d     Employee: %15s     Horas trabajadas %6d     Sueldo: %8d\n",
					bEmpleado->id,bEmpleado->nombre,bEmpleado->horasTrabajadas,bEmpleado->sueldo);
			retorno = 0;
		}
	}
	else
		printf("No fue posible imprimir la informacion!\n");
	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int lenLL;

	lenLL = ll_len(pArrayListEmployee);
	if(pArrayListEmployee!=NULL && lenLL>0)
	{
		ll_sort(pArrayListEmployee,emp_sortEmployeByName,1);//1asc y 0 desc
		controller_ListEmployee(pArrayListEmployee);
		printf("Empleados ordenados por Nombre!!\n");
		retorno = 0;
	}
	else
	{
		printf("No existen datos cargados a editar!\n");
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pFile;
	int lenLL;
	int wt;
	pFile = fopen(path,"a");

	lenLL = ll_len(pArrayListEmployee);
	printf("Largo lenLL %d\n",lenLL);
	if(pFile!=NULL && pArrayListEmployee!=NULL && lenLL>0)
	{

		fclose(pFile);
	}
	else
		printf("No fue posible guardar los datos en el archivo\n");
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	return 1;
}

