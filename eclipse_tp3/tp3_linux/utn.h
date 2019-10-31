/*
 * utn.h
 *
 *  Created on: 23 sep. 2019
 *      Author: javijps
 */

#ifndef UTN_H_
#define UTN_H_

#define QTY_CARACTERES 50

int getInt(   int *pNumero,
		      char *mensaje,
			  char *mensajeError,
			  int minimo,
			  int maximo,
			  int reintentos);
int esInt(char *nInt);
int getFloat(float *pResultado,
	      char *pMensaje,
		  char *pMensajeError,
		  int minimo,
		  int maximo,
		  int reintentos);;
int esFloat(char *nfloat);
int getChar(char *pChar,
		      char *mensaje,
			  char *mensajeError,
			  int minimo,
			  int maximo,
			  int reintentos);
int getString(char *pResultado,
		char *pMensaje,
		char *pMensajeError,
		int minimo,
		int maximo,
		int reintentos);
int getLetra(char *pChar,
		      char *pMensaje,
			  char *pMensajeError,
			  int reintentos);
int esLetra(char character);
int esNombre(char *pNombre);
int getNombre(char *pNombre,char *pMensaje,char *pMensajeError,int reintentos);
int esNumerica(char *cadena);
int esAlfaNumerica(char *cadena);
int getAlfanumerica(char *input,char *pMensaje,char *pMensajeError,int reintentos);
int esCuit(char *cadena);
int getCuit(char *input,char *pMensaje,char *pMensajeError,int reintentos);


int getstringToInt(int *enteroRetorno,char *pString,char *pMensaje,char *pMensajeError,int len,int reintentos);
int getstringToFloat(float *flotanteRetorno,char *pString,char *pMensaje,char *pMensajeError,int len,int reintentos);












#endif /* UTN_H_ */
