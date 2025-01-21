/**
 * @file: p2_primer_programa.c
 * @author: Mishicoder
 * 
 * Este código muestra la estructura de un programa en C.
 * Ademas éxplica como funciona la función "printf(const char* _Format, ...);"
 */

// esto es un archivo de encabezado propio del lenguaje C, más adelante se explicará que es un encabezado.
// siempre van primero, antes que todo el resto del código
#include <stdio.h> 

// esto se conoce como una definición (En px_constantes.c) se habla más sobre esto,
// van después que los encabezados y antes que las variables globales y funciones.
#define MESSAGE "Bienvenido"

// esto es una variable global, esto quieres decir que se puede usar en cualquier función del documento.
char name[] = "David";

// La función main indica que es el punto de entrada de un programa al compilador.
int main()
{
    /*
    Entendiendo la función printf(const char* _Format, ...);
    Es una función que nos permite mostrar texto por pantalla(consola)

    const char* _Format: es un texto con formato, donde se pueden usar carácteres de escape y formateadores de texto.
    Nota: Mirar las imágenes img0.png, img1.png, img2.png para ver los carácteres de escape y formateo.

    ...: esto indica que se pasaran n argumentos, estos argumentos dependen de la cantidad de carácteres de formateo que hayas puesto.
    */

    // Ejemplos (se usa el carácter de escape "\n" que indica que se debe saltar a la siguiente línea de la terminal)

    // En este ejemplo, solo paso un parámetro, ya que solo hay un "%s"
    printf("Bienvenido, %s!\n", name);
    
    // En este ejemplo, paso dos parámetros, ya que hay dos "%s"
    printf("%s, %s!\n", MESSAGE, name);

    /*
    Nota: Se debe tener en cuenta que los carácteres de formateo son secuenciales, es decir que se debe respetar el orden,
    si has puesto "%s, %d, %c" indica que debes ingresar primero una cadena de texto(char[]), segundo un entero (int) y tercero un caracter(char)
    si no siguese el orden, el editor te indicará una advertencia y puedes tener un error al compilar.
    */

    // esto es el punto de salida del programa, cuando es 0, es porque la compilación ha sido exitosa
    // caso contrario, se debe retornar -1.
    // Nota: el compilador, si el programador no maneja un error o es un error fuera de su código, retornará un código de salida
    // diferente de -1. Cuando la compilación es correcta, en la consola se debe mostrar el código de salida 0.
    return 0; 
}