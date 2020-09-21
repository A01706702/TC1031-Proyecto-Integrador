Actividad Integral 1 Conceptos Básicos y Algoritmos Fundamentales
===

Descripción
---

Este programa consiste en una lista de canciones o "playlist" que se encuentra en un archivo de texto con formato:  
**Canción Artista Año**

El programa tiene funciones que muestran la lista completa de las canciones tal como está. Además, ordena la playlist según en nombre de la canción y en orden alfabético siguiendo el formato ASCII y muestra la lista ya ordenada. También permite la búsqueda de una canción en particular mediante el nombre de la cancion y muestra artista y año.

***Nota:*** Es importante saber que el archivo de texto auxiliar, en este caso "ordenadas.txt" está vacío porque es donde se sobreescribe la lista de las canciones una vez que se hayan ordenado.

Análisis de complejidad:
---

Para realizar el ordenamiento se utilizó el argoritmo merge Sort, por lo que su complejidad es de O(n log(n)) para el peor de los casos, porque va recorriendo en el vector dividiendo en subgrupos, hasta comparar grupos lo más pequeño posibles. Entonces va iterando en las ramas de un árbol.

Para la búsqueda de las canciones se utilizó una búsqueda secuencial que va comparando cada elemento contra una entrada, por lo que al ir recorriendo de uno en uno su complejidad es de O(n)
