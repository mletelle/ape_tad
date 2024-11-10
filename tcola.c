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
	if(C!=NULL){
		cVacia = 0;
	}
	return cVacia;
}

void asignar(tNodo **nodo, int dato){
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
        // Cola vacia, primerNodo y ultimoNodo apuntan al nuevo nodo
        C->primerNodo = nuevoNodo;
        C->ultimoNodo = nuevoNodo;
    }else{
        //Cola no vacia, enlaza el ultimo nodo al nuevo y actualiza ultimoNodo
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

/* Retorna recursivamente la cantidad de elementos de la cola C. */
int longitud(tCola *C) {//recibe el Tipo Exportado
    return C->qElementos;//retorna lo almacenado en el campo qelementos(0(1))
}

/*USANDO el TAD TCOLA, diseña e implementa una función llamada existe que reciba una cola C y un valor entero X, 
y retorne la posición en la que se encuentra el elemento X. Ten en cuenta que el valor podría no existir, en cuyo caso la función debe retornar -1.
*/
int existe(COLA *C, int x){
/// Avanza sobre la lista sumando un valor I que determina la posicion del valor buscado 'x', si se encontró la variable encontrado cambia a verdadero y retorno obtiene la "posicion" dónde
/// quedó I, si no se encontró el valor de "retorno" nunca cambia y la funcion retorna -1. Para encontrar el valor se recorre la lista de inicio a fin para encontrar el valor 'x', si se encontró 
/// termina de buscar.
	int retorno = -1;
	int encontrado = 0;
	int i = 1;
	tNodo aux = C->primerNodo;
	while(aux != NULL && encontrado != 1){
		if(aux->dato == dato){
		   encontrado = 1;
		   retorno = i;
		}

		i++;
	 	aux = aux->sgte;
	}
	return retorno;
}


/// Modulo/s auxiliar/es
//Si, existe algo llamado funciones privadas segun bibliografia, es decir, funciones ocultas al usuario pero que se usan en el tad, lindas para mdularizar
//Se pueden usar todos los modulos auxiliares que consideremos necesarios para implementar las funciones del TAD


