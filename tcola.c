/// Idea inicial
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

