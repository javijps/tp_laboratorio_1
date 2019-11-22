/*
 * utn.c
 *
 *  Created on: 23 sep. 2019
 *      Author: javijps
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayEmployees.h"
#define MAX_FLOAT 1000
#define QTY_CARACTERES 50

/**
* \brief Solicita numero entero al usuario y lo valida.
* \param pNumero Se carga el numero ingresado.
* \param mensaje Mensaje a ser mostrado.
* \param mensajeError Mensaje a ser mostrado en caso de error.
* \param minimo Limite minimo a validar.
* \param maximo Limite maximo a validar.
* \param reintentos Reintentos permitidos en caso de error.
* \return Si tuvo exito al obtener el numero [0] o si fallo [-1]
*/

int getInt(   int *pNumero,
		      char *mensaje,
			  char *mensajeError,
			  int minimo,
			  int maximo,
			  int reintentos)
{
	int retorno = -1;
	int buffer;

	if(     pNumero != NULL &&
			mensaje != NULL &&
			mensajeError != NULL &&
			minimo < maximo &&
			reintentos>=0)
	{
		do
		{

			printf("%s",mensaje);
			__fpurge(stdin);
			if((scanf("%d",&buffer)==1) && buffer >= minimo && buffer <= maximo)
			{
				retorno = 0;
				*pNumero = buffer;
				break;

			}
			printf("%s",mensajeError);
			//__fpurge(stdin)
			reintentos--;
		}while(reintentos >= 0);

	}

	return retorno;
}


/**
* \brief Solicita numero float al usuario y lo valida.
* \param pNumero Se carga el numero ingresado.
* \param mensaje Mensaje a ser mostrado.
* \param mensajeError Mensaje a ser mostrado en caso de error.
* \param minimo Limite minimo a validar.
* \param maximo Limite maximo a validar.
* \param reintentos Reintentos permitidos en caso de error.
* \return Si tuvo exito al obtener el numero [0] o si fallo [-1]
*/
int getFloat(   float *pNumero,
		      char *mensaje,
			  char *mensajeError,
			  int minimo,
			  int maximo,
			  int reintentos)
{
	int retorno = -1;
	float buffer;

	if(     pNumero != NULL &&
			mensaje != NULL &&
			mensajeError != NULL &&
			minimo < maximo &&
			reintentos>=0)
	{
		do
		{

			printf("%s",mensaje);
			__fpurge(stdin);
			if((scanf("%f",&buffer)==1) && buffer >= minimo && buffer <= maximo)
			{
				retorno = 0;
				*pNumero = buffer;
				break;

			}
			printf("%s",mensajeError);
			//__fpurge(stdin)
			reintentos--;
		}while(reintentos >= 0);

	}

	return retorno;
}

/**
* \brief Solicita caracter al usuario y lo valida.
* \param pChar Se carga el caracter ingresado.
* \param mensaje Mensaje a ser mostrado.
* \param mensajeError Mensaje a ser mostrado en caso de error.
* \param minimo Limite minimo a validar.
* \param maximo Limite maximo a validar.
* \param reintentos Reintentos permitidos en caso de error.
* \return Si tuvo exito al obtener el caracter [0] o si fallo [-1]
*/
int getChar(   char *pChar,
		      char *mensaje,
			  char *mensajeError,
			  int minimo,
			  int maximo,
			  int reintentos)
{
	int retorno = -1;
	char buffer;

	if(     pChar != NULL &&
			mensaje != NULL &&
			mensajeError != NULL &&
			minimo < maximo &&
			reintentos>=0)

	{
		do
		{

			printf("%s",mensaje);
			__fpurge(stdin);
			if(scanf("%c",&buffer)==1 &&  buffer >= minimo && buffer <= maximo)
			{
				retorno = 0;
				*pChar = buffer;
				break;

			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos >= 0);

	}

	return retorno;
}

/**
* \brief Solicita letra al usuario y valida que la misma sea entre 'a' y 'z',tanto mayuscula como minuscula.
* \param pChar Se carga la letra ingresada.
* \param mensaje Mensaje a ser mostrado.
* \param mensajeError Mensaje a ser mostrado en caso de error.
* \param reintentos Reintentos permitidos en caso de error.
* \return Si tuvo exito al obtener la letra [0] o si fallo [-1]
*/
int getLetter(   char *pChar,
		      char *mensaje,
			  char *mensajeError,
			  int reintentos)
{
	int retorno = -1;
	char buffer;
	char minimoLower='a';
	char maximoLower='z';
	char minimoUpper='A';
	char maximoUpper='Z';

	if(     pChar != NULL &&
			mensaje != NULL &&
			mensajeError != NULL &&
			reintentos>=0)

	{
		do
		{

			printf("%s",mensaje);
			__fpurge(stdin);
			if(scanf("%c",&buffer)==1 &&//reemplazar scanf
					((buffer >= minimoLower && buffer <= maximoLower) ||
					(buffer >= minimoUpper && buffer <= maximoUpper)))
			{
				retorno = 0;
				*pChar = buffer;
				break;

			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos >= 0);

	}

	return retorno;
}
/**
* \brief Solicita  cadena de caracteres al usuario y lo valida.
* \param pResultado Se carga la cadena ingresada.
* \param mensaje Mensaje a ser mostrado.
* \param mensajeError Mensaje a ser mostrado en caso de error.
* \param minimo Limite minimo a validar.
* \param maximo Limite maximo a validar.
* \param reintentos Reintentos permitidos en caso de error.
* \return Si tuvo exito al obtener la cadena [0] o si fallo [-1]
*/
int getString(char *pResultado,
		      char *pMensaje,
			  char *pMensajeError,
			  int minimo,
			  int maximo,
			  int reintentos)
{
	int retorno = -1;
	char buffer[4098];

	if(pResultado != NULL &&
	   pMensaje != NULL &&
	   pMensajeError != NULL &&
	   minimo <= maximo &&
	   reintentos >=0)
	{
		do
		{
			printf("%s",pMensaje);
			__fpurge(stdin);
			fgets(buffer,sizeof(buffer),stdin);
			buffer[strlen(buffer)-1] = '\0';
			if(strlen(buffer)>=minimo && strlen(buffer)<=maximo)
			{
				strncpy(pResultado,buffer,maximo+1);
				retorno = 0;
				break;
			}
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos>=0);
	}

	return retorno;
}

/**
* \brief Inicializa todos los elementos de un array de enteros.
* \param array Array a ser inicializado.
* \param mensaje Mensaje a ser mostrado.
* \param limite Limite del array
* \param valor Valor utilizado para inicializar los elementos del array
* \return Si tuvo exito al inicializar el array [0] o si fallo [-1]
*/
int initArrayInt(int array[],int limite,int valor)
{
	int i;
	int retorno = -1;

	if(array != NULL && limite > 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			array[i] = valor;//
		}
	}
	return retorno;
}
/**
* \brief Imprime todos los elementos de un array de enteros.
* \param array Array a ser inicializado.
* \param limite Limite del array
* \return Si tuvo exito al imprimir el array [0] o si fallo [-1]
*/
int imprimeArrayInt(int array[],int limite)
{
	int i;
	int retorno = -1;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		printf("\n\n-------\n");
		for(i=0;i<limite;i++)
		{
			printf("%d\n",array[i]);
		}

	}
	return retorno;
}

