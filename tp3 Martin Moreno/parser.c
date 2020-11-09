#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char buffer1[128];
    char buffer2[128];
    char buffer3[128];
    char buffer4[128];
    int len;
    Employee* auxEmpleado;
    auxEmpleado= (auxEmpleado + len);
    int i;
    len = ll_len(pArrayListEmployee);
    int cant;

    pFile = fopen("data.csv","r");
    if(pFile==NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    do
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer1, buffer2,buffer3,buffer4);

        if(cant == 4)
        {
            employee_getId(auxEmpleado, atoi(buffer1));
            employee_getNombre(auxEmpleado, buffer2);
            employee_getHorasTrabajadas(auxEmpleado, atoi(buffer3));
            employee_getSueldo(auxEmpleado, atoi(buffer4));

            i++;
        }
        else
        {
            break;
        }
    }while( !feof(pFile) && i<len);
    return 1;
}

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
