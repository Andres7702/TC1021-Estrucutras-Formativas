Actividad 3.3

add: 
la funcion add recorre el arbol hasta encontrar null para agregar un dato nuevo y luego aplica la funcion de splay. Agregar un nodo al arbol es 
de complejidad o(log n) y la funcion splay hace rotaciones para que el ultimo elemento agregado sea convierta en la raiz. Ambas funciones son de complejidad
o(log n).


remove:
La funcion remove recorre el arbol buscando al elemento que queremos eliminar y despues transforma el arbol completo con un proceso similar al splay.
esta funcion es de complejidad o(log n).


size:
size solo checa la variable del arbol que contiene el arbol y la regresa, por lo que es de complejidad o(1).


find:
find recorre el arbol buscando al elemento solicitado y despues le aplica un splay para que ese elemento se convierta en la riaz.
splay es una funcion de complejidad o(log n) y recorrer el arbol en busqueda de un elemento tambien es de complejidad o(log n), 
por lo que la funcion find  es de o(log n).
