/*
 * empleados.c
 *
 *  Created on: 30 sep. 2019
 *      Author: javijps
 */
#include "ArrayEmployees.h"

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define STATUS_EMPTY  0
#define STATUS_NOT_EMPTY 1
#define MAX_CHAR 50
#define MAX_SALARY 100000


/** \brief To indicate that all position in the array are empty,
*this function put the flag (isEmpty) in TRUE in all
*position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee *list, int len)
{

	int i;
	int retorno = -1;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			list[i].isEmpty = STATUS_EMPTY;
		}
		retorno = 0;
	}
	return retorno;

}

/**
* \brief Genera el ID correspondiente a una pantalla.
* \return Devuelve el ID correspondiente.
*/

static int idEmployee(void){
	static int id = 0;
	id++;
	return id;
}

/** \brief Toma los datos correspondientes a un empleado.
*
* \param list Employee*
* \param list Employee* puntero a un array de empleados
* \param len int Array length
* \return Return (-1) si es Error [Si los datos del empleado no pudieron ser registrados] - (0)
* si se pudieron registrar los datos.
*
*/
int getDatosEmployee(Employee* list,int len){

	int retorno = -1;
	Employee bEmpleado;
	int i;

	for(i=0;i<len;i++)
	{

		if(getNombre(bEmpleado.name,MAX_CHAR,2)!=0)
			break;
		if(getApellido(bEmpleado.lastName,MAX_CHAR,2)!=0)
			break;
		if(getFloat(&bEmpleado.salary,"Ingrese salario del empleado\n",
				"Error, el salario ingresado es incorrecto\n",
				1,MAX_SALARY,2)!=0)
			break;
		if(getInt(&bEmpleado.sector,"Ingrese sector 1 a 10\n",
				"Error, el sector ingresado es incorrecto\n",
				1,10,3)!=0)
			break;

		list[i].salary = bEmpleado.salary;
		list[i].sector = bEmpleado.sector;
		strncpy(list[i].name,bEmpleado.name,50);
		strncpy(list[i].lastName,bEmpleado.lastName,50);
		list[i].isEmpty = STATUS_NOT_EMPTY;
		list[i].id = idEmployee();
		retorno = 0;
	}
	return retorno;
}

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param list Employee* puntero a un array de empleados
* \param len int Array length
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id)
{
	int retorno = -1;
	int i;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].id == id && list[i].isEmpty == STATUS_NOT_EMPTY)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
/** \brief find an Empty Employee and returns the index position in array.
* \param list Employee* puntero a un array de empleados
* \param len int Array length
* \param id int id correspondiente a un empleado
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmptyEmployee(Employee* list,int len)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==STATUS_EMPTY)
				return i;
		}
	}
	return retorno;
}


/** \brief add in a existing list of employees the values received as parameters
in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/

int addEmployee(Employee* list,int len)
{
	int respuesta;
	int retorno = -1;
	int index=0;

	do
	{
		if(list != NULL && len>0)
		{
			index = findEmptyEmployee(list,len);

			if(index!=-1)
			{
				if(getDatosEmployee(list,len)==0)
				{
					retorno = 0;
				}
				else
					printf("No fue posible realizar el alta!\n");
			}
		}
		getInt(&respuesta,"Desea Ingresar otro empleado?\nIngrese 1\nPara finalizar\nIngrese 2\n","Error,respuesta Incorrecta\n",1,2,2);
	}while(respuesta==1);

	return retorno;
}




/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id)
{

	int retorno = -1;
	int index=0;

	if(list != NULL && len>0)
	{
		index = findEmployeeById(list,len,id);

		if(index!=-1)
		{
			list[index].isEmpty = STATUS_EMPTY;
			retorno = 0;
			printf("Baja Exitosa!\n");
		}
	}
	return retorno;

}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order)
{
	int i;
	Employee bEmployee;
	int fSwap;
	int retorno=-1;

	if(list!=NULL && len>0)
	{

			retorno = 0;
			do
			{
				fSwap=0;
				for(i=0;i<len-1;i++)
				{
					if(order==1)
					{
						if(strncmp(list[i].lastName,list[i+1].lastName,50)>0)
						{
							if(list[i].isEmpty==STATUS_EMPTY)
								continue;
							fSwap = 1;
							bEmployee = list[i];
							list[i] = list[i+1];
							list[i+1] = bEmployee;

						}
						else if(strncmp(list[i].lastName,list[i+1].lastName,50)==0)
						{
							if(list[i].sector>list[i+1].sector)
							{
								fSwap = 1;
								bEmployee = list[i];
								list[i] = list[i+1];
								list[i+1] = bEmployee;
							}
						}
					}

					if(order==0)
					{
						if(strncmp(list[i].lastName,list[i+1].lastName,50)<0)
						{
							if(list[i].isEmpty==STATUS_EMPTY)
								continue;
							fSwap = 1;
							bEmployee = list[i];
							list[i] = list[i+1];
							list[i+1] = bEmployee;

						}
						else if(strncmp(list[i].lastName,list[i+1].lastName,50)==0)
						{
							if(list[i].sector<list[i+1].sector)
							{
								fSwap = 1;
								bEmployee = list[i];
								list[i] = list[i+1];
								list[i+1] = bEmployee;

							}
						}
					}

				}

			}while(fSwap);

	}
	return retorno;
}

/** \brief print the content of employees array(active employees)
*
* \param list Employee* pointer to an array of employees
* \param len int Array length
* \return int
*IMPRIME SOLO EMPLEADOS ACTIVOS
*/
int printEmployees(Employee* list, int len)
{
	int i;
	int retorno = -1;
	if(list != NULL && len>0)
	{
		retorno = 0;

		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty!=STATUS_NOT_EMPTY)
				continue;
			printf("\n Id: %d - Name: %s - Last name: %s - Salary: %.2f - Sector: %d - Status: %d \n ",
				list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector,list[i].isEmpty);
			//printf("Status: %d\n ",list[i].isEmpty);
		}
	}
	return retorno;
}

