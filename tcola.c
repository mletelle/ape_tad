#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tcola.h"

//TNodo modela los nodos contenidos en la "lista"
typedef struct tNodo {
	    int dato;
	    struct tNodo *sgte;//puntero al siguiente nodo
}tNodo;

//TCola va a ser el tipo de dato exportado del TAD
typedef struct tCola {
//resuelto como el parcial
	    int qElementos;//cantidad de elementos en la cola
	    tNodo *primerNodo;//puntero al primer nodo (frente de la cola)
	    tNodo *ultimoNodo;//puntero al último nodo (final de la cola)
}tCola;

// Implementacion de funcionalidades provistas por el TAD(y las auxiliares necesarias)
//Funciones publicas y privadas del TAD

COLA crear() {
// Crea una cola vacía. Inicializa la estructura de cola con inicio y último apuntando a NULL,
//y establece qElementos en 0 
	COLA colaVacia = (COLA) malloc(sizeof(tCola)); //asignar memoria 
//inicializar los valores de la cola
	colaVacia->primerNodo = NULL;
	colaVacia->ultimoNodo = NULL;
	colaVacia->qElementos = 0;//la cola empieza vacía
	return colaVacia;//retorna el puntero a la cola inicializada
}

int vacia(COLA C){
/* Indica si la cola C está vacía, en cuyo caso retorna 1, 0 en otro caso. */
	int cVacia = 1;
	if(C->primerNodo!=NULL){
		cVacia = 0;
	}
	return cVacia;
}

void asignar(tNodo **nodo, int dato){
//Auxiliar de encolar
// Asigna memoria a un nodo e ingresa el dato en el campo "dato" de la estructura tNodo, además setea el siguiente de
// del nodo en NULL (Utilizado para encolar al final)
	*nodo = malloc(sizeof(tNodo));
	(*nodo)->sgte = NULL;
	(*nodo)->dato = dato;
}

void encolar(COLA *C, int dato) {
/* Agrega el elemento dato al final de la cola C. */
// Entra TipoExportado y se invoca funcion auxiliar con *ultimoNodo
	tNodo *nuevoNodo;
	asignar(&nuevoNodo, dato);
	if(vacia(*C)){
        //si la cola esta vacia primerNodo y ultimoNodo apuntan al nuevo nodo
        	(*C)->primerNodo = nuevoNodo;
		(*C)->ultimoNodo = nuevoNodo;
    	}else{
        //si la cola no esta vacia, linkea el ultimo nodo al nuevo y actualiza ultimoNodo
       		(*C)->ultimoNodo->sgte = nuevoNodo;
        	(*C)->ultimoNodo = nuevoNodo;
    	}    
	(*C)->qElementos++; //incrementa la cantidad de elementos en la cola
}

/* Desencola el primer elemento de la cola C y lo retorna en el parámetro desencolado.
La cantidad de elementos de la cola C disminuye en 1.
Pre-condición: cola no vacía*/
void desencolar(COLA *C, int* desencolado) {
    if ((*C)->primerNodo != NULL) {
        tNodo *temp = (*C)->primerNodo;//se guarda el nodo a desencolar
        *desencolado = temp->dato;//el dato del primer nodo se asigna a desencolado
        (*C)->primerNodo = (*C)->primerNodo->sgte;//actualiza el primer nodo a su siguiente nodo
	    
	    if ((*C)->primerNodo == NULL) { //si despues de desencolar la cola queda vacía, se actualiza el ultimo nodo a NULL
            (*C)->ultimoNodo = NULL;
        }
        free(temp);//libera la memoria del nodo desencolado
        (*C)->qElementos--;//disminuye la cantidad de elementos en la cola
    }
}

/* Recupera el valor del dato que está al frente de la cola, sin desencolarlo.
Pre-condición: cola no vacía*/
int verPrimero(COLA C) {
	int retorno = -1; //
	if ((*C).primerNodo != NULL) {
	retorno = (*C).primerNodo->dato;// asigna el dato del primer nodo al retorno
	}
	return retorno;
}

/* Retorna la cantidad de elementos de la cola C. */
int longitud(COLA C) {//recibe el Tipo Exportado
    return (*C).qElementos;//retorna lo almacenado en el campo qelementos
}

/* Copia el contenido de C2 a C1. */
void copiar(COLA *C1, COLA C2) {
	COLA nuevaCola = crear(); //crea una nueva cola para almacenar la copia
	tNodo* aux = (*C2).primerNodo;//declara un nodo auxiliar y le asigna el primer nodo de la cola
	while (aux != NULL) { //iterar sobre los elementos de C2 y encolarlos en la nuevacola
		encolar(&nuevaCola, aux->dato);
		aux= aux->sgte;
	}
	*C1=nuevaCola;//asignar la nuevacola a C1
}

/*ubica en el frente de la cola C1 al elemento que se encuentra en la posicion posX.
posX es una posicion valida en C1, comprendida entre 1 y la cantidad de elementos de la cola C1*/
void llevarAlFrente(COLA *C1, int posX) {
	if (!vacia(*C1)){
		tNodo *actual = (*C1)->primerNodo;
		tNodo *anterior = NULL;
		int i = 1;//iterador
		while (i < posX) {//recorrer la lista hasta llegar al nodo en posX
			anterior = actual;
			actual = actual->sgte;
			i++;
		}
		if (actual != NULL && actual->sgte != NULL) {//si el nodo a mover no es el ultimo 
			if (anterior != NULL) {// si no es el primero, mover el nodo de la posición posX
				anterior->sgte = actual->sgte;
			}
			actual->sgte = (*C1)->primerNodo;//mover el nodo al frente
			(*C1)->primerNodo = actual;
		}
		if (actual->sgte==NULL) {//si el nodo movido era el último, actualizamos el último nodo
			tNodo *aux = NULL;
			aux = (*C1)->ultimoNodo;
			(*C1)->ultimoNodo = (*C1)->primerNodo;
			(*C1)->primerNodo = aux;
		}
	}
}
