/*
Enunciado
Hacer una calculadora. Para ello el programa iniciará y contará con
un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una
biblioteca aparte,que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#include "fMatematicas.h"
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>

int main(void) {

	setbuf(stdout,NULL);

	float x;
	float y;
	char strX[20];
	char strY[20];
	int opcion;
	float resultado;
	char strResultado[20];
	char mensaje[4000];
	char aux[80];
	int banderaA=0;
	int banderaB=0;
	int banderaResultados=0;

	do{
		Menu(&opcion,&banderaA,&banderaB,&x,&y);
		switch (opcion){
			case 1:
				system("cls");
				utn_getFloat(&x,"Ingrese el valor de A:  ","El numero ingresado NO ES VALIDO. Vuelva a ingresarlo:  ",20);
				banderaA=1;
				sprintf(aux,"----->Aun no se calcularon las operaciones!\n");
				strcpy(mensaje,aux);
				LimpiarCerosDecimales(x,strX);
				break;
			case 2:
				system("cls");
				utn_getFloat(&y,"Ingrese el valor de B:  ","El numero ingresado NO ES VALIDO. Vuelva a ingresarlo:  ",20);
				banderaB=1;
				sprintf(aux,"----->Aun no se calcularon las operaciones!\n");
				strcpy(mensaje,aux);
				LimpiarCerosDecimales(y,strY);
				break;
			case 3:
				system("cls");
				if(banderaA==0||banderaB==0){
					printf("Para elegir esta opcion debe ingresar primero los Operandos A y B.");
				}
				else{
					printf("========OPERACIONES=CALCULADAS========");
					LimpiarCerosDecimales(Sumar(x,y),strResultado);
					sprintf(aux,"==============RESULTADOS==============\na) El resultado de %s+%s es: %s\n",strX,strY,strResultado);
					strcpy(mensaje,aux);
					LimpiarCerosDecimales(Restar(x,y),strResultado);
					sprintf(aux,"b) El resultado de %s-%s es: %s\n",strX,strY,strResultado);
					strcat(mensaje,aux);
					LimpiarCerosDecimales(Multiplicar(x,y),strResultado);
					sprintf(aux,"c) El resultado de %s*%s es: %s\n",strX,strY,strResultado);
					strcat(mensaje,aux);
					if(Dividir(x,y,&resultado)==0){
						sprintf(aux,"d) No se puede dividir por 0\n");
						strcat(mensaje,aux);
					}
					else{
						LimpiarCerosDecimales(resultado,strResultado);
						sprintf(aux,"d) El resultado de %s/%s es: %s\n",strX,strY,strResultado);
						strcat(mensaje,aux);
					}
					if(Factorial(x,&resultado)==0){
						strcat(mensaje,"e) A es incompatible para hacer su factorial ");
					}
					else{
						LimpiarCerosDecimales(resultado,strResultado);
						sprintf(aux,"e) El factorial de %s es: %s ",strX,strResultado);
						strcat(mensaje,aux);
					}
					if(Factorial(y,&resultado)==0){
						strcat(mensaje,"Y B es incompatible para hacer su factorial\n");
					}
					else{
						LimpiarCerosDecimales(resultado,strResultado);
						sprintf(aux,"Y el factorial de %s es: %s ",strY,strResultado);
						strcat(mensaje,aux);
					}
					banderaResultados=1;
				}
				break;
			case 4:
				system("cls");
				if(banderaResultados==0){
					printf("Aun no se calcularon las operaciones!");
				}
				else{
					printf("%s",mensaje);
				}

				break;
			case 5:
				system("cls");
				Firma();
				break;
		}


	}while(opcion!=5);

	return EXIT_SUCCESS;
}
