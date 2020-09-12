#include "bib.h"

/** \brief formula que suma dos numeros enteros
 *
 * \param a int, primer numero
 * \param b int, segundo numero
 * \return int, resultado de la suma de los dos numeros
 *
 */
int sumar(int a, int b)
{
    int rdo;

    rdo= a + b;

    return rdo;
}

/** \brief formula que resta dos numeros enteros
 *
 * \param a int, primer numero
 * \param b int, segundo numero
 * \return int, resultado de la resta de los dos numeros
 *
 */
int resta(int a, int b)
{
    int rdo;

    rdo= a - b;

    return rdo;
}

/** \brief formula que divide dos numeros enteros
 *
 * \param a float, primer numero
 * \param b float, segundo numero
 * \return float, resultado de la division de los dos numeros
 *
 */
float division(float a, float b)
{
    float rdo;

    rdo= a / b;

    return rdo;
}

/** \brief formula que multiplica dos numeros enteros
 *
 * \param a int, primer numero
 * \param b int, segundo numero
 * \return int, resultado de la multiplicacion de los dos numeros
 *
 */
int multiplicacion(int a, int b)
{
    int rdo;

    rdo= a * b;

    return rdo;
}

/** \brief formula que factoriza un numero entero
 *
 * \param a int, numero
 * \return int, resultado de la factorizacion del numero
 *
 */
int factorial(int a)
{
    if( a==1 || a==0 || a==(-1))
    {
        return a;
    }
    else if(a<0)
    {
        return a * factorial((a+1));
    }
    else
    {
        return a * factorial((a-1));
    }

}
