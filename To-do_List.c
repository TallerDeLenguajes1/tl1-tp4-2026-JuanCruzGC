//-----LIBRERIAS-----
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//-----ESTRUCTURAS-----
typedef struct Tarea{
    int tareaID;
    char *descripcion;
    int duracion
}Tarea;
typedef struct Nodo{
    Tarea T;
    Nodo *siguiente;
}Nodo;
//-----FUNCIONES-----


//-----MAIN-----
