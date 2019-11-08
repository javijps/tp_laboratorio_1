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
	//deberia agregar system clear

	//PUNTO 7 //hacer submenu sort CON TODAS LAS OPCIONES. ACTUAL, ordena por nombre de forma descendente


	//AGREGAR TODOS LOS FLAG NECESARIOS.(APERTURA DE ARCHIVOS Y ESCRITURA DE ARCHIVOS
	//HACER TODA LA DOCUMENTACION!!!!
	//CHEQUEAR QUE TODAS LAS FUNCIONES TENGAN EL IF CORRESPONDIENTE AL CHEQUEO DE PARAMETROS EN EL PRIMER IF
	//CHEQUEAR LOS MENSAJES DE ERROr DE CADA FUNCION
	//CHEQUEAR SI ES NECESARIO IMPORTAR EMPLOYEE EN EL MAIN


	int option;
	int flagTexto = 0;
	int flagBinario = 0;
	LinkedList* listaEmpleados = ll_newLinkedList();

	do{
		if(getInt(&option,"\nIngrese opcion:\n1-Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
				"2-Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
				"3-Alta empleado\n"
				"4-Modificar datos de empleado\n"
				"5-Baja de empleado\n"
				"6-Listar empleados\n"
				"7-Ordenar empleados\n"
				"8-Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
				"9-Guardar los datos de los empleados en el archivo data.csv (modo binario)\n"
				"10-Exit","Error\n",1,11,2)==0)
		{
			switch(option)
			{
			case 1:
				if(flagBinario==0 && controller_loadFromText("data.csv",listaEmpleados)==0)
					flagTexto =1;
				else
					printf("No es posible abrir el archivo en modo texto si se abrio un archivo en modo binario!\n");
				break;
			case 2:
				if(flagTexto==0 && controller_loadFromBinary("data.bin",listaEmpleados)!=0)
						flagBinario = 1;
				else
					printf("No es posible abrir el archivo en modo binario si se abrio un archivo en modo texto!\n");
				break;
			case 3:
				controller_addEmployee(listaEmpleados);
				break;
			case 4:
				controller_editEmployee(listaEmpleados);
				break;
			case 5:
				controller_removeEmployee(listaEmpleados);
				break;
			case 6:
				controller_ListEmployee(listaEmpleados);
				break;
			case 7:
				controller_sortEmployee(listaEmpleados);
				break;
			case 8:
				controller_saveAsText("data.csv",listaEmpleados);
				break;
			case 9:
				controller_saveAsBinary("data.bin",listaEmpleados);
				break;
			case 10:
				if(controller_exitMenu(listaEmpleados)==0)
					option=11;
				break;
			}
		}
		}while(option!=11);
	printf("Programa cerrado!\n");
	return 0;
}

