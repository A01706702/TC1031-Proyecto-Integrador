#include <iostream>
#include <cstring>
#include "ftree.h"

using namespace std;

int opcion;

int main(){

    //int src[] = {5,2,9,-3,5,20,10,-7,2,3,-4,0,-2,15,5};

    int src[15];
    info_archi(src);

    //
    vector<int> arr;
    for (int i: src) {
        arr.push_back(i);
    }
    Ftree t(arr);
    //t.print_array();

    ofstream write;

    //menu de funciones
    //checar casos de prueba
    cout << "===== Bienvenido =====" << endl;
        while (opcion != 4){
            cout<<"\n";
            cout << "-Ver lista(1)" << endl;
            cout << "-Sumar valores hasta... (2)" << endl;
            cout << "Agregar valor a indice... (3)" << endl;
            cout << "-Salir(4)" << endl;
            cout<< "-->";
            cin >> opcion;

    	//en esta parte aun no se limitan los inputs para que no sean string, por lo que si se pasa un string se loopea
            if (opcion==1){
                // cout<<arr[2];
                info_archivo();
                cout<<"\n";
            }
            else if (opcion==2){
                int opc;
                cout << "desde 0 hasta index (1)"<< endl;
                cout << "desde index hasta index (2)"<< endl;
                cout<< "-->";
                cin >> opc;
                if(opc == 1){
                    int index;
                    cout<<"escribe un indice de 0 hasta 15: ";
                    cin >> index;
                    t.sum(index);
                    t.print_array();
                }
                else if (opc ==2){
                    int left, right;
                    cout<<"escribe limite izquierdo: ";
                    cin >> left;
                    cout<<"escribe limite derecho: ";
                    cin >> right;
                    cout<<t.sum(left, right)<<endl;
                    t.print_array();
                    cout<<"\n";
                }

                /*
        	    //caso de prueba 1

                */
            }
            else if (opcion==3){
                int index;
                cout<<"escribe un indice de 0 hasta 15: ";
                cin >> index;
                int valor;
                cout<<"escribe el valor que quieres agregar: ";
                cin >> valor;
                t.add(index,valor);// se agrega conforme a los inputs
                cout<<"Se actualizo la lista\n"<<endl;
                t.print_array();
                /*
        	    // caso de prueba 4


                // caso de prueba 5

                */
            }
        }
        t.escribir("newdata.txt");
        // se imprimen todas las sumas en un nuevo archivo de texto

    return 0;
}
