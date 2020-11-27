#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[20];
    float sueldo;
} Employee;

int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    if(this!=NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk= 1;
    }
    return todoOk;
}

int employeeSortByName(void* empleadoA, void* empleadoB)
{
    int retorno = 0;
    char nombresA[20];
    char nombresB[20];

    if(employee_getNombre((Employee*)empleadoA, nombresA) &&
        employee_getNombre((Employee*)empleadoB, nombresB))
    {
        retorno = strcmp(nombresA, nombresB);
    }

    return retorno;
}


//ll_len
//ll_get
void printList(LinkedList* lista)
{
    Employee* auxEmp;
    int len = ll_len(lista);

    for(int i=0; i<len; i++)
    {
        auxEmp= (Employee*) ll_get(lista, i);
        printf("%d %s %.2f\n", auxEmp->id, auxEmp->nombre, auxEmp->sueldo);
    }
}

int menu()
{
    int opcion;
    system("cls");

    printf("*** Menu ***\n\n");
    printf("1. listar los empleados\n");
    printf("2. cambiar nombre de empleado\n");
    printf("3. remover empleado\n");
    printf("4. borrar toda la lista\n");
    printf("5. buscar salario por nombre\n");
    printf("6. checkear si la lista esta vacia\n");
    printf("7. agregar nuevo emp a posicion indicada\n");
    printf("8. modificar elemento por id\n");
    printf("9. fijarse si el primer empleado de la lista2 esta en la primera lista\n");
    printf("10. fijarse si todos los empleados de la lista2 estan en la primera lista\n");
    printf("11. crear una tercera lista con elemento indicados\n");
    printf("12. ordenar por nombre\n");
    printf("13. crear lista copia\n");
    printf("14 Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

int main()
{
    char seguir = 's';
    int idAux=0;
    int newId=0;
    int i=0;
    float auxSueldo =0;
    int primerElement=0;
    int ultimoElement=0;

    char confirma = 's';
    char confirmaBorrar = 's';
    Employee* auxEmp;
    Employee auxEmpleado;
    char auxNombre [20];

    //ll_newLinkedList DONE
    LinkedList* lista = ll_newLinkedList();
    LinkedList* lista2 = ll_newLinkedList();
    LinkedList* lista3;
    LinkedList* newList;

    Employee emp1 = {1, "juan", 72000};
    Employee emp2 = {2, "juana", 12300};
    Employee emp3 = {3, "emilia", 31000};
    Employee emp4 = {4, "juanito", 22000};
    Employee emp5 = {5, "martin", 54000};
    Employee emp6 = {6, "emilia", 60000};
    Employee emp7 = {7, "pedro", 12500};
    Employee emp8 = {8, "martina", 12500};

    ll_add(lista, &emp1);
    ll_add(lista, &emp2);
    ll_add(lista, &emp3);
    ll_add(lista, &emp4);
    ll_add(lista, &emp5);
    ll_add(lista, &emp6);
    ll_add(lista, &emp7);
    ll_add(lista, &emp8);

    Employee e1 = {1, "juan", 72000};
    Employee e2 = {2, "juana", 12300};

    ll_add(lista2, &e1);
    ll_add(lista2, &e2);

    do
    {
        switch(menu())
        {
        case 1:
            system("cls");
            printList(lista);
            break;

        case 2:
            system("cls");
            printList(lista);

            fflush(stdin);
            idAux = getInt("ingrese id del usuario a cambiar");

            if(idAux>0 && idAux<=ll_len(lista))
            {
                auxEmp= (Employee*) ll_get(lista, idAux);
                if(getStringLetras("ingrese nuevo nombre", auxNombre))
                {
                    printf("nombre invalido\n");
                }
                else
                {
                    ll_set(lista,auxEmp->id,auxNombre); // ll_set
                }
            }
            else
            {
                printf("id invalido\n");
            }
            break;

        case 3:
            system("cls");
            printList(lista);
            idAux = getInt("ingrese id del usuario a borrar");

            if(idAux>0 && idAux<=ll_len(lista))
            {
                auxEmp= (Employee*) ll_get(lista, idAux);

                if(auxEmp!=NULL)
                {
                    ll_remove(lista,idAux);
                    printf("usuario borrado\n");
                }
                else
                {
                    printf("error al borrar\n");
                }
            }
            break;

        case 4:
            system("cls");
            printList(lista);
            printf("Confirma borrado?: ");
            fflush(stdin);
            scanf("%c", &confirmaBorrar);
            confirmaBorrar = tolower(confirmaBorrar);
            if(confirmaBorrar == 's')
            {
                ll_clear(lista);
                printf("lista borrada\n");
            }
            break;

        case 5:
            system("cls");

            printList(lista);
            if(getStringLetras("ingrese nombre", auxNombre))
            {
                printf("nombre invalido\n");
            }
            else
            {
                i=ll_indexOf(lista, auxNombre); // ll_indexOf
                auxEmp= (Employee*) ll_get(lista, i);
                printf("el salario es %.2f",auxEmp->sueldo);
            }
            break;

        case 6:
            system("cls");
            if(ll_isEmpty(lista)==0)
            {
                printf("lista no esta vacia\n");
            }
            else if(ll_isEmpty(lista)==1)
            {
                printf("lista esta vacia\n");
            }
            else
            {
                printf("Error al checkear la lista\n");
            }
            break;

        case 7:
            newId = ll_len(lista)+1;
            int posicion=0;
            posicion = getInt("\n ingrese posicion");
            getStringLetras("\n ingrese nuevo nombre", auxNombre);
            auxSueldo = getFloat("\n ingrese nuevo sueldo");

            auxEmpleado.id=newId;
            strcpy(auxEmpleado.nombre, auxNombre);
            auxEmpleado.sueldo=auxSueldo;

            if(!ll_push(lista, posicion, &auxEmpleado)) // ll_push
            {
                printf("Empleado agregado correctamente\n");
            }
            else
            {
                printf("Error agregar empleado\n");
            }
            break;

        case 8:

            system("cls");
            printList(lista);
            idAux = getInt("ingrese id del usuario a modificar\n");

            if(idAux>0 && idAux<=ll_len(lista))
            {
                auxEmp= (Employee*) ll_get(lista, idAux);

                if(auxEmp!=NULL)
                {
                    auxEmp=ll_pop(lista, idAux);
                    getStringLetras("\n ingrese nuevo nombre", auxNombre);
                    auxSueldo = getFloat("\n ingrese nuevo sueldo");

                    auxEmp->id=idAux;
                    strcpy(auxEmp->nombre, auxNombre);
                    auxEmp->sueldo=auxSueldo;
                    printf("usuario modificado\n");
                }
                else
                {
                    printf("error al modificar\n");
                }
            }

            break;

        case 9:
            if(ll_contains(lista, e1.nombre)==1)
            {
                printf("\n si contiene el primer elemento\n");
            }
            else if(ll_contains(lista, e1.nombre)==0)
            {
                printf("\n NO contiene el primer elemento\n");
            }
            else
            {
                printf("\n error al leer las listas\n");
            }
            break;

        case 10:
            if(ll_containsAll(lista, lista2))
            {
                printf("todos los elementos de la lista2 estan en la primera lista\n");
            }
            else if(!ll_containsAll(lista, lista2))
            {
                printf("los elementos de la lista2 NO estan en la primera lista\n");
            }
            else
            {
                printf("error\n");
            }
            break;

        case 11:
            primerElement=getInt("ingresar el primer elemento\n");
            ultimoElement=getInt("ingresar el ultimo elemento\n");
            if(primerElement>0 && ultimoElement>ll_len(lista))
            {
                lista3 = ll_subList(lista, primerElement, ultimoElement);
                printList(lista3);
            }
            else
            {
                printf("erro al crear nueva lista\n");
            }

            break;

        case 12:
            if(!ll_sort(lista, employeeSortByName, 1))
            {
                printf("se a logrado el ordenado\n");
            }
            else
            {
                printf("Error al ordenar\n");
            }
            break;

        case 13:
            newList = ll_clone(lista);
            if(newList!=NULL)
            {
                printf("se a logrado la creacion de la nueva lista\n");
            }
            else
            {
                printf("Error al crear la nueva lista\n");
            }
            break;

        case 14:
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("Opcion invalida!!!\n");
            break;
        }
        system("pause");
    }while(seguir=='s');

    //ll_len DONE

    // ll_add DONE

    // ll_get DONE

    // ll_set DONE

    // ll_remove DONE

    // ll_clear DONE

    // ll_indexOf DONE

    // ll_isEmpty DONE

    // ll_push DONE

    // ll_pop DONE

    // ll_contains

    // ll_containsAll DONE

    // ll_subList DONE

    // ll_clone  DONE

    // ll_sort DONE

    // ll_deleteLinkedList DONE
    ll_deleteLinkedList(lista);
}
