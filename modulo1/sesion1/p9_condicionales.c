/** 
 * @file: p9_condicionales.c
 * @author: Mishicoder
 * 
 * Este archivo muestra como funcionan las condicionales.
*/

#include <stdio.h>

int main()
{
    /*
    Las condicionales nos permiten mantener un control en el código, es decir que podemos
    controlar que algo se cumpla para que algo ocurra.

    El ejemplo más simple para entender:
    En nuestros espacios tenemos luces, estás luces suelen tener un interruptor para encender.
    Si el interruptor está apagado, la energía no pasa y la bombilla no enciende.
    Si el interruptor está encendido, la energía pasa y la bombilla enciende.
    */

    // condifional IF
    // se lee: si se cumple la condicion, entonces hacer...
    int a = 0;
    if(a == 0) // si a es igual a b
    {
        // entonces
        printf("La condicion se ha cumplido, se ejecuta el código que está entre llaves.\n");
    }

    return 0;
}
