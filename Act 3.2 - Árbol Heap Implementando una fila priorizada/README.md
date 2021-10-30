Actividad de Estructuras Formativas 3.2 Arbol Heap Implementando una fila priorizada.

push
Esta funcion agrega un valor a al heap dependiendo de su prioridad. En el mejor de los casos es de complejidad O(1) cuando el valor nuevo pertenece a la
ultima posicion y en el peor de sus casos es de O(log n) cuando tiene que recorrer el arbol de abajo hasta arriba.

pop
La funcion pop en realidad solo regresa y elmina del heap el valor que esta en la posicion 0, pero ademas tambien manda a llamar a heapify. Heapify es
una funcion que organiza al arbol y es de complejidad O(log N). 

top
Solo regresa el valor del heap que esta en la posicion 0, por lo que la funcion es de O(1).


empty
Checa que la variable count sea mayor a 0 y regresa true o false dependiendo del resultado. Es de O(1).


size
regresa la variable count. Es de O(1).
