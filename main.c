#include <stdio.h>
#include <stdlib.h>
#include "tcola.h"


//PROTOTIPOS
/*USANDO el TAD TCOLA, diseña e implementa una función llamada existe que reciba una cola C y un valor entero X,
y retorne la posición en la que se encuentra el elemento X. Ten en cuenta que el valor podría no existir, en cuyo caso la función debe retornar -1.*/
int existe(COLA C, int x);
/* Si la especificacion de la interfaz del TAD TCOLA no cuenta con la funcionalidad longitud
Diseño de la solucion propuesta, asumiendo el rol de usuario del TAD
Se emplea el nombre longitud2 para evitar problemas de definicion*/
int longitud2(COLA *C);


//PROGRAMA PRINCIPAL
int main() {
  int opcion, dato, primero, desencolado, qElem, elem, posicion;
  COLA cola = crear();//crear e inicializar la cola
  COLA cola1 = crear();//crear otra cola para usar en la funcion de copia
  do {
    printf("\nMENU\n");
    printf("1. Encolar un dato que se lee desde teclado\n");
    printf("2. Ver primer elemento en la cola\n");
    printf("3. Desencolar\n");
    printf("4. Ver longitud de la cola\n");
    printf("5. Copiar cola\n");
    printf("6. Llevar al frente un elemento en posicion X\n");
    printf("7. Buscar elemento en la cola (existe)\n");
    printf("8. Finalizar\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    switch (opcion) {
      case 1:
        printf("Ingrese el dato a encolar: ");
        scanf("%d", &dato);
        encolar(&cola, dato);
        break;
      case 2:
        if (!vacia(cola)) {
          primero = verPrimero(cola);
          printf("El primer elemento es: %d\n", primero);
        } else {
          printf("La cola esta vacia.\n");
        }
        break;
      case 3:
        if (!vacia(cola)) {
          desencolar(&cola, &desencolado);
          printf("Elemento desencolado: %d\n", desencolado);
        } else {
          printf("La cola esta vacia.\n");
        }
        break;
      case 4:
        qElem = longitud(cola);
        printf("La longitud de la cola es: %d\n", qElem);
        break;                
      case 5:
        copiar(&cola1, cola);
        printf("Contenido copiado.\n");
        break;
      case 6:
        printf("Ingrese la posicion del elemento a llevar primero: ");
        scanf("%d", &posicion);
        if (posicion > 0 && posicion <= longitud(cola)) {//verifica una posicion valida
          llevarAlFrente(&cola, posicion);
          printf("Elemento llevado al frente.\n");
        } else {
          qElem = longitud(cola);
          printf("Posicion no valida, intente con un valor entre 1 y %d.\n",qElem);
        }
        break;
      case 7:
        printf("Ingrese un elemento a buscar: ");
        scanf("%d", &elem);
        posicion = existe(cola, elem);
        if (posicion != -1) {
          printf("Elemento %d encontrado en la posicion: %d\n", elem, posicion);
        } else {
          printf("Elemento no encontrado en la cola.\n");
        }
        break;
      case 8:
        printf("Gracias por utilizar nuestro programa ;) \n");
        break;
      default:
        printf("Opcion no valida.\n");
        break;
      }
    } while (opcion != 8);
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


