

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

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
void Menu(int *pOpcion,int*banderaA,int*banderaB,float*A,float*B);

void utn_getInt(int* pResultado, char* mensaje,char* mensajeError,int reintentos);
void utn_getFloat(float* pResultado, char* mensaje,char* mensajeError,int reintentos);
void LimpiarCerosDecimales (float numeroAMostrar, char*resultado);

//============================================================
void Firma(void);



#endif /* BIBLIOTECA_H_ */
