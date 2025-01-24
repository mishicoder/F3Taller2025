/**
 * @file: p13_pointer.c
 * @author: Mishicoder
 *
 * Este archivo explica como funcionan los punteros en C.
 *
 * Abrir el documento memoria_0.excalidraw en "https://excalidraw.com/"
*/

#include <stdio.h>

int main()
{
  /*
    Al momento de imprimir en pantalla, se mostrará la misma direccion de memoria
    tanto para x como para ip.

    También, vemos como para accder al valor que esta en dicha direccion de memoria,
    se usa el operador * que es el operador "pointer".

    Nota importante: Al momento de que se apunta a una direccion en memoria, se puede
    trabajar con el valor, y con ello, se puede modificar el valor a través del
    puntero.

    Se ha visto los pointer anteriormente, por ejemplo, al momento de pasar un
    argumento por referencia, ahora, ya se entiende mejor lo que está pasando,
    al momento de pasar un argumento por referencia, estamos pasando la direccion
    en memoria, con la cual podemos operar, como lo hemos hecho.
   * */

  int x = 120;
  int *ip;

  ip = &x;

  printf("Direccion de memoria de la variable x: %p\n", &x);

  printf("Direccion de memoria del puntero ip: %p\n", ip);

  printf("Valor de la direccion de memoria a la que apunta ip: %d\n", *ip);
  
  return 0;
}
