Actividad Integral 2 Conceptos Básicos y Algoritmos Fundamentales
===

Correcciones
---

- Se agregaron casos de prueba y comentarios al código.
- Se arreglaron los errores de compilación.

Descripción
---

Este programa consiste en una lista de canciones o "playlist" que se encuentra en un archivo de texto con formato:  
**Canción Artista Año**

El programa tiene funciones que muestran la lista completa de las canciones tal como está. Además, permite la búsqueda de una canción en particular mediante el nombre de la cancion y muestra artista y año, así como agregar una canción a la lista y mostrarla en un archivo de texto nuevo con la playlist actualizada.

***Nota:*** Es importante saber que el archivo de texto auxiliar, en este caso "newlist.txt" empieza vacío porque es donde se sobreescribe la lista de las canciones una vez que se hayan ordenado.

Análisis de complejidad:
---

Para la búsqueda de las canciones se utilizó una búsqueda secuencial que va comparando cada elemento contra una entrada, por lo que al ir recorriendo de uno en uno su complejidad es de O(n)

Para la función de agregar se va recorriendo la lista uno por uno por lo que su complejidad es de O(n)

Cambios/Mejoras en esta entrega
---

Lo que principalmente se hizo fue dejar de utilizar vector para utilizar listas ligadas y de ahí desarrollar las funciones básicas de CRUD. también se agregaron casos de prueba y casos donde falla el programa. El programa se irá mejorando en cada entrega, por lo que no es perfecto ahora
