/**
 * @file: p5_variables.c
 * @author: Mishicoder
 * 
 * En este archi se ven a fondo las variables.
 */

#include <stdio.h>

int main()
{
    /*
     Una variable es una etiqueta que nos permite acceder a un espacio en memoria.
     Cada una debe ser de un tipo de dato, ya sea de C o definida por el usuario.
     Al momento de ser declaradas se les puede dar un valor.

     La notación de una variable es:

     tipo_de_dato nombre_de_variable;

     o:

     tipo_de_dato nombre_de_variable = valor_de_variable;

     Nota: ver p3_tipos_de_datos.c para ver todos los tipos de datos que puede tener un variable.
    */

    // se declara la variable pero no se le da valor
    int age;

    // se declara la variable y se le da un valor
    float gravity = 9.8f;

    // en el anterior caso
    // tipo_de_dato: float
    // nombre_de_variable: gravity
    // valor_de_variable: 9.8f

    // se pueden declarar varias variable del mismo tipo, usando ","
    int numberA, numberB, numberC = 4;
    // como se puede verm, a numberC se le ha dado un valor.
    // no se puede hacer lo siguiente:
    // int numberA, numberB, float numberC; // causa un error (descomenta para ver) [se descomenta borrando los // del principio]

    /*
    Reglas de nomenclatura: 
    A continuación, se muestran las formas en como se puede darle un nombre a las variables.

    IMPORTANTE: las variables no pueden ser llamadas igual que las palabras reservadas de C o los tipos de datos definidos por el usuario. (ver imagen "img3.png")
    */
   int _number = 0;
   int myVariable = 1;
   char letra_de_incio = 'A';
   float Fov = 60.0f;

   // Nombres que darían error (descomentar para comprobar)
   //int &mi_var; // error, inicia con caracter especial.
   //char 1letra = 'c'; // error, inicia con número.
   //float @fov = 60.0f; // error, inicia con caracter especial.
   //long break = 712321321321312312; // error, el nombre es igual a una palabra reservada.

   /*
    Como se puede ver, no se debe inicial con un carácter incial, a menos que sea el guión bajo "_".
    Tampoco se puede iniciar el nombre de una variable con un número.
   */

    return 0;
}