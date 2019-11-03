#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado//ver el id. buscar maximo en el archivo y dar maximo+1(hacer una funcion)
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	getInt(&option,"ingrese opcion:\n1-Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
    			"2-Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
    			"3-Alta empleado\n"
    			"4-Modificar datos de empleado"
    			"5-Baja de empleado"
    			"6-Listar empleados"
    			"7-Ordenar empleados"
    			"8-Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
    			"9-Guardar los datos de los empleados en el archivo data.csv (modo binario)\n","Error\n",1,10,2);

    	switch(option)
    	{
    	case 1:
    		if(controller_loadFromText("data.csv",listaEmpleados)==0)
    			printf("controller ok\n");
    		else
    			printf("no funciona\n");
    		break;
    	case 2://mal
    		if(controller_loadFromBinary("data.csv",listaEmpleados)==0)
    			printf("controller ok\n");
    		else
    			printf("noa nda\n");
    		break;
    	case 3:
    		if(controller_addEmployee(listaEmpleados)==0)
    			printf("controller ok\n");
    		else
    			printf("controller not ok\n");
    		break;
    	case 8:
    		break;
    	case 9:
    		break;
    	}
    }while(option!=10);
    return 0;
}

