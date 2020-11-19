Actividad Integral 3 Árboles
===

Descripción
---

Este programa consiste en una lista de canciones o "playlist" que se encuentra en un archivo de texto con formato:  
**Canción Artista Año**

El programa tiene funciones que muestran la lista completa de las canciones tal como está. Además, permite la búsqueda de una canción en particular mediante el nombre de la cancion y muestra artista y año, así como agregar una canción a la lista y mostrarla en el archivo actualizado con la playlist actualizada.

Se utilizaron grafos para esta entrega. Para las relaciones entre los nodos del grafo se tiene un archivo csv que contiene pares de canciones que están en diferentes colas o listas de reproducción, por lo que habrá canciones que estén en varias colas.

Análisis de complejidad:
---

Para la búsqueda de las canciones se utilizó una búsqueda secuencial que va comparando cada elemento de un vector contra una entrada e itera de uno en uno, por lo que al ir recorriendo de uno en uno su complejidad es de O(n)

Para la función de agregar se va recorriendo el grafo uno por uno mediante un for, por lo que su complejidad es de O(n)

Cambios/Mejoras en esta entrega
---

Lo que principalmente se hizo fue comenzar a utilizar grafos y llenarlos con un archivo de texto y de ahí desarrollar las funciones básicas que se implementan como lectura y escritura de archivos, búsqueda e inserción. También se agregaron casos de prueba y casos donde falla el programa. El programa se mejorará para la última entrega, por lo que no es perfecto ahora
