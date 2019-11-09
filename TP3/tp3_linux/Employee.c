#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

/** \brief Validacion de nombre
 *
 * \param char* nombre. puntero a cadena de caracteres
 * \return int 1 si el nombre es valido, -1 si no lo es
 *
 */

static int isValidNombre(char* nombre)
{
	int retorno = -1;
	int i;
	int lenString;

	if(nombre!=NULL)
	{
		lenString = strlen(nombre);
		for(i=0;i<lenString;i++)
		{
			if((nombre[i] >= 'a' && nombre[i] <= 'z') ||
					(nombre[i] >= 'A' && nombre[i] <= 'Z') ||
					(nombre[i]== ' '))
			{

				retorno = 1;
				i++;
			}
			else
			{
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Validacion de Id
 *
 * \param char* id. puntero a cadena de caracteres
 * \return int 1 si el id es valido, -1 si no lo es
 *
 */
static int isValidId(int id)//CARGAR UTN.H
{
	int retorno=-1;

	if(id>=0)
	{
		retorno=1;
	}
	return retorno;
}

/** \brief Validacion de horas trabajadas
 *
 * \param char* horas trabajadas. puntero a cadena de caracteres
 * \return int 1 si el id es valido, -1 si no lo es
 *
 */
static int isValhorasTrabajadas(int horasTrabajadas)//CARGAR UTN.H
{
	int retorno=-1;

	if(horasTrabajadas>=1)
	{
		retorno=1;
	}
	return retorno;
}

/** \brief Validacion de sueldo
 *
 * \param char* sueldo. puntero a cadena de caracteres
 * \return int 1 si el id es valido, -1 si no lo es
 *
 */
static int isValsueldo(int sueldo)//CARGAR UTN.H
{
	int retorno=-1;

	if(sueldo>=1)
	{
		retorno=1;
	}
	return retorno;
}

/** \brief Pide espacio en memoria
 *
 * \return puntero a espacio de memoria reservado para dato del tipo Employee
 *
 */
Employee* employee_new()
{
	return malloc(sizeof(Employee));
}

/** \brief Libera espacio de memoria por medio de free
 *
 *
 */
void employee_delete(Employee* this)
{
	free(this);
}

/** \brief Carga id en el campo id de una estructura Employee
 *
 * \return 0 si logra la carga -1 si falla
 *
 */
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

/** \brief Obtiene id del campo id de una estructura Employee
 *
 * \return 0 si logra la obtenerlo -1 si falla
 *
 */
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

/** \brief Carga nombre en el campo nombre de una estructura Employee
 *
 * \return 0 si logra la carga -1 si falla
 *
 */
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


/** \brief Obtiene  nombre del campo nombre  de una estructura Employee
 *
 * \return 0 si logra la obtenerlo -1 si falla
 *
 */
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

/** \brief Carga horasTrabajadas en el campo horasTrabajadas de una estructura Employee
 *
 * \return 0 si logra la carga -1 si falla
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;

	if(this!=NULL && isValhorasTrabajadas(horasTrabajadas)==1)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

/** \brief Obtiene horas trabajadas del campo horas trabajadas de una estructura Employee
 *
 * \return 0 si logra la obtenerlo -1 si falla
 *
 */
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
/** \brief Carga sueldo en el campo sueldo de una estructura Employee
 *
 * \return 0 si logra la carga -1 si falla
 *
 */
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

/** \brief Obtiene sueldo del campo sueldo de una estructura Employee
 *
 * \return 0 si logra la obtenerlo -1 si falla
 *
 */
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


/** \brief Carga todos los campos de una estructura Employee
 *
 * \return 0 si logra la carga -1 si falla
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
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

/** \brief Imprime un elemento de la estructura Employee
 *
 *
 *
 */
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

/** \brief Imprime array de elementos de la estructura Employee
 *
 *
 *
 */void emp_printEmployees(Employee* aEmployee,int len)
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

 /** \brief Busca un empleado en un array LinkedList a partir de su id
  *param LinkedList* puntero a la estructura LinkedList.
  *param int idEmployee. id del empleado
  *
  *return 1 elemento de la estructura Employee(con todos sus campos si lo encuentra) NULL si no lo encuentra
  */
Employee* emp_findEmployeeById(LinkedList* pArrayListEmployee,int idEmployee)
{
	int lenLlARray;
	int i;
	Employee* bEmployee = NULL;

	lenLlARray = ll_len(pArrayListEmployee);
	if(pArrayListEmployee!=NULL && lenLlARray>0 && idEmployee>0)
	{
		for(i=0;i<lenLlARray;i++)
		{
			bEmployee = ll_get(pArrayListEmployee,i);
			if(bEmployee->id == idEmployee)
			{
				emp_printAemployee(bEmployee);
				return bEmployee;
				break;//es necesario?
			}
		}
	}
	return bEmployee;
}

/** \brief Revisa si existe un empleado con el mismo nombre ingresado
 *param LinkedList* puntero a la estructura LinkedList.
 *param char bName. nombre del empleado
 *
 *return 0 si lo encuentra -1 si no lo encuentra
 */
int emp_existeEmpleadoByName(LinkedList* pArrayListEmployee,char *bName)
{
	int retorno = -1;
	int lenLlARray;
	int i;
	int lenString;
	Employee* bEmpleado = NULL;

	lenLlARray = ll_len(pArrayListEmployee);
	if(pArrayListEmployee!=NULL && lenLlARray>0 && bName!=NULL)
	{
		for(i=0;i<lenLlARray;i++)
		{
			bEmpleado = ll_get(pArrayListEmployee,i);
			lenString = strlen(bName)-1;
			if(strncmp(bEmpleado->nombre,bName,lenString)==0)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


/** \brief Busca el id maximo en un array Linked LIst de Employees
 * param LinkedList* puntero a la estructura LinkedList.
 * \return 0 si logra la carga -1 si falla
 *
 */
int emp_maximoId(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int maximo_id=0;
	int i;
	int lenArray;
	Employee* bEmpleado;

	lenArray = ll_len(pArrayListEmployee);
	if(pArrayListEmployee!=NULL && lenArray>0)
	{
		for(i=0;i<lenArray;i++)
		{
			bEmpleado = ll_get(pArrayListEmployee,i);
			if(bEmpleado!=NULL && bEmpleado->id > maximo_id)
			{
				maximo_id = bEmpleado->id;
			}
		}
		retorno = maximo_id;
	}
	return retorno;
}

/** \brief Devuelve el id correspondiente a un nuevo empleado
 * param LinkedList* puntero a la estructura LinkedList.
 * \return 0 si logra generar el id, -1 si falla
 *
 */
int emp_getNextId(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int maxId=0;
	int nextId;
	int lenArray;

	lenArray = ll_len(pArrayListEmployee);
	if(pArrayListEmployee!=NULL && lenArray>0)
	{
		maxId = emp_maximoId(pArrayListEmployee);
		if(maxId>=0)
		{
			nextId = maxId+1;
			retorno = nextId;
		}
	}
	return retorno;
}

/**
 * \brief Solicita los datos correspondientes a una EMPLEADO.
 * \param LinkedList* pArrayListEmployee puntero a un array de la estructura del tipo LinkedList.
 * \return Si tuvo exito al completar todos los campos devuelve un Employee o si fallo [NULL]
 */
Employee* employee_getDatosEmployee(LinkedList* pArrayListEmployee)
{
	char bId[1046];
	char bName[1046];
	char bHoras[1046];
	char bSueldo[1046];
	Employee* bEmployee = NULL;

	if(pArrayListEmployee!=NULL)
	{
		bEmployee = employee_new();
		if(getNombre(bName,"\nIngrese nombre del empleado\n","Nombre Incorrecto\n",3)!=0)
		{
			printf("No fue posible agregar el nombre\n");
			bEmployee=NULL;
		}
		if(getHoras(bHoras,"Ingrese cantidad de hs trabajadas","Cantidad de hs incorrecta!\n",2)!=0)
		{
			printf("No fue posible agregar las hs trabajadas!\n");
			bEmployee=NULL;
		}
		if(getSueldo(bSueldo,"Ingrese sueldo del empleado","Sueldo Incorrecto!\n",2)!=0)
		{
			printf("No fue posible agregar el sueldo del empleado!\n");
			bEmployee=NULL;
		}
		if(bEmployee!=NULL)
		{
			bEmployee = employee_newParametros(bId,bName,bHoras,bSueldo);
			bEmployee->id = emp_getNextId(pArrayListEmployee);
			if(emp_existeEmpleadoByName(pArrayListEmployee,bName)==0)
			{
				printf("\nNombre de Empleado existente!\n"
						"Ha creado un empleado con un nombre igual a un empleado registrado\n"
						"Si se trata de un empleado duplicado,elimine(opcion 5 Menu principal)\n");
			}
		}
		else
			employee_delete(bEmployee);
	}
	return bEmployee;
}

/**
 * \brief eDITA los datos correspondientes a una EMPLEADO.
 * \param LinkedList* pArrayListEmployee puntero a un array de la estructura del tipo LinkedList.
 * \return Si tuvo exito a editar todos los campos devuelve un Employee o si fallo [NULL]
 */
Employee* employee_EditEmployee(LinkedList* pArrayListEmployee)
{
	Employee* bEmpleado = NULL;
	int indexEmpleado;
	int bId;

	if(pArrayListEmployee!=NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		if(getInt(&bId,"Ingrese ID del Empleado a modificar\n","Error Id invalido!\n",1,10000,2)==0)
		{
			bEmpleado = emp_findEmployeeById(pArrayListEmployee,bId);
			if(bEmpleado!=NULL)
			{
				indexEmpleado = ll_indexOf(pArrayListEmployee,bEmpleado);
				if(emp_subMenuEditEmployee(bEmpleado)!=NULL)
				{
					ll_set(pArrayListEmployee,indexEmpleado,bEmpleado);
					emp_printAemployee(bEmpleado);
					printf("\nModificacion Exitosa!");
				}
				else
				{
					printf("No fue posible cargar las modificaciones en el empleado seleccionado!\n");
				}
			}
			else
				printf("Empleado no encontrado!\n");
		}
	}
	return bEmpleado;
}

/**
 * \brief Muestra un menu para interactuar en la modificacion de un empleado con el usuario.
 * \param LinkedList* bEmpleado puntero a un elemento del tipo Employee.
 * \return Si tuvo exito al completar todos los campos devuelve un Employee o si fallo [NULL]
 */
Employee* emp_subMenuEditEmployee(Employee* bEmpleado)
{
	char bNombre[1046];
	int bHoras;
	int bSueldo;
	int option;

	do{
		if(getInt(&option,"\nIngrese opcion:\n1-Modificar Nombre del Empleado\n"
				"2-Modificar Horas trabajadas del empleado\n\n"
				"3-Modificar Sueldo del Empleado\n"
				"4-EXIT\n",
				"Error opcion incorrecta\n",1,4,2)==0)//DEBERIA IMPRIMIR EL ERROR
		{
			switch(option)
			{
			case 1:
				if(getNombre(bNombre,"Ingrese nuevo nombre del Empleado\n","Nombre Incorrecto\n",3)!=0)
				{
					printf("No fue posible modificar el nombre!\n");
					break;
				}
				else
					employee_setNombre(bEmpleado,bNombre);
				break;
			case 2:
				if(getInt(&bHoras,"Ingrese nueva cantidad de hs trabajadas","Cantidad de hs incorrecta!\n",1,1000,2)!=0 ||
						isValhorasTrabajadas(bHoras)!=1)
				{
					printf("No fue posible agregar las hs trabajadas!\n");
					break;
				}
				else
					employee_setHorasTrabajadas(bEmpleado,bHoras);
				break;
			case 3:
				if(getInt(&bSueldo,"Ingrese nuevo sueldo del empleado","Sueldo Incorrecto!\n",1,1000,2)!=0 ||
						isValsueldo(bSueldo)!=1)
				{
					printf("No fue posible modificar el sueldo del empleado!\n");
					break;
				}
				else
					employee_setSueldo(bEmpleado,bSueldo);
				break;
			}
		}
	}while(option!=4);

	return bEmpleado;
}

/**
 * \brief Elimina un elemento del array de LinkedList y libera su espacio en memoria
 * \param LinkedList* pArrayListEmployee puntero a un array de la estructura del tipo LinkedList.
 * \return Si tuvo exito al completar todos los campos devuelve un Employee o si fallo [NULL]
 */
int employee_deleteEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* bEmpleado = NULL;
	int indexEmpleado;
	int bId;
	int option;

	if(pArrayListEmployee!=NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		//getID
		if(getInt(&bId,"Ingrese ID del Empleado a eliminar\n","Error Id invalido!\n",1,10000,2)==0)
		{
			if(getInt(&option,"\nConfirma que desea borrar este empleado?\n"
					"1-Confirmar eliminacion\n"
					"2-Desechar operacion\n","Error, opcion invalida",1,3,2)==0
					&& option==1)
			{
				bEmpleado = emp_findEmployeeById(pArrayListEmployee,bId);
				if(bEmpleado!=NULL)
				{
					indexEmpleado = ll_indexOf(pArrayListEmployee,bEmpleado);
					ll_remove(pArrayListEmployee,indexEmpleado);
					retorno = 0;
					printf("El empleado ha sido eliminado!\n");
				}
			}
			else
				printf("Operacion cancelada!\n");
		}
	}
	return retorno;
}

/**
 * \brief Ordena  un array de LinkedList por id, de forma Asc o Desc, segun se le indique.
 * \param void*a puntero a void
 * \param void*b puntero a void
 * \return Si tuvo exito al ordenar ascendentemente 1 o -1 descendentemente
 */
int emp_sortEmployeById(void* a,void* b)
{
	int id_a = ((Employee*)a)->id;
	int id_b = ((Employee*)b)->id;

	if(id_a > id_b)
	{
		return 1;
	}
	else if(id_a < id_b)
	{
		return -1;
	}
	return 0;
}

int emp_sortEmployeByName(void* a,void* b)
{
	if(strncmp(((Employee*)a)->nombre,((Employee*)b)->nombre,126)>0)
	{
		return 1;
	}
	if(strncmp(((Employee*)a)->nombre,((Employee*)b)->nombre,126)<0)
	{
		return -1;
	}
	return 0;
}






















