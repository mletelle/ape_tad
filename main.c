#include <stdio.h>
#include <stdlib.h>
#include "tcola.h"

/*USANDO el TAD TCOLA, diseña e implementa una función llamada existe que reciba una cola C y un valor entero X,
y retorne la posición en la que se encuentra el elemento X. Ten en cuenta que el valor podría no existir, en cuyo caso la función debe retornar -1.*/
int existe(COLA C, int x){
/*Usa una cola auxiliar para almacenar temporalmente los elementos de la cola mientras los desencola y verifica si coinciden con x. 
Si encuentra el valor, asigna la posicion actual del iterador; luego, restaura la cola a su estado original encolando los elementos desde aux.*/
    int posicion=-1;//si no existe el elemento
    int encontrado=0;//variable de estado
    int i = 1;//iterador, refleja la posicion a retornar en caso de existir
    int elemento;//almacena el elemento desencolado temporalmente
    COLA aux = crear();//cola auxiliar para almacenar elementos temporalmente

    while (!vacia(C) && encontrado==0) {//mientras la cola no este vacia y el elemento no haya sido encontrado
        desencolar(&C, &elemento);//recuperamos el elemento
        if (elemento == x) {//si el elemento coincide con x
            encontrado = 1;//para finalizar la iteracion
            posicion = i;//asignar el valor del iterador a la variable que se retorna
        }
        encolar(&aux, elemento);//encolar el elemento en la cola auxiliar para guardarlo temporalmente
        i++;
    }
    while (!vacia(aux)) {//restaurar la cola original desde la auxiliar
        desencolar(&aux, &elemento);
        encolar(&C, elemento);
    }
    return posicion;//devuelve la posicion si encontro, o -1 si no
}



int main() {
  //declarar cola
  COLA cola;
  //crear e inicializar cola
  cola = crear();
  //encolar un dato
  int dato;
  scanf("%d",&dato);
  encolar(&cola, dato);
  //ver el primer elemento de la cola sin desencolarlo
  int primero = verPrimero(cola1);
  //desencolar el primer elemento
  int desencolado;
  desencolar(&cola1, &desencolado);  
  //longitud de la cola
  int len = longitud(cola1);
  // Copiar el contenido de cola1 a cola2
  COLA cola1 = crear();
  COLA cola2 = crear();
  copiar(&cola1, cola2);
  //llevar un elemento al frente
  llevarAlFrente(&cola1, 2);//lleva el elemento en la posicion 2 al frente
  //usar existe para buscar el elemento 2 en la cola
  int posicion = existe(cola, 2);
  return 0;
}
