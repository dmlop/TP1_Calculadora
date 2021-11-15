#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "biblioteca.h"
#include "menu.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* pathEmpleado , LinkedList* pArrayListEmployee,char* pathId,int* id)
{
	int retorno;
	FILE* pFile;
	retorno=0;

	if(pathEmpleado!=NULL&&pArrayListEmployee!=NULL&&pathId!=NULL&&id!=NULL){
		retorno=1;
		pFile=fopen(pathEmpleado,"r");
		if(parser_EmployeeFromText(pFile, pArrayListEmployee)){
			retorno=1;
		}
		fclose(pFile);

		pFile=fopen(pathId,"r");
		parser_IdFromText(pFile,id);
		fclose(pFile);
	}
	return retorno;
}
int controller_loadFromTextId(char* path ,int* id)
{
	int retorno;
	char buff[7];
	FILE* pFile;

	retorno=0;

	if(path!=NULL&&id!=NULL){
		pFile=fopen(path,"r");

		fgets(buff,6,pFile);
		*id=atoi(buff);

		fclose(pFile);
	}

	if(*id>0){
		retorno=1;
	}
	return retorno;
}
int controller_setID(char* path,int* id){
	int retorno;
	int aux;
	char buff[7];
	FILE* pFile;

	retorno=0;
	if(path!=NULL&&id!=NULL){
		GetIntRango(&aux, "ingrese el valor de ID que quiera setear: ", "ERROR", 1, 99999,99);

		pFile=fopen(path, "w");

		sprintf(buff,"%d",aux);
		fprintf(pFile,"%s",buff);

		fclose(pFile);

		*id=aux;
	}
	if(*id==aux){
		retorno=1;
	}
	return retorno;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* pathEmpleado , LinkedList* pArrayListEmployee,char* pathId,int* id)
{
	int retorno;
	int len;
	FILE* pFile;
	retorno=0;

	if(pathEmpleado!=NULL&&pArrayListEmployee!=NULL&&pathId!=NULL&&id!=NULL){
		pFile=fopen(pathEmpleado,"rb");

		while(!feof(pFile)){
			if(parser_EmployeeFromBinary(pFile,pArrayListEmployee)){
				retorno=1;
			}
		}

		fclose(pFile);

		//CONSULTAR- REMUEVO EL ULTIMO POR QUE SE CREA UN EMPLEADO EXTRA NULLEADO
		len=ll_len(pArrayListEmployee);
		ll_remove(pArrayListEmployee, len-1);

		pFile=fopen(pathId,"rb");//TAMBIEN CARGO EL ID GUARDADO EN EL ARCHIVO idEmpleado.bin
		fread(&id,sizeof(int),1,pFile);
		fclose(pFile);
	}
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id)
{
	int retorno;
	Employee aux;
	Employee* empleado;
	retorno=0;

	if(pArrayListEmployee!=NULL&&id!=NULL){
		Employee_PedirDatos(&aux,id);
		empleado=employee_newParametrosPorAux(aux);
		ll_add(pArrayListEmployee, empleado);
		retorno=1;
		*id=*id+1;
	}
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int optionModification;
	Employee* empleado;
	Employee aux;

	retorno=0;

	if(pArrayListEmployee!=NULL){
		empleado=employee_GetEmpleado(pArrayListEmployee);
		do{
			MenuModificacion(&optionModification);
			switch(optionModification){
				case 1://Modificar Nombre del Empleado
					GetCharNombre(aux.nombre, 128, "Ingrese el nuevo nombre: ", "ERROR\n", 99);
					if(employee_setNombre(empleado, aux.nombre)){
						retorno=1;
					}
					else{
						retorno=0;
					}
					break;
				case 2://Modificar Horas Trabajadas del Empleado
					GetIntRango(&aux.horasTrabajadas, "Ingrese las horas trabajadas: ","ERROR!\n",10, 400, 99);
					if(employee_setHorasTrabajadas(empleado, aux.horasTrabajadas)){
						retorno=1;
					}
					else{
						retorno=0;
					}
					break;
				case 3://Modificar Sueldo del Empleado
					GetIntRango(&aux.sueldo, "Ingrese el nuevo sueldo: ","ERROR\n", 10000, 100000, 99);
					if(employee_setSueldo(empleado,aux.sueldo)){
						retorno=1;
					}
					else{
						retorno=0;
					}
					break;
			}
		}while(optionModification!=4);
	}
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int index;
	Employee* empleado;

	retorno=0;

	if(pArrayListEmployee!=NULL){
		empleado=employee_GetEmpleado(pArrayListEmployee);
		index=ll_indexOf(pArrayListEmployee, empleado);
		ll_remove(pArrayListEmployee, index);
		retorno=1;
	}
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;

	retorno=0;
	if(pArrayListEmployee!=NULL){
		if(Employee_MostrarEmpleados(pArrayListEmployee)){
			retorno=1;
		}
	}

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int opcion;
	int opcionOrden;
	LinkedList* pAux;

	retorno=0;

	if(pArrayListEmployee!=NULL){
		pAux=ll_clone(pArrayListEmployee);

		do{
			MenuInformes(&opcion);
			if(opcion!=4){
				MenuOrden(&opcionOrden);
			}
			switch(opcion){
				case 1://ORDENAR POR NOMBRE
					ll_sort(pAux, Employee_CompararNombre, opcionOrden);
					break;
				case 2://ORDENAR POR HORAS TRABAJADAS
					ll_sort(pAux, Employee_CompararHorasTrabajadas, opcionOrden);
					break;
				case 3://ORDENAR POR SUELDO
					ll_sort(pAux, Employee_CompararSueldo, opcionOrden);
					break;
				case 4://Salir
					break;
			}
			if(Employee_MostrarEmpleados(pAux)){//MUESTRO EMPLEADOS DE LA LISTA CLON
				retorno=1;
			}
		}while(opcion!=4);
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee,char* pathId,int id)
{
	int retorno;
	int len;
	FILE* pFile;
	Employee* empleado;
	retorno=0;

	if(path!=NULL&&pArrayListEmployee!=NULL&&pathId!=NULL){
		len=ll_len(pArrayListEmployee);

		pFile=fopen(path,"w");
		fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");

		for(int i=0;i<len;i++){
			empleado=(Employee*)ll_get(pArrayListEmployee, i);
			fprintf(pFile,"%d,%s,%d,%d\n",empleado->id,empleado->nombre
					,empleado->horasTrabajadas,empleado->sueldo);
			retorno=1;
		}

		fclose(pFile);

		pFile=fopen(pathId,"w");//GUARDO EL ID

		fprintf(pFile,"%d",id);

		fclose(pFile);
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee,char* pathId,int id)
{
	int retorno;
	int len;
	FILE* pFile;
	Employee* empleado;
	retorno=0;

	if(path!=NULL&&pArrayListEmployee!=NULL&&pathId!=NULL){
		len=ll_len(pArrayListEmployee);

		pFile=fopen(path,"wb");

		for(int i=0;i<len;i++){
			empleado=(Employee*)ll_get(pArrayListEmployee, i);
			fwrite(empleado,sizeof(Employee),1,pFile);
			retorno=1;
		}

		fflush(pFile);
		fclose(pFile);

		pFile=fopen(pathId,"wb");

		fwrite(&id,sizeof(int),1,pFile);

		fflush(pFile);
		fclose(pFile);
	}
    return retorno;
}

