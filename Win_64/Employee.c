


/** \brief Asigna a la variable this una direccion de memoria.
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


int employee_getId(Employee* this, int* id)
{

    *id = this->id;

    return 0;
}




Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* salaryStr)
{

    int id, sueldo, horasTrabajadas;

    id = atoi(idStr);
    sueldo = atoi(salaryStr);
    horasTrabajadas = atoi(horasTrabajadasStr);


}
