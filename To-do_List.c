//-----LIBRERIAS-----
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//-----ESTRUCTURAS-----
typedef struct Tarea{
    int tareaID;
    char *descripcion;
    int duracion;
}Tarea;

typedef struct Nodo{
    Tarea T;
    struct Nodo* siguiente;
}Nodo;

//-----DECLARACION DE FUNCIONES-----
void crearTarea(Nodo** tareas);
void mostrarTareas(Nodo* tareas);
//-----MAIN-----
int main(){
    srand(time(NULL));
    Nodo* pendientes;
    //Nodo* completadas;
    pendientes=NULL;
    //completadas=NULL;
    crearTarea(&pendientes);
    mostrarTareas(pendientes);
    return 0;
}
//-----DEFINICION DE FUNCIONES-----
void crearTarea(Nodo** tareas){
    char descr[100];
    int i=0;
    if(*tareas==NULL){
        Nodo* aux;
        aux=(Nodo*)malloc(sizeof(Nodo));
        aux->siguiente=NULL;
        aux->T.tareaID=1001;
        aux->T.duracion=10+rand()%(91);
        printf("Ingrese una descripcion de la tarea\n");
        gets(descr);
        aux->T.descripcion=(char*)malloc(sizeof(char)*strlen(descr));   
        strcpy(aux->T.descripcion,descr);
        (*tareas)=aux;
    }else{
        Nodo* aux;
        aux=(Nodo*)malloc(sizeof(Nodo));
        aux->siguiente=*tareas;
        aux->T.tareaID=(*tareas)->T.tareaID+1;
        aux->T.duracion=10+rand()%(91);
        printf("Ingrese una descripcion de la tarea\n");
        gets(descr);
        aux->T.descripcion=(char*)malloc(sizeof(char)*strlen(descr)); 
        strcpy(aux->T.descripcion,descr);
        (*tareas)=aux;
    }
}

void mostrarTareas(Nodo* tareas){
    Nodo* aux;
    aux=tareas->siguiente;
    printf("-----TAREAS PENDIENTES-----\n");
    while(tareas!=NULL){
        printf("id: %d\n",tareas->T.tareaID);
        printf("Descripcion: %s",tareas->T.descripcion);
        printf("\nDuracion: %d\n",tareas->T.duracion);
        tareas=aux;
        aux=tareas->siguiente;
    }
}

/*
typedef struct Tarea{
    int tareaID;
    char *descripcion;
    int duracion;
}Tarea;

typedef struct Nodo{
    Tarea T;
    struct Nodo* siguiente;
}Nodo;
*/