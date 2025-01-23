/**
 * @file: p10_bucles.c
 * @author: Mishicoder
 * 
 * Este archivo describe como funcionan los bucles
 */

#include <stdio.h>

int main()
{
    /*
        Los bucles son instrucciones de control que nos permiten ejecutar repetidamente una tarea
        las veces que se requiera o de forma casi infinita.
     */

    /*
        Bucle while
        Este bucle se ejecuta mientras una expresión se cumpla.
        Se escribe de la siguiente forma:

        while(expresion)
        {
            // cuerpo...
        }

        En el primer ejemplo, se declara la variable x y se le da el valor decero, luego,
        se declara el bucle while, el cual se ejecutará siempre que x sea menor que 10.
        También, se le suma una unidad a la varible x, de caso contrario, se crearía un bucle infinito.

        En el segundo ejemplo, se declara la variable run y se le asigna el valor 1, siguiente a ello,
        se declara el bucle while que se ejecutará mientras x sea menor que 20 y además, que run sea igual a 1.
        Dentrol del bucle, se sigue sumando una unidad a la variable x, pero también, se controla que el módulo
        de x y 14 sea 1, de ser así, run pasar a tener el valor 0, con ello, el bucle dejaría de ejecutarse,
        ya que una de las expresiones no se cumple.
    */
    int x = 0;
    while (x < 10)
    {
        printf("Iteración: %d\n", x);
        x++;
    }

    x = 0;
    int run = 1;
    while(x < 20 && run == 1)
    {
        printf("Iteración: %d\n", x);

        if(x % 14 == 1)
        {
            run = 0;
        }

        x++;
    }

    /*
    Bucle for.
    Este bucle tiene más control, ya que se busca que no sea casi infinito.
    Se declara de la siguiente forma
    for(variable de control; expresion logica; incremento)
    {
        // cuerpo
    }
    Donde:
        variable de control: Es una variable que se puede declarar y asignar para el bucle o se puede usar una variable externa y asignar su valor ahí.
        expresion logica: Esta expresion o conjunto de expresiones se debe cumplir para ejecutar el código del cuerpo.
        incremento: Esto indica como aumenta la variable de control. (Ojo: no solo se limita a incrementar, se puede disminuir, multiplicar, dividir).

        En el primer ejemplo, en la declaración del blucle for:
            - se declara la variable i y se le asigna el valor 0.
            - se controla que i sea menor que 10.
            - se multiplica a i por el numero dos.
            - dentro del cuerpo, se imprime el valor actual de la variable de control.

        En el segundo ejemplo:
            - se declara una variable a.
            * En la declaración del bucle for
                - se le asigna el valor 10 a la variable a.
                - se controla que a sea mayor que 0.
                - se le resta una unidad a la variable a
                - dentro del cuerpo, se imprime el valor actual de la variable de control.
    */

    for(int i = 0; i < 100; i * 2)
    {
        printf("Valor del for 1: %d\n", i);
    }

    int a;
    for(a = 10; a > 0; a--)
    {
        printf("Valor del for 2: %d\n", a);
    }

    /*
        Bucle do-while
        En este bucle pasa exactamente lo mismo que el bucle while, pero, este tiene un caso especial.
        El código del cuerpo del bucle do-while, siempre se ejecuta al menos una vez.
        Su declaración es la siguiente.
        do
        {
            // cuerpo...
        }while(expresion);

        Tenemos dos ejemplos, el primero, se ejecuta solo una vez, debido a la propiedad especial del bucle,
        el segundo, se ejecuta 11 veces.
    */
    int p = 20; 
    do{
        printf("Este bucle se ejecuta al menos una vez.\n");
    }while(p < 20);

    int m = 0;
    do
    {
        printf("Iteracion del bucle do-while: %d\n", m);
    } while (m < 10);
    

    return 0;
}