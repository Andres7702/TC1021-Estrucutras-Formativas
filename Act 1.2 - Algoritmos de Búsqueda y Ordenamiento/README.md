NOTA: No pude hacer el Merge Sort, pero mi Busqueda Binaria y Sequencial si sirven. Como el main utiliza Merge Sort para acomodar el vector antes de utilizar estas funciones, aparecera que no sirven. Porfavor utilizen otro tipo de Sort en esa parte para que vean que si sirven.

ordenaSeleccion: Este Sort es de tipo O(n^2). Esto se debe princiaplmente a que hay un ciclo for dentro de otro ciclo for.

BubbleSort: Al igual que el SelectSort este igual es de tipo O(n^2), igualmente por el ciclo for doble.

MergeSort: Este es de tipo O(n log(n)). Utiliza mucho espacio en memoria ya que crea copias del mismo arreglo utilizando recursion. Aunque ocupe mucha memoria utiliza operaciones simples en todo momento

Busqueda sequencial: Este es de tipo O(n) en el peor de los casos. El programa solo recorre el array en busqueda de un elemento en particular, por lo que la longitud del array es lo que dicta cuantas operaciones se van a realizar.

Busqueda Binaria: Este es de tipo O(log(n)) ya que el array se "divide" entre 2 cada vez que el programa esta buscando al elemento en particualr. Haciendo que el numero de operaciones totales sea mucho menor a la longitud del array.
