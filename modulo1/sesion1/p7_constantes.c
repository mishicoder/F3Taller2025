/**
 * @file: p7_constantes.c
 * @author: Mishicoder
 * 
 * En este archivo se habla sobre las constantesen C.
 */

#include <stdio.h>

/*
 Las constantes son valores fijos que no cambian durante la ejecución del programa.
 Son útilies para mejorar la legibilidad y seguridad en los datos.
 Por ejemplo, si no usamos una constante para la gravedad, puedes terminar poniendo
 diversos valores como 9.8, 10.0, etc. y esto puede causar errores de cálculo o que
 después de no ver tu código durante un tiempo, no sepas que valor es.

 Para las constantes tenemos tres formas para declararlas.
 Usando "#define" y usando "const".
 Los "#define" se suelen poner despues de los arhivos de encabezado.
 Usando "const" y usando "enum" (enumeraciones)

 Las constantes deben ser nombradas en mayúsuculas, si tienen varias palabras, se usa "_"
 para separarlas.

 Se usa #define para valores simples.
 Se usa const para valores que necesitan un tipo explícito.
 Para constantes relacionadas usar enum

 Comenta las constantes para una mayor legibilidad de código
*/

// en este ejemplo se usa #define debido a que es un valor simple que indica la cantidad maxima
// de slots en un inventario.
#define MAX_INVENTORY_SLOTS 30

// en este caso se usa const porque se pone explícitamente que el valor de la variable debe ser float.
// esto mejorar la legibilidad
const float GRAVITY = 9.80;

// en este caso se usa una enumeración para los meses del año
// ya que tienen una relación entre sí.
enum Months{ ENERO = 1, FEBRERO, MARZO, ABRIL, MAYO, JUNIO, JULIO, AGOSTO, SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE };

int main()
{
    printf("El jugado solo tiene un maximo de %s slots en su inventario.\n", MAX_INVENTORY_SLOTS);
    printf("El valor constante de la gravedad en la aplicación es: %f\n", GRAVITY);
    printf("El segundo mes del año es: %d\n", FEBRERO);

    return 0;
}