/** \brief Modifica empleado por ID
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*/

int modifyEmployeeById(Employee* list,int len,int id)
{
	int retorno = -1;
	char option;
	Employee bEmployee;

	int index = findEmployeeById(list,len,id);

	if(index!=-1)
	{
		do
		{

			getChar(&option,"a-Modificar nombre\n"
					"b-Modificar apellido\n"
					"c-Modificar salario\n"
					"d-MOdificar sector\n"
					"e-SALIR\n",
					"Error,opcion incorrecta\n",
					'a','e',2);

			switch(option)
			{
			case 'a':
				if(getString(bEmployee.name,"Ingrese el nombre del empleado\n",
						"Nombre Incorrecto\n",
						1,49,3)!=0)
				{
					printf("No se pudo modificar el nombre");
					retorno = -1;
				}
				else
				{
					strncpy(list[index].name,bEmployee.name,50);
					retorno = 0;
				}
				break;
			case 'b':
				if(getString(bEmployee.lastName,"Ingrese el apellido del empleado\n",
						"Apellido Incorrecto\n",
						1,49,3)!=0)
				{
					printf("No se pudo modificar el apellido");
					retorno = -1;
				}
				else
				{
					strncpy(list[index].lastName,bEmployee.lastName,50);
					retorno = 0;
				}
				break;
			case 'c':
				if(getFloat(&bEmployee.salary,"Ingrese el salario del empleado\n",
						"Salario Incorrecto\n",
						1,100000,2)!=0)
				{
					printf("No se pudo modificar el salario");
					retorno = -1;
				}
				else
				{
					list[index].salary = bEmployee.salary;
					retorno = 0;
				}
				break;
			case 'd':
				if(getInt(&bEmployee.sector,"Ingrese el sector del empleado\n",
						"Sector Incorrecto\n",
						1,3,2)!=0)
				{
					printf("No se pudo modificar el sector");
					retorno = -1;
				}
				else
				{
					list[index].sector = bEmployee.sector;
					retorno = 0;
				}
				break;
			}
		}while(option!='e');

		//list[index].isEmpty = STATUS_NOT_EMPTY;

	}
	return retorno;

}

/** \brief Calcula Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
*
* \param list Employee* puntero a array de empleados
* \param len lenght
* \return int Return (-1) if Error [No pudo realizar los calculos] - (0) if Ok
*/
int totalSalary_AverageSalary_AboveAverageSalary(Employee* list,int len)
{
	int retorno = -1;
	int i;
	float acumuladorSalarios=0;
	int contadorEmpleados=0;
	int contadorAboveAverage=0;
	float averageSalaries;

	if(list!=NULL && len > 0)
	{

		retorno = 0;
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==STATUS_NOT_EMPTY)
			{
				acumuladorSalarios = acumuladorSalarios + list[i].salary;
				contadorEmpleados++;//countActiveEmployees
			}
		}
		averageSalaries = acumuladorSalarios / contadorEmpleados;
		for(i=0;i<len;i++)
		{
			if(list[i].salary>averageSalaries)
			{
				contadorAboveAverage++;
			}
		}
		printf("\n---------------------------\n"
				"\nEl total de los salarios es: %.2f\n"
				"El promedio de los salarios es %.2f\n"
				"La cantidad de salarios que se encuentran por encima del promedio es: %d"
				"\n---------------------------\n"
				,acumuladorSalarios,
				averageSalaries,
				contadorAboveAverage);


	}
	return retorno;
}
