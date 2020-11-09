#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

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

int menu();

int main()
{
    int rta;
    char seguir = 's';
    char confirma;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        switch(menu())
        {
            case 1:
                if(!controller_loadFromText("data.csv",listaEmpleados))
                {
                    printf("Problema al cargar los empleados");
                }
                else
                {
                    printf("Empleados cargados correctamente");
                }
                break;

            case 2:
                if(controller_loadFromBinary("data.csv",listaEmpleados))
                {
                    printf("Problema al cargar los empleados");
                }
                else
                {
                    printf("Empleados cargados correctamente");
                }
                break;

            case 3:
                if(!controller_addEmployee(listaEmpleados))
                {
                    printf("alta exitosa\n\n");
                }
                else
                {
                    printf("problemas con el alta\n\n");
                }
                break;

            case 4:
                rta = controller_editEmployee(listaEmpleados);

                if( rta == 0)
                {
                    printf("modificacion exitosa\n\n");
                }
                else if(rta ==2)
                {
                    printf("modificacion cancelada\n\n");
                }
                else
                {
                    printf("se a producido un error en la modificacion\n\n");
                }
                break;

            case 5:
                rta = controller_removeEmployee(listaEmpleados);

                if( rta == 0)
                {
                    printf("baja exitosa\n\n");
                }
                else if(rta ==2)
                {
                    printf("baja cancelada\n\n");
                }
                else
                {
                    printf("se a producido un error en la baja\n\n");
                }
                break;

            case 6:
                system("cls");
                if(!controller_ListEmployee(listaEmpleados))
                {
                printf("Problema al cargar los empleados");
                }
                else
                {
                    printf("Empleados cargados correctamente");
                }
                break;

            case 7:
                if(!controller_sortEmployee(listaEmpleados))
                {
                    printf("\n problema al ordenar personas\n\n");
                }
                else
                {
                    printf("\n personas ordenadas con exito\n\n");
                }
                break;

            case 8:
                controller_saveAsText("data.csv",listaEmpleados);
                break;

            case 9:
                controller_saveAsBinary("data.csv",listaEmpleados);
                break;

            case 10:
                printf("Confirma salida?: ");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma = tolower(confirma);
                if(confirma == 's')
                {
                    seguir = 'n';
                }

            default:
            printf("Opcion invalida!!!\n");
        }
        system("pause");
    }while(seguir == 's');
    return 0;
}

int menu()
{
    int opcion;
    system("cls");

    printf("*** Menu ***\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10 Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}
