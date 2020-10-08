#include <iostream>
#include <string>
#include <fstream>
#include "list.h"

using namespace std;

int opcion;
int main(){
    List<string> vinilist;
    ifstream archivo;
    ofstream write;

    verArchivo(vinilist, "canciones.txt");



	cout << "===== Bienvenido =====" << endl;
    while (opcion != 4){
        cout << "-Ver lista(1)" << endl;
        cout << "-Buscar elemento (2)" << endl;
        cout << "Agregar elemento (3)" << endl;
        cout << "-Salir(4)" << endl;
        cout<< "-->";
        cin >> opcion;

        if (opcion==1){
            vinilist.verlista();
        }
        else if (opcion==2){
            string cancionbuscada;
            cout<<"Escribe la cancion que quieres buscar: ";
            cin>>cancionbuscada;
            findSong(archivo, cancionbuscada);
        }
        else if (opcion==3){
            string nuevacancion;
            cout<<"Escribe la cancion que quieres agregar: ";
            cin>>nuevacancion;
            vinilist.addSong(nuevacancion);
            vinilist.escribir("newlist.txt");
        }
        else if (opcion==5){

        }
    }
    return 0;
}
//hacer el find pero con espacios
