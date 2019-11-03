#ifndef employee_H_INCLUDED

#include "LinkedList.h"
#include "utn.h"

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
int employee_buscarEmployee(LinkedList* pArrayListEmployee,Employee* empleado);
Employee* employee_getDatosEmployee(LinkedList* pArrayListEmployee);//

#endif // employee_H_INCLUDED
