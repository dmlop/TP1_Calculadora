#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "biblioteca.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	char buffId[10];
	char buffNombre[128];
	char buffHorasTrabajadas[10];
	char buffSueldo[10];
	//int i=0; //PARA CARGAR SOLO 15 EMPLEADOS Y TESTEAR LOS SORT
	Employee* empleado;

	retorno=0;
	if(pFile!=NULL&&pArrayListEmployee!=NULL){
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffId,buffNombre,buffHorasTrabajadas,buffSueldo);

		while(!feof(pFile)){
			/*i++;
			if(i==15){
				break;
			}*/
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffId,buffNombre,buffHorasTrabajadas,buffSueldo);

			empleado=employee_newParametros(buffId,buffNombre,buffHorasTrabajadas,buffSueldo);

			ll_add(pArrayListEmployee,empleado);
			retorno=1;
		}
	}
	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	Employee* empleado;
	retorno=0;
	if(pFile!=NULL&&pArrayListEmployee!=NULL){

		empleado=employee_new();
		fread(empleado,sizeof(Employee),1,pFile);
		ll_add(pArrayListEmployee, empleado);
		retorno=1;

	}

	return retorno;
}
int parser_IdFromText(FILE* pFile, int* id){
	int retorno;
	char buff[7];

	retorno=0;

	if(pFile!=NULL&&id!=NULL){
		fgets(buff,6,pFile);
		*id=atoi(buff);
		retorno=1;
	}
	return retorno;
}
Employee* employee_GetEmpleado(LinkedList* pArrayListEmployee){
	Employee* empleado;
	int auxId;
	int len;

	if(pArrayListEmployee!=NULL){
		len=ll_len(pArrayListEmployee);

		GetIntR(&auxId, "Ingrese el ID de un empleado: ", "ERROR\n",99);

		for(int i=0;i<len;i++){
			empleado=(Employee*)ll_get(pArrayListEmployee, i);

			if(empleado->id==auxId){
				break;
			}
		}
	}
	return empleado;
}
int Employee_MostrarEmpleados(LinkedList* pArrayListEmployee){
	int retorno;
	int len;
	Employee* aux;

	retorno=0;

	if(pArrayListEmployee!=NULL){
		len=ll_len(pArrayListEmployee);

		for(int i=0;i<len;i++){
			aux=(Employee*)ll_get(pArrayListEmployee,i);
			printf(" %-4d  %-16s  %-4d  %-7d\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
			retorno=1;
		}
	}

	return retorno;
}


