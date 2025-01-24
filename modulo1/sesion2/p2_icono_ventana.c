/**
 * @file: p2_icono_ventana.c
 * @author: Mishicoder
 *
 * Este archivo muestra como ponerle un icono a nuestra ventana.
*/

#include <raylib.h>

int main()
{
  InitWindow(800, 600, "Mi primera ventana");

  // Se carga la imagen desde la carpeta "assets"
  // las imagenes se cargan en la CPU
  Image icon = LoadImage("assets/window_icon.png");
  // Se usa la función SetWindowIcon de raylib para establecer
  // el icono de la ventana, se pasa la imagen por parametro
  SetWindowIcon(icon);

  while(!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(WHITE);
    EndDrawing();
  }
  
  // Debemos liberar recursos de la ram antes
  // de liberar la memoria general
  UnloadImage(icon);
  CloseWindow();

  return 0;
}
