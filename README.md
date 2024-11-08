<em> # Actividad Práctica Entregable N° 4 - Grupal </em>Actividad Práctica Entregable N° 4 - Grupal

## Tipo de Datos Abstractos (TAD)

### Objetivos
- Implementar el TAD **TCOLA** a partir de una especificación dada, utilizando las estrategias de **RP** y las estructuras de datos trabajadas en el curso.
- Resolver un problema **USANDO** el TAD TCOLA.
- Reflexionar sobre la forma de trabajo que se propone a través del uso de TADs, en comparación a cómo se trabajó hasta este tema.



### Preguntas y Tareas

1. **Estructura de Datos**
   - ¿Qué estructura de datos propondrían para que el tiempo de ejecución de los algoritmos `longitud`, `encolar` y `desencolar` sea O(1)?
     - **Propuesta**: Utilizar una **lista enlazada** con punteros al inicio y al final, junto con un entero `qElementos`.

2. **Funcionalidades del TAD**
   - Implementar, usando la estructura de datos propuesta, al menos **3 funcionalidades** provistas por el TAD.

3. **Determinación de Elementos**
   - Si la especificación de la interfaz del TAD TCOLA no incluye la funcionalidad `longitud`, ¿pueden determinar la cantidad de elementos de la cola usando el resto de las funcionalidades? Diseñe la solución propuesta asumiendo el rol de usuario del TAD.

4. **Función `existe`**
   - **USANDO** el TAD TCOLA, diseña e implementa una función llamada `existe` que reciba una cola `C` y un valor entero `X`, y retorne la posición del elemento `X`. Si el valor no existe, la función debe retornar `-1`.

5. **Reflexión sobre el Uso de TADs**
   - ¿En qué aspectos la forma de trabajo con TADs “mejora” o “facilita” la resolución de problemas usando algoritmos en comparación a lo que hemos trabajado hasta ahora?

---

### Consignas

- a) ¿Qué estructura de datos propondrían para que el tiempo de ejecución de los algoritmos `longitud`, `encolar` y `desencolar` sea O(1)?
- b) Se pide que implementes, usando la estructura de datos propuesta en el inciso a), al menos 3 de las funcionalidades provistas por el TAD.
- c) Si la especificación de la interfaz del TAD TCOLA no cuenta con la funcionalidad `longitud`, ¿podrían determinar la cantidad de elementos de la cola usando el resto de las funcionalidades? Diseñe la solución propuesta, asumiendo el rol de usuario del TAD.
- d) **USANDO** el TAD TCOLA, diseña e implementa una función llamada `existe` que reciba una cola `C` y un valor entero `X`, y retorne la posición en la que se encuentra el elemento `X`. Ten en cuenta que el valor podría no existir, en cuyo caso la función debe retornar `-1`.
- e) ¿En qué aspectos la forma de trabajo con TADs “mejora” o “facilita” la resolución de problemas usando algoritmos que trabajamos hasta el momento?
