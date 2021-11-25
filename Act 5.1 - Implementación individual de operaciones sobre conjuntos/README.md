# Put
Put recorre la tabla hash en busqueda de un espacio vacio para agregar un nuevo elemento. En su mejor caso 
no tiene que recorrer la tabla y lo inserta en el primer espacio disponible, en su peor caso tiene que
recorrer toda la tabla por lo que su complejidad es de o(n).

# Get 
Get consulta el index de la llave solicitada y despues usa ese index para obtener un valor de la tabla de 
values. Como solo es una consulta su complejidad es de o(1).
