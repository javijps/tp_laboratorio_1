#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	char bId[1046];
	char bName[1046];
	char bHoras[1046];
	char bSueldo[1046];
	int flagCabecera=0;
	Employee* bEmpleado;
	int rd;

	if(pFile!=NULL)
	{
		while(!feof(pFile))
		{
			rd = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bId,bName,bHoras,bSueldo);
			if(flagCabecera==0)
			{
				flagCabecera=1;
				continue;
			}
			else if(flagCabecera!=0 && rd==4)
			{
				bEmpleado = employee_newParametros(bId,bName,bHoras,bSueldo);
				if(bEmpleado!=NULL)
				{
					ll_add(pArrayListEmployee,bEmpleado);//agregar if?
					retorno = 0;
				}
				else
				{
					retorno = -1;
					break;
				}
			}
		}
	}
	fclose(pFile);
	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* bEmpleado;
	int rd;
	int flagCabecera = 0;

	if(pFile!=NULL)
	{
		bEmpleado =  employee_new();
		if(bEmpleado!=NULL)
		{
			while(!feof(pFile))
			{
				rd = fread(bEmpleado,sizeof(Employee),1,pFile);
				if(flagCabecera==0)
				{
					flagCabecera=1;
					continue;
				}
				else
				{
					if(flagCabecera==1 && rd==1)
					{
						if(ll_add(pArrayListEmployee,bEmpleado)==0)//chequear retorno de add
							retorno = 0;
					}
					else
						employee_delete(bEmpleado);
					break;
				}
			}
		}
	}
	else
		printf("error de lectura");
	return retorno;
}
