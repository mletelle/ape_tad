#ifndef COLA_H_INCLUDE
#define COLA_H_INCLUDE

///Estructura planteada:
//typedef struct tNodo *NODO;
typedef struct tCola *COLA;// importa solo el Tipo exportado? o tmb el tipo de nodo? el user interactua solo con el TIPO EXPORTADO?

/* Crea una cola vacía. */
COLA crear();
/* Indica si la cola C está vacía, en cuyo caso retorna 1, 0 en otro caso. */
int vacia(COLA C);
/* Agrega el elemento dato al final de la cola C. */
void encolar(COLA *C, int dato);
/* Desencola el primer elemento de la cola C y lo retorna en el parámetro desencolado.
La cantidad de elementos de la cola C disminuye en 1.
Pre-condición: cola no vacía*/
void desencolar(COLA *C, int* desencolado);
/* Recupera el valor del dato que está al frente de la cola, sin desencolarlo. 
Pre-condición: cola no vacía*/
int verPrimero(COLA C);
/* Retorna la cantidad de elementos de la cola C. */
int longitud(COLA C);
/* Copia el contenido de *C1 a C2. */
void copiar(COLA *C1, COLA C2);
/*ubica en el frente de la cola C1 al elemento qué se encuentra en la posición posX.
posX es una posición valida en C1, comprendida entre 1 y la cantidad de elementos
de la cola C1*/
void llevarAlFrente(COLA *C1, int posX);

#endif
