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

int main()//HACER TODA LA DOCUMENTACION!!!!
{
	//hacer WRITE TEXTO.

	//deberia agregar system clear? sino no entra cuando ordeno.
	//PUNTO 7 //hacer submenu sort CON TODAS LAS OPCIONES. ACTUAL, ordena por nombre de forma descendente
	//EXIT //debe borrar ll., CONFIRMAR CON PREGUNTA DE SALIDA
	//CHEQUEAR QUE TODAS LAS FUNCIONES TENGAN EL IF CORRESPONDIENTE AL CHEQUEO DE PARAMETROS EN EL PRIMER IF
	//CHEQUEAR LOS MENSAJES DE ERRO DE CADA FUNCION

	//validar: si el archivo se abre en texto, no se puede abrir en binario y viceversa.
	//validar: si el archivo fue leido en texto, no puedo guardar en binario?y viceversa?
	//Pedir y liberar memoria solo cuando creo y cuando borro, cuando uso buffer no?
	//AGREGAR TODOS LOS FLAG NECESARIOS.(APERTURA DE ARCHIVOS Y ESCRITURA DE ARCHIVOS
	//hacer de forma correcta el binario(2). ultimos(2 y 9)
	//CHEQUEAR SI ES NECESARIO IMPORTAR EMPLOYEE EN EL MAIN

	int option;
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
				"10-Exit","Error\n",1,10,2)==0)
		{
			switch(option)
			{
			case 1:
				controller_loadFromText("data.csv",listaEmpleados);
				break;
			case 2:
//				controller_loadFromBinary("data.bin",listaEmpleados);
				printf("entro 2");
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
				printf("entro 8");
				//controller_saveAsText("data.csv",listaEmpleados);
				break;
			case 9:
				printf("entro 9");
//				controller_saveAsBinary("data.csv",listaEmpleados);
				break;
			case 10:
				printf("entro 10");
				break;
			}
		}
		}while(option!=10);
	return 0;
}

