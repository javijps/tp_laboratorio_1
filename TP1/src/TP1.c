/*******************************************************************
* Programa: Trabajo Practico N�1
* Objetivo: Hacer una calculadora
*
* Version: 0.1 del 9 Septiembre de 2019
* Autor: Scalise Javier
*
********************************************************************/

#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include "funcionesMatematica.h"
#include "utn.h"
#define MAX_PERMITIDO 1000
#define MIN_PERMITIDO 0
#define REINTENTOS 3
#define MIN_CHAR 'a'
#define MAX_CHAR 'e'
#define SALIDA 5

int main(void) {

	int opcion;
	char opcionChar;
	float numeroA=0;
	float numeroB=0;
	float resultadoSuma;
	float resultadoResta;
	float resultadoProducto;
	float resultadoDivision;
	unsigned long long int factorialA;
	unsigned long long int factorialB;

	do
	{


	printf("Ingrese una opcion\n"
			"1. Ingresar 1er operando numeroA=%.2f)\n"
			"2. Ingresar 2do operando numeroA=%.2f)\n"
			"3. Calcular todas las operaciones\n"
               "a) Calcular la suma (A+B)\n"
               "b) Calcular la resta (A-B)\n"
               "c) Calcular la division (A/B)\n"
               "d) Calcular la multiplicacion (A*B)\n"
               "e) Calcular el factorial (A!)\n"
               "4. Informar resultados\n"
               "a) El resultado de A+B\n"
               "b) El resultado de A-B\n"
               "c) El resultado de A/B\n"
               "d) El resultado de A*B\n"
               "e) El factorial de A y El factorial de B\n"
               "5. Salir\n",numeroA,numeroB);

	getInt(&opcion,"Ingrese una opcion\n","El valor ingresado no es valido\n",MIN_PERMITIDO,MAX_PERMITIDO,REINTENTOS);
	switch(opcion)
	{
	case 1:
		if(getFloat(&numeroA,"Ingrese 1er operando\n","El valor ingresado no es valido\n",MIN_PERMITIDO,MAX_PERMITIDO,REINTENTOS)==EXIT_SUCCESS)
		{}
		break;
	case 2:
		if(getFloat(&numeroB,"Ingrese 2do operando\n","El valor ingresado no es valido\n",MIN_PERMITIDO,MAX_PERMITIDO,REINTENTOS)==EXIT_SUCCESS)
		{}
		break;
	case 3:
		if(getChar(&opcionChar,"Ingrese a, b c, d, e\n","Caracter incorrecto",MIN_CHAR,MAX_CHAR,REINTENTOS)==EXIT_SUCCESS)
		{
			switch(opcionChar)
			{
			case 'a':
				if(sumaFloat(numeroA,numeroB,&resultadoSuma)==EXIT_SUCCESS)
				break;
			case 'b':
				if(restaFloat(numeroA,numeroB,&resultadoResta)==EXIT_SUCCESS)
				break;
			case 'c':
				if(divisionFloat(numeroA,numeroB,&resultadoDivision)==EXIT_SUCCESS)
				break;
			case 'd':
				if(productoFloat(numeroA,numeroB,&resultadoProducto)==EXIT_SUCCESS)
				break;
			case 'e':

				if(floatEsEntero(numeroA)==EXIT_SUCCESS)
				{
					factorialA = factorial(numeroA);
				}
				else
				{
					printf("Solo es posible calcular el factorial de numeros enteros y positivos\n");
				}
				if(floatEsEntero(numeroB)==0)
				{
					factorialB = factorial(numeroB);
				}
				else
				{
					printf("Solo es posible calcular el factorial de numeros enteros y positivos\n");
				}
				break;
			}
		}
			break;
			break;
	case 4:
		if(getChar(&opcionChar,"Ingrese a, b c, d, e\n","Caracter incorrecto",MIN_CHAR,MAX_CHAR,REINTENTOS)==EXIT_SUCCESS)
		{
			switch(opcionChar)
		    {
			case 'a':
				printf("El resultado de %.2f + %.2f es: %.2f\n",numeroA,numeroB,resultadoSuma);
				break;
			case 'b':
				printf("El resultado de %.2f - %.2f es: %.2f\n",numeroA,numeroB,resultadoResta);
				break;
			case 'c':
				printf("El resultado de %.2f / %.2f es: %.2f\n",numeroA,numeroB,resultadoDivision);
				break;
			case 'd':
				printf("El resultado de %.2f * %.2f es: %.2f\n",numeroA,numeroB,resultadoProducto);
				break;
			case 'e':
				if(factorialA==0)
				{
					printf("No es posible mostrar el factorial de A\n");
				}
				else
				{
					printf("El factorial de A es: %lld\n",factorialA);
				}
				if(factorialB==0)
				{
					printf("No es posible mostrar el factorial de B\n");
				}
				else
				{
					printf("El factorial de B es: %lld\n",factorialB);
				}
				break;
				}
		}
			break;
			break;
	}
	}while(opcion!=SALIDA);
	printf("Adios!");
return EXIT_SUCCESS;
}

