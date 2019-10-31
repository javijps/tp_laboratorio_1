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
#include "utn.h"

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
	char bufferStr[50];

	if(     pNumero != NULL &&
			mensaje != NULL &&
			mensajeError != NULL &&
			minimo < maximo &&
			reintentos>=0)
	{
		do
		{
			__fpurge(stdin);
			if((getString(bufferStr,mensaje,mensajeError,1,50,2)==0) && (esInt(bufferStr))==0)
			{
				retorno = 0;
				*pNumero =atoi(bufferStr);
				break;
			}
			else
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos >= 0);

	}

	return retorno;
}

/**
* \Valida si el nombre es entero
* \param nInt numero recibido
* \return Si valida el entero [0] o si es invalido [-1]
*/
int esInt(char *nInt)
{
    int retorno=-1;
    int i=0;

    while(nInt[i]!='\0')
    {
    	if(nInt[i]>='0' && nInt[i]<='9')
    	{
    		i++;
    		retorno=0;
    	}
    	else
    	{
    	  	printf("no es numero\n");
    		retorno = -1;
    		break;
    	}
    }
    return retorno;
}

/**
* \brief Solicita numero flotante al usuario y lo valida.
* \param pResultado Se carga el numero ingresado.
* \param mensaje Mensaje a ser mostrado.
* \param mensajeError Mensaje a ser mostrado en caso de error.
* \param minimo Limite minimo a validar.
* \param maximo Limite maximo a validar.
* \param reintentos Reintentos permitidos en caso de error.
* \return Si tuvo exito al obtener el numero [0] o si fallo [-1]
*/
int getFloat(float *pResultado,
	      char *pMensaje,
		  char *pMensajeError,
		  int minimo,
		  int maximo,
		  int reintentos)
{
	int retorno = -1;
	char bufferStr[QTY_CARACTERES];

	if(     pResultado != NULL &&
			pMensaje != NULL &&
			pMensajeError != NULL &&
			minimo < maximo &&
			reintentos>=0)
	{
		do
		{
			if(getString(bufferStr,pMensaje,pMensajeError,1,QTY_CARACTERES,2)==0 && esFloat(bufferStr)==0)
				{
					retorno = 0;
					*pResultado =atof(bufferStr);
					break;
				}
				else
					printf(pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}

	return retorno;
}


/**
* \Valida si el nombre es flotante
* \param nInt numero recibido
* \return Si valida el flotante [0] o si es invalido [-1]
*/
int esFloat(char *nfloat)
{
    int retorno=-1;
    int i=0;

    while(nfloat[i]!='\0')
    {
    	if((nfloat[i]>='0' && nfloat[i]<='9') || (nfloat[i]=='.'))
    	{
    		i++;
    		retorno=0;
    	}
    	else
    	{
    		retorno = -1;
    		break;
    	}
    }
    return retorno;
}


/**
* \Valida si el caracter es una letra
* \param nInt numero recibido
* \return Si valida el flotante [0] o si es invalido [-1]
*/
int esLetra(char character)
{
    int retorno=-1;

    if((character >= 'a' && character <= 'z') ||
    		(character >= 'A' && character <= 'Z'))
    	{
    		retorno=0;
    	}
    	else
    		retorno = -1;
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
int getLetra(   char *pChar,
		      char *pMensaje,
			  char *pMensajeError,
			  int reintentos)
{
	int retorno = -1;
	char bufferChar;
	if(pChar != NULL &&
			pMensaje != NULL &&
			pMensajeError != NULL &&
			reintentos>=0)
	{
		do
		{
			if(getString(&bufferChar,pMensaje,pMensajeError,1,1,2)==0 && esLetra(bufferChar)==0)
			{
				retorno = 0;
				*pChar =bufferChar;
				break;
			}
			else
				printf(pMensajeError);
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
				strncpy(pResultado,buffer,maximo);
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
 *
* \Valida si el nombre esta compuesto por letras
* \param pNombre Nombre recibido
* \return Si valida el nombre [0] o si es invalido [-1]
*/
int esNombre(char *pNombre)
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
				printf("Error, los datos ingresados no corresponden a un nombre!!\n");
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
 * \brief Evalua si la cadena de caracteres es alfanumerica.
 * \param cadena Array de caracteres a ser validado
 * \return Si la cadena de caracteres recibida es alfanumerica [0] o si no lo es[-1]
 */

int esAlfaNumerica(char *cadena)
{
	int retorno=-1;
	int i;
	if(cadena!=NULL)
	{
		while(cadena[i]!='\0')
		{
			if((cadena[i] >= '0' && cadena[i] <= '9') || (cadena[i] >= 'a' && cadena[i] <= 'z') ||
					(cadena[i] >= 'A' && cadena[i] <= 'Z'))
			{
				retorno = 0;
				i++;
			}
			else
			{
				retorno = -1;
					break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param input puntero a Array donde se cargará el texto ingresado
 * \param reintentos reintentos permitidos al usuario
 * \return 0 si el texto es correcto -1 si no lo es
 */

int getAlfanumerica(char *pAlfanumerica,char *pMensaje,char *pMensajeError,int reintentos)
{
	int retorno = -1;

	if(pAlfanumerica != NULL &&
			pMensaje != NULL &&
			pMensajeError != NULL &&
			reintentos >=0)
	{
		do
		{
			if(getString(pAlfanumerica,pMensaje,pMensajeError,0,100,reintentos)==0)
			{
				if(esAlfaNumerica(pAlfanumerica)==0)
				{
					retorno = 0;
					break;
				}
				else
				{
					printf(pMensajeError);
					reintentos--;
				}
			}
		}while(reintentos>0);
	}
	return retorno;
}

/**
* \brief Evalua si la cadena de caracteres es alfanumerica.
* \param cadena Array de caracteres a ser validado
* \return Si la cadena de caracteres recibida es numerica [0] o si no lo es[-1]
*/

int esCuit(char *cadena)
{
	int retorno=-1;
	int i;
	int contadorCaracteres=0;

	if(cadena!=NULL)
	{
		while(cadena[i]!='\0')
		{
			if((cadena[i] >= '0' && cadena[i] <= '9')|| cadena[i] == '-' )			{
				retorno = 0;
				contadorCaracteres++;
				i++;
			}
			else
			{
				retorno = -1;
				printf("Error, los datos ingresados no corresponden a caracteres de un cuit!!\n");
				break;
			}
		}
		if(contadorCaracteres!=13)
		{
			retorno = -1;
			printf("Cantidad de caracteres ingresados (%d) incorrecto!\nEl cuit debe contener 11 caracteres\n",contadorCaracteres);
		}
	}
	return retorno;
}

/**
 * \brief Solicita un cuit al usuario y lo devuelve
 * \param input puntero a Array donde se cargará el cuit ingresado
 * \param reintentos reintentos permitidos al usuario
 * \return 0 si el cuit es correcto -1 si no lo es
 */

int getCuit(char *input,char *pMensaje,char *pMensajeError,int reintentos)
{
	int retorno = -1;

	if(input != NULL &&
			pMensaje != NULL &&
			pMensajeError != NULL &&
			reintentos >=0)
	{
		do
		{
			if(getString(input,"\nIngrese cuit sin / ni - \n","No corresponde a un Cuit\n",1,111,reintentos)==0)//es 10 u 11
			{
				if(esCuit(input)==0)
				{
					retorno = 0;
					break;
				}
				else
					reintentos--;
			}
		}while(reintentos>0);
	}
	return retorno;
}





int getstringToInt(int *enteroRetorno,char *pString,char *pMensaje,char *pMensajeError,int len,int reintentos)
{
	int retorno = -1;

	if(pString != NULL &&
			pMensaje != NULL &&
			pMensajeError != NULL &&
			len>0 &&
			reintentos >=0)
	{
		do
		{
			if(getString(pString,pMensaje,pMensaje,1,50,reintentos)==0 && esInt(pString)==0)
				{
					*enteroRetorno =atoi(pString);
					retorno = 0;
					break;
				}
				else
				{
					printf(pMensajeError);
					reintentos--;
				}
		}while(reintentos>0);
	}
	return retorno;
}

int getstringToFloat(float *flotanteRetorno,char *pString,char *pMensaje,char *pMensajeError,int len,int reintentos)
{
	int retorno = -1;

	if(pString != NULL &&
			pMensaje != NULL &&
			pMensajeError != NULL &&
			len>0 &&
			reintentos >=0)
	{
		do
		{
			if(getString(pString,pMensaje,pMensaje,1,50,reintentos)==0 && esFloat(pString)==0)
			{
				*flotanteRetorno =atof(pString);
				retorno = 0;
				break;
			}
			else
			{
				printf(pMensajeError);
				reintentos--;
			}
		}while(reintentos>0);
	}
	return retorno;
}
