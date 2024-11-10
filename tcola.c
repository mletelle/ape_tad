#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tcola.h"

//TNodo va a modelar los nodos contenidos en la "lista"
typedef struct tNodo {
	    int dato;
	    struct tNodo *sgte;  // Puntero al siguiente nodo
} tNodo;

//TCola va a ser la "locomotora de la lista", el tipo de dato exportado del TAD
typedef struct tCola {
//resuelto como el parcial
	    int qElementos;       // Cantidad de elementos en la cola
	    tNodo *primerNodo;        // Puntero al primer nodo (frente de la cola)
	    tNodo *ultimoNodo;        // Puntero al último nodo (final de la cola)
} tCola;

// Implementacion de 3 funcionalidades provistas por el TAD(y las auxiliares necesarias)
//Funciones publicas y privadas del TAD

COLA crear() {
// Crea una cola vacía. Inicializa la estructura de cola con inicio y último apuntando a NULL,
//y establece qElementos en 0 
// Deberia asignarle memoria con malloc al puntero que sea crea? No, el puntero es una variable simple
	COLA colaVacia;// Aquí no se usa malloc, es una variable local de tipo COLA
// Inicializa los valores de la cola
	colaVacia.inicio = NULL;// No hay nodos en la cola
	colaVacia.ultimo = NULL;
	colaVacia.qElementos = 0;// La cola empieza vacía
	return colaVacia;// Retorna la cola inicializada
}

int vacia(COLA C){
/* Indica si la cola C está vacía, en cuyo caso retorna 1, 0 en otro caso. */
	int cVacia = 1;
	if(C.primerNodo!=NULL){
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
	if(vacia(C)){
        	//si la cola esta vacia primerNodo y ultimoNodo apuntan al nuevo nodo
        	C->primerNodo = nuevoNodo;
        	C->ultimoNodo = nuevoNodo;
    	}else{
        //si la cola no esta vacia, linkea el ultimo nodo al nuevo y actualiza ultimoNodo
       		C->ultimoNodo->sgte = nuevoNodo;
        	C->ultimoNodo = nuevoNodo;
    	}    
	C->qElementos++; // Incrementa la cantidad de elementos en la cola
}

/* Desencola el primer elemento de la cola C y lo retorna en el parámetro desencolado.
La cantidad de elementos de la cola C disminuye en 1.
Pre-condición: cola no vacía*/
void desencolar(COLA *C, int* desencolado) {
    if (C->primerNodo != NULL) {
        tNodo *temp = C->primerNodo;//se guarda el nodo a desencolar
        *desencolado = temp->dato;//el dato del primer nodo se asigna a desencolado
        C->primerNodo = C->primerNodo->sgte;//actualiza el primer nodo a su siguiente nodo
	    
	    if (C->primerNodo == NULL) { // Si después de desencolar la cola queda vacía, se actualiza el último nodo a NULL
            C->ultimoNodo = NULL;
        }
        free(temp); // Libera la memoria del nodo desencolado
        C->qElementos--; // Disminuye la cantidad de elementos en la cola
    }
}

/* Recupera el valor del dato que está al frente de la cola, sin desencolarlo.
Pre-condición: cola no vacía*/
int verPrimero(COLA C) {
	int retorno = -1; //esto nunca debe retornarse según la pre-condicion
	if (C.primerNodo != NULL) {
	retorno = C.primerNodo->dato;// asigna el dato del primer nodo al retorno
	}
	return retorno;
}

/* Retorna recursivamente la cantidad de elementos de la cola C. */
int longitud(Cola *C) {//recibe el Tipo Exportado
    return C->qElementos;//retorna lo almacenado en el campo qelementos(0(1))
}

/* Copia el contenido de C2 a C1. */
void copiar(COLA *C1, COLA C2) {
	COLA nuevaCola = crear(); //crea una nueva cola para almacenar la copia
	tNodo* aux = C2.primerNodo;//declara un nodo auxiliar y le asigna el primer nodo de la cola
	while (aux != NULL) { //iterar sobre los elementos de C2 y encolarlos en la nuevacola
		encolar(&nuevaCola, aux->dato);
		aux= aux->sgte;
	}
	*C1=nuevaCola;//asignar la nuevacola a C1
}

/*ubica en el frente de la cola C1 al elemento que se encuentra en la posicion posX.
posX es una posicion valida en C1, comprendida entre 1 y la cantidad de elementos de la cola C1*/
void llevarAlFrente(COLA *C1, int posX) {
	tNodo *actual = C1->primerNodo;
	tNodo *anterior = NULL;
	int i = 1;
	while (i < posX) {//recorrer la lista hasta llegar al nodo en posX
		anterior = actual;
		actual = actual->sgte;
		i++;
	}
	if (actual != NULL && actual->sgte != NULL) {//si el nodo a mover no es el ultimo
		if (anterior != NULL) {//mover el nodo de la posición posX
			anterior->sgte = actual->sgte;
		}
		actual->sgte = C1->primerNodo;//mover el nodo al frente
		C1->primerNodo = actual;
	}
	if (actual->sgte==NULL) {//si el nodo movido era el último, actualizamos el último nodo
		tNodo *aux = NULL;
		aux = C1->ultimoNodo;
		C1->ultimoNodo = C1->primerNodo;
		C1->primerNodo = aux;
	}
}
