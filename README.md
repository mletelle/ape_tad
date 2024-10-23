# Actividad Práctica Entregable N° 4 - Grupal

## Tipo de Datos Abstractos (TAD)

### Objetivos
- Realizar una implementación del TAD TCOLA a partir de una especificación dada, utilizando las estrategias de RP y las estructuras de datos trabajadas en el curso.
- Resolver un problema **USANDO** el TAD TCOLA.
- Reflexionar sobre la forma de trabajo que se propone a través del uso de TADs, en comparación a cómo se trabajó hasta este tema.

### Preguntas y Tareas

1. **Estructura de Datos**
   - ¿Qué estructura de datos propondrían de manera que el tiempo de ejecución de los algoritmos: `longitud`, `encolar` y `desencolar` sea O(1)?
     - **Propuesta**: Lista enlazada, puntero al inicio, al final y un entero `qElementos`.

2. **Funcionalidades del TAD**
   - Se pide que implementes, usando la estructura de datos propuesta, al menos 3 de las funcionalidades provistas por el TAD.

3. **Determinación de Elementos**
   - Si la especificación de la interfaz del TAD TCOLA no contara con la funcionalidad `longitud`, ¿podrían determinar la cantidad de elementos de la cola usando el resto de las funcionalidades? Diseñe la solución propuesta, asumiendo el rol de usuario del TAD.

4. **Función `existe`**
   - **USANDO** el TAD TCOLA, diseña e implementa una función llamada `existe` (en un programa que USE el TCOLA), que recibe una cola `C` y un valor entero `X`, y retorna la posición en la que se encuentra el elemento `X`. Ten en cuenta que el valor podría no existir, en cuyo caso la función debe retornar `-1`.

5. **Reflexión sobre el Uso de TADs**
   - La forma de trabajo con TAD, ¿en qué aspectos “mejora”/“facilita” la forma de resolver problemas usando algoritmos que trabajamos hasta el momento?
