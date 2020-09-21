#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

//InfoArchivo
template <class T>
bool verArchivo(vector<T>& vinictor, string nombrearch) {
	ifstream arch(nombrearch);
	if (!arch) {
		cout << "No se encuentra el archivo: " << nombrearch << endl;
		return false;
	}
	string linea;
	while (getline(arch, linea)) { //saca una linea del archivo y lo guarda en string linea
		if (linea.size() > 0) {
			vinictor.push_back(linea);
		}
	}
	arch.close();
	return true;
}

//////////////// Ver lista //////////////
void vercancion(ifstream &archivo){
    string nombre, artista, anio;
    archivo.open("canciones.txt", ios::in);
    if(archivo.is_open()){
        archivo>>nombre;
        while(!archivo.eof()){ //mientras no sea el final del archivo
            archivo>>artista;
            archivo>>anio;
            cout<<nombre<<" "<<artista<<" "<<anio<<endl;
            cout<<" "<<endl;
            archivo>>nombre;
        }
        archivo.close();
    }
    else{
        cout<<"Error"<<endl;
    }
}

// buscar cancion
void buscarCancion(ifstream &archivo){
    archivo.open("canciones.txt", ios::in);
    string cancion, artista, anio, cancionbuscada;
    int aux = 0;
    cout<<"Cancion que quieres buscar: ";
    cin>>cancionbuscada;
    archivo>>cancion;
    while(!archivo.eof() && aux == 0){
        archivo>>artista;
        archivo>>anio;
        if(cancion == cancionbuscada){
            cout << "La cancion es: "<< endl;
            cout<<cancion<<" "<<artista<<" "<<anio<<endl;
			cout<<"\n";
            aux = 1;
        }
        archivo>>cancion;
    }
    archivo.close();
    if (aux == 0){
        cout << "La cancion no existe"<<endl;
		cout<<"\n";
    }
}
///////////////////CLASE SORTS///////////////////////
template <class T>
class Sorts{
private:
    void swap(vector<T>&, int, int);
	void copyArray(vector<T>&, vector<T>&, int, int);
	void mergeArray(vector<T>&, vector<T>&, int, int, int);
	void mergeSplit(vector<T>&, vector<T>&, int, int);
public:
    vector<T> mergeSort(vector<T>&);
};

//vinictor es el vector

//swap
template <class T>
void Sorts<T>::swap(vector<T> &vinictor, int i, int j) {
	T aux = vinictor[i];
	vinictor[i] = vinictor[j];
	vinictor[j] = aux;
}
//copyarray aux1
template <class T>
void Sorts<T>::copyArray(vector<T> &A, vector<T> &B, int low, int high) {

	for (int i = low; i <= high; i++) {
		A[i] = B[i];
	}
}
//mergearray aux2
template <class T>
void Sorts<T>::mergeArray(vector<T> &A, vector<T> &B, int low, int mid, int high) {
	int i, j, k;

	i = low;
	j = mid + 1;
	k = low;

	while (i <= mid &&j <= high) {
		if (A[i] < A[j]) {
			B[k] = A[i];
			i++;
		} else {
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (; j <= high; j++) {
			B[k++] = A[j];
		}
	} else {
		for (; i <= mid; i++) {
			B[k++] = A[i];
		}
	}
}
//mergesplit aux3
template <class T>
void Sorts<T>::mergeSplit(vector<T> &A, vector<T> &B, int low, int high) {
	int mid;

	if ( (high - low) < 1 ) {
		return;
	}
	mid = (high + low) / 2;
	mergeSplit(A, B, low, mid);
	mergeSplit(A, B, mid + 1, high);
	mergeArray(A, B, low, mid, high);
	copyArray(A, B, low, high);
}

//ordenaMerge
template <class T>
vector<T> Sorts<T>::mergeSort(vector<T> &vinictor) {
	vector<T> tmp(vinictor.size());
	mergeSplit(vinictor, tmp, 0, vinictor.size() - 1);
	return vinictor;
}

#endif
