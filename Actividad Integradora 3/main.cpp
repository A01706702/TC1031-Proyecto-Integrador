/* ** Jose Pablo Miranda Berumen
   ** A01706702
   ** 2/nov/2020
   ** Entrega 3 Proyecto integrador
*/

//En esta entrega del proyecto integrador se implementaron las funciones agregar buscar y ver en un arbol splay
//Aun hay fallas, se mejorarán en las siguientes entregas
//para esta entrega se Agregaron los casos de prueba que faltaban para la entrega 2 y algunos comentarios sobre el código y se cumple la competencia de implementación de un arbol, casos de prueba, lectura y escritura de archivos

#include <iostream>
#include <string>
#include <fstream> //para el manejo de archivos
#include "tree.h"

using namespace std;

int opcion;

int main(){
    SplayTree<string> vinitree;
    ifstream archivo;

    verArchivo(vinitree, "canciones.txt"); //se manda a llamar verarchivo que guarda las lineas del txt en el arbol
    vinitree.escribir("newlist.txt");
//menu de funciones
//es importante saber que el menú aún no esta listo, pues en ciertos casos el programa truena
//checar casos de prueba

cout << "===== Bienvenido =====" << endl;
    while (opcion != 4){
        cout << "-Ver Arbol(1)" << endl;
        cout << "-Buscar elemento (2)" << endl;
        cout << "Agregar elemento (3)" << endl;
        cout << "-Salir(4)" << endl;
        cout<< "-->";
        //cout<<vinitree.inorder();
        cin >> opcion;

	//en esta parte aun no se limitan los inputs para que no sean string, por lo que si se pasa un string se loopea
        if (opcion==1){
            cout<<vinitree.verlista();
        }
        else if (opcion==2){
            string cancionbuscada;
            cout<<"Escribe la cancion que quieres buscar: ";
            cin>>cancionbuscada;
            //vinitree.find(cancionbuscada); // hacer busqueda desde tree
            findSong(archivo,cancionbuscada);

            /*
    	    //caso de prueba 1
    		findSong(archivo, zombie) //deberia arrojar la cancion zombie de cranberries
    	    //caso de prueba 2
    		findSong(archivo, cranberries) //arroja que no existe la cancion porque el criterio de busqueda es por nombre de las canciones
    	    //caso de prueba 3
    		findSong(archivo, zombie cranberries 1993) //se loopea porque no entiende los espacios (se corregirá en la siguiente entrega)
            */
        }
        else if (opcion==3){
            string nuevacancion;
            string artista;
            string anio;
            cout<<"Escribe el nombre de la cancion que quieres agregar (SIN ESPACIOS): ";
            cin>>nuevacancion;
            cout<<"Escribe el artista (SIN ESPACIOS): ";
            cin>>artista;
            cout<<"Escribe el anio: ";
            cin>>anio;
            vinitree.add(nuevacancion, artista, anio);// se agrega conforme a los inputs
            vinitree.escribir("newlist.txt");
            cout<<"Cancion Agregada!"<<endl;
            cout<<"\n";

    	    // en este caso se agrega una nueva cancion al árbol y se escribe toda la lista en un archivo de texto

            /*
    	    // caso de prueba 4
    		vinitree.add(Dove_Cymande_2018) //agrega una cancion separada por _
    	    //caso de pureba 5
    		vinitree.add(Dove Cymande) //se loopea por los espacios (se corregira)
            */
        }

    }
    return 0;
}

// TO DO:
// hacer el find pero con espacios y en el arbol
// hacer find por rango (separar por objetos)
