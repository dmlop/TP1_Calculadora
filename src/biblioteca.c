
#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#include <string.h>
#include <ctype.h>

#include <windows.h>
/// @brief pide al usuario ingresar caracteres y de forma segura se guardan en una variable.
///
/// @param cadena - es el vector char en la cual se guarda lo que el usuario ingreso
/// @param tam - es el tamaño del vector char, usado para que no desborde el vector
/// @return
int myGets(char* cadena,int tam){
	fflush(stdin);
	fgets(cadena,tam,stdin);
	cadena[strlen(cadena)-1]='\0';
	return 0;
}
/// @brief pide al usuario ingresar caracteres, los lee y checkea que que tenga un formato numero ENTERO
///
/// @param pResultado - el puntero por el cual devuelve el entero ingresado y validado.
/// @return - retorna 1 si el si lo que ingreso el usuario es convertible a int, sino retorna 0
int getInt(int* pResultado){
	int retorno=1;
	char buffer[4096];

	if(myGets(buffer,sizeof(buffer))==0&&esNumericaInt(buffer)){
		retorno=0;
		*pResultado=atoi(buffer);
	}

	return retorno;
}
/// @brief pide al usuario ingresar caracteres, los lee y checkea que que tenga un formato de numero FLOAT
///
/// @param pResultado - el puntero por el cual devuelve el float ingresado y validado.
/// @return - retorna 1 si el si lo que ingreso el usuario es convertible a float, sino retorna 0
int getFloat(float* pResultado){
	int retorno=1;
	char buffer[4096];

	if(myGets(buffer,sizeof(buffer))==0&&esNumericaFloat(buffer)&&strlen(buffer)<8){
		retorno=0;
		*pResultado=atof(buffer);
	}

	return retorno;
}

/// @brief toma una cadena de caracteres y checkea que sea numerica del tipo Int
///
/// @param cadena - la cadena de caracteres a checkear
/// @return - retorna 1 si la cadena es numerica del tipo int y 0 si algun caracter no es valido para una variable int.
int esNumericaInt(char* cadena){
	int retorno= 1;
	int i=0;
	if(cadena[0]=='-'){
		i=1;
	}
	for(;cadena[i]!='\0';i++){
		if(cadena[i]<'0'||cadena[i]>'9'){
			retorno=0;
			break;
		}
	}
	return retorno;
}
/// @brief toma una cadena de caracteres y checkea que sea numerica del tipo float
///
/// @param cadena - la cadena de caracteres a checkear
/// @return - retorna 1 si la cadena es numerica del tipo float y 0 si algun caracter no es valido para una variable float.
int esNumericaFloat(char* cadena){
	int retorno= 1;
	int i=0;
	int contadorPunto=0;
	int esNegativo=0;
	if(cadena[0]=='-'){
		i=1;
		esNegativo=1;
	}
	for(;cadena[i]!='\0';i++){

		if(cadena[i]<'.'||(cadena[i]>'.'&&cadena[i]<'0')||cadena[i]>'9'){

			retorno=0;
			break;
		}
		else{

			if(cadena[i]=='.'){
				contadorPunto++;
				if(contadorPunto>1||(esNegativo==0&&i==0)||(esNegativo==1&&i==1)){
					retorno=0;
					break;
				}
			}
		}
	}
	return retorno;
}

/// @brief funcion final para pedir un entero, utilizando varias funciones que le dan seguridad y otros agregando parametros como Rango y Reintentos.
///
/// @param pResultado - puntero donde se guardara el numero ingresado por el usuario
/// @param mensaje	- mensaje en pantalla antes de pedir al usuario ingresar el numero.
/// @param mensajeError - mensaje de error por si el usuario no ingresa un numero valido.
/// @param minimo - el minimo valor aceptado.
/// @param maximo - el maximo valor aceptado
/// @param reintentos - la cantidad de reintentos por si falla constantemente.
void utn_getIntRango(int* pResultado, char* mensaje,char* mensajeError,int minimo, int maximo, int reintentos){

	int buffer;
	if(pResultado!=NULL&&mensaje!=NULL&&mensajeError!=NULL&&minimo<=maximo&&reintentos>=0){
		do{
			printf("%s",mensaje);
			if(getInt(&buffer)==0&&buffer>=minimo&&buffer<=maximo){
				*pResultado=buffer;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos>=0);
	}

}

/// @brief toma una cadena de caracteres y devuelve la misma cadena con la primer letra de cada palabra mayuscula
///
/// @param mensaje - el vector char que se modificara
/// @return
int PrimerasLetrasMayuscula(char*mensaje){
	int i;
	mensaje[0]=toupper(mensaje[0]);
	for(i=1;mensaje[i]!='\0';i++){
		mensaje[i]=tolower(mensaje[i]);
		if(mensaje[i-1]==32){
			mensaje[i]=toupper(mensaje[i]);
		}
	}
	return 1;
}
/// @brief acomoda el nombre y el apellido en el siguiente formato: Apellido, PrimerNombre SegundoNombre ...
///
/// @param nombre - el vector char donde se encuentra el nombre
/// @param apellido - el vector char donde se encuentra el apellido
/// @param nombreCompleto - el puntero del vector char donde se devolvera el nombre y apellido concatenados
/// @param tam - el tamaño del puntero nombreCompleto para asegurar que no se desbordara el vector
/// @return
int ConcatenarNombreYApellido(char*nombre,char*apellido,char*nombreCompleto,int tam){
	int retorno=0;
	snprintf(nombreCompleto,tam,"%s, %s",apellido,nombre);
	retorno=PrimerasLetrasMayuscula(nombreCompleto);
	return retorno;
}
/// @brief Menu que mostrara el programa constantemente y pide ingresar la opcion que usuario quiera
///
/// @param pResultado - puntero que devolvera la opcion que el usuario haya ingresado.
/// @param banderaA - bandera del numero A.
/// @param banderaB - bandera del numero B.
/// @param A - puntero del primer operador.
/// @param B - puntero del segundo operador.
void Menu(int *pOpcion,int*banderaA,int*banderaB,float*A,float*B){
	char strResultado[15];
	printf("\n=================MENU=================\n");
	if(*banderaA==0){
		printf("||1. Ingresar operando A.\n");
	}
	else{
		LimpiarCerosDecimales(*A,strResultado);
		printf("||1.Modificar operando A. \t |A=%s|\n",strResultado);
	}
	if(*banderaB==0){
		printf("||2. Ingresar operando B.\n");
		}
		else{
			LimpiarCerosDecimales(*B,strResultado);
			printf("||2.Modificar operando B. \t |B=%s|\n",strResultado);
		}
		printf("||3. Calcular todas las operaciones.\n"
			"||4. Informar resultados.\n"
			"||5. Salir.\n"
			"=======================================\n");

	utn_getIntRango(pOpcion,"Ingrese la opcion elegida: ","ERROR! NUMERO INVALIDO!\n",1,5,99);


}

/// @brief funcion final para pedir un numero int, utilizando varias funciones que le dan seguridad y otros agregando parametros como mensaje, mensaje de error y Reintentos.
///
///
/// @param pResultado - puntero que devuelve el numero ingresado
/// @param mensaje - mensaje que se le muestra al usuario antes de pedirle un numero
/// @param mensajeError - mensaje de error que se le muestra al usuario si ingresa algun caracter fuera de los permitidos
/// @param reintentos - cuantos intentos tiene el usuario de poder llegar a ingresar un numero correctamente
void utn_getInt(int* pResultado, char* mensaje,char* mensajeError, int reintentos){

	int buffer;
	if(pResultado!=NULL&&mensaje!=NULL&&mensajeError!=NULL&&reintentos>=0){
		do{
			printf("%s",mensaje);
			if(getInt(&buffer)==0){
				*pResultado=buffer;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos>=0);
	}
}
/// @brief funcion final para pedir un numero float, utilizando varias funciones que le dan seguridad y otros agregando parametros como mensaje, mensaje de error y Reintentos.
///
///
/// @param pResultado - puntero que devuelve el numero ingresado
/// @param mensaje - mensaje que se le muestra al usuario antes de pedirle un numero
/// @param mensajeError - mensaje de error que se le muestra al usuario si ingresa algun caracter fuera de los permitidos
/// @param reintentos - cuantos intentos tiene el usuario de poder llegar a ingresar un numero correctamente

void utn_getFloat(float* pResultado, char* mensaje,char* mensajeError, int reintentos){

	float buffer;
	if(pResultado!=NULL&&mensaje!=NULL&&mensajeError!=NULL&&reintentos>=0){
		do{
			printf("%s",mensaje);
			if(getFloat(&buffer)==0){
				*pResultado=buffer;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos>=0);
	}
}
/// @brief funcion para limpar los ceros a la derecha de la parte decimal, el resultado lo devuelve en forma de string, asi que solo se usa para mostrar
///
/// @param numeroAMostrar - el numero float que se lo quiere dejar bonito :D
/// @param resultado - el string del numero con TRES decimales sin ceros a la derecha
void LimpiarCerosDecimales (float numeroAMostrar, char*resultado) {
	char aux[20];
	int i;
	sprintf(aux,"%.3f",numeroAMostrar);

	for(i=(strlen(aux)-1);i>0;i--){
		if(aux[i]=='0'){
			aux[i]='\0';
		}
		else{
			if(aux[i]=='.'){
				aux[i]='\0';
				break;
			}
			break;
		}
	}
	strcpy(resultado,aux);
}




/// @brief Firma de que programa termino. muestra la firma y 5 segundos despues el programa finaliza.

void Firma(void){

	printf("========================================DANIEL MANRESA========================================\n");
	printf("||  ::::::::  :::::::::: ::::::::::   :::::::::  :::::::::: :::::::::   ::::::::  :::   ::: ||\n");
	printf("|| :+:    :+: :+:        :+:          :+:    :+: :+:        :+:    :+: :+:    :+: :+:   :+: ||\n");
	printf("|| +:+    +:+ +:+        +:+          +:+    +:+ +:+        +:+    +:+ +:+         +:+ +:+  ||\n");
	printf("|| +#+    +:+ :#::+::#   :#::+::#     +#++:++#+  +#++:++#   +#++:++#:  +#+          +#++:   ||\n");
	printf("|| +#+    +#+ +#+        +#+          +#+        +#+        +#+    +#+ +#+           +#+    ||\n");
	printf("|| #+#    #+# #+#        #+#          #+#        #+#        #+#    #+# #+#    #+#    #+#    ||\n");
	printf("||  ########  ###        ###          ###        ########## ###    ###  ########     ###    ||\n");
	printf("========================================DANIEL MANRESA========================================\n");
	Sleep(5000);
}
