/**
 * @file: p1_comentarios.c
 * @author: Mishicoder
 * 
 * Este archivo contiene la información esencial para etender los comentarios.
 * Este comentario siempre va al incio de cada archivo, ya que muestra información importante del mismo.
 * Es conocido como un comentario de documentación.
 * La forma en como se está escribiendo este comentario de documentación, es la que se debe seguir.
 * En "@file" se pone el nombre del archivo.
 * En "@author" se pone el nombre del autor del archivo.
 * El resto se considera como la descripción del archivo, se recomienda dejar un espacio después de "@author".
*/

#include <stdio.h>

// Los comentarios son de gran ayuda para la legibilidad de nuestro código.
// Estos comentarios solo son de una línea, por lo que si queremos escribir más líneas

/*
Debemos usar los comentarios de bloque,
aquí ya podemos comentar sin causar errores en el editor y compilador
*/

/**
 * Suma dos numeros enteros.
 * 
 * @param[in] a El primer número a sumar
 * @param[in] b El segundo número a sumar
 * @return Retorna un entero que es el resultado de la suma de los números a y b.
 */
int sum(int a, int b);

/**
 * La función principal, el compilador lo toma como punto de inicio del programa.
 * 
 * @return Retorna 0 si la ejecución del código ha sido existosa, de caso contrario, retorna -1
 */
int main()
{
    /*
    Explicando los comentarios que se han puesto encima de las funciones.
    Estos comentarios también son de documentación, pero están dirigidos a las funciones.
    Lo que se escribe al incio, antes de los términos, es la descripción de la función.

    El termino "@param[in] var":
        [in]: indica que es una variable de entrada
        var: es el nombre de la variable que hemos puesto en los argumentos
    El termino "@return":
        Con este termino, indicas que tipo de dato retorna la función.
    */

   // pasa el cursor sobre "sum", verás que se muestra la información dada en el comentario de documentación.
   int result = sum(5, 8);

    printf("El resultado de la suma es: %d\n", result);

    return 0;
}

int sum(int a, int b)
{
    return a + b;
}