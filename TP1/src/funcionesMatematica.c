
#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
/**
* \brief Devuelve suma de dos numeros flotantes
* \param numeroA Primer operando.
* \param numeroB Segundo operando.
* \param *resultado puntero a resultado de la suma.
* \return Si tuvo exito al realizar la operacion [0]
* */
int sumaFloat(float numeroA,float numeroB,float *pResultado)
{
	int retorno;
	retorno =-1;
	*pResultado = numeroA + numeroB;
	retorno = 0;

	return retorno;
}
/**
* \brief Devuelve resta de dos numeros flotantes
* \param numeroA Primer operando.
* \param numeroB Segundo operando.
* \param *resultado puntero a resultado de la resta.
* \return Si tuvo exito al realizar la operacion [0]
* */
int restaFloat(float numeroA,float numeroB,float *resultado)
{
	*resultado = numeroA - numeroB;
	return 0;
}
/**
* \brief Devuelve producto de dos numeros flotantes
* \param numeroA Primer operando.
* \param numeroB Segundo operando.
* \param *resultado puntero a resultado de la operacion de multiplicacion.
* \return Si tuvo exito al realizar la operacion [0]
* */

int productoFloat(float numeroA,float numeroB,float *resultado)// ver overflow. definir maximo?
{
	*resultado = numeroA * numeroB;
	return  0;
}
/**
* \brief Calcula division de dos numeros flotantes. Toma el primer operando como dividendo y el segundo como divisor.
* \param numeroA Primer operando.
* \param numeroB Segundo operando.
* \param *resultado puntero a resultado de la operacion de multiplicacion.
* \return Si tuvo exito al realizar la operacion [0]
* */
int divisionFloat(float numeroA,float numeroB,float *resultado)
{
	int retorno;
	if(numeroB == 0)
	{
		printf("No es posible dividir por 0\n");
		retorno = -1;
	}
	else
	{
		*resultado = numeroA /  numeroB;
		retorno =0;
	}

	return retorno;
}
/**
* \brief Calcula el factorial de un numero entero positivo.
* \param numero Entero para calcular el factorial.
* \return El resultado del calculo.
*/

long long int factorial(long int numero)
{
    if(numero == 0)
    {
        return 1;
    }
    else
    {
        return numero * factorial(numero-1);
    }

}









