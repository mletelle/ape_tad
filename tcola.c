#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tcola.h"
//TNodo va a ser los nodos contenidos en la "lista"
struct tNodo{
	int dato;
	/// Ponele que en una "lista" de 30, un nodo X está en la posicion 3
	/// con ese criterio determinamos la posicion de cada nodo en funcion de
	/// qElementos.
	int posNodo;
	NODO *sgte;
};
//TCola va a ser la "lista"
struct tCola{
	int qElementos;
	/// Los ultimos dos serian un puntero a estructura tNodo
	NODO ultimo;
	NODO inicio;
};
/// Modulo/s auxiliar/es (Desconozco si se pueden usar modulos auxiliares corrijanme si estoy mal chicos)
void asignar(NODO *C,int dato){
	/// Asigna memoria a un nodo y setea el sgte en NULL
	(*C) = malloc(sizeof(struct tNodo));
	(*C)->sgte = NULL;
	(*C)->dato = dato;
}
	
/// Implementacion de 3 funcionalidades provistas por el TAD

/* Agrega el elemento dato al final de la cola C. */
void encolar(COLA *C, int dato){
	if(vacia(*C) == 0){
		if((*C)->ultimo->sgte == NULL){
			asignar((*C)->ultimo->sgte,dato);
		}
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
