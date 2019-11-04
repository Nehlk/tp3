#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct S_Persona
{
    int id;
    char nombre[32];
    char apellido[32];
    int edad;
};

typedef struct S_Persona Persona;

int parseData(char* fileName, Persona* arrayPersonas, int len);





int main(void){







    Persona personas[10];
    int r,i;

    r = parseData("datos.csv", personas, 12);

    for(i=0; i<r; i++)
        printf("id:%d nombre:%s apellido:%s edad:%d\n", personas[i].id, personas[i].nombre, personas[i].apellido, personas[i].edad);

    exit(EXIT_SUCCESS);
}







int parseData(char* fileName,Persona* arrayPersonas, int len)
{
    FILE *archivo;

    archivo = fopen("test.csv", "w+");


    FILE *pFile;
    int r, i = 0;
    char var1[50], var3[50], var2[50], var4[50];

    pFile = fopen( fileName, "r");

    if(archivo == NULL)
    {
        return -1;
    }


    if(pFile == NULL){
        return -1;
    }


            //Esto es para evitar que imprima la 1ra linea
    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", var1, var2, var3, var4);
    fprintf(archivo, "Id - Nombre - Apellido - Edad\n\n");   //Para poner el titulo al texto sin que lo imprima X veces

    do{                 // ^ significa q lea todo hasta llegar a la coma / y lee todo menos el \n y se le pone \n al final para que salte de linea


        r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", var1, var2, var3, var4); //FscanF toma el dato desde un archivo en lugar de teclado. y los guarda en las variables declaradas arriba


        if(r == 4) // devuelve las veces que leyo fscanf y las compara con 4
        {
            fprintf(archivo, "%s - %s - %s - %s\n", var1, var2, var3, var4); //Copia el contenido a otro archivo, o remplaza en el mismo cuidado

            arrayPersonas[i].id = atoi(var1);
            strncpy( arrayPersonas[i].nombre, var2, sizeof( arrayPersonas[i].nombre) );
            strncpy( arrayPersonas[i].apellido, var3, sizeof( arrayPersonas[i].apellido) );
            arrayPersonas[i].edad = atoi(var4);

            i++;
        }
            else{
               break;
            }

    }while(!feof(pFile) && i<len);

    fclose(pFile);
    fclose(archivo);

    return i;
}
