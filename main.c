#include <stdio.h>
#include <stdlib.h>
#include "tcola.h"


//PROTOTIPOS
/*USANDO el TAD TCOLA, diseña e implementa una función llamada existe que reciba una cola C y un valor entero X,
y retorne la posición en la que se encuentra el elemento X. Ten en cuenta que el valor podría no existir, en cuyo caso la función debe retornar -1.*/
int existe(COLA C, int x);
/* Si la especificación de la interfaz del TAD TCOLA no cuenta con la funcionalidad longitud
Diseño de la solucion propuesta, asumiendo el rol de usuario del TAD*/
int longitud2(COLA *C);


//PROGRAMA PRINCIPAL
int main() {
  int dato, primero,desencolado,qElem,pos,elem,posicion;
  //declarar cola
  COLA cola;
  //crear e inicializar cola
  cola = crear();
  //encolar un dato
  scanf("%d",&dato);
  encolar(&cola, dato);
  //ver el primer elemento de la cola sin desencolarlo
  primero = verPrimero(cola);
  //desencolar el primer elemento
  desencolar(&cola, &desencolado);  
  //longitud de la cola
  qElem = longitud(cola);
  qElem = longitud2(cola);
  // Copiar el contenido de cola1 a cola2
  COLA cola1 = crear();
  COLA cola2 = crear();
  copiar(&cola1, cola2);
  //llevar un elemento al frente
  scanf("%d",&pos);
  llevarAlFrente(&cola1, pos);//lleva el elemento en la posicion pos al frente
  //usar existe para buscar el elemento elem en la cola
  scanf("%d",&elem);
  posicion = existe(cola, elem);
  return 0;
}

//IMPLEMENTACIONES
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

int longitud2(COLA *C) {
/*Se crea aux para almacenar temporalmente los elementos. Usamos desencolar la cola principal y encolar en aux mientras incrementamos contador.
Volvemos a mover todos los elementos de aux a C, dejando la cola en su estado original. Retornamos el valor del iterador*/
    COLA aux = crear();//crea una cola auxiliar
    int elemento;
    int contador = 0;//inicializar el contador
    while (!vacia(*C)) {//mientras la cola no este vacia
        desencolar(C, &elemento);//desencolar elemento
        encolar(&aux, elemento); //encolarlo en la cola auxiliar
        contador++;//incrementar contador
    }
    //restaurar la cola original desde la auxiliar
    while (!vacia(aux)) {
        desencolar(&aux, &elemento);
        encolar(C, elemento);
    }
    return contador;
}


