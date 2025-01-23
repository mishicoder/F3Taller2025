/**
 * @file: p12_arreglos.c
 * @author: Mishicoder
 * 
 * En este archivo se describen los arreglos(array) y como se usan con la notación "[]" y como
 * se pueden manejar con bucles.
 */

#include <stdio.h>

/*
    Los arreglos nos permiten tener una colección de datos, esto nos ayuda a simplificar el código
    cuando queremos contener gran cantidad de valores de un tipo.
    Podemos tener arreglos de una sola dimension o varias dimensiones.
    Todo arreglo tiene n elementos y sus índices van desde 0 hasta n-1.
    Digamos que tenemos un arreglo con 100 elementos, entonces:
        índices = 0 a n-1
                = 0 a 100 - 1
                = 0 a 99
    ¿Pero, para qué son los índices?
    Para acceder a un valor en el array, se usa la notación "[]", bien, dentro de los corchetes,
    debemos colocar el índice del elemento al que queremos acceder.
    Siguiendo con el arreglo de 100 elementos, digamos que queremos acceder al elementos 15.
    Para acceder al elemento 15, debemos poner entre corchetes el número 14.
    ¿Por qué el 14 si queremos el elemento 15?
    Como se especifica, los índices van de 0 a n-1, por lo que para acceder al elemento 15 también
    se aplica "n-1", ya que si queremos acceder al elemento 100, debemos poner 99, ya que si ponemos
    100, se marcará un error de desborde, ya que de 0 a 99 hay cien numeros, y el arreglo
    que se esta poniendo de ejemplo, tiene 100 elementos.

    Para declara un arreglo de una sola dimension se puede hacer de la siguiente forma:
        Sin datos inicializados:
            tipo_de_dato nombre_de_arreglo[cantidad_de_elementos];
        Con datos iniciales (Aquí tu tienes no explícito de la cantidad de datos):
            tipo_de_dato nombre_de_arreglo = {dato-1, ..., dato-n};

    Para arreglos de más dimensiones:
        Sin datos inicializados:
            tipo_de_dato nombre_de_arreglo[cantidad][cantidad][cantidad];
        Con datos iniciales (Aquí tu tienes no explícito de la cantidad de datos):
            tipo_de_dato nombre_de_arreglo[3][3][3] = {
                {
                    {1,0,0},
                    {0,1,0},
                    {0,0,1}
                },
                {
                    {1,0,0},
                    {0,1,0},
                    {0,0,1}
                },
                {
                    {1,0,0},
                    {0,1,0},
                    {0,0,1}
                }
            };

    Los elementos de los arreglos deben ser inicializados, para ello, podemos usar bucles.
    IMPORTANTE: El tamño de los array no puede ser modificado, una vez se le da el tamaño de forma
    explícita o implícita, no se puede modificar.
*/

int main()
{
    int numbers[100]; // elementos con valores sin asignar
    for(int i = 0; i < 100; i++) // el bucle itera de 0 a 99
    {
        if(i % 2 == 0)
            numbers[i] = 1;
        else
            numbers[i] = 0;
    }
    // al finalizar los elementos pares tendran el valor 1 y los impares el valor 0

    printf("Valor del elemento 24 en el arreglo: %d\n", numbers[23]); // imprime 1
    printf("Valor del elemento 87 en el arreglo: %d\n", numbers[86]); // imprime 0

    // MULTI DIMENSIONAL
    int map[4][5] = {
        {1,1,1,1,1},
        {1,0,0,0,1},
        {1,0,0,0,1},
        {1,1,1,1,1}
    };
    // En este ejemplo, se simula como se dibujará un mapa, donde 1 puede ser una pared
    // y 0 un espacio vacio
    // para iterar sobre este array:
    printf("\nITERACION DEL ARRAY MAP:\n");
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(map[i][j] == 1)
            {
                printf("Se dibuja una pared\n");
            }
        }
    }

    return 0;
}