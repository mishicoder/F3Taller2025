/**
 * @file: p3_tipos_de_datos.c
 * @author: Mishicoder
 * 
 * En este archivo se ven los tipos de datos que existen, su tamaño en bytes y su rango de valores.
 */

#include <stdio.h>

/*
Antes de empezar ¿Qué es un byte?
Un byte es una unidad de información digital, cuando descargas un archivo habrás notado los símbolos "GB", "KB", "MB".
También, un Bite es un valor que solo puede ser 1 o 0

Pues se vería de la siguiente forma:
1 byte equivale a 8 bites, veamos la siguiente forma
    0 1 0 0 1 1 0 1 -> esto son 8 bites que equivalen a un byte
1024 bytes equivalen a un Kilobyte [KB]
1024 kilobytes equvalen a un Megabyte [MB]
1024 Megabytes equivalen a un Gigabyte [GB]

Una vez entendido esto, pasemos a los tipos de datos de C.

Nota: Es importante aprenderse los tamaños, en el apartado de uso de memoria, se verá más a detaller el porqué.
*/

int main()
{
    /* 
     char -> este tipo de dato puede contener un carácter y siempre debe estar entre comillas simples
     su tamaño es de 1 byte
     puede almacenar valores númericos entre -128 a 127 en caso de no especificar que es unsigned
     en caso de ser unsgined podrá almacenar valores ente 0 a 255
     Para crear cadenas de texto, se usa una colección de char con la notación [], el tamaño en memoria equivale a la cantidad
     de caracters que tenga la cadena, en el ejemplo serían 14 bytes.
    */
    char c = 'A';
    unsigned char b = 'B';
    char taller[] = "Videojuegos 2D";

    // Nota: El término "unsigned" indica que el número no puede tener signo "-"
    // por defecto las varibles que puedan ser modificadas con "unsigned" son "signed"
    // pero también se puede expresar de forma explícita.

    /*
     int -> este tipo de dato puede contener valores enteros, pero hay algo a tener en cuenta, su tamaño en bytes depende
     de la arquitectura del sistema:
        en un computador de 16 bits su tamaño será de 2 bytes
        en un computador de 32 o 64 bits su tamaño será de 4 bytes
     también es afectado por "unsigned"
     cuando puede tener signo su rango va de:
        16 bits: -32,768 a 32,767
        32/64 bits: -2,147,483,648 a 2,147,483,647
     cuando no puede tener signo (unsigned):
        16 bits: 0 a 65,535
        32/64 bits: 0 a 4,294,967,295
    */
    signed int number = -25456; // indica de forma explícita que la variable puede tener valores tanto negativos como positivos
    unsigned int number2 = 355; // la variable solo puede contener valores sin signo (si se le coloca el signo "-" el compilador lo quitará)

    /*
     short -> es un entero de valor corto, su tamaño en memoria es de 2 bytes
     al igual que int, puede ser afectado por "unsigned"
     su rango con signo es: -32,768 a 32,767
     su rango sin signo es: 0 a 65,535
    */
    short numberShort = -45;
    unsigned numberShort2 = 45000;

    /*
     long -> es un entero con un valor enorme, su tamaño en memoria es de 8 bytes
     al igual que int, puede ser afectado por "unsigned"
     su rango con signo es: -9223372036854775808 a 9223372036854775807
     su rango sin signo es: 0 a 18446744073709551615
    */
    long bigNumber = -9223372036854745804;
    unsigned long bigNumber2 = 18446744073709551613;

    // TIPOS FLOTANTES (DECIMALES)
    // en el caso de los decimales, se debe tener en cuenta su precisión
    // no pueden ser unsigned

    /*
     float -> su tamaño en memoria es de 4 bytes
     su valor es de: 1.2E-38 a 3.4E+38
     su precisión es de 6 decimales
     se puede poner una f al final de valor (opcional)
    */
    float x = 150.45f;

    /*
     double -> su tamaño en memoria es de 10 bytes, es más grande en valores que float
     su valor es de: 2.3E-308 a 1.7E+308
     su precisión es de 15 decimales
    */
    double gravity = 9.80665;

    /*
     long double -> su tamaño en memoria es de 8 bytes, su valor es enorme a diferencia de float y double
     su valor es de: 3.4E-4932 a 1.1E+4932
     su precisión es de 19 decimales
    */
    long double bigDobule = 1232131.4325444352354;

    // TIPOS DEFINIDOS POR LOS USUARIOS
    /*
     Los tipos definidos por el usuarios son todos aquellos que el programador puede crear usando
     struct -> estructuras
     enums -> enumeraciones

     cuando se usa una "struct" el tamaño depende de los datos que puede contener dicha estructura.
     En el siguiente ejemplo:
        Tenemos la estructura "student"
        tiene una cadena de texto de 20 caracateres(char), esto quivale a 20 bytes en memoria
        usa un float para el promedio, esto equivale a 4 bytes
        usa un int para la edad, esto equivale a 4 bytes (en arquitectura de 32 y 64 bites)
        Sumando todo, tenemos como resultado un tamaño de:
            28 bytes
        Eso es lo que ocupará en memoria nuestro tipo definido.
    */
    struct student{
        char name[20];
        float average;
        int age;
    };
    // ¿Cómo lo uso? de la siguiente forma
    struct student studen1 = {"Carlos", 7.8, 19};

    /* 
     y así es como hemos creado y usado un tipo definido por usuario
     pero ¿y si no quiero usar struct?
     Para ello, en c tenemos la palabra clave "typedef"
     ¿Cómo lo uso?
    */
    typedef struct member
    {
        char namr[20];
        int hasSub;
        int age;
    } gmember;
    // ahora, el uso al declarar una variable con nuestro tipo de dato ess
    gmember member1 = {"Rodrigo", 0, 24};

    /*
     Como se puede apreciar se usa "typedef" antes de "struct", esto le indica al compilador que se creará un tipo de dato con esa estructura.
     Tener en cuenta que se debe poner el nombre del tipo antes del punto y coma.
     Como se puede ver, después de estruct dice "member" pero antes del punto y coma dice "gmember".
     member -> nombre de la estructura
     gmember -> nombre del tipo de dato
    */

    // ARRAYS
    /*
     Los array son colecciones de datos, que nos permiten evitar la declaración de un sin fin de variables.
     Al ver el tipo de dato "char" ya se vio un array, ahora veremos que se puede hacer de varios tipos.
     En los ejemplos, se crea un array de tipo "int" que puede contener 5 valores. Se puede omitir el poner el número si le da los valores al ser declarado el array.
     Caso contrario, se debe especificar el número.
     En los array el primer indice es el 0, esto es muy importante.
     Para acceder a los valores de un array, se usa la notación [indice] (como se ve en el ejemplo)
     Si ponemos un índice incorrecto, causará un error.
     Como se mencionó, el índice empieza en cero, por ello, en el ejemplo, al usar la notación [indice], se usan los números del 0 al 3
     ya que si contamos, del 0 al tres, son cuatro elementos, los mismos que tiene el array "letters".

     IMPORTANTE: el tamaño de un array no se puede cambiar, una vez es declarado con tamaño, no puede mutar dicho tamaño.
        Si un array tiene un tamaño de 5, se quedará con ese tamaño desde que el programa inicia hasta que finaliza.
    */
    int moreNumbers[] = { 1, 2, 3, 4, 5 }; // ya se le puso valores, se puede omitir el número entre los corchetes.
    char letters[4]; // se le pone la cantidad que puede contener el array, ya que no se le da valores al declarar.
    letters[0] = 'a';
    letters[1] = 'b';
    letters[2] = 'c';
    letters[3] = 'd';

    return 0;
}