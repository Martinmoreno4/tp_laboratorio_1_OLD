#include <stdio.h>
#include <stdlib.h>
#include "bib.h"



int main()
{
    int operandoA;
    int operandoB;

    printf("introdusca el operando A\n");
    scanf("%d", &operandoA);
    printf("introdusca el operando B\n");
    scanf("%d", &operandoB);

    printf("El resultado de A+B es: %d\n", sumar(operandoA,operandoB));
    printf("El resultado de A-B es: %d\n", resta(operandoA,operandoB));

    if(operandoB!=0)
    {
        printf("El resultado de A/B es: %.2f\n", division(operandoA,operandoB));
    }
    else
    {
        printf("No es posible dividir por cero");
    }

    printf("El resultado de A*B es: %d\n", multiplicacion(operandoA,operandoB));
    printf("El factorial de A es: %d y El factorial de B es: %d\n", factorial(operandoA),factorial(operandoB));

    return 0;
}

