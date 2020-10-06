#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include"ArrayEmployees.h"
#include "biblioteca.h"

#define LEN 1000

int menu();
/*int menuModificacion();*/

int main()
{
    char seguirModificar;
    int indice;
    int rta;
    int eleccionInformar;

    int idBaja;
    int nextId = 1000;
    Employee lista[LEN];
    char seguir = 's';

    if(initEmployees(lista, LEN)==0)
    {
        printf("empleados inicializados con exito\n");
    }
    else
    {
        printf("error al inicializar\n");
    }

    do
    {
        char newName[51];
        char newLastName[51];
        float newSalary;
        int newSector;
        int findId = NULL;
        switch(menu())
        {

        case 1:
            getStringLetras("ingrese nombre: ", newName);

            getStringLetras("ingrese apellido: ", newLastName);

            newSalary = getFloat("ingrese salario: ");

            newSector = getInt("ingrese sector: ");


            if(addEmployee(lista, LEN, nextId, newName, newLastName, newSalary, newSector)==0)
            {
                nextId++;
                printf("alta exitosa\n\n");
            }
            else
            {
                printf("problemas con el alta\n\n");
            }
            break;

        break;

        case 2:
            rta=modifyEmployee(lista, LEN);
            if(rta==1)
            {
                printf("se a realizado la modificacion");
            }
            if(rta==2)
            {
                printf("se a cancelado la modificacion");
            }
            else
            {
                printf("error durante modificacion...");
            }
        break;

        case 3:
            system("cls");
            printf("ingrese el id: ");
            scanf("&d", &idBaja);

            removeEmployee(lista, LEN, idBaja);
        break;

        case 4:

            printf("informar\n");
            printf("1 - Listado de los empleados ordenados alfabéticamente por Apellido y Sector ASCENDENTE\n");
            printf("2 - Listado de los empleados ordenados alfabéticamente por Apellido y Sector DESCENDENTE\n");
            printf("3 - Total y promedio de los salarios, y cuántos empleados superan el salario promedio\n");

            eleccionInformar = getInt("ingrese eleccion");

            switch(eleccionInformar)
            {
            case 1:
                sortEmployees(lista, LEN, 1);
                printEmployees(lista, LEN);
                break;

            case 2:
                sortEmployees(lista, LEN, 2);
                printEmployees(lista, LEN);
                break;
            }

        break;

        }

        system("pause");

    }
    while( seguir == 's');

    return 0;
}

int menu()
{
    int opcion;
    system("cls");

    printf("1 ALTAS\n");
    printf("2 MODIFICAR\n");
    printf("3 BAJA\n");
    printf("4 INFORMAR\n");
    printf("5 SALIR\n");
    fflush(stdin);
    opcion = getInt("Ingrese opcion: ");

    return opcion;
}


