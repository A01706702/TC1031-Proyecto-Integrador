#include <iostream>
#include <cstring>
#include "graph.h"

using namespace std;

int opcion;

int main(){
    Graph<string> vg;
    ifstream archivo;
    ofstream write;
    info_archivo(vg);
    read_conections(vg); //se manda a llamar verarchivo que guarda las lineas del txt en el arbol
    //vinitree.escribir("newlist.txt"); //debería imprimirse los datos en el arbol, pero aún no se implementa la función de manera correcta

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
            //vinitree.find(cancionbuscada); //busqueda desde tree
            findSong(archivo,cancionbuscada);

            //La búsqueda se realiza en el archivo de texto porque aún no está implementado totalmente en el árbol.
            //Por eso mismo, si se agrega un elemento nuevo al árbol no se desplegará con el find

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
            vg.add_node(nuevacancion, artista, anio);// se agrega conforme a los inputs
            vg.escribir("canciones.txt");
            cout<<"\n";

    	    // en este caso se agrega una nueva cancion al árbol y se escribe toda la lista en el archivo de texto (aun falta escritura)

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