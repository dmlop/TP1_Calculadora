#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int optionMenu;
    int id;
    LinkedList* listaEmpleados = ll_newLinkedList();
    id=0;

    do{
    	Menu(&optionMenu);
        switch(optionMenu)
        {
        	case 0://set ID
    			system("cls");
        		if(controller_setID("idEmpleado.csv", &id)){
        			printf("ID SETEADO A: %d\n",id);
        		}
        		else{
        			printf("AH OCURRIDO UN ERROR!\n");
        		}
        		break;
            case 1://Cargar los datos de los empleados desde el archivo data.csv (modo texto).
    			system("cls");
    			if(ll_len(listaEmpleados)>0){
    				printf("UN ARCHIVO YA ESTA CARGADO\n");
    				break;
    			}
                if(controller_loadFromText("data.csv",listaEmpleados,"idEmpleado.csv",&id)){
                	printf("LOS DATOS DESDE TEXTO SE CARGARON CON EXITO!\n");
                }
                else{
                	printf("AH OCURRIDO UN ERROR!\n");
                }
                break;
            case 2://Cargar los datos de los empleados desde el archivo data.csv (modo binario).
    			system("cls");
    			if(ll_len(listaEmpleados)>0){
    				printf("UN ARCHIVO YA ESTA CARGADO\n");
    				break;
    			}
            	if(controller_loadFromBinary("data.bin" , listaEmpleados,"idEmpleado.bin",&id)){
                	printf("LOS DATOS DESDE BINARIO SE CARGARON CON EXITO!\n");
            	}
            	else{
            		printf("AH OCURRIDO UN ERROR!\n");
            	}
            	break;
            case 3://Alta de empleado
    			system("cls");
    			if(ll_len(listaEmpleados)==0){
    				printf("CUIDADO! NO SE CARGO NINGUN ARCHIVO PREVIAMENTE RIESGO DE PERDER DATOS!\n");
    			}
            	if(controller_addEmployee(listaEmpleados, &id)){
            		printf("SE DIO DE ALTA EL EMPLEADO\n");
            	}
            	else{
            		printf("AH OCURRIDO UN ERROR!\n");
            	}
            	break;
            case 4://Modificar datos de empleado
    			system("cls");

              	if(controller_editEmployee(listaEmpleados)){
              		printf("LA MODIFICACION FUE UN EXITO\n");
              	}
              	else{
              		printf("AH OCURRIDO UN ERROR!\n");
              	}
            	break;
            case 5://Baja de empleado
    			system("cls");
    			if(ll_len(listaEmpleados)==0){
    				printf("NO HAY EMPLEADOS CARGADOS!\n");
    				break;
    			}
            	if(controller_removeEmployee(listaEmpleados)){
            		printf("SE DIO DE BAJA UN EMPLEADO\n");
            	}
            	else{
            		printf("AH OCURRIDO UN ERROR!\n");
            	}
            	break;
            case 6://Listar empleados
    			system("cls");
    			if(ll_len(listaEmpleados)==0){
    				printf("NO HAY EMPLEADOS CARGADOS!\n");
    				break;
    			}
            	if(controller_ListEmployee(listaEmpleados)){
            		printf("SE MOSTRO LA LISTA DE EMPLEADOS\n");
            	}
            	else{
            		printf("AH OCURRIDO UN ERROR!\n");
            	}
            	break;
            case 7://Ordenar empleados
    			system("cls");
    			if(ll_len(listaEmpleados)==0){
    				printf("NO HAY EMPLEADOS CARGADOS!\n");
    				break;
    			}
            	if(controller_sortEmployee(listaEmpleados)){
            		printf("SE MOSTRO LA LISTA DE EMPLEADOS ORDENADOS\n");
            	}
            	else{
            		printf("AH OCURRIDO UN ERROR!\n");
            	}
            	break;
            case 8://Guardar los datos de los empleados en el archivo data.csv (modo texto).
    			system("cls");
    			if(ll_len(listaEmpleados)==0){
    				printf("NO HAY EMPLEADOS CARGADOS!\n");
    				break;
    			}
            	if(controller_saveAsText("data.csv",listaEmpleados,"idEmpleado.csv",id)){
            		printf("SE GUARDARON LOS DATOS EN TEXTO CON EXITO!\n");
            	}
            	else{
            		printf("AH OCURRIDO UN ERROR!\n");
            	}
            	break;
            case 9://Guardar los datos de los empleados en el archivo data.csv (modo binario).
    			system("cls");
    			if(ll_len(listaEmpleados)==0){
    				printf("NO HAY EMPLEADOS CARGADOS!\n");
    				break;
    			}
            	if(controller_saveAsBinary("data.bin" ,listaEmpleados,"idEmpleado.bin",id)){
            		printf("SE GUARDARON LOS DATOS EN BINARIO CON EXITO!\n");
            	}
            	else{
            		printf("AH OCURRIDO UN ERROR!\n");
            	}
            	break;
            case 10://SALIR
    			system("cls");
            	Firma();
            	break;
       }
    }while(optionMenu != 10);
    return 0;
}

