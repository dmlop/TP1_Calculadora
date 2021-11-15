int controller_loadFromText(char* pathEmpleado , LinkedList* pArrayListEmployee,char* pathId,int* id);
int controller_loadFromTextId(char* path ,int* id);
int controller_loadFromBinary(char* pathEmpleado , LinkedList* pArrayListEmployee,char* pathId,int* id);
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee,char* pathId,int id);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee,char* pathId,int id);
int controller_setID(char* path,int* id);



