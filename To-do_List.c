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
void marcarCompletada(Nodo** pendientes,Nodo** completada, int id);
//-----MAIN-----
int main(){
    srand(time(NULL));
    Nodo* pendientes;
    Nodo* completadas;
    pendientes=NULL;
    completadas=NULL;
    int respuesta=1,id;
    while(respuesta==1){
        crearTarea(&pendientes);
        printf("Desea agregar otra tarea?   1:Si\n");
        scanf("%d",&respuesta);
        while(getchar()!='\n');
    }
    printf("-----Pendientes-----\n");
    mostrarTareas(pendientes);
    printf("-----Completadas-----\n");
    mostrarTareas(completadas);
    printf("Ingrese el ID de la tarea para marcar como completa\n");
    scanf("%d",&id);
    marcarCompletada(&pendientes,&completadas,id);
    printf("-----Pendientes-----\n");
    mostrarTareas(pendientes);
    printf("-----Completadas-----\n");
    mostrarTareas(completadas);
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
        aux->T.descripcion=(char*)malloc(sizeof(char)*strlen(descr)+1);   
        strcpy(aux->T.descripcion,descr);
        (*tareas)=aux;
    }else{
        Nodo* aux;
        aux=(Nodo*)malloc(sizeof(Nodo));
        aux->siguiente=*tareas;
        aux->T.tareaID=((*tareas)->T.tareaID)+1;
        aux->T.duracion=10+rand()%(91);
        printf("Ingrese una descripcion de la tarea\n");
        gets(descr);
        aux->T.descripcion=(char*)malloc(sizeof(char)*strlen(descr)+1); 
        strcpy(aux->T.descripcion,descr);
        (*tareas)=aux;
    }
}

void mostrarTareas(Nodo* tareas){
    while(tareas!=NULL){
        printf("--ID: %d\n",tareas->T.tareaID);
        printf("Descripcion: %s",tareas->T.descripcion);
        printf("\nDuracion: %d\n",tareas->T.duracion);
        tareas=tareas->siguiente;
    }
}

void marcarCompletada(Nodo** pendientes,Nodo** completada,int id){
    Nodo* aux1;
    Nodo* aux2;
    aux1=*pendientes;
    aux2=aux1->siguiente;
    int seEncontro;
    seEncontro=0;
    //Caso especial, la lista de pendientes solo tiene 1 o 0 elementos
    if(aux2==NULL){
        if(aux1->T.tareaID==id){
            Nodo* aux3;
            aux3=*completada;
            *completada=aux1;
            *pendientes=aux2;
            aux1=aux3;
            seEncontro=1;
        }else{
            if(aux1==NULL){
                printf("La lista esta vacía...\n");
            }
        }
    }else{
        while(aux2!=NULL && seEncontro==0){
            if(aux2->T.tareaID==id){
                Nodo* aux3;
                aux3=*completada;
                *completada=aux2;
                aux1->siguiente=aux2->siguiente;
                aux2->siguiente=aux3;
                seEncontro=1;
            }
            aux1=aux2;
            aux2=aux1->siguiente;
        }
    }
    if(seEncontro==1)   printf("El nodo se movio a tareas completadas correctamente\n");
    else    printf("No se encontraron tareas con ese id...\n");
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