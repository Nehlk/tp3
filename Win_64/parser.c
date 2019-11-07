#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos  de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{

    Employee* auxEmpleado;
    Employee empl;

    char id[50];
    char nombre[50];
    char hTrabajadas[50];
    char salario[50];

    int fullDato;

    fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", id, nombre, hTrabajadas, salario);

    do{
        fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", id, nombre, hTrabajadas, salario);


        auxEmpleado = employee_newParametros(id, nombre, hTrabajadas, salario);

        ll_add(pArrayListEmployee, auxEmpleado);

    }while(!feof(pFile));


    return 0;
}






/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    Employee* auxEmpleado;
    Employee empleado;


    do{
        auxEmpleado = employee_newParametrosBinary(empleado);

        fread(&empleado, sizeof(Employee), 1, pFile);

        ll_add(pArrayListEmployee, auxEmpleado);


    }while(!feof(pFile));

    return 0;

}
