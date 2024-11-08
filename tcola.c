#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tcola.h"
//TNodo va a ser los nodos contenidos en la "lista"
typedef struct tNodo {
    int dato;
//quito posnodo segun visto correccion de parcial
    struct tNodo *sgte;  // Puntero al siguiente nodo
} tNodo;

//TCola va a ser la "lista"
typedef struct tCola {
//resuelto como el parcial
    int qElementos;       // Cantidad de elementos en la cola
    tNodo *primerNodo;        // Puntero al primer nodo (frente de la cola)
    tNodo *ultimoNodo;        // Puntero al último nodo (final de la cola)
} tCola;
/// Modulo/s auxiliar/es
//Si, existe algo llamado funciones privadas segun bibliografia, es decir, funciones ocultas al usuario pero que se usan en el tad, lindas para mdularizar
//Se pueden usar todos los modulos auxiliares que consideremos necesarios para implementar las funciones del TAD
void asignar(NODO *C,int dato){
	/// Asigna memoria a un nodo e ingresa el dato en el campo "dato" de la estructura tNodo, además setea el siguiente de
	/// del nodo en NULL (Utilizado para encolar al final, modificar en caso de querer usarlo para otro modulo)
	(*C) = malloc(sizeof(struct tNodo));
	(*C)->sgte = NULL;
	(*C)->dato = dato;
}
	
/// Implementacion de 3 funcionalidades provistas por el TAD

 /*Creaunacolavacía.*/
//Inicializa la cola en "vacia", y qElementos en 0.
COLA crear(){
	//especificar
	return colaVacia;
}
/* Agrega el elemento dato al final de la cola C. */
void encolar(COLA *C, int dato){
	if(vacia(*C) == 0){
		asignar((*C)->ultimo->sgte,dato);
	}
}
	
/* Indica si la cola C está vacía, en cuyo caso retorna 1, 0 en otro caso. */
int vacia(COLA C){
	int cVacia = 1;
	if(C != NULL){
		cVacia = 0;
	}
	return cVacia;
}


