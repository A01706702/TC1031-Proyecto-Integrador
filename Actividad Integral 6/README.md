Actividad Integral 6 Estructura Extra 
===

Fenwick Tree (Binary Indexed Tree)
---

Descripción
---

Un arbol de Fenwick o Binary Indexed Tree es una estructura que permite hacer operaciones como el cálculo de la suma de un rango de números, pero sin tener que recorrer toda la estructura por lo que lo hace mucho más rapido. Consta de funciones como el add que realiza la suma hasta un indice mediante un arreglo modificado y recorriendo con índices en binario.
Un arbol de Fenwick funciona como si se tuvieran dos arreglos donde uno mantiene los valores originales y el segundo mantiene las sumas desde el primer índice hasta tal indice, por lo que es como si se dividiera el array en mitades para hacer las operaciones más sencillas; por eso se llama árbol porque al ir "dividiendo" el array queda como forma de árbol.

Análisis de Complejidad:
---

SUM:
- 

La función realiza una suma del valor de indice "i", después le resta el último bit de i invertido con complementos a 2 (toma el indice y compara los bits con su complemento a 2, después le resta ese valor al valor del indice. Tiene una complejidad de O(log(n)) porque va recorriendo el while

ADD:
- 

La función actualiza el valor en cierto indice y lo propaga a todo el arreglo, funciona mediante un while hasta el tamaño del arreglo y compara tambien los indices y su complemento a 2 pero ahora le suma eso al valor del indice original. Muchas veces no termina de propagarse a toda la lista porque no todos los elementos pueden considerarse padres y el array tendría que ser más grande. Tiene una complejidad de O(log(n))

Visualización:
---

En el siguiente link se puede visualizar el funcionamiento de un fenwick tree: https://visualgo.net/bn/fenwicktree
Es muy explícito que para realizar la suma no se tiene que recorrer todo el arreglo sino simplemente sumar el elemento anterior y por esto son muy útiles estas estructuras

Casos de Prueba:
---

Para opción 1 de menu:
- // CASO DE PRUEBA:
				// si se manda a llamar antes que un add despliega los datos del txt sin modificar
				// si se manda a llamar despues de haber modificado el vector entonces muestra la lista con el valor de la suma modificado en ese indice.
				//original: vector<int> orig=[2,3,4,5];
				//orig.add(0,4);
				// si se le aplica reconstruct despues del add quedaría así:
				// orig=[6,3,4,5]
  
Para opción 2 de menu:
- /*
        	    //caso de prueba 1
				//t.sum(0,5) devuelve 15, se suman 0+1+2+3+4+5

				//caso de prueba 2
				//t.sum(-3,4) devuelve 15, se suman 0+1+2+3+4 pero no debería introducir indices negativos porque no hay (NULL)
                */
                
Para opción 3 de menu:
- /*
        	    // caso de prueba 4
				   t.add(0,2); // Actualiza el valor en indice 0 sumando 0+2
				   //para comprobar puede correr lo siguiente:
				   t.add(0,2);
				   vector<int> reconstructed = t.reconstruct();
                   print_int_vector(reconstructed, ",");
                   cout<<"\n";

				   //debería imprimirse: 2,1,2,3,4,5,6,7,8,9,10


                // caso de prueba 5
					t.add(-1,3); //no modifica nada porque el indice no existe
					// Esto se corrige agregando un whhile que no permita inputs menores a 0 o mayores a t.size()-1;

                */
Para opción 4 de menu:
- Se debería salir del programa y actualizar el archivo con la lista serializada.
