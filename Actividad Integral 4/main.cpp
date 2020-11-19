#include <iostream>
#include <cstring>
#include "graph.h"

using namespace std;

int opcion;

int main(){
    Graph<string> vg;
    ifstream archivo;
    ofstream write;
    info_archivo(vg);//se manda a llamar info_archivo que guarda las lineas del txt en el grafo
    read_conections(vg);//read conections lee las relaciones entre los nodos (aristas) del csv. EN este caso las conexiones serían la playlist o cola de canciones en la que se encuentran

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

	//en esta parte aun no se limitan los inputs para que no sean string, por lo que si se pasa un string se loopea
        if (opcion==1){
            cout<<vg.print_nodes_list();
            cout<<"\n";
        }
        else if (opcion==2){
            string cancionbuscada;
            cout<<"Escribe la cancion que quieres buscar: ";
            cin>>cancionbuscada;
            vg.find(cancionbuscada); //busqueda desde grafo
            //findSong(archivo,cancionbuscada); //desde archivo

            /*
    	    //caso de prueba 1
    		vg.find(zombie) //deberia arrojar la cancion zombie de cranberries
    	    //caso de prueba 2
    		vg.find(cranberries) //arroja que no existe la cancion porque el criterio de busqueda es por nombre de las canciones
            //esto se puede mejorar fácil pues los datos tienen su vector respectivamente
    	    //caso de prueba 3
            vg.find(zombie cranberries 1993)
    		findSong(archivo, zombie cranberries 1993) //se loopean porque no entiende los espacios (se corregirá proximamente)
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
            vg.add_node(nuevacancion, artista, anio);// se agrega conforme a los inputs
            vg.escribir("canciones.txt");
            cout<<"\n";

    	    // en este caso se agrega una nueva cancion al graph y se escribe toda la lista en el archivo de texto

            /*
    	    // caso de prueba 4
    		vg.add_node(Dove Cymande) //se loopea por los espacios (se corregira)

            // caso de prueba 5
    		vg.add_node(Dove, Cymande, 2012) //se agrega correctamente
            */
        }

    }
    return 0;
}
