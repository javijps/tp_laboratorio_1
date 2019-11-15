#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Empleado.h"
#include "Parser.h"



int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)//MENSAJE ACA EN LUGAR DEL MAIN?
{
	int retorno = -1;
	FILE* pFile;
	pFile = fopen(path,"r");

	if(pFile!=NULL &&
			pArrayListEmployee!=NULL &&
			ll_len(pArrayListEmployee)==0 &&
			parser_parseEmpleados(pFile,pArrayListEmployee)==0)
	{
		retorno = 0;
		printf("Archivo cargado!\n");
		fclose(pFile);
	}
	else
		printf("No fue posible cargar el archivo\n");
	return retorno;
}

int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{

    return 1; // OK
}

