

#ifndef PARSER_H_
#define PARSER_H_

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_IdFromText(FILE* pFile, int* id);

Employee* employee_GetEmpleado(LinkedList* pArrayListEmployee);
int Employee_MostrarEmpleados(LinkedList* pArrayListEmployee);

#endif /* PARSER_H_ */
