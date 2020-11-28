#include <iostream>
#include <string>
#include <fstream>
#include "ordenamiento.h"

using namespace std;


int opcion;
int main(){

    Sorts<string> sorts;
    vector<string> vinictor;
    ifstream archivo;
    ofstream write;

// se lee el archivo y se imprime en canciones.txt
    verArchivo(vinictor,"canciones.txt");

    //menu de funciones
    //es importante saber que el menú aún no esta listo, pues en ciertos casos el programa truena
    //checar casos de prueba
	cout << "===== Bienvenido =====" << endl;
    while (opcion != 4){
        cout << "-Ver lista(1)" << endl;
        cout << "-Ordenar lista(2)" << endl;
        cout << "-Buscar elemento (3)" << endl;
        cout << "-Salir(4)" << endl;
        cout<< "-->";
        cin >> opcion;

//en esta parte aun no se limitan los inputs para que no sean string, por lo que si se pasa un string se loopea
        if (opcion==1){
            vercancion(archivo);

        }
        else if (opcion==2){
			sorts.mergeSort(vinictor);
		    ofstream escribe("ordenadas.txt");
		    if(escribe.is_open()){
		        for (string & line: vinictor){
		            escribe<<line<<endl;
		        }
		        escribe.close();
		    }
			for (string & line : vinictor){
				cout<<line<<endl;
				cout<<"\n";
			}
        }
        else if (opcion==3){
            string cancionbuscada;
            cout<<"Escribe la cancion que quieres buscar: ";
            cin>>cancionbuscada;
            buscarCancion(archivo, cancionbuscada);
            // caso de prueba 1
            // buscarCancion(archivo, "time")
            // lo que devuelve es "La cancion es: time pinkfloyd 1973"

            // caso de prueba 2
            // buscarCancion(archivo, "pinkfloyd")
            // Imprime "La cancion no existe" porque el parámetro de busqueda es por cancion y no por artista

            // caso de prueba 3
            // buscarCancion(archivo, "time pinkfloyd")
            // se loopea porque no acepta espacios como input
        }
    }
    return 0;
}
