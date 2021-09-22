*1er Seccion:
La linea de compilacion del TDA lista enlazada es gcc -g -O0 lista.c  main.c -o pruebas y la de ejecucion es ./pruebas.
-En la creacion de la lista se reserva memoria en el HEAP para la lista, con sus nodos apuntando a NULL, y la cantidad inicializada en 0. 
-Luego en insertar al final se reserva memoria para los nuevos nodos, en los cuales hay 3 casos en los que varia su implementacion. 
-En insertar en posicion se reserva memoria para el nuevo nodo y con un nodo auxiliar se recorre la lista para asi insertarlo en la posicion indicada.
-En lista_borrar se libera el ultimo nodo, para que luego nodo_fin apunte al predecesor.
-Lista_borrar_de_posicion libera el nodo en la posicion indicada, no sin antes apuntarlo con un nodo auxiliar, para asi apuntar con el anterior al siguiente del nodo a liberar.
-Lista_elemento_en_posicion recorre la lista y devuelve el elemento pedido.
-En lista_destruir recorro la lista liberando nodo por nodo.
-Luego creo el iterador externo reservando memoria en el HEAP, asignandole una lista y su nodo inicial.
-Y en el iterador interno recorro la lista hasta que la condicion se deje de cumplir, y devuelvo un contador de la cantidad de elementos recorridos.
*2da Seccion:
-Una lista basicamente es un conjunto de elementos. En nuestro caso es un conjunto de nodos, los cuales tienen un elemento y su enlace es simple ya que estos solo apuntan hacia una direccion. Se diferencia de la doblemente enlazada ya que los nodos tienen una referencia al anterior y al siguiente, lo que facilita su recorrido.
-Las pilas tambien son un conjunto ordenado de elementos los cuales tienen un tipo caracteristico de eliminacion denominado LIFO (Last in first out) en el cual el ultimo elemento en insertarse es el primero en salir, a este se lo denomina tope. Sus principales funciones son las de push (insertar) y pop (eliminar). Luego, las colas a diferencia de las pilas poseen 2 extremos, inicio y final, en los cuales su metodo de eliminacion es denominado FIFO (First in first out), en el que el primero que entra es el primero que sale. Sus principales funciones son las de encolar y desencolar.
-Un iterador es un tipo de dato abstracto utilizado para recorrer otros tipos de TDA. Un iterador interno permite recorrer todos los elementos de un tda sin tener que controlar el ciclo en el cual se recorre el mismo, a diferencia del iterador externo, que maneja la iteracion mediante sus propias primitivas.
