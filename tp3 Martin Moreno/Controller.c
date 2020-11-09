#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    FILE* pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");

        if(pFile != NULL)
        {
            if(!parser_EmployeeFromText(pFile, pArrayListEmployee))
            {
                todoOk = 1;
            }
            fclose(pFile);
        }
    }

    return todoOk;
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
    int todoOk = -1;
    FILE* pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");

        if(pFile != NULL)
        {
            if(!parser_EmployeeFromText(pFile, pArrayListEmployee))
            {
                todoOk = 0;
            }
            fclose(pFile);
        }
    }

    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int todoOk=0;

    system("cls");
    controller_ListEmployee(pArrayListEmployee);
    printf("ingrese id del empleado a modificar");


    ll_add(pArrayListEmployee , auxEmployee);
    return todoOk;
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
    Employee* auxEmployee;
    int todoOk=0;
    int id;
    int indice;

    system("cls");
    controller_ListEmployee(pArrayListEmployee);
    printf("ingrese id del empleado a modificar");
    scanf("%d",&id);

    indice = ll_get(pArrayListEmployee, id);

    printf("%d", indice);

    if(id==NULL)


    return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int tam = ll_len(pArrayListEmployee);
    int auxId;
    int indice;
    char confirma;
    Employee* auxEmp;
    if(pArrayListEmployee!=NULL)
    {
        system("cls");
        printf("      Baja de Empleado     \n\n");
        controller_ListEmployee(pArrayListEmployee);
        printf("ingrese id: ");
        scanf("&d", &auxId);

        auxEmp = (Employee*) ll_get(pArrayListEmployee, auxId);

        if( auxEmp == NULL)
        {
            printf("no existe un empleado con esa id\n\n");
        }
        else
        {
            mostratEmployee(auxEmp);
            printf("Confirma borrado: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                ll_remove(pArrayListEmployee, auxId);
                todoOk=1;
            }
            else
            {
                todoOk = 2;
            }
        }

    }
    return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int tam = ll_len(pArrayListEmployee);
    Employee* auxEmp;
    if(pArrayListEmployee != NULL)
    {
        todoOk=1;
        for(int i=0; i<tam; i++)
        {
            auxEmp=(Employee*) ll_get(pArrayListEmployee, i);
            if(auxEmp!= NULL)
            {
                mostratEmployee(auxEmp);
            }
        }
    }

    return todoOk;
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
    int error=0;
    int opcion;
    printf("*** Ordenar ***\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    if (opcion>4 || opcion <0)
    {
        error=0;
    }
    else
    {
        error=1;
        switch(opcion)
        {
        case 1:
            ll_sort(pArrayListEmployee, employeeSortById, 1);
            break;

        case 2:
            ll_sort(pArrayListEmployee, employeeSortByName, 1);
            break;

        case 3:
            ll_sort(pArrayListEmployee, employeeSortByHours, 1);
            break;

        case 4:
            ll_sort(pArrayListEmployee, employeeSortBySalary, 1);
            break;
        default:
            printf("opcion invalida");
            break;
        }

    }

    return error;
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

