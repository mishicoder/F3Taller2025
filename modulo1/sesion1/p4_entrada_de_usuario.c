/**
 * @file: p4_entrada_de_usuario.c
 * @author: Mishicoder
 * 
 * En este archivo se muestra el uso de las funciones "scanf(const char* _Format, &...);" y "gets(char[])".
 * Se usan los formatos de texto. (ver p2_primer_programa.c)
 */

#include <stdio.h>

int main()
{
    /*
     Ya hemos visto como mostrar mensajes por pantalla, ahora veremos como obtener la entrada del usuario.
     para ello usaremos la función "scanf(const char* _Format, &...)"
     Como vimos en "printf" tenemos "const char* _Format", es decir que para obtener los datos,
     debemos pasar formatos de texto.
     El seungo elemento es "&...", esto indica que debemos colocar las variables donde se volcaran los datos,
     deben ser una referencia a la variable (se verá esto en la sección de punteros). 
    */


    /*
     En este ejemplo, digamos que queremos decirle al usuario si es menor o mayor de edad, para ello, debemos obtener su edad.
     Primero declaramos la variable donde se volcará el valor obtenido por el usuario.
     Segundo, mostramos un mensaje que le indica que ingrese su edad.
     Tercero, usamos la función "scanf" y le ponemos como parámetros "%d" y &age.
        %d -> indicamos que queremos obtener un valor entero(int) ya que de ese tipo de dato es nuestra variable age.
        &age ->
            &   -> indica que el valor se pasa como referencia (esto se ve en funciones).
            age -> es la variable que tendrá el valor obtenido por el usuario.
     Por último, comprobamos que la edad sea mayor o igual a 18, de ser así, se le dirá que es mayor de edad, de caso contrario,
     se le dirá que es menor.
     Nota: los términos "if" ">=" "else" se ven en las secciones "operadores" y "condicionales" respectiavamente.
    */
    int age;
    
    printf("Ingresa tu edad: ");
    scanf("%d", &age);

    if(age >= 18)
        printf("Eres mayor de edad!\n");
    else
        printf("Eres menor de edad!\n");


    /*
     En el siguiente ejemplo digamos que queremos mostrar un mensaje personalizado y para ello deseamos obtener
     el nombre del usuario.
     Aquí ocurre algo especial, cuando pasamos la variable "name" como argumento no le hemos puesto "&", esto es debido a que
     en el caso de los array, estos ya se manejan como una referencia a memoria.
     En este caso hemos usado "scanf" con el caracter de formato "%s".
    */
    char name[20];

    printf("Ingresa tu nombre: ");
    scanf("%s", name);

    printf("Bienvenido, %s! Disfruta de tu aventura en el mundo de los videojuegos!\n", name);

    /*
     En este caso usaremos "gets".
     Como podedmos notar, solo le debemos pasar el nombre de la variable.

     IMPORTANTE: Esto no funciona en Visual Studi 2022. Pero como se verá en clase, si funciona cuando se usa otro compilador.
    */

    char gameName[100];
    printf("Ingresa el nombre de un videojuego: ");
    gets(gameName);

    printf("El videojuego digitado es: %s", gameName);

    /*
     Como se ha visto, hemos usado scanf para obtener entrada de usuario.
     Se puede capturar los tipos de datos de C, pero no podemos capturar los tipos de datos definidos por el usuario.
     ¿Cómo resolvemos eso?
    */
    typedef struct student
    {
        char name[20];
        int age;
    } student;

    student myStudent;

    printf("Ingresa el nombre del estudiante: ");
    gets(myStudent.name);

    printf("Ingresa la edad del estudiante: ");
    scanf("%d", &myStudent.age);

    printf("Estudiante: %s\nEdad: %d\n", myStudent.name, myStudent.age);

    /*
     Como podemos ver, los tipos definidos poseen datos de C, por lo que podemos crear una variable con nuestro tipo de dato y con la notación "."
     podemos acceder a los datos, en el caso del nombre, no se hace fata usar "&", pero en el caso de la edad, sí y se debe poner al incio,
     justo como se muestra en el ejemplo. Con esto, se cubre el capturar la entrada del usuario incluso con datos definidos por el usuario.
    */

    return 0;
}