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

	if(pFile!=NULL && pArrayListEmployee!=NULL && parser_EmployeeFromText(pFile,pArrayListEmployee)==0)
	{
		retorno = 0;
		fclose(pFile);
	}
	else
		printf("error controller\n");
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
	pFile = fopen(path,"rb");//AGREGAR IF SI NO SE PUDO ABRIR

	if(pFile!=NULL && pArrayListEmployee!=NULL && parser_EmployeeFromBinary(pFile,pArrayListEmployee)==0)
	{
		retorno = 0;
		fclose(pFile);
	}
	else
		printf("error controller\n");
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
	Employee* pEmployee;
	if(pArrayListEmployee!=NULL)
	{
		pEmployee = employee_getDatosEmployee(pArrayListEmployee);
		if(pEmployee!=NULL && ll_add(pArrayListEmployee,pEmployee)==0)//chequear retorno de add
			retorno = 0;
		else
			printf("No fue posible agregar el empleado!\n");

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
    return 1;
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
    return 1;
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
			printf("ID: %d     Employee: %15s     Horas trabajadas %d     Sueldo: %d\n",
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
    return 1;
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
    return 1;
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

