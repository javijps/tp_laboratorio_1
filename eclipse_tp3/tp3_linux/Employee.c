#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"

void emp_printAemployee(Employee* employee)
{
	if(employee!=NULL)
	{
		printf("ID: %d\n"
				"Nombre: %s\n"
				"Horas trabajadas: %d\n"
				"Sueldo: %d",
				employee->id,
				employee->nombre,
				employee->horasTrabajadas,
				employee->sueldo);
	}
}
