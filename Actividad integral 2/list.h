#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <fstream>
#include <list>
#include <vector>

using namespace std;

template <class T> class List;
template <class T> class Artistas;
template <class T> class Anio;
template <class T> class Canciones;

//clase mayor
template <class T>
class Link {
private:
	Link(T);
	Link(T, Link<T>*);
	Link(const Link<T>&);
	T value;
	Link<T> *next;


	friend class List<T>;
	friend class Canciones<T>;
	friend class Artistas<T>;
	friend class Anio<T>;
};

//constructores:
template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}

template <class T>
Link<T>::Link(const Link<T> &source) : value(source.value), next(source.next) {}

////////////////////////////clase List////////////////////////////////////
template <class T>
class List {
public:
	List();
	List(const List<T>&);
	~List();

    void addFirst(T);
	void addSong(T);
    T findSong(T) const;
    void verlista();
	void escribir(string);

    std::string toString() const;
	bool empty() const;
	//std::string toString() const;
	void operator= (const List&);

private:
	Link<T> *head;
	int size;

};

//constructores
template <class T>
List<T>::List() : head(0), size(0) {}
//destructor
template <class T>
List<T>::~List() {
}

//////////////////////empty///////////////////////
template <class T>
bool List<T>::empty() const {
	return (head == 0);
}


/////////////////////toString/////////////////////////////

template <class T>
std::string List<T>::toString() const {
	std::stringstream aux;
	Link<T> *p;

	p = head;
	aux << "[";

	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

/////////////////add///////////////////////////////////////
template <class T>
void List<T>::addFirst(T val){
	Link<T> *newLink;
	newLink = new Link<T>(val);
	newLink->next = head;
	head = newLink;
	size++;
}

template <class T>
void List<T>::addSong(T val){
	Link<T> *newLink, *p;
	newLink = new Link<T>(val);
	if (empty()) {
		addFirst(val);
		return;
	}
	p = head;
	while (p->next != 0) {
		p = p->next;
	}
	newLink->next = 0;
	p->next = newLink;
	size++;
}

//////////////////////findSong////////////////////////////
template <class T>
T List<T>::findSong(T val) const {
	Link<T> *p;

	p = head;
    int index=0;
	while (p != 0) { //itera sobre la lista
		if (p->value == val) {//si el valor buscado es igual al de p actual
            cout<<"La cancion se encuentra en la lista: "<<"'"<<p->value<<"'"<<endl;//se imprime
            return "";
		}
		p = p->next;
        index++;
	}
    cout<<"la cancion no existe"<<endl;//si no es igual entonces no existe
	return "";
}


/////////////////////////infoarchivo////////////////////////////
template <class T>
bool verArchivo(List<T>& vinilist, string nombrearch) {
	ifstream arch(nombrearch);
	if (!arch) {
		cout << "No se encuentra el archivo: " << nombrearch << endl;
		return false; //si no está el archivo
	}
	string linea;
	while (getline(arch, linea)) { //saca una linea del archivo y lo guarda en string linea
		if (linea.size() > 0) {
			vinilist.addSong(linea);//agrega cada linea del txt como un objeto de la lista
		}
	}
	arch.close();
	return true;
}

/////////////////escribir/////////////////
template <class T>
void List<T>::escribir(string myfile){
	ofstream arch; //archivo en modo output
    arch.open (myfile);//abrir el archivo
	Link<T> *p;
    p = head;
	while (p != 0) {//iteramos sobre la lista
        arch<< p->value << endl;//para cada elemento sobre el que pasa se imprimirá en arch
		//cout<<"\n";
        p = p->next;
	}
    arch.close();// se cierra el archivo
}

//////////////// Ver canciones desde lista //////////////
template <class T>
void List<T>::verlista(){
    Link<T> *p;
    p = head;
	while (p != 0) {//itera
        cout<< p->value << endl;//en cada iteracion imprime el value de p
		cout<<"\n";
        p = p->next;
	}
}


/*
//////////////////////findSong////////////////////////////
template <class T>
T Canciones<T>::findSong(T val) const {
	Link<T> *p;

	p = head;
    int index=0;
	while (p != 0) {
		if (p->value == val) {
            cout<<"La cancion se encuentra en la lista: "<<"'"<<p->value<<"'"<<endl;
            return "";
		}
		p = p->next;
        index++;
	}
    cout<<"la cancion no existe"<<endl;
	return "";
}
*/
#endif
