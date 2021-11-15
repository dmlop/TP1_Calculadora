#include "Employee.h"
#include "LinkedList.h"
#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Employee* employee_new(){
	Employee* empleado;
	empleado=(Employee*)calloc(1,sizeof(Employee));
	return empleado;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){
	Employee* aux;
	if(idStr!=NULL&&nombreStr!=NULL&&horasTrabajadasStr!=NULL&&sueldoStr!=NULL){
		aux=employee_new();
		employee_setId(aux, atoi(idStr));
		employee_setNombre(aux, nombreStr);
		employee_setHorasTrabajadas(aux, atoi(horasTrabajadasStr));
		employee_setSueldo(aux, atoi(sueldoStr));
	}
	return aux;
}
Employee* employee_newParametrosPorAux(Employee aux){
	Employee* auxNuevoEmpleado;

	auxNuevoEmpleado=employee_new();
	employee_setId(auxNuevoEmpleado, aux.id);
	employee_setNombre(auxNuevoEmpleado, aux.nombre);
	employee_setHorasTrabajadas(auxNuevoEmpleado, aux.horasTrabajadas);
	employee_setSueldo(auxNuevoEmpleado, aux.sueldo);


	return auxNuevoEmpleado;
}

int employee_setId(Employee* this,int id){
	int retorno;
	retorno=0;
	if(this!=NULL){
		this->id=id;
		retorno=1;
	}
	return retorno;
}
int employee_setNombre(Employee* this,char* nombre){
	int retorno;
	retorno=0;
	if(this!=NULL){
		strcpy(this->nombre,nombre);
		retorno=1;
	}
	return retorno;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int retorno;
	retorno=0;
	if(this!=NULL){
		this->horasTrabajadas=horasTrabajadas;
		retorno=1;
	}
	return retorno;
}
int employee_setSueldo(Employee* this,int sueldo){
	int retorno;
	retorno=0;
	if(this!=NULL){
		this->sueldo=sueldo;
		retorno=1;
	}
	return retorno;
}

int employee_mostrarUno(Employee* unEmpleado){
	int retorno;
	int aux1;
	int aux2;
	int aux3;
	char aux4[128];
	retorno=0;

	if(unEmpleado!=NULL){
		employee_getId(unEmpleado, &aux1);
		employee_getNombre(unEmpleado, aux4);
		employee_getHorasTrabajadas(unEmpleado, &aux2);
		employee_getSueldo(unEmpleado, &aux3);

		printf("%d  %s  %d  %d",aux1,aux4,aux2,aux3);
		retorno=1;
	}
	return retorno;
}

int Employee_CompararNombre(void* datoUno,void* datoDos){
	int retorno;
	Employee* empleado1;
	Employee* empleado2;
	char nombre1[128];
	char nombre2[128];

	if(datoUno!=NULL&&datoDos!=NULL){
		empleado1=(Employee*)datoUno;
		empleado2=(Employee*)datoDos;

		employee_getNombre(empleado1, nombre1);
		employee_getNombre(empleado2, nombre2);

		retorno=strcmpi(nombre1,nombre2);
	}
	return retorno;
}
int Employee_CompararHorasTrabajadas(void* datoUno,void* datoDos){
	int retorno;
	Employee* empleado1;
	Employee* empleado2;
	int horasTrabajadas1;
	int horasTrabajadas2;

	retorno=-2;
	if(datoUno!=NULL&&datoDos!=NULL){
		empleado1=(Employee*)datoUno;
		empleado2=(Employee*)datoDos;

		employee_getHorasTrabajadas(empleado1, &horasTrabajadas1);
		employee_getHorasTrabajadas(empleado2, &horasTrabajadas2);

		if(horasTrabajadas1>horasTrabajadas2){
			retorno=1;
		}
		else{
			if(horasTrabajadas1<horasTrabajadas2){
				retorno=-1;
			}
			else{
				retorno=0;
			}
		}
	}
	return retorno;
}
int Employee_CompararSueldo(void* datoUno,void* datoDos){
	int retorno;
	Employee* empleado1;
	Employee* empleado2;
	int sueldo1;
	int sueldo2;

	retorno=-2;
	if(datoUno!=NULL&&datoDos!=NULL){
		empleado1=(Employee*)datoUno;
		empleado2=(Employee*)datoDos;

		employee_getSueldo(empleado1, &sueldo1);
		employee_getSueldo(empleado2, &sueldo2);

		if(sueldo1>sueldo2){
			retorno=1;
		}
		else{
			if(sueldo1<sueldo2){
				retorno=-1;
			}
			else{
				retorno=0;
			}
		}
	}
	return retorno;
}
int employee_getId(Employee* this,int* id){
	int retorno;
	retorno=0;
	if(this!=NULL&&id!=NULL){
		*id=this->id;
		retorno=1;
	}
	return retorno;
}
int employee_getNombre(Employee* this,char* nombre){
	int retorno;
	retorno=0;
	if(this!=NULL&&nombre!=NULL){
		strcpy(nombre,this->nombre);
		retorno=1;
	}
	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int retorno;
	retorno=0;
	if(this!=NULL&&horasTrabajadas!=NULL){
		*horasTrabajadas=this->horasTrabajadas;
		retorno=1;
	}
	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo){
	int retorno;
	retorno=0;
	if(this!=NULL&&sueldo!=NULL){
		*sueldo=this->sueldo;
		retorno=1;
	}
	return retorno;
}
int Employee_PedirDatos(Employee* aux,int* id){
	int retorno;
	retorno=0;

	if(aux!=NULL&&id!=NULL){
		GetCharNombre(aux->nombre, 128,"Ingrese Nombre del Empleado: ", "ERROR\n", 99);
		GetIntRango(&aux->horasTrabajadas, "ingrese las horas Trabajadas: ", "ERROR\n", 1, 500, 99);
		GetIntRango(&aux->sueldo,"Ingrese el sueldo: ","ERROR!\n", 10000, 100000, 99);
		if(*id==0){
			*id=1;
		}
		aux->id=*id;
		retorno=1;
	}

	return retorno;
}


