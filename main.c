#include <stdio.h>
#include <stdlib.h>
#include "tcola.h"

/*USANDO el TAD TCOLA, diseña e implementa una función llamada existe que reciba una cola C y un valor entero X,
y retorne la posición en la que se encuentra el elemento X. 
Ten en cuenta que el valor podría no existir, en cuyo caso la función debe retornar -1.*/
int existe(COLA *C, int x){
/* Avanza sobre la lista incrementando el iterado que determina la posicion del valor buscado x, si se encontro la variable encontrado cambia a verdadero y a retorno se le asigna la posicion donde
quedo el iterador, si no se encontro el valor x, el valor de retorno nunca cambia y la funcion retorna -1. 
Para encontrar el valor se recorre la lista desde el inicio, si se encontró termina de buscar.*/
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


int main() {
  return 0;
}
