Actividad 2.1

insertion: Insertion es una funcion que agrega un elemento nuevo al final de una lista. Para hacer esto tiene que recorrer la lista completa
de inicio a fin, por lo que es una funcion de complejidad O(n).

search: Search es una funcion que recorre la lista en busca de un elemento en particular y al encontrarlo devuelve su posicion. En el peor
de sus casos esta funcion es 0(n) suponiendo que el elemento es el ultimo de la lista o el elemento no existe. En otros casos la funcion 
puede ser de log(n) y si el elemento es el primero en la lista es de O(1).

update: es una funcion que recorre la lista hasta llegar a una posicion de lista deseada y cambia el valor de dicho elemento. En el peor
de sus casos esta funcion es 0(n) suponiendo que el elemento es el ultimo de la lista. En otros casos la funcion puede ser de log(n) y si
el elemento es el primero en la lista es de O(1).

DeleteAT: Es una funcion que recibe una posicion en la lista y borra dicho elemento. Al igual que las otras dos, en el peor
de sus casos esta funcion es 0(n) suponiendo que el elemento es el ultimo de la lista. En otros casos la funcion puede ser de log(n) y si
el elemento es el primero en la lista es de O(1).
