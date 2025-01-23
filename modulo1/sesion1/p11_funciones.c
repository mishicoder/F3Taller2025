/**
 * @file: p11_funciones.c
 * @author: Mishicoder
 * 
 * Este archivo describe las funciones en C y las reglas de alcance.
 */


/*
    Una función es aquella que nos permite evitar el re-escribir código.
    Pueden devolver o no un tipo de datos propio del lenguaje o definido por el usuario.
    Pueden recibir valores argumentales(argumentos) que serán utilizados en el cuerpo de la función.

    Declaración de una funcion:

    Con argumentos:
        tipo_de_retorno nombre_de_funcion(argumentos...);
    Sin argumentos:
        tipo_de_retorno nombre_de_funcion();

    Donde:
        tipo_de_retorno: Puede ser un tipo de dato del lenguaje, uno definido por el ususrio o void.
        nombre_de_funcion: Es ek binbre que quieres que tenga la funcion.
        argumentos...: sonlos argumentos que recine la funcion.

    Depués de declarar una función se debe implementar su definición.
        Al declarar, se pone el ";" al final.
        Al implementar la definicion se usan las "{}"

    Ejemplo 1:
        Se declara una función que retorna el área de un cuadrado.


    REGLAS DE ALCANCE
        Conocemos las variables globales, estas están fuera de las funciones y suelen ponerse por buenas prácticas,
        despues de los archivos de encabezado(ejemplo: "#include <stdio.h>").
        En este caso tenemos la variable global PI, la cual se puede ver que se usa en dos funciones.

        En cambio, cundo declaramos una variable dentro de una funcion, su alcance es local, esto quiere decir que
        solo se puede usar en el cuerpo de la funcion.
        Veamos la funcion "addition", tiene como variable local "args", si intenamos usar esa variable dentro de otra
        funcion, tanto el editor como el compilador nos indicaran un error porque dicha variable no ha sido definida
        como global o dentro de la funcion donde la queremos usar.

        * Si quieres ver el error, descomentar la parte que se indica que se mostarará el error.
*/

#include <stdio.h>
#include <stdarg.h> // para las funciones VARIADIC

// valor constante de PI
const float PI = 3.1415f;

/**
 * Función que retorna el área de un círculo.
 * 
 * @param rad Radio del círculo.
 * 
 * @return Un float, que es el área del círuclo.
 */
float circle_area(float rad);

/**
 * Función que muestra un mensaje por pantalla.
 */
void show_welcome_message();

/**
 * Función que posee una parámetro por refencia y le asigna el valor del área del círculo.
 * 
 * @param[in] rad Radio del círculo.
 * @param[out] result Variable donde se volcará el resultado de la operación.
 */
void circle_area_ref(float rad, float *result);

/**
 * Funcion VARIADIC que suma los n numeros pasados como argumento.
 * 
 * @param[in] n Cantidad de argumentos que se pasarán a la función.
 * @param[in] args... Valores argumentales separados por ","
 * 
 * @return Un int que es el valor total de la suma.
 */
int addition(int n, ...);

/** 
 * Función que recibe una función puntero y la ejecuta.
 * 
 * @param void(*func)() Funcion que se ejecutará dentro de la función.
*/
void callback_in_function(void(*func)());

/**
 * Función para pasar como argumento dentro la funcion "callback_in_function"
 */
void myFunc();

