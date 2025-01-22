/**
 * @file: p8_operadores.c
 * @author: Mishicoder
 * 
 * Este archivo muestra como funcionan los operadores.
 */

#include <stdio.h>

int main()
{
    // OPERADORES LÓGICOS

    // suma
    int a = 5 + 7;

    // resta
    int b = 6 - 8;

    // multiplicación
    int c = 4 * 9;

    // división
    float d = (float) 45 / 0.9;

    // módulo
    // el operador de módulo lo que hace es devolver el residuo de una división
    int resto = 73 % 5;

    /*
    El operador unitario de suma.
    Este operador lo que hace es sumarle una unidad a la variable.
    */
    int e = 5;
    e++; // ahora e vale 6 

    /*
    El operador unitario de resta.
    Este operador lo que hace es restarle una unidad a la variable.
    */
    int f = 41;
    f--; // ahora f vale 40

    // OPERADORES RELACIONALES (se verán a detalle en las condicionales)
    // igualdad (verifica que el valor izquierdo sea igual al valor derecho)
    if(a == b) printf("Las variables tienen el mismo valor\n");

    // diferente (verfica que el valor izquierdo sea diferente al valor derecho)
    if(a != b) printf("Las variables tienen diferente valor\n"); 

    // mayor (verifica que el valor izquierdo sea mayor que el derecho)
    if(a > b) printf("La variable izquierda ese mayor que la derecha\n");

    // menor (verifica  que el valor izquierdo sea menor que el derecho)
    if(a < b) printf("La variable izquierda es menor que la izquierda\n");

    // mayor igual (verifica que el valor izquierdo sea mayor o igual que el derecho)
    if(a >= b) printf("El valor izquierdo es mayor o igual que el valor derecho\n");

    // menor igual (verifica que el valor izquierdo sea menor o igual que el derecho)
    if(a <= b)printf("El valor izquierdo es menor o igual que el derecho\n");

    // OPERADORES LÓGICOS
    // operador AND (&&) [controla que todas las condiciones sean verdaderas]
    if(a != 5 && b > 3) printf("Ambas condicione se cumplen\n");

    // operador OR (||) [Controla que una de las condiciones sea verdadera]
    if(a > 3 || b != 4) printf("Una de las condiciones se ha cumplido\n");

    // operador de negación (!) [Convierte un valor de verdad a su contrario]
    // si es verdadero, pasa a ser falso
    // si es falso, pasa a ser verdadero
    // en el ejemplo, el operador causará que se cumpla la condición si el valor de a == b no es falso
    if(!(a == b)) printf("Controla que a == b no sea falso\n");

    // OPERADORES DE OPERACIÓ-ASIGNACIÓN
    /*
    Estos operadores permiten asignar un valor y operar
    ¿Cómo funcionan?
    digamos qsue tenemos una variable x con un valor de 5
    entonces, aplicamos el operador
    x += 8;
    Ahora la variable vale 13 pero ¿Qué pasó?
    Lo que pasa, es lo siguiente:
    x = x + 8;
    x = 5 + 8;
    x = 13;
    Internamente, es lo que pasa, se toma el valor actual de x y se le suma 8, dando como resultado 13.
    Lo mismo pasa con cada operador aritmético.
    */

    int p = 45, k = 23;
    p += 4;

    // Existen otros operadores, pero se verán en las secciones correspondientes

    return 0;
}