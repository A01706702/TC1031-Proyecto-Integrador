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

    verArchivo(vinictor,"canciones.txt");

	cout << "===== Bienvenido =====" << endl;
    while (opcion != 4){
        cout << "-Ver lista(1)" << endl;
        cout << "-Ordenar lista(2)" << endl;
        cout << "-Buscar elemento (3)" << endl;
        cout << "-Salir(4)" << endl;
        cout<< "-->";
        cin >> opcion;

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
            buscarCancion(archivo);
        }
    }
}
