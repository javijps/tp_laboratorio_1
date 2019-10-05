/*
 * empleados.h
 *
 *  Created on: 30 sep. 2019
 *      Author: javijps
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#ifndef EMPLEADOS_H_
#define EMPLEADOS_H_

struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

}typedef Employee;

int initEmployees(Employee* list, int len);
int getDatosEmployee(Employee* list,int len);
int findEmptyEmployee(Employee* list,int len);
int addEmployee(Employee* list,int len);
int modifyEmployeeById(Employee* list,int len,int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int len);//
int totalSalary_AverageSalary_AboveAverageSalary(Employee* list,int len);
#endif /* EMPLEADOS_H_ */
