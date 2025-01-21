/**
 * @file: p6_convertir_datos.c
 * @author: Mishicoder
 * 
 * Este archivo explica como convetir tipos de datos.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
     Para convetir entre tipos de datos, se usa la siguient forma.
     (tipo_de_dato) expresión;

     Ejemplo 1:
     Convetirmos un valor "char" a un valor "int"

     Ejemplo 2:
     Convertimos el resultado de una división de enteros(int) a un valor flotante(float)
    */
    char a = 'A';
    int numberOfA = (int) a;

    int x = 50, y = 15;
    float result = (float) x / y;

    /*
     Pero para convertir una cadena de texto a un valor número, se debe aplicar una función.
     Para la forma invetida, también se debe aplicar otra función.

     atoi(char str[]) -> convierte una cadena de texto a un número
        donde:
            str -> cadena de texto a convetir en número

     itoa(int n, char str[], int len) -> convierte un número a una cadena de texto
        donde:
            n -> núnero a convertir a cadena de texto
            str[] -> cadena de texto donde se guardará el número convetido.
            len -> tamaño de la cadena de texto (en el ejemplo 10)
    */

    int num = 450;
    char nstr[10];
    itoa(num, nstr, 10); // con esto convertimos un entero a una cadena de texto

    char rchoise[] = "150";
    int ichoise = atoi(rchoise); // así convertimos una cadena de texto a entero

    return 0;
}