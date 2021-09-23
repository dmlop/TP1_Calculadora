
#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>


int IngresarNumero(char mensaje[]){
	int numeroIngresado;
	printf("%s",mensaje);
	scanf("%d",&numeroIngresado);
	return numeroIngresado;
}
int IngresarTexto(char mensaje[],int tam){
	int actividad=0;
	char aux[tam];
	printf("Ingrese un texto: ");
	fflush(stdin);
	scanf("%s",aux);
	while(strnlen(aux,sizeof(aux))>tam){
		printf("Se excedio el maximo de caracteres, por favor ingrese menos de %d caracteres",tam);
		fflush(stdin);
		scanf("%s",aux);
		actividad=1;
	}

	strncpy(aux,mensaje,sizeof(aux));
	printf("El texto ingresado fue: %s",mensaje);
	return actividad;
}
int IngresarNumeroRango(char mensaje[],int rangoMin,int rangoMax){
	int numeroIngresado;
	numeroIngresado=IngresarNumero(mensaje);
	while(numeroIngresado<rangoMin||numeroIngresado>rangoMax){
		printf("FUERA DE RANGO: ingrese un numero entre %d y %d\n",rangoMin,rangoMax);
		numeroIngresado=IngresarNumero(mensaje);
	}
	return numeroIngresado;
}
void IngresarNumeroPosicionAleatorioExcluyente(int vector[],int tam,int cantidadIngresos,char excluyente){
	int i;
	int posicionVector;
	for(i=0;i<cantidadIngresos;i++){
		printf("Elija una posicion del Vector entre 1 y %d: ",tam);
		scanf("%d",&posicionVector);
		posicionVector--;
		while(posicionVector<0||posicionVector>tam-1){
			printf("Posicion invalida, ingrese una posicion entre 1 y %d: ",tam);
			scanf("%d",&posicionVector);
			posicionVector--;
		}
		switch(excluyente){
			case 'N':
				printf("Ingrese un numero: ");
				scanf("%d",&vector[posicionVector]);
				break;
			case '0':
				printf("Ingrese un numero: ");
				scanf("%d",&vector[posicionVector]);
				while(ValidarCero(vector[posicionVector])==1){
					printf("DATO INVALIDO, Ingrese un numero distinto de cero: ");
					scanf("%d",&vector[posicionVector]);
				}
				break;
		}

	}
}
int ValidarCero(int numeroIngresado){
	if(numeroIngresado==0){
		return 1;
	}
	else{
		return 0;
	}
}
int VerificarParImpar(int numeroIngresado){
	if(numeroIngresado%2==0){
		return 0;
	}
	else{
		return 1;
	}


}
int VerificarPositivoNegativoNeutro(int numeroIngresado){
	if(numeroIngresado>0){
		return 1;
	}
	else{
		if(numeroIngresado<0){
			return -1;
		}
		else{
			return 0;
		}
	}

}
int ContadorGenerico(int vector[],int tam,char contar){
	int contador=0;
	int i;
	for(i=0;i<tam;i++){
		switch(contar){
			case 'P':
				if(VerificarParImpar(vector[i])==0){
					contador++;
				}
				break;
			case 'I':
				if(VerificarParImpar(vector[i])==1){
					contador++;
				}
				break;
			case '+':
				if(VerificarPositivoNegativoNeutro(vector[i])==1){
					contador++;
				}
				break;
			case '-':
				if(VerificarPositivoNegativoNeutro(vector[i])==-1){
					contador++;
				}
				break;
			case '0':
				if(VerificarPositivoNegativoNeutro(vector[i])==0){
					contador++;
				}
				break;
			default:
				printf("WARNING! ContadorGenerico char[] invalido, use: Pares='P',Impares='I',Positivo='+',Negativo='-',Neutro='0'");

		}
	}
	return contador;
}
int AcumuladorGenerico(int vector[],int tam,char contar){
	int acumulador=0;
	int i;
	for(i=0;i<tam;i++){
		switch(contar){
			case 'P':
				if(VerificarParImpar(vector[i])==0){
					acumulador+=vector[i];
				}
				break;
			case 'I':
				if(VerificarParImpar(vector[i])==1){
					acumulador+=vector[i];
				}
				break;
			case '+':
				if(VerificarPositivoNegativoNeutro(vector[i])==1){
					acumulador+=vector[i];
				}
				break;
			case '-':
				if(VerificarPositivoNegativoNeutro(vector[i])==-1){
					acumulador+=vector[i];
				}
				break;
			case '0':
				if(VerificarPositivoNegativoNeutro(vector[i])==0){
					acumulador+=vector[i];
				}
				break;
			default:
				printf("WARNING! AcumuladorGenerico char[] invalido, use: Pares='P',Impares='I',Positivo='+',Negativo='-',Neutro='0'");

		}
	}
	return acumulador;
}
int ValorMayorGenerico(int vector[],int tam,char mayor){
	int i;
	int valorMayor=-32768;
	for(i=0;i<tam;i++){
		switch(mayor){
			case 'I':
				if(VerificarParImpar(vector[i])==1){

					if(valorMayor<vector[i]){
						valorMayor=vector[i];
					}
				}
				break;
		}

	}
	return valorMayor;
}
void MostrarVectorIntGenerico(int vector[],int tam,char mensaje[],char mostrar){
	int i;

	printf("%s",mensaje);
	for(i=0;i<tam;i++){
		switch(mostrar){
			case 'T':
				printf("%d\t",vector[i]);
				break;
			case 'P':
				if(VerificarParImpar(vector[i])==0){
					printf("%d\t",vector[i]);
				}
				break;
			case 'I':
				if(VerificarParImpar(vector[i])==1){
					printf("%d\t",vector[i]);
				}
				break;
			case '+':
				if(VerificarPositivoNegativoNeutro(vector[i])==1){
					printf("%d\t",vector[i]);
				}
				break;
			case '-':
				if(VerificarPositivoNegativoNeutro(vector[i])==-1){
					printf("%d\t",vector[i]);
				}
				break;
			case '0':
				if(VerificarPositivoNegativoNeutro(vector[i])==0){
					printf("%d\t",vector[i]);
				}
				break;
			default:
				printf("WARNING! MostrarVectorIntGenerico char[] invalido, use: TODO='T',Pares='P',Impares='I',Positivo='+',Negativo='-',Neutro='0'");
		}
	}

}
void MostrarPosicionVectorParImpar(int vector[],int tam,char mensaje[],char mostrar){
	int i;

	printf("%s",mensaje);
	for(i=0;i<tam;i++){
		switch(mostrar){
			case 'P':
				if(VerificarParImpar(i)==0){
					printf("Valor de la posicion Par[%d] es %d\n",i,vector[i]);
				}
				break;
			case 'I':
				if(VerificarParImpar(i)==1){
					printf("Valor de la posicion Impar[%d] es %d\n",i,vector[i]);
				}
				break;
			default:
				printf("WARNING! MostrarPosicionVectorParImpar char[] invalido, use: Pares='P',Impares='I'");
		}
	}

}
int IntercambioDeValores(int* a,int* b){
	int aux;
	aux=*a;
	*a=*b;
	*b=aux;

	return 1;
}
int CrearVectorPositivos(int vector[],int tam, int vectorPositivos[]){
	int i;
	int actividad=0;

	for(i=0;i<tam;i++){
		if(VerificarPositivoNegativoNeutro(vector[i])==1||VerificarPositivoNegativoNeutro(vector[i])==0){
			vectorPositivos[i]=vector[i];
			actividad=1;
		}
	}


	return actividad;
}
int CrearVectorNegativo(int vector[],int tam,int vectorNegativos[]){
	int actividad=0;

	for(int i=0;i<tam;i++){
		if(VerificarPositivoNegativoNeutro(vector[i])==-1){
			vectorNegativos[i]=vector[i];
			actividad=1;
		}
	}

	return actividad;
}
void CambiarValorVector(int vector[],int tam,int seteo){
	int i;
	for(i=0;i<tam;i++){
		vector[i]=seteo;
	}
}
void OrdenarVectorGenerico(int vector[],int tam,char criterio){

	for(int i=0;i<tam;i++){
		for(int j=i+1;j<tam;j++){
			switch(criterio){
			case 'C':
				if(vector[i]>vector[j]){
					int aux;
					aux=vector[i];
					vector[i]=vector[j];
					vector[j]=aux;
				}
				break;
			case 'D':
				if(vector[i]<vector[j]){
					int aux;
					aux=vector[i];
					vector[i]=vector[j];
					vector[j]=aux;
				}
				break;
			}
		}
	}
}
//===================================================
int myGets(char* cadena,int tam){
	fflush(stdin);
	fgets(cadena,tam,stdin);
	cadena[strlen(cadena)-1]='\0';
	return 0;
}
int getInt(int* pResultado){
	int retorno=-1;
	char buffer[4096];

	if(myGets(buffer,sizeof(buffer))==0&&esNumericaInt(buffer)){
		retorno=0;
		*pResultado=atoi(buffer);
	}

	return retorno;
}
int getFloat(float* pResultado){
	int retorno=-1;
	char buffer[4096];

	if(myGets(buffer,sizeof(buffer))==0&&esNumericaFloat(buffer)){
		retorno=0;
		*pResultado=atof(buffer);
	}

	return retorno;
}
int getChar(char* pResultado, int tam){
	int retorno=0;
	char buffer[4096];

	if(myGets(buffer,tam)==0&&esTextoBasico(buffer)==1){
		retorno=1;
		strncpy(pResultado,buffer,tam);
	}

	return retorno;
}
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
int esTextoBasico(char* cadena){
	int retorno= 1;
		int i;

		for(i=0;cadena[i]!='\0';i++){
			//if(cadena[i]<'A'||(cadena[i]>'Z'&&cadena[i]<'a')||(cadena[i]>'z'&&cadena[i]<'ñ')||cadena[i]>'Ñ'){
			if(cadena[i]<32||(cadena[i]>32&&cadena[i]<65)||(cadena[i]>90&&cadena[i]<97)||(cadena[i]>122&&cadena[i]<164)||cadena[i]>165){
				retorno=0;
				break;
			}
		}
	return retorno;
}
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
void utn_getCharNombre(char* pResultado,int tam, char* mensaje,char* mensajeError, int reintentos){
	char buffer[4096];
	if(pResultado!=NULL&&mensaje!=NULL&&mensajeError!=NULL&&reintentos>=0){
		do{
			printf("%s",mensaje);
			if(getChar(buffer,tam)==1){
				strncpy(pResultado,buffer,tam);
				break;
			}
			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos>=0);
	}
}
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
int ConcatenarNombreYApellido(char*nombre,char*apellido,char*nombreCompleto,int tam){
	int retorno=0;
	snprintf(nombreCompleto,tam,"%s, %s",apellido,nombre);
	retorno=PrimerasLetrasMayuscula(nombreCompleto);
	return retorno;
}

void Menu(int *pResultado,int*A,int*B,float*x,float*y){
	char strResultado[8];
	printf("\n=================MENU=================\n");
	if(*A==0){
		printf("||1. Ingresar operando A.\n");
	}
	else{
		LimpiarCerosDecimales(*x,strResultado);
		printf("||1.Modificar operando A. \t |A=%s|\n",strResultado);
	}
	if(*B==0){
		printf("||2. Ingresar operando B.\n");
		}
		else{
			LimpiarCerosDecimales(*y,strResultado);
			printf("||2.Modificar operando B. \t |B=%s|\n",strResultado);
		}
		printf("||3. Calcular todas las operaciones.\n"
			"||4. Informar resultados.\n"
			"||5. Salir.\n"
			"=======================================\n");

	utn_getIntRango(pResultado,"Ingrese la opcion elegida: ","ERROR! NUMERO INVALIDO!",1,5,99);


}
float Sumar(float a, float b){
	float resultado;
	resultado=a+b;
	return resultado;
}
float Restar(float a, float b){
	float resultado;
	resultado=a-b;
	return resultado;
}
float Multiplicar(float a, float b){
	float resultado;
	resultado=a*b;
	return resultado;
}
int Dividir(float a, float b,float*pDivision){
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

int Factorial(float a,float*pResultado){
	int i;
	int retorno;

	if(a==(int)a){
			retorno=1;
			for(i=(a-1);i>1;i-- ){
				a*=i;
			}
			*pResultado=a;
		}
		else{

			retorno=0;
		}

	return retorno;
}
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
