#include <stdio.h>
#include <stdlib.h>
#include "tcola.h"

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


int main() {
  return 0;
}
