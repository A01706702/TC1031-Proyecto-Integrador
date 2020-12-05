#include <iostream>
#include <cstring>
#include "ftree.h"
#include <fstream>

using namespace std;

int opcion;

///////////dividir string//////////////////////
string substring(string s, int start, int end){
	string ss = "";
	for(int i = start; i < end; i ++ )
		ss += s[i];
	return ss;
}

vector<string> split(string s, string delimiter){
	vector<string> v;
	int pos = 0;
	int n = delimiter.size();
	int last = -n;
	while((pos = s.find(delimiter, last + n)) != string::npos){
		v.push_back(substring(s, last + n, pos));
		last = pos;
	}
	string fin = substring(s, last + n, s.size());
	if(fin != "")
		v.push_back(fin);
	return v;
}

/////////////////print vecotres////////////////////////
void print_string_vector(vector<string> v, string separator){
	for(int i = 0; i < v.size(); i++){
		cout << v[i];
		if(i != v.size() - 1)
			cout << separator;
	}
}

void print_int_vector(vector<int> v, string separator){
	for(int i = 0; i < v.size(); i++){
		cout << v[i];
		if(i != v.size() - 1)
			cout << separator;
	}
}

//////////////info de archivo////////////////////////
vector<int> read_file(string path){
	vector<int> v;
	ifstream file;
	file.open(path);
	//debería ser una unica linea
	while(!file.eof()){
		string line;
		getline(file, line);
		string trimmed = substring(line, 1, line.size() - 1);
		vector<string> splt = split(trimmed, ",");
		for(int i = 0; i < splt.size(); i ++){
			int n = stoi(splt[i], nullptr, 10);
			v.push_back(n);
		}
	}
	return v;
}

/////////////////////escribir en txt//////////////////////
void write_file(string out, string content){
	ofstream arch;
	arch.open(out);
	arch << content;
	arch.close();
}

int main(){
	vector<int> v = read_file("data2.txt");
	//objeto que recibe vector que contiene datos
    Ftree t(v);
    ofstream write;

    //menu de funciones
    //checar casos de prueba
    cout << "===== Bienvenido =====" << endl;
        while (opcion != 4){
            cout<<"\n";
            cout << "-Ver lista con cambios hechos(1)" << endl;
            cout << "-Sumar valores hasta... (2)" << endl;
            cout << "Agregar valor a indice... (3)" << endl;
            cout << "-Salir y serializar(4)" << endl;
            cout<< "-->";
            cin >> opcion;

    	//en esta parte aun no se limitan los inputs para que no sean string, por lo que si se pasa un string se loopea
            if (opcion==1){
				vector<int> reconstructed = t.reconstruct();
                print_int_vector(reconstructed, ",");
                cout<<"\n";
				// CASO DE PRUEBA:
				// si se manda a llamar antes que un add despliega los datos del txt sin modificar
				// si se manda a llamar despues de haber modificado el vector entonces muestra la lista con el valor de la suma modificado en ese indice.
				//original: vector<int> orig=[2,3,4,5];
				//orig.add(0,4);
				// si se le aplica reconstruct despues del add quedaría así:
				// orig=[6,3,4,5]
            }
            else if (opcion==2){
                int left, right;
                cout<<"escribe limite izquierdo: ";
                cin >> left;
                cout<<"escribe limite derecho: ";
                cin >> right;
                cout<<t.sum(left, right)<<endl;

                /*
        	    //caso de prueba 1
				//t.sum(0,5) devuelve 15, se suman 0+1+2+3+4+5

				//caso de prueba 2
				//t.sum(-3,4) devuelve 15, se suman 0+1+2+3+4 pero no debería introducir indices negativos porque no hay (NULL)
                */
            }
            else if (opcion==3){
                int index;
                cout<<"escribe un indice de 0 hasta "<<t.get_tree_size() - 1<<":"<<endl;
                cin >> index;
                int valor;
                cout<<"escribe el valor que quieres agregar: ";
                cin >> valor;
                t.add(index,valor);// se agrega conforme a los inputs
                cout<<"Se actualizo el indice "<<index<<" en "<<valor<<endl;
                /*
        	    // caso de prueba 4
				   t.add(0,2); // Actualiza el valor en indice 0 sumando 0+2
				   //para comprobar puede correr lo siguiente:
				   t.add(0,2);
				   vector<int> reconstructed = t.reconstruct();
                   print_int_vector(reconstructed, ",");
                   cout<<"\n";

				   //debería imprimirse: 2,1,2,3,4,5,6,7,8,9,10


                // caso de prueba 5
					t.add(-1,3); //no modifica nada porque el indice no existe
					// Esto se corrige agregando un whhile que no permita inputs menores a 0 o mayores a t.size()-1;

                */
            }
        }
		write_file("serialized.txt", t.format_tree());
        // se imprimen todas las sumas en un nuevo archivo de texto

    return 0;
}
