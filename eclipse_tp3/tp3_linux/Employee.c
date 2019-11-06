#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

static int isValidNombre(char* nombre)//CARGAR UTN.H
{
	return 1;
}

static int isValidId(int id)//CARGAR UTN.H
{
	return 1;
}

static int isValhorasTrabajadas(int horasTrabajadas)//CARGAR UTN.H
{
	return 1;
}

static int isValsueldo(int sueldo)//CARGAR UTN.H
{
	return 1;
}

Employee* employee_new()
{
	return malloc(sizeof(Employee));
}

void employee_delete(Employee* this)
{
	free(this);
}



int employee_setId(Employee* this,int id)
{
	int retorno = -1;

	if(this!=NULL && isValidId(id))
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}


int employee_getId(Employee* this,int* id)
{
	int retorno = -1;

	if(this!=NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}



int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;

	if(this!=NULL && isValidNombre(nombre))
	{
		strcpy(this->nombre,nombre);
		retorno = 0;
	}
	return retorno;
}


int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;

	if(this!=NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 0;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;

	if(this!=NULL && isValhorasTrabajadas(horasTrabajadas))
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;

	if(this!=NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;

	if(this!=NULL && isValsueldo(sueldo))
	{
		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;

	if(this!=NULL)
	{
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}



Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{//modificar pase de string to int, nueva funcion sin msjs ni reintentos

	Employee* retorno = NULL;
	Employee* this;
	this = employee_new();

	int bId;
	int bHsTrabajadas;
	int bSueldo;

	if(this!=NULL)
	{
		bId = atoi(idStr);
		bHsTrabajadas = atoi(horasTrabajadasStr);
		bSueldo = atoi(sueldo);
		{
			if(employee_setId(this,bId)==0 &&
					employee_setNombre(this,nombreStr)==0 &&
					employee_setHorasTrabajadas(this,bHsTrabajadas)==0 &&
					employee_setSueldo(this,bSueldo)==0)
				retorno = this;
			else
				employee_delete(this);
		}
	}
	return retorno;
}



void emp_printAemployee(Employee* employee)
{
	if(employee!=NULL)
	{
		printf("\nID: %d\n"
				"Nombre: %s\n"
				"Horas trabajadas: %d\n"
				"Sueldo: %d\n",
				employee->id,
				employee->nombre,
				employee->horasTrabajadas,
				employee->sueldo);
	}
}



void emp_printEmployees(Employee* aEmployee,int len)
{
	int i;

	if(aEmployee!=NULL)
	{
		for(i=0;i<len;i++)
		{
			printf("ID: %d\n"
					"Nombre: %s\n"
					"Horas trabajadas: %d\n"
					"Sueldo: %d",
					aEmployee[i].id,
					aEmployee[i].nombre,
					aEmployee[i].horasTrabajadas,
					aEmployee[i].sueldo);
		}
	}
}

/*
int generarIdEmployee(LinkedList* pArrayList,bufferId)//llama a buscarIdMaximo. devuelve el id
{
	int retorno = 0;
	int i;

	if(pArrayList!=NULL)
	{
		ll_sort(pArrayList,*empl_buscarMaximoId())
	}
	return retorno;
}


*/

int employee_buscarEmployee(LinkedList* pArrayListEmployee,Employee* empleado)
{//chequear logica index

	int retorno;
	if(pArrayListEmployee!=NULL)
	{

		if(ll_contains(pArrayListEmployee,empleado)==0)
			retorno = 0;
		else
			printf("El empleado ya existe!\n");
	}
	return retorno;
}




/**
 * \brief Solicita los datos correspondientes a una cliente.
 * \param sCliente *acliente puntero a una xxxxx de la estructura cliente.
 * \param cantidad Cantidad de clientes.
 * \return Si tuvo exito al completar todos los campos devuelve [0] o si fallo [-1]
 */
Employee* employee_getDatosEmployee(LinkedList* pArrayListEmployee)//
{
	Employee* retorno = NULL;
	char bId[1046]="1000";
	char bName[1046];
	char bHoras[1046];
	char bSueldo[1046];
	int option;
	Employee* bEmployee;

	if(pArrayListEmployee!=NULL)
	{
		do
		{
			//ASI ESTOY VALIDANDO 2 VECES, ACA Y EN EL ISVALID DEL SET.
			if(getNombre(bName,"Ingrese nombre del empleado\n","Nombre Incorrecto\n",3)!=0)
			{
				printf("No fue posible agregar el nombre\n");
				retorno=NULL;
				break;
			}
			if(getString(bHoras,"Ingrese cantidad de hs trabajadas","Cantidad de hs incorrecta!\n",1,1000,2)!=0)//hacer geths
			{
				printf("No fue posible agregar las hs trabajadas!\n");
				retorno=NULL;
				break;
			}
			if(getString(bSueldo,"Ingrese sueldo del empleado","Sueldo Incorrecto!\n",1,1000,2)!=0)
			{
				printf("No fue posible agregar el sueldo del empleado!\n");
				retorno=NULL;
				break;
			}
			//int generarIdEmployee(linkedlist)llama a buscarIdMaximo
			bEmployee = employee_newParametros(bId,bName,bHoras,bSueldo);
			if(bEmployee!=NULL)
			{
//				printf("bemplo ok\n");
//				if(employee_buscarEmployee(pArrayListEmployee,bEmployee)!=0)
//				{
//					retorno = bEmployee;
//					printf("busco ok ok");
//				}
//				else
//				{
//					printf("Error al cargar el empleado!\n");
//					break;
//				}
									retorno = bEmployee;
			}
			if(getInt(&option,"\n1-Ingresar otro empleado\n2-Salir\n",
					"Opcion incorrecta!\n",1,2,2)!=0)
				break;
		}while(option==1);
	}
	return retorno;
}















/*NOTAS LL
 * CASO NODO NUEVO EN 1ER ELEMENTO
 * CREAR NODO, DEVUELVE P*
 * FIRST NODE == PROXIMO DE NODO NUEVO
 * LISTA FIRST NODE == P*NUEVO NODO
 * SIZE++
 *
 *AGREGAR EN SIZE ES DECIR LO MISMO Q ULTIMO
 *SIZE-1 ES EL ULTIMO
 *
 *
 *hay 2 casos, agregar al principio cambio primernode en struct ll
 *agregar en medio de 2(agregar al final es un caso particular de agregar en medio).pido anterior.
 *
 *
 *get node. tomo recorro de uno en uno.pasa x todos.
 *get node node index >=0 && node index<size
 *size++
 *ll ad ,es  llamar add node
 *ll get es llam
 *ll clear es remove repetido
 *ll delete es remove y free
 *ll
 *hacer remove node
 */






















