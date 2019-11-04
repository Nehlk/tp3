#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"





/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
        FILE* archivoDatos;

        system("cls");

    if ( (archivoDatos = fopen(path,"r") ) != NULL ) // Si la carga de archivos es diferente a NULL, abre..
    {
        archivoDatos = fopen(path, "r");

        parser_EmployeeFromText(archivoDatos, pArrayListEmployee);

        printf("\n\n Carga OK.");

    }else{
        printf("\n\nNo se pudo realizar la carga.");
    }



    fclose(archivoDatos);

    return 0;
}











/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
        FILE* datosBinario;

        system("cls");

    if ( (datosBinario = fopen(path,"rb") ) != NULL ) // Si la carga de archivos es diferente a NULL, abre..
    {
        datosBinario = fopen(path, "rb");

        parser_EmployeeFromBinary(datosBinario, pArrayListEmployee);

        printf("\n\n Carga OK.");

    }else{
        printf("\n\nNo se pudo realizar la carga.");
    }



  //  fclose(archivoDatos);

    return 0;
}





/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int hsTrabajadas;
    int salario;
    char name[31];

    Employee* auxiliarEmpleado = employee_new();

    system("cls");

    printf("\n ********* Ingreso de datos de Nuevo Empleado *********");
    printf("\n\nDigite Nombre: ");
    fflush(stdin);
    scanf("%s", name);

    employee_setNombre(auxiliarEmpleado, name);

    printf("\n\nDigite ID: ");
    fflush(stdin);
    scanf("%i", &id);

    employee_setId(auxiliarEmpleado, id);

    printf("\n\nDigite Sueldo: ");
    fflush(stdin);
    scanf("%i", &salario);

    employee_setSueldo(auxiliarEmpleado, salario);

    printf("\n\nDigite Horas Trabajadas: ");

    fflush(stdin);
    scanf("%i", &hsTrabajadas);



    employee_setHorasTrabajadas(auxiliarEmpleado, hsTrabajadas);

    ll_add(pArrayListEmployee, auxiliarEmpleado);

    printf("\n\nEmpleado agregado");

    return 1;
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

    int listLenght = ll_len(pArrayListEmployee);
    int idEmpleado;
    int a; //variable recorrido For().


    Employee* auxEmpleado; // = employee_new();

    system("cls");
    printf("\n\nIngrese el ID del Empleado a modificar: ");
    scanf("%i", &idEmpleado);

    auxEmpleado = ll_get(pArrayListEmployee, idEmpleado - 1);

    for(a = 0; a <= listLenght; a++)
    {
        if((auxEmpleado)->id == a)
        {

            printf("\n\n %d, %d", (auxEmpleado)->id, a );

            printf("\n\nDigite Nombre: ");
            scanf("%s", (auxEmpleado)->nombre);

            printf("\nDigite Sueldo: ");
            scanf("%i", &(auxEmpleado)->sueldo);

            printf("\nDigite Horas Trabajadas: ");
            scanf("%i", &(auxEmpleado)->horasTrabajadas);

        }
    }


    return 1;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int listLenght = ll_len(pArrayListEmployee);
    int idEmpleado;
    int a; //variable recorrido For().
    char opcion;

    Employee* auxEmpleado;

    system("cls");
    printf("\n\nIngrese el ID del Empleado a Eliminar: ");
    scanf("%i", &idEmpleado);

    auxEmpleado = ll_get(pArrayListEmployee, idEmpleado - 1);

    for(a = 0; a <= listLenght; a++)
    {
        if((auxEmpleado)->id == a)
        {

            do{
                printf("\n\nEsta seguro que desea Eliminar el Empleado? s/n->  ");
                opcion = toupper(getch());

                if(opcion == 'S')
                {
                    ll_remove(pArrayListEmployee, idEmpleado-1);
                    printf("\n\nEl Empleado %s, cuyo Id: %i. Se ha Eliminado Correctamente.", (*auxEmpleado).nombre, (*auxEmpleado).id);
                }
                else if(opcion == 'N')
                {
                    break;
                }

        }while(opcion != 'S' && opcion != 'N');
    }


    }
    return 1;
}


/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int a;
    int lenght;

    Employee* auxEmpleado = employee_new();

    lenght = ll_len(pArrayListEmployee);

    system("cls");

    printf("\n\nID - Nombre - Salario - HorasTrabajadas\n");




    for(a = 0; a < lenght; a++)
    {
        auxEmpleado = ll_get(pArrayListEmployee, a);

        if((auxEmpleado)->id > 0)
        {
            printf("\n%i - %s - %i - %i", (auxEmpleado)->id, (auxEmpleado)->nombre, (auxEmpleado)->sueldo, (auxEmpleado)->horasTrabajadas);
        }

    }


    return 0;
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
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