/**
* \Valida si el nombre esta compuesto por letras
* \param pNombre Nombre recibido
* \return Si valida el nombre [0] o si es invalido [-1]
*/
int esNombre(char pNombre[50])
{
	int retorno = -1;
	int i;

	if(pNombre!=NULL)

		for(i=0;pNombre[i]!='\0';i++)
		{
			if((pNombre[i] >= 'a' && pNombre[i] <= 'z') ||
					(pNombre[i] >= 'A' && pNombre[i] <= 'Z') ||
					(pNombre[i]== ' '))
			{
				retorno = 0;
				i++;
			}
			else
			{
				printf("Error, los datos ingresados son incorrectos!!\n");
				break;
			}
		}
	return retorno;
}

/**
* \brief Solicita nombre al usuario.
* \param pNombre Se carga el nombre ingresado.
* \param reintentos cantidad de errores permitidos
* \return Si tuvo exito al obtener el nombre [0] o si fallo [-1]
*/
int getNombre(char *pNombre,char *pMensaje,char *pMensajeError,int reintentos)
{
	int retorno=-1;
	if(pNombre != NULL &&
			pMensaje != NULL &&
			pMensajeError != NULL &&
			reintentos >=0)
	{
		do
		{
			getString(pNombre,pMensaje,pMensajeError,1,49,3);
			if(esNombre(pNombre)==0)
			{
				retorno = 0;
				break;
			}
			else
				reintentos--;
		}while(reintentos>0);
	}
	return retorno;
}

/**
* \Valida si el apellido esta compuesto por letras
* \param pNombre apellido recibido
* \return Si valida el apellido [0] o si es invalido [-1]
*/
int esApellido(char pApellido[50])
{
	int retorno = -1;
	int i;

	if(pApellido!=NULL)

		for(i=0;pApellido[i]!='\0';i++)
		{
			if((pApellido[i] >= 'a' && pApellido[i] <= 'z') ||
					(pApellido[i] >= 'A' && pApellido[i] <= 'Z') ||
					(pApellido[i]== ' '))
			{
				retorno = 0;
				i++;
			}
			else
			{
				printf("Error, los datos ingresados no corresponden a un apellido!!\n");
				break;
			}
		}
	return retorno;
}

/**
* \brief Solicita apellido al usuario.
* \param pApellido Se carga el apellido ingresado.
* \param limite. tamaño del array
* \param reintentos cantidad de errores permitidos
* \return Si tuvo exito al obtener el apellido [0] o si fallo [-1]
*/
int getApellido(char pApellido[50],int limite,int reintentos)
{
	int retorno=-1;

	do
	{
		getString(pApellido,"Ingrese apellido\n","El apellido ingresado es incorrecto\n",1,49,3);
		if(esApellido(pApellido)==0)
		{
			retorno = 0;
			break;
		}
		else
			reintentos--;

	}while(reintentos>0);

	return retorno;
}
