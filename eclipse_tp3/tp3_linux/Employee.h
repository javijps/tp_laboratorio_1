#ifndef employee_H_INCLUDED

#include "LinkedList.h"
#include "utn.h"
#include "Controller.h"

#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

void emp_printAemployee(Employee* employee);

//int buscarIdMaximo()
//int generarIdEmployee(llama a buscarIdMaximo)
Employee* emp_findEmployeeById(LinkedList* pArrayListEmployee,int idEmployee);

Employee* employee_getDatosEmployee(LinkedList* pArrayListEmployee);//
Employee* employee_EditEmployee(LinkedList* pArrayListEmployee);
Employee* emp_subMenuEditEmployee(Employee* bEmpleado);


#endif // employee_H_INCLUDED
