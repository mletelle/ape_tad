
# Actividad Práctica Entregable N° 2  

## Tipo de Datos Abstractos (TAD)
Es una descripción matemática de un objeto no definido nativamente por el lenguaje, que se caracteriza por las operaciones que se pueden realizar sobre él. 
Aunque los problemas básicos pueden resolverse con estructuras simples como variables y arreglos, otros problemas complejos, requieren modelar estructuras que escapan a las predefinidas en el lenguaje. Estas estructuras separan el código en dos partes diferentes:
- Una parte es la especificación que escribe el programador
- Otra la interfaz que puede utilizar el usuario.

	![tad_user_prog](https://github.com/user-attachments/assets/119f29ef-3559-4510-8902-ca01d3d7c47f)

En el presente trabajo, asumimos el rol de las dos partes, implementándolo y utilizándolo para gestionar una cola de enteros.

## Objetivos
- Implementar el TAD **TCOLA** a partir de una especificación dada, utilizando las estrategias de **RP** y las estructuras de datos trabajadas en el curso.
- Resolver un problema **USANDO** el TAD TCOLA.
- Reflexionar sobre la forma de trabajo que se propone a través del uso de TADs, en comparación a cómo se trabajó hasta este tema.

## TAD COLA
Una Cola es una estructura de datos tipo FIFO (First In, First Out), donde el primer elemento en entrar es el primero en salir, como en un consultorio médico. Frecuentemente, se utiliza como un almacenamiento temporal que conserva el orden de llegada de los elementos hasta que puedan ser procesados. Al igual que la pila, la cola es un subtipo de lista.

Nuestro TAD posee las siguientes operaciones según la definicion de su interfaz:
![ape2-tad_cola drawio](https://github.com/user-attachments/assets/c610e678-c357-4d8e-b280-e4541872dbdd)


## Consignas

### a) ¿Qué estructura de datos propondrían para que el tiempo de ejecución de los algoritmos `longitud`, `encolar` y `desencolar` sea O(1)?

Estructura Propuesta:
- tNodo: modelo para los nodos de la cola, cada uno con un campo `dato` y un puntero `sgte` que enlaza al siguiente nodo en la cola.
````c copy
typedef struct tNodo {
	    int dato;
	    struct tNodo *sgte;
} tNodo;
````

- tCola: será nuestro tipo exportado, representa la "locomotora" que controla el acceso y operaciones en la lista de nodos, con tres campos:
	- qElementos: contador que mantiene el número de elementos en la cola.
	- primerNodo: puntero al primer nodo (frente de la cola).
	- ultimoNodo: puntero al último nodo (final de la cola).

```c copy
typedef struct tCola {
	    int qElementos;
	    tNodo *primerNodo;
	    tNodo *ultimoNodo;
} tCola;
```

> Obtenible desde [el repositorio de GitHub](https://github.com/mletelle/ape_tad/blob/main/tcola.c)	

De este modo obtenemos los siguientes tiempos de ejecución:
 - `longitud`: se accede al valor contenido en el contador `qElementos`, tiempo `O(1).`  
 - `encolar`: inserta un nuevo nodo al final de la lista, actualiza el puntero ultimoNodo, incrementa `qElementos`, tiempo `O(1).`  
 - `desencolar`: elimina el primer nodo, actualiza el primer elemento de la cola, disminuye `qElementos`, tiempo `O(1).`

El tipo `tCola` es exportado en el archivo de cabecera como `typedef struct tCola *COLA`, permitiendo al usuario trabajar este tipo de dato exportado  `COLA` sin acceder a su estructura interna.

Esta implementación puede entenderse más fácilmente con la siguiente representación gráfica:
![ape2-tcola drawio](https://github.com/user-attachments/assets/d3d06c77-eda5-4af7-9861-5c79ce5e341b)


### b) Se pide que implementes, usando la estructura de datos propuesta en el inciso a), al menos 3 de las funcionalidades provistas por el TAD.
> Obtenible desde [el repositorio de GitHub](https://github.com/mletelle/ape_tad/blob/main/tcola.c)

#### Función crear:
Esta función crea una cola vacía, inicializando los punteros primerNodo y ultimoNodo a NULL y estableciendo la cantidad de elementos qElementos en 0.
- Datos de entrada: Ninguno.
- Precondición: Ninguna.
- Datos de salida: Una cola vacía.
- Postcondición: La cola es inicializada.

![ape2-crear drawio](https://github.com/user-attachments/assets/05d45a8d-079b-4562-92ad-021d36d46d98)


#### Función vacia:
Verifica si la cola ha sido creada o si está vacía. Retorna 1 si primerNodo apunta a NULL (indicando una cola vacía o aún no creada), y 0 si contiene elementos.
- Datos de entrada: Una cola C.
- Precondición: Ninguna.
- Datos de salida: cVacia de tipo entero.
- Postcondición: Retorna 1 si la cola está vacía, 0 si no lo está.

![ape2-vacia drawio](https://github.com/user-attachments/assets/ae15025f-1f52-459f-b81c-ee253a1b487d)


#### Procedimiento encolar:
Agrega un nuevo nodo al final de la cola, almacenando en él el valor dato.Si la cola estaba vacía, tanto primerNodo como ultimoNodo apuntarán al nuevo nodo. 
Si la cola no estaba vacía, ultimoNodo se actualizará para apuntar al nuevo nodo.
- Datos de entrada: cola C y dato de tipo entero.
- Precondición:Ninguna.
- Datos de salida: cola C modificada.
- Postcondición: El contador qElementos aumenta en 1.

![ape2-encolar drawio](https://github.com/user-attachments/assets/4ce2615c-6f43-4732-8a90-cdf4126dbec6)


#### Procedimiento desencolar:
Elimina el primer nodo de la cola y almacena su valor en la variable apuntada por desencolado.
El primer nodo es eliminado de la cola. Si había más de un elemento, primerNodo se actualiza para apuntar al siguiente nodo.Si este era el único nodo, primerNodo y ultimoNodo se asignan a NULL, indicando una cola vacía.
- Datos de entrada:cola C y *desencolado de tipo entero
- Precondición: La cola no debe estar vacía.
- Datos de salida: *desencolado de tipo entero
- Postcondición: qElementos disminuye en 1.

![ape2-desencolar drawio](https://github.com/user-attachments/assets/8145f7b8-c95b-4779-933d-3c8d6b4ed1a9)


#### Procedimiento verPrimero
Retorna el dato del primer elemento de la cola sin modificarla.
- Datos de entrada: cola C.
- Precondición: La cola no debe estar vacía.
- Datos de salida: retorno de tipo entero.
- Postcondición: Retorna el valor almacenado en el primer nodo de la cola sin modificar la estructura de la misma.

![ape2-verPrimero drawio](https://github.com/user-attachments/assets/acd644ff-cabe-4837-b698-d84dbca3d394)


#### Función longitud
Retorna la cantidad de elementos en la cola, usando qElementos que lleva un contador de los nodos en la cola.
- Datos de entrada: Una cola C.
- Precondición: Ninguna.
- Datos de salida: qElementos de tipo entero.
- Postcondición: Retorna el valor del contador qElementos que indica la cantidad de elementos en la cola.

![ape2-longitud drawio](https://github.com/user-attachments/assets/09addef6-96b8-428d-a7b6-4e2751a09e12)


#### Procedimiento copiar
Copia los elementos de la cola C2 a la cola C1, manteniendo el orden de los elementos.
- Datos de entrada: *C1 y C2 de tipo cola
- Precondición: Ninguna.
- Datos de salida:*C1 de tipo cola
- Postcondición: C1=C2

![ape2-copiar drawio](https://github.com/user-attachments/assets/052af17d-c108-486f-9501-5e5d02684dd2)

#### Procedimiento: llevarAlFrente
Mueve el nodo en la posición posX al frente de la cola C1, dejando los otros nodos en el mismo orden.
- Datos de entrada:*C1 de tipo cola, posX de tipo entero
- Precondición: posX debe ser una posición válida en la cola
- Datos de salida: *C1 de tipo cola
- Postcondición: El nodo en la posición posX es movido al frente de la cola.

![ape2-llevarAlFrente drawio](https://github.com/user-attachments/assets/0e43d63e-c0ea-4c0f-b7b9-4ca4525255fd)


> Obtenible desde [el repositorio de GitHub](https://github.com/mletelle/ape_tad/blob/main/tcola.c)

### c) Si la especificación de la interfaz del `TAD TCOLA` no cuenta con la funcionalidad `longitud`, ¿podrían determinar la cantidad de elementos de la cola usando el resto de las funcionalidades? Diseñe la solución propuesta, asumiendo el rol de usuario del TAD.

Presentamos **dos** ideas para este problema:

1. Implementación de una función para calcular la longitud de la cola, dentro archivo principal, sin usar `longitud` del TAD:

Creando una cola auxiliar, y mediante las operaciones `desencolar` y `encolar` contamos los elementos. Ya que desencola cada elemento de la cola original, incrementando un contador y almacenando temporalmente los elementos en una cola auxiliar. Por lo que la cantidad de elementos, es la cantidad de veces que se pudo `desencolar`.
````c copy
while (!vacia(*C)) {
        desencolar(C, &elemento);
        encolar(&aux, elemento);
        contador++;
    }
````

Posteriormente, restaura los elementos a la cola original desde la cola auxiliar, preservando el orden original de los elementos y manteniendo la cola en su estado inicial. Al finalizar retorna el valor contenido en el contador.
````c copy
while (!vacia(aux)) {
        desencolar(&aux, &elemento);
        encolar(C, elemento);
    }
````
La ventaja de este método es que permite contar la cantidad de elementos de una cola con elementos. El problema es que tiene un tiempo de ejecución `O(n)` debido al desencolado y reencolado de todos los elementos de la cola. 

> Obtenible desde [el repositorio de GitHub](https://github.com/mletelle/ape_tad/blob/main/main.c)

2. Otra forma de calcular la longitud sin utilizar la función específica del TAD es usar una variable contadora en el programa principal. De la siguiente manera:
- Iniciamos una variable contadora de elementos en el programa principal en 0. 
- Incrementamos el contador con cada operación de encolar. 
- Decrementamos el contador con cada operación de desencolar.

De este modo, el contador refleja la cantidad total de elementos de la cola en tiempo constante, `O(1)`, proporcionando el tamaño de la cola sin necesidad de invocar funciones. El problema es que solo funciona cuando se crea una cola vacía desde el inicio de ejecución del programa. 

| Función  | Variable contadora  |
|--|--|
| Utiliza desencolar y encolar con una COLA auxiliar. | Mantiene un contador de elementos. |
|Permite contar elementos en una cola con datos existentes.| Sólo funciona si la cola se inicia vacía y se usa desde el inicio.|
|Debe procesar todos los elementos de la cola.| No depende del tamaño de la cola.|
|O(n)|O(1)|

#### d) **USANDO** el `TAD TCOLA`, diseña e implementa una función llamada `existe` que reciba una cola `C` y un valor entero `X`, y retorne la posición en la que se encuentra el elemento `X`. Ten en cuenta que el valor podría no existir, en cuyo caso la función debe retornar `-1`.

![ape2-existe drawio](https://github.com/user-attachments/assets/4bd83309-6f4e-43be-aa6e-b89358a1c456)

#### Funcion existe: 
Nuestro diseño de `existe` emplea una lógica simila a la utilizada en el punto anterior: 
- Crea una cola auxiliar para almacenar temporalmente los elementos de la cola principal,
- Cuando desencola un elemento 
	- Incrementa un iterador
	- Verifica si coincide con x. 

La principal diferencia con `longitud` del punto *c)* se encuentra en lo siguiente:
- Si encuentra el valor, asigna la posicion según el valor del iterador.
- Si no encuentra el elemento, no se modifica la variable de retorno, por lo que devuelve `-1`.
````c copy
    if (elemento == x) {
            encontrado = 1;
            posicion = i;
        }
````
Luego, restaura la cola a su estado original encolando los elementos desde la cola auxiliar. Al finalizar la funcion, la cola original queda de la misma manera que cuando fue invocada. 

Datos de Entrada:
- COLA *C: Un puntero a una estructura de cola.
- X: entero.
  
Precondiciones:
- Ninguna
  
Datos de Salida:
- La función devuelve la posición (entero)
  
Postcondiciones:
- Si el valor X se encuentra en uno de los nodos de la cola, la función retorna el número de la posición de dicho valor. `posición`>0
- Si el valor X no se encuentra en la cola, la función retorna -1.


> Obtenible desde [el repositorio de GitHub](https://github.com/mletelle/ape_tad/blob/main/main.c)

### e) ¿En qué aspectos la forma de trabajo con TADs `mejora` o `facilita` la resolución de problemas usando algoritmos que trabajamos hasta el momento?

Desde nuestra experiencia al estudiar y luego implementar esta APE TAD, encontramos las siguientes ventajas y desventajas:
#### Ventajas:

- El usuario no tiene que saber/aprender **CÓMO** funciona, sino **QUÉ** hace, ya que los TAD **ocultan** los detalles de implementación y el usuario interactúa sólo mediante una **interfaz**, a través de un conjunto de operaciones definidas, sin necesidad de conocer la estructura interna. Cualquier cambio en la implementacion es transparente para el usuario.
- Encontramos que son útiles para problemas de situaciones reales ya que pueden modelar situaciones más complejas que datos nativos del lenguaje.
- Si ya existe un TAD implementado, nos ahorra tiempo para manejar nuestra `COLA`, ya que de esta manera, sólo debemos `crear` la cola y suministrar un dato para `encolar`, y no debe diseñar desde 0 la estructura y cada una de las funciones.
- Si una persona no sabe programar, puede entender la lógica de mi algoritmo que emplea TAD, ya que reflejan claramente las acciones que realiza (como `verPrimero` o `encolar`), pero debe estar bien documentado y utilizar palabras descriptivas.
- Otro beneficio es que se puede usar un TAD **diseñado por otras personas**, como compañeros de curso o descargadas de Internet similar a si fueran bibliotecas.

#### Desventajas:
- El uso de TADs presenta un mayor nivel de **complejidad en el aprendizaje**, ya que requiere dominar no solo los conceptos básicos de programación como punteros, listas y pasaje de parámetros, sino también saber combinar esto con los TADs.
- Debido al encapsulamiento y dado que sólo podemos manipular la cola mediante las operaciones de la interfaz, encontramos dificultades a la hora de pensar como resolver las consignas dadas (por ejemplo, al implementar `existe`). Pensamos en primera instancia en recorrer la lista, pero no es posible dado que, desde el `main.c` somos usuarios del TAD y no conocemos como está este implementado. Al final optamos por utilizar la funciones de la interfaz `encolar` y `desencolar` para lograr solucionar el problema. 
- Otra complicación que encontramos fue tener que usar tres archivos, lo cual no fue soportado nativamente por el programa Zinjai, teniendo que utilizar otras alternativas como [onlinegdb](https://www.onlinegdb.com/online_c_compiler#).
- Un problema que planteamos como grupo va relacionado con uno de los beneficios, si podemos usar el TAD de otra persona, éste tiene que estar bien documentado y explicado. Es posible no entender la lógica de quien lo programó (sin saber la implementación), esto depende de que el programador del TAD haya hecho una clara interfaz y una solida documentación.

### Uso y funcionamiento:
Las funciones implementadas pueden ser observadas en la siguiente imagen del programa que utiliza los demas archivos del repositorio:

![image](https://github.com/user-attachments/assets/5bfb1102-36d6-406a-b75f-f4589e2e058e)

Habiendo encolado 6 elementos (1,2,3,4,5,6) se observa que devuelve el valor correcto:

![image](https://github.com/user-attachments/assets/428f0e6b-6674-4bee-90bd-3c401ce110ae)


Se consulta por el valor del primer elemento, y devuelve el resultado esperado:

![image](https://github.com/user-attachments/assets/78c001e6-1c34-44ff-aad0-2d42346eca81)


Se consulta si el elemento 3 existe en la cola y muestra el resultado esperado:

![image](https://github.com/user-attachments/assets/70959f90-19c7-452a-a13b-092ffbf22fc6)


Se desencola el primer elemento:

![image](https://github.com/user-attachments/assets/0ae9da95-500c-4887-ac85-e1cf959ac359)


Si se inserta una opcion no valida, el programa lo indica:

![image](https://github.com/user-attachments/assets/2e3ba573-84a6-48f1-b5b1-0dd88e1444c6)


## Bibliografia

- Aho, A. V., Hopcroft, J. E., & Ullman, J. D. (1988). Estructuras de Datos y Algoritmos. Addison-Wesley Publishing Company.
- Arriondo, R., Bottazzi, C., Costarelli, S., D’Elía, J., Dalcin, L., Galizzi, D., Giménez, J. M., Olivera, J., Novara, P., Paz, R., Prigioni, J., Pucheta, M., Rojas Fredini, P. S., Romeo, L., Sánchez, I., Storti, M., Tessi, G., & Vidocevich, J. P. (2023). Algoritmos y Estructuras de Datos (Versión AED-2.0.5-1584-gdfa537f7). Facultad de Ingeniería y Ciencias Hídricas, Universidad Nacional del Litoral, Centro de Investigación de Métodos Computacionales (CIMEC, CONICET-UNL). Recuperado de https://cimec.org.ar/~mstorti/aed/aednotes.pdf
- Dasso, A., & Funes, A. (2014). Tipos de Datos Abstractos. Área de Programación y Metodologías de Desarrollo del Software, Departamento de Informática, Facultad de Ciencias Físico-Matemáticas y Naturales, Universidad Nacional de San Luis, Argentina.
- Hernández, R., Lázaro, J. C., Dormido, R., & Ros, S. (2001). Estructuras de Datos y Algoritmos. Prentice Hall.
- Joyanes Aguilar. (2001). Fundamentos de Programación: Algoritmos, estructura de datos y objetos (4.a ed.). McGraw Hill. Capítulos 15-18.
- Knuth, D. E. (1981). The Art of Computer Programming. Addison-Wesley.
- Universidad de la República (UDELAR). (2009). Clase 8 - Tecnólogo Informático - Estructura de Datos y Algoritmos. Recuperado de https://www.fing.edu.uy/tecnoinf/mvd/cursos/eda/material/teo/anterior/7-EDA-teo.pdf.
- Sznajdleder, P. A. (2021). Algorítmos a fondo con aplicaciones en C y Java. Capítulo 9.

