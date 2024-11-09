#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tcola.h"

//TNodo va a modelar los nodos contenidos en la "lista"
typedef struct tNodo {
    int dato;
//quito posnodo segun visto correccion de parcial
/// Pero según la correccion del parcial, al que le corrigieron no puso posNodo como una posicion individual de cada nodo
/// puso la cantidad de nodos total en cada nodo, es decir, puso la cantidad de elementos en su totalidad en cada nodo
    struct tNodo *sgte;  // Puntero al siguiente nodo
} tNodo;

//TCola va a ser la "locomotora de la lista", el tipo de dato exportado del TAD
typedef struct tCola {
//resuelto como el parcial
    int qElementos;       // Cantidad de elementos en la cola
    tNodo *primerNodo;        // Puntero al primer nodo (frente de la cola)
    tNodo *ultimoNodo;        // Puntero al último nodo (final de la cola)
} tCola;

// Implementacion de 3 funcionalidades provistas por el TAD
//Funciones publicas del TAD

COLA crear() {
    /* Crea una cola vacía. Inicializa la estructura de cola con inicio y último apuntando a NULL,
       y establece qElementos en 0 */
/// Deberia asignarle memoria con malloc al puntero que sea crea?
    COLA colaVacia;
    colaVacia.inicio = NULL;// No hay nodos en la cola
    colaVacia.ultimo = NULL;
    colaVacia.qElementos = 0;// La cola empieza vacía
    return colaVacia;// Retorna la cola inicializada
}

void encolar(COLA *C, int dato){
/* Agrega el elemento dato al final de la cola C. */
/// Suponiendo que entra *ultimoNodo
	if(vacia((*C)) == 0){
	   asignar((*C)->sgte,dato)
	   
	
	}
}
//REVISAR LA NECESIDAD DE ASIGNAR TENIENDO ENCOLAR,SE COMBINAN?
/// Considero que deberia mantenerse, porque si fuera todo parte de un mismo quedaría (*C)->sgte->sgte para setear el siguiente del nuevo nodo, y según "las buenas practicas de programacion"
/// no deberia haber un puntero que haga "sgte->sgte", cito: "(...)chicos no hagan(no me gusta) que la lista sea el siguiente del siguiente del siguiente..."

void asignar(NODO *C,int dato){
// Asigna memoria a un nodo e ingresa el dato en el campo "dato" de la estructura tNodo, además setea el siguiente de
// del nodo en NULL (Utilizado para encolar al final, modificar en caso de querer usarlo para otro modulo)
	(*C) = malloc(sizeof(struct tNodo));
	(*C)->sgte = NULL;
	(*C)->dato = dato;
}

	
int vacia(COLA C){
/* Indica si la cola C está vacía, en cuyo caso retorna 1, 0 en otro caso. */
	int cVacia = 1;
	if(C != NULL){
		cVacia = 0;
	}
	return cVacia;
}
/*
USANDO el TAD TCOLA, diseña e implementa una función llamada existe que reciba una cola C y un valor entero X, 
y retorne la posición en la que se encuentra el elemento X. Ten en cuenta que el valor podría no existir, en cuyo caso la función debe retornar -1.
*/


/// Modulo/s auxiliar/es
//Si, existe algo llamado funciones privadas segun bibliografia, es decir, funciones ocultas al usuario pero que se usan en el tad, lindas para mdularizar
//Se pueden usar todos los modulos auxiliares que consideremos necesarios para implementar las funciones del TAD


