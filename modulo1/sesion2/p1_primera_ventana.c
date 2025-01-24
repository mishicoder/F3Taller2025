/**
 * @file: p1_primera_ventana.c
 * @author: Mishicoder
 *
 * En este archivo se muestra como se abre una ventana
 * con raylib y los comando basicos.
 */

#include <stdio.h>
#include <raylib.h>

int main()
{
  // Se inicializa la ventana de raylib
  // se le pasa primero el ancho de la ventana
  // segudo, el alto de la ventana
  // tercero el título de la ventana
  InitWindow(800, 600, "Mi primera ventana");

  // Se declara el bucle while que se ejecutará mientras
  // no se cierre la ventana o no se presione la tecla Escape
  // para ello usamos la funcion de raylib "WindowShouldClose()
  while (!WindowShouldClose())
  {
    // esta funcion se encarga de inicial el modo de dibujado
	  // esta es una funcion de apertura, por lo que se necesita una de cierre
	  // dentro de la funcion de apertura y cierre se debem dibujar
	  // los gradicos que queremos mostrar.
	  BeginDrawing();
	  // limpia la pantalla con un color, en este caso, blanco
	  ClearBackground(WHITE);

	  // funcion de cierre para el dibujado
	  EndDrawing();
  }

  // Al finalizar el bucle while, se debe cerrar la ventan (liberar memoria)
  CloseWindow();

  return 0;
}
