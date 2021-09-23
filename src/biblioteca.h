

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

int IngresarNumero(char[]);
int IngresarTexto(char mensaje[],int tam);
int IngresarNumeroRango(char[],int,int);
void IngresarNumeroPosicionAleatorioExcluyente(int[],int,int,char);
int ValidarCero(int);
int VerificarParImpar(int);
int VerificarPositivoNegativo(int);
int ContadorGenerico(int[],int,char);
int AcumuladorGenerico(int[],int,char);
int ValorMayorGenerico(int[],int,char);
void MostrarVectorIntGenerico(int[],int,char[],char);
void MostrarPosicionVectorParImpar(int[],int,char[],char);
int IntercambioDeValores(int*,int*);
int CrearVectorPositivos(int[],int, int[]);
int CrearVectorNegativo(int[],int,int[]);
void CambiarValorVector(int[],int,int);
void OrdenarVectorGenerico(int[],int,char);

//===================================================
int myGets(char* cadena,int tam);
int getInt(int* pResultado);
int getFloat(float* pResultado);
int esNumericaInt(char* cadena);
int esNumericaFloat(char* cadena);
void utn_getNumeroRango(int*, char*,char*,int,int,int);
int esTextoBasico(char* cadena);
void utn_getCharNombre(char*,int, char*,char*,int);
int getChar(char* pResultado, int tam);
int PrimerasLetrasMayuscula(char*mensaje);
int ConcatenarNombreYApellido(char*,char*,char*,int);
void Menu(int* pResultado,int*A,int*B,float*x,float*y);
float Sumar(float a, float b);
float Restar(float a, float b);
float Multiplicar(float a, float b);
int Dividir(float a, float b,float*pDivision);
int Factorial(float numero,float*pResultado);
void utn_getInt(int* pResultado, char* mensaje,char* mensajeError,int reintentos);
void utn_getFloat(float* pResultado, char* mensaje,char* mensajeError,int reintentos);
void LimpiarCerosDecimales (float numeroAMostrar, char*resultado);

//============================================================
void Firma(void);



#endif /* BIBLIOTECA_H_ */
