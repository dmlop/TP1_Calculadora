#include <stdio.h>
#include <stdlib.h>
#include "fMatematicas.h"
/// @brief suma los 2 numeros que se le pasan
///
/// @param a numero uno
/// @param b numero dos
/// @return retorna el resultado
long Sumar(float a, float b){
	long resultado;
	resultado=a+b;
	return resultado;
}
/// @brief resta los 2 numeros que se le pasan
///
/// @param a numero uno
/// @param b numero dos
/// @return retorna el resultado
long Restar(float a, float b){
	long resultado;
	resultado=a-b;
	return resultado;
}
/// @brief Multiplica los 2 numeros que se le pasan
///
/// @param a numero uno
/// @param b numero dos
/// @return retorna el resultado
long Multiplicar(float a, float b){
	long resultado;
	resultado=a*b;
	return resultado;
}
/// @brief Divide los 2 numeros que se le pasan, checkea que el segundo numero no sea 0
///
/// @param a numero uno
/// @param b numero dos
/// @return retorna el resultado
int Dividir(float a, float b,long *pDivision){
	int retorno;
	if(b!=0.0){

		*pDivision=(a/b);
		retorno=1;
	}
	else{
		retorno=0;
	}
	return retorno;
}
/// @brief el factorial del numero que se le ingresa
///
/// @param a numero ingresado
/// @return retorna el resultados
int Factorial(float a,long *pResultado){
	int i;
	int retorno;

	if(a==0){
		retorno=1;
		*pResultado=1;
	}
	else{
		if(a==(int)a){
			if(a==0){
					retorno=1;
					*pResultado=1;
			}
			else{
				if(a>0){
					retorno=1;
					for(i=(a-1);i>0;i-- ){
						a*=i;
					}
				}
			}
			*pResultado=a;
		}
		else{
			retorno=0;
			}
	}
	return retorno;
}
