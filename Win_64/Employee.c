#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"


/**\brief Asigna a la variable this una direccion de memoria.
 *
 * \param void
 * \return this
 *
 */
Employee* employee_new()
{
    Employee* this = malloc(sizeof(Employee));

    return this;
}




/**\brief Asigna el ID en la variable this de Employee.
 *
 * \param this Employee* empleado
 * \param int* horasTrabajadas
 * \return int 0.
 *
 */
int employee_setId(Employee* this, int id)
{
    this->id = id;

    return 0;
}


/** \brief Obtiene el ID de un empleado.
 *
 * \param this Employee* empleado
 * \param int* horasTrabajadas
 * \return int 0.
 *
 */
int employee_getId(Employee* this, int* id)
{

    *id = this->id;

    return 0;
}




/**\brief Asigna el sueldo en la variable this de Employee.
 *
 * \param this Employee* empleado
 * \param int* horasTrabajadas
 * \return int 0.
 *
 */
int employee_setSueldo(Employee* this, int sueldo)
{

    this->sueldo = sueldo;

    return 0;
}


/**\brief Obtiene el sueldo de un Empleado.
 *
 * \param this Employee* empleado
 * \param int* horasTrabajadas
 * \return int 0.
 *
 */
int employee_getSueldo(Employee* this, int* sueldo)
{
    *sueldo = this->sueldo;

    return 0;
}







/**\brief Asigna las horas trabajadas en la variable del Employee pasado por parametro.
 *
 * \param this Employee* empleado
 * \param int* horasTrabajadas
 * \return int 0.
 *
 */
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{

    this->horasTrabajadas = horasTrabajadas;

    return 0;
}





/**\brief Obtiene las hyoras trabajadas de un Empleado.
 *
 * \param this Employee* empleado
 * \param int* horasTrabajadas
 * \return int 0.
 *
 */
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{

    *horasTrabajadas = this->horasTrabajadas;

    return 0;
}





/**\brief Asigna el nombre en la variable del Employee pasado por parametro.
 *
 * \param this Employee* empleado
 * \param int* horasTrabajadas
 * \return int 0.
 *
 */
int employee_setNombre(Employee* this, char* nombre)
{

    strcpy(this->nombre, nombre);


    return 0;
}


/**\brief Obtiene el nombre en la variable del Employee pasado por parametro.
 *
 * \param this Employee* empleado
 * \param char* nombre cadena de caracteres
 * \return int 0.
 *
 */
int employee_getNombre(Employee* this, char* nombre)
{

    nombre = this->nombre;

    return 0;
}





/**\brief Retorna un Employee* con todos los campos asignados en el argumento de la funcion (Modo Texto).
 *
 * \param char* idStr: numero formato string
 * \param char* nombrestr cadena de caracteres
 * \param char* horasTrabajadasStr numero formato string
 * \param char* salaryStr numero formato string
 * \return auxEmpleado.
 *
 */
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* salaryStr)
{

     int id, sueldo, horasTrabajadas;

     Employee* auxEmpleado;


     id = atoi(idStr);
     sueldo = atoi(salaryStr);
     horasTrabajadas = atoi(horasTrabajadasStr);

     auxEmpleado = employee_new();

     employee_setId(auxEmpleado, id);
     employee_setNombre(auxEmpleado, nombreStr);
     employee_setSueldo(auxEmpleado, sueldo);
     employee_setHorasTrabajadas(auxEmpleado, horasTrabajadas);




    return auxEmpleado;
}


/**\brief Retorna un Employee* con todos los campos asignados en su argumento de la funcion (Modo BInario).
 *
 * \param int id: numero int
 * \param char* nombrestr cadena de caracteres
 * \param int horasTrabajadas: numero int
 * \param int salario: numero int
 * \return auxEmpleado.
 *
 */
Employee* employee_newParametrosBinary(int id, char* nombreStr, int horasTrabajadas, int salario)
{

     Employee* auxEmpleado;

     auxEmpleado = employee_new();

     employee_setId(auxEmpleado, id);
     employee_setNombre(auxEmpleado, nombreStr);
     employee_setSueldo(auxEmpleado, salario);
     employee_setHorasTrabajadas(auxEmpleado, horasTrabajadas);


     return auxEmpleado;

}
