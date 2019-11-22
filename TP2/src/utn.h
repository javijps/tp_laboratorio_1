/*
 * utn.h
 *
 *  Created on: 23 sep. 2019
 *      Author: javijps
 */

#ifndef UTN_H_
#define UTN_H_

int getInt(   int *pNumero,
		      char mensaje[],
			  char mensajeError[],
			  int minimo,
			  int maximo,
			  int reintentos);
int getFloat(   float *pNumero,
		      char *mensaje,
			  char *mensajeError,
			  int minimo,
			  int maximo,
			  int reintentos);
int getChar(   char *pChar,
		      char *mensaje,
			  char *mensajeError,
			  int minimo,
			  int maximo,
			  int reintentos);
int getLetter(   char *pChar,
		      char *mensaje,
			  char *mensajeError,
			  int reintentos);
int getString(char *pResultado,
		      char *pMensaje,
			  char *pMensajeError,
			  int minimo,
			  int maximo,
			  int reintentos);
int esNumerica(char *cadena);

int getNombre(char *pNombre,char *pMensaje,char *pMensajeError,int reintentos);
int esNombre(char pNombre[50]);
int getApellido(char pApellido[50],int limite,int reintentos);
int esApellido(char pApellido[50]);

#endif /* UTN_H_ */