int main()
{
    /*
    Directiva "void":
        Cuando una función no retorna ningún valor, se usa esta directiva en su declaración.
        Como en el ejemplo siguiente:
            void sumar_ref(int a, int b, int *result);
    */

    /* 
        para usar una función se escribe su nonbre, seguido de la apetura y cierre de paréntesis.
        en este caso, dentro de los paréntesis se pone un valor, ya que la función pide un argumento.

        como se puede ver, cuando llamamos a la función "circle_area", la llamamos al momento de asignar
        el valor para la variable "area", esto se debe a que la función retorna un valor, en este caso, flotante.

        cuando llamamos a la funcion "show_wellcome_message", no la estamos llamando al asignar algún valor,
        ya que esta funcion no retorna valor alguno, así que simplemente se puede llamar como se está mostrando.
    */
    
    float area = circle_area(7.5f);
    printf("Area del circulo con radio 7.5: %f\n", area);

    show_welcome_message();

    /*
        Al llamar a la funcion con paso por referencia, la variable que será referenciada, se acompaña del operador "&",
        el cual indica que es una referencia.
    */
    float result;
    circle_area_ref(8.0f, &result);
    printf("El resultado del area, usando un paso por referencia es: %f\n", result);

    /*
        Llamando a la función VARIADIC.
        La suma debe dar com resultado: 15.
        Como se puede notar, el primer argumento es la cantidad de argumentos adicionales, en este caso 5.
        Luego, se han puesto 5 argumentos adicionales que son los numeros del 1 al 5.
    */
    int total = addition(5, 1, 2, 3, 4, 5);
    printf("Resultado de la suma usando funcion VARIADIC: %d\n", total);

    /*
        Llamando a la funcion callback_in_function.
        Como se puede ver, se pasa la funcion "myFunc" como argumento.
        NOTA IMPORTANTE:
            La forma de la función debe ser igual a la que se pide como argumento.
            Mismo tipo de retorno, y misma cantidad y tipo de argumentos.
            El nombre puede variar, pero lo anteriormente mencionado, no.
        
            En el ejemplo:
                El argumento tiene la siguiente forma:
                    void(*func)()
                    Su tipo de retorno es void y no recibe argumentos
                La funcion "myFunc":
                    void myFunc()
                    Su tipo de retorno es void y no recibe argumentos
                
                Siendo así, todo es correcto, como se menciona anteriormente, el nombre puede variar.

    */
    callback_in_function(myFunc);

    /*
        Error de alcance
    */
    // args = NULL; // borra los "//" del principio para descomentar y ver el error.

    return 0;
}

/*
    Cuando se especifica un tipo de dato, como en este caso que sea especificado float,
    se debe utilizar la directiva "return".

    return indica que se retornará un valor en la función, en este caso, debemos retornar
    un valor flotante(float) y por ello se especifica:
        return PI * (rad * rad);
        return indica que se devolverá el resultado de la operacion de PI * (rad * rad)
 */

float circle_area(float rad)
{
    return PI * (rad * rad);
}

/*
    En este caso se ha especificado "void" por lo que no es necesario retornar un valor,
    es decir, que no hace falta usar "return".
    Esta funcion mostrar el texto por pantalla, cada vez que sea llamada.
*/

void show_welcome_message()
{
    printf("Welcome to C program language!\n");
}

/*
    En este caso, veremos las funciones que reciben argumentos por referencia.
    Un argumento por referencia indica que la variable que se pasa como argumento, pueda ser modificada dentro de la función.
    En este caso la variable que se modificará será "*result".
    Cuando se requiere de un argumento por referencia se pone el "*" antes del nombre del parámetro.

    Nota: los otros valores que se pasan, son argumentos por valor, es decir que de ser variables que se pasan como argumento,
        no se modificara su valor fuera de la funcion.

    Como se vio, en el comentario de documentación de la función:
        @param[out] result
    [in] indica que es un valor de entrada (paso por valor).
    [out] indica que dicho a dicho argumento se le asignará un valor de salida. (paso por referencia)

    Importante:
        Un argumento por referencia puede ser tanto de entrada como de salida, es decir que se puede usar su valor para operar dentro
        de la función y luego ser modificado.
        Al momento de documentar se usaría: [int, out]
*/

void circle_area_ref(float rad, float *result)
{
    *result = PI * (rad * rad);
}

/*
    En caso de las funciones VARIADIC se usa: 
    "va_list": que se encargará de contener los valores argumentales.
    "va_start": que indica que se empezarán a usar los argumentos "...".
    "va_arg": que se usa para obtener uno a uno los argumentos, se especifica el tipo.
    "va_end": que indica el cierre de la recolección y tratado de argumentos.
*/

int addition(int n, ...)
{
    va_list args;
    int i, sum = 0;

    va_start(args, n);

    for(i = 0; i < n; i++)
    {
        sum += va_arg(args, int);
    }

    va_end(args);

    return sum;
}

/*
    Las funciones puntero (pointer function) no permiten asignar una función a una variable o pasarla como argumento.
    Se declaran de la siguiente forma:
        Con argumentos:
            tipo_de_retorno(*nombre_funcion)(argumentos)
        Sin argumentos:
            tipo_de_retorno(*nombre_funcion)()
*/

void callback_in_function(void (*func)())
{
    printf("Al iniciar la función callback_in_function\n");
    (*func)();
    printf("Al finalizar la función callback_in_function\n");
}

void myFunc()
{
    printf("Puedo estar dentro de otra funcip¿on\n");
}
