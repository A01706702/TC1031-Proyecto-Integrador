//En esta entrega del proyecto integrador se implementaron las funciones agregar buscar y ver en una lista ligada
//Aun hay fallas, se mejorarán en las siguientes entregas
//para esta entrega se Agregaron los casos de prueba que faltaban y algunos comentarios sobre el código
#include <iostream>
#include <string>
#include <fstream> //para el manejo de archivos
#include "tree.h"

using namespace std;

int opcion;

int main(){
    SplayTree<string> vinitree;
    ifstream archivo;
    ofstream write;

    verArchivo(vinitree, "canciones.txt"); //se manda a llamar verarchivo que guarda las lineas del txt en una lista
    //vinitree.escribir("newlist.txt");
//menu de funciones
//es importante saber que el menú aún no esta listo, pues en ciertos casos el programa truena
//checar casos de prueba
cout << "===== Bienvenido =====" << endl;
    while (opcion != 4){
        cout << "-Ver lista(1)" << endl;
        cout << "-Buscar elemento (2)" << endl;
        cout << "Agregar elemento (3)" << endl;
        cout << "-Salir(4)" << endl;
        cout<< "-->";
        cin >> opcion;
	// while(opcion!=1 and opcion!=2 and opcion!=3 and opcion!=4){
	//     cout<<"Por favor ingrese 1, 2, 3 o 4: ";
	//     cin >> opcion;
    // }

	//en esta parte aun no se limitan los inputs para que no sean string, por lo que si se pasa un string se loopea
        if (opcion==1){
            //vinitree.inorder();
            cout<<vinitree.verlista();
            //cout<<vinitree.toString();
        }
        else if (opcion==2){
            string cancionbuscada;
            cout<<"Escribe la cancion que quieres buscar: ";
            cin>>cancionbuscada;
            //vinitree.find(cancionbuscada);
            findSong(archivo,cancionbuscada);
	    //caso de prueba 1
		//findSong(archivo, zombie) //deberia arrojar la cancion zombie de cranberries
	    //caso de prueba 2
		//findSong(archivo, cranberries) //arroja que no existe la cancion porque el criterio de busqueda es por nombre de las canciones
	    //caso de prueba 3
		//findSong(archivo, zombie cranberries 1993) //se loopea porque no entiende los espacios (se corregirá en la siguiente entrega)
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
            //vinitree.escribir("canciones.txt");

	    // en este caso se agrega una nueva cancion a la lista y se escribe toda la lista en un nuevo archivo de texto
	    // caso de prueba 4
		//vinitree.addSong(Dove_Cymande_2018) //agrega una cancion separada por _
	    //caso de pureba 5
		//vinitree.addSong(Dove Cymande) //se loopea por los espacios (se corregira)
        }

    }
    return 0;
}
//hacer el find pero con espacios
