#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"





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

	if(pFile!=NULL
			&&
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

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario). Si no existe, lo crea
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
	if(pFile==NULL)
	{
		pFile = fopen(path,"wb");
		if(pFile!=NULL)
		{
			printf("Archivo creado!\n");
			retorno = 0;
		}
		else
			printf("NO fue posible abrir el archivo!\n");
	}
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
		printf("Ordenando empleados por Nombre de forma ascendente....\n");
		ll_sort(pArrayListEmployee,emp_sortEmployeByName,1);//1asc y 0 desc
		controller_ListEmployee(pArrayListEmployee);
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
	int i;
	Employee* bEmpleado;

	pFile = fopen(path,"w");
	lenLL = ll_len(pArrayListEmployee);
	if(pFile!=NULL && pArrayListEmployee!=NULL && lenLL>0)
	{
		fprintf(pFile,"Id,Nombre,HorasTrabajadas,Sueldo\n");
		for(i=0;i<lenLL;i++)
		{
			bEmpleado = ll_get(pArrayListEmployee,i);
			if(bEmpleado!=NULL)
			{
				fprintf(pFile,"%d,%s,%d,%d\n",
						bEmpleado->id,
						bEmpleado->nombre,
						bEmpleado->horasTrabajadas,
						bEmpleado->sueldo);
				retorno = 0;
			}
			else
				break;
		}
		printf("Informacion guardada!\n");
	}
	else
		printf("No fue posible guardar la informacion!\n");
	fclose(pFile);
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
	int retorno = -1;
	FILE* pFile;
	int lenLL;
	int i;
	Employee* bEmpleado;

	pFile = fopen(path,"wb");
	lenLL = ll_len(pArrayListEmployee);

	if(pFile!=NULL && pArrayListEmployee!=NULL && lenLL>0)
	{
		//		pFile = fopen(path,"wb");
		for(i=0;i<lenLL;i++)
		{
			bEmpleado = ll_get(pArrayListEmployee,i);
			fwrite(bEmpleado,sizeof(Employee),1,pFile);
		}
		retorno = 0;
		fclose(pFile);
	}
	else
		printf("No fue posible guardar la informacion!\nArchivo Inexistente!\n");
	return retorno;
}
/** \brief Sale del menu al confirmar, Elimina array LinkedList y libera espacio en memoria
 * \param pArrayListEmployee LinkedList*
 * \return 0 si se confirma la eliminacion -1 si falla o es cancelada.
 *
 */
int controller_exitMenu(LinkedList* pArrayListEmployee)
{
	int retorno = -1;;
	int option;

	getInt(&option,"\nDesea abandonar el programa?\nToda la informacion no grabada en archivo se perdera\n"
			"Ingrese\n"
			"1-Confirmar\n"
			"2-Continuar dentro del programa\n",
			"Opcion Incorrecta\n",1,3,2);
	if(pArrayListEmployee!= NULL && option==1)
	{
		ll_deleteLinkedList(pArrayListEmployee);
		retorno = 0;
	}
	return retorno;
}
