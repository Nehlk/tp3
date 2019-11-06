#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"


int ordenamientoId(void* pEmployeeA, void* pEmployeeB);


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* archivoDatos;

    system("cls");

    if ( (archivoDatos = fopen(path,"r") ) != NULL ) // Si la carga de archivos es diferente a NULL, abre..
    {
        archivoDatos = fopen(path, "r");

        parser_EmployeeFromText(archivoDatos, pArrayListEmployee);

        printf("\n\n Carga OK.");

    }
    else
    {
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
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* datosBinario;

    system("cls");

    if ( (datosBinario = fopen(path,"rb") ) != NULL ) // Si la carga de archivos es diferente a NULL, abre..
    {
        datosBinario = fopen(path, "rb");

        parser_EmployeeFromBinary(datosBinario, pArrayListEmployee);

        printf("\n\n Carga OK.");

    }
    else
    {
        printf("\n\nNo se pudo realizar la carga.");
    }



    //  fclose(archivoDatos);

    return 0;
}






int returnIdAvailable(LinkedList*  pArrayListEmployee)
{
    int a;
    int length = ll_len(pArrayListEmployee);
    int position = length + 1;

    Employee* empleado;
    Employee* auxEmpleado = employee_new();


    for(a = 1; a < length - 1 ; a++)
    {
        empleado = ll_get(pArrayListEmployee, a+1);
        auxEmpleado = ll_get(pArrayListEmployee, a);



        if(!( (auxEmpleado)->id+1 == (empleado)->id ))
        {
            position = (auxEmpleado)->id+1;
            break;
        }
        else
        {
            position = (empleado)->id+1;
        }



    }

    return position;
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

    printf("\nOrdenando la lista de Empleados por ID para el asignamiento de ID automatico...");

    ll_sort(pArrayListEmployee, ordenamientoId, 1);

    system("cls");

    printf("\nOrdenamiento Completado.\n");

    if(pArrayListEmployee != NULL)
    {


        printf("\n ********* Ingreso de datos de Nuevo Empleado *********");
        printf("\n\nIngrese Nombre: ");
        fflush(stdin);
        scanf("%s", name);

        employee_setNombre(auxiliarEmpleado, name);

        id = returnIdAvailable(pArrayListEmployee);

        employee_setId(auxiliarEmpleado, id);

        printf("\n\nDigite Sueldo: ");
        fflush(stdin);
        scanf("%i", &salario);

        //  salario = getInt("\n\nDigite Sueldo: ");

        employee_setSueldo(auxiliarEmpleado, salario);

        printf("\n\nDigite Horas Trabajadas: ");

        fflush(stdin);
        scanf("%i", &hsTrabajadas);



        employee_setHorasTrabajadas(auxiliarEmpleado, hsTrabajadas);


        ll_add(pArrayListEmployee, auxiliarEmpleado);
        ll_sort(pArrayListEmployee, ordenamientoId, 1);

        printf("\n\nEmpleado agregado con el ID:%d", id);

    }
    else
    {

        printf("\n\nAun no hay una lista cargada.");
    }

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


    Employee* auxEmpleado = employee_new();
    Employee* empleado;

    system("cls");
    printf("\n\nIngrese el ID del Empleado a modificar: ");
    scanf("%i", &idEmpleado);

    auxEmpleado = ll_get(pArrayListEmployee, idEmpleado - 1);

    for(a = 0; a <= listLenght; a++)
    {
        empleado = ll_get(pArrayListEmployee, a);

        if((auxEmpleado)->id == (empleado)->id)
        {

            printf("\n\n %d, %d", (auxEmpleado)->id, (empleado)->id );

            printf("\n\nDigite Nombre: ");
            scanf("%s", (auxEmpleado)->nombre);

            printf("\nDigite Sueldo: ");
            scanf("%i", &(auxEmpleado)->sueldo);

            printf("\nDigite Horas Trabajadas: ");
            scanf("%i", &(auxEmpleado)->horasTrabajadas);

            break;

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
    Employee* empleado;

    system("cls");
    printf("\n\nIngrese el ID del Empleado a Eliminar: ");
    scanf("%i", &idEmpleado);

    auxEmpleado = ll_get(pArrayListEmployee, idEmpleado - 1);

    for(a = 0; a <= listLenght; a++)
    {

        empleado = ll_get(pArrayListEmployee, a);

        if((auxEmpleado)->id == (*empleado).id)
        {

            do
            {
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

            }
            while(opcion != 'S' && opcion != 'N');
            break;
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



/** \brief Ordenamiento de Empleados por ID
 *
 * \param void* pEmployeeA
 * \param void* pEmployeeB
 * \return 0
 *
 */
int ordenamientoId(void* pEmployeeA, void* pEmployeeB)
{


    if(((Employee*)pEmployeeA)->id > ((Employee*)pEmployeeB)->id)
    {
        return 1;
    }
    if(((Employee*)pEmployeeA)->id < ((Employee*)pEmployeeB)->id)
    {
        return -1;
    }

    return 0;
}




/** \brief Ordenamiento de Empleados por Nombre
 *
 * \param void* pEmployeeA
 * \param void* pEmployeeB
 * \return 0
 *
 */
int ordenamientoNombre(void* pEmployeeA, void* pEmployeeB)
{


    if(  strcmpi(( (Employee*)pEmployeeA)->nombre, ((Employee*)pEmployeeB)->nombre) > 0)
    {
        return 1;
    }
    if(strcmpi(( (Employee*)pEmployeeA)->nombre, ((Employee*)pEmployeeB)->nombre) < 0)
    {
        return -1;
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
    system("cls");

    printf("\nEste Proceso podria tardar unos momentos.. ");


    ll_sort(pArrayListEmployee, ordenamientoNombre, 1);

    system("cls");

    printf("\nSe ha ordenado por Nombre Ascendente Correctamente.");



    return 1;
}






/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int length = ll_len(pArrayListEmployee);
    int a;

    char id[3] = "id";
    char nombre[7] = "nombre";
    char hsTrabajadas[18] = "horasTrabajadas";
    char sueldo[7] = "sueldo";


    Employee* auxEmployee;

    FILE* archivo;

    if ( (archivo = fopen(path,"w")) == NULL )
    {
        printf("No se pudo abrir el archivo");
        exit(1);
    }




    fprintf(archivo, "%s,%s,%s,%s\n", id, nombre, hsTrabajadas, sueldo);
    for(a = 1; a < length; a++)
    {

        auxEmployee = ll_get(pArrayListEmployee, a);
        fseek(archivo, 0L, SEEK_END);
        fprintf(archivo, "%i,%s,%i,%i\n", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);

    }

    fclose(archivo);

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int length = ll_len(pArrayListEmployee);
    int a;

    Employee* auxEmployee;

    FILE* archivo;

    if ( (archivo = fopen(path,"r+")) == NULL )       // si el archivo existe lo abre
    {
        if ((archivo = fopen(path,"w+")) == NULL )        //si no existe lo crea
        {
            printf("No se pudo abrir el archivo");
            exit(1);
        }
    }




    for(a = 1; a < length; a++)
    {

        auxEmployee = ll_get(pArrayListEmployee, a);
        fseek(archivo, 0L, SEEK_END);
        fwrite(auxEmployee, sizeof(Employee), 1, archivo);

    }

    fclose(archivo);

    return 1;
}

