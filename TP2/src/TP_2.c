/*
 ============================================================================
 Name        : TP_2_.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define MAX_EMPLOYEE 1000
#define STATUS_EMPTY  0
#define STATUS_NOT_EMPTY 1
#define EXIT_MENU 5

int main(void) {

	int option;
	Employee aEmployee[MAX_EMPLOYEE];
	int id;
	int fAlta=0;
	int order;

	initEmployees(aEmployee,MAX_EMPLOYEE);
	printEmployees(aEmployee,MAX_EMPLOYEE);
	do
	{

		getInt(&option,"\n-------------------\n"
				"Ingrese :\n"
				"1-Altas\n"
				"2-Modificar\n"
				"3-Baja\n"
				"4-INFORMAR\n"
				"     *1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n"
				"     *2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n"
				"5-SALIR\n"
				"\n-------------------\n",
				"Error,opcion incorrecta\n",
				1,5,2);

		switch(option)
		{
		case 1:
			if(addEmployee(aEmployee,1000)==0)
			{
				fAlta=0;
				printEmployees(aEmployee,MAX_EMPLOYEE);
			}
			else
			{
				printf("EL empleado no pudo ser dado de alta\n");
			}
			break;
		case 2:
			if(fAlta==0)
			{
				printEmployees(aEmployee,MAX_EMPLOYEE);
				getInt(&id,"\nIngrese ID del empleado a modificar\n","Error\n",1,1000,2);//reemplazar x getId
				if(modifyEmployeeById(aEmployee,MAX_EMPLOYEE,id)!=0)
				{
					printf("No fue posible realizar la modificacion\n");
				}
				printEmployees(aEmployee,MAX_EMPLOYEE);
			}
			else
				printf("Es necesario dar empleados de alta!\n");
			break;
		case 3:
			if(fAlta==0)
			{
				printEmployees(aEmployee,MAX_EMPLOYEE);
				getInt(&id,"\nIngrese ID del empleado a dar de baja\n","Error\n",1,1000,2);//reemplazar x getId
				if(removeEmployee(aEmployee,MAX_EMPLOYEE,id)!=0)
				{
					printf("No fue posible realizar la modificacion\n");
				}
				printEmployees(aEmployee,MAX_EMPLOYEE);
			}
			else
				printf("Es necesario dar empleados de alta!\n");
			break;
		case 4:
			if(fAlta==0)
			{
				if(getInt(&option,"Ingrese:\n1-Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n"
						"2-Total y promedio de los salarios, y cuántos empleados superan el salario promedio.",
						"Error\n",
						1,
						2,
						2)==0)
				{
					switch(option)
					{
					case 1:
						if(getInt(&order,"\nIngrese\n0-Orden descendente\n1-Orden ascendente\n","Opcion incorrecta\n",0,1,2)==0)
						{
							if(sortEmployees(aEmployee,5,order)!=0)//sortOrder = 1 ASC, sortOrder = 2
							{
								printf("No fue posible realizar el ordenamiento!\n");
							}

							break;
					case 2:
						if(totalSalary_AverageSalary_AboveAverageSalary(aEmployee,1000)!=0)
						{
							printf("No fue posible procesar la informacion!\n");
						}
						break;
						}
					}
				}
			}
			else
				printf("Es necesario dar empleados de alta!\n");
		}
	}while(option!=EXIT_MENU);
	return EXIT_SUCCESS;
}
