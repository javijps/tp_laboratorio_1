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

int main()//CHEQUEAR QUE TODAS LAS FUNCIONES TENGAN EL IF CORRESPONDIENTE AL CHEQUEO DE PARAMETROS EN EL PRIMER IF
{	int option;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{//PONERLE IF AL GETINT
    	getInt(&option,"\nIngrese opcion:\n1-Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
    			"2-Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
    			"3-Alta empleado\n"
    			"4-Modificar datos de empleado\n"
    			"5-Baja de empleado\n"
    			"6-Listar empleados\n"
    			"7-Ordenar empleados\n"
    			"8-Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
    			"9-Guardar los datos de los empleados en el archivo data.csv (modo binario)\n","Error\n",1,10,2);

    	switch(option)//AGREGAR TODOS LOS FLAG NECESARIOS.
    	{
    	case 1://SI SE CARGO COMO BINARIO, NO PERMITIR CARGAR?
    		controller_loadFromText("data.csv",listaEmpleados);//HACER VALIDACIONES DE LOS INPUR. GET NOMBRE NO FUNCIONA.
    		break;
    	case 2://SI SE CARGO COMO TEXTO, NO PERMITIR CARGAR?
    		controller_loadFromBinary("data.csv",listaEmpleados);//hacer de forma correcta el binario. ultimo
    		break;
    	case 3://CHEQUEAR VALIDACIONES DE INPUTS. HACER ESHORAS Y ES SUELDO? HACER FUNCION GENERAR ID Y MAXIMO ID.
    		controller_addEmployee(listaEmpleados);//ARREGLAR FUNCIONES INPUT
    		break;
    	case 4://CHEQUEAR VALIDACIONES DE INPUTS. HACER ESHORAS Y ES SUELDO?
    		controller_editEmployee(listaEmpleados);//ARREGLAR FUNCIONES INPUT
    		break;
    	case 5:
    		controller_removeEmployee(listaEmpleados);
    		break;
    	case 6:
    		controller_ListEmployee(listaEmpleados);
    		break;
    	case 8:
    		break;
    	case 9:
    		break;
    	}
    }while(option!=10);
    return 0;
}

