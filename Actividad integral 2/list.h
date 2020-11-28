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

    void addFirst(T,T,T);
	void addSong(T,T,T);
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
void List<T>::addFirst(T canc, T art, T ani){
	Link<T> *newLink;
	T val= canc + " " + art + " " + ani;
	newLink = new Link<T>(val);
	newLink->next = head;
	head = newLink;
	size++;
}

template <class T>
void List<T>::addSong(T canc, T art, T ani){
	Link<T> *newLink, *p;
	T val= canc + " " + art + " " + ani;
	newLink = new Link<T>(val);
	if (empty()) {
		addFirst(canc, art, ani);
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

//sobrecarga add////////////////////////////////////////
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
void findSong(ifstream &archivo, string cancionbuscada){
    archivo.open("canciones.txt", ios::in);
    string cancion, artista, anio;
    int aux = 0;
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


/////////////////////////infoarchivo////////////////////////////
template <class T>
bool verArchivo(List<T>& vinilist, string nombrearch) {
	ifstream arch(nombrearch);
	if (!arch) {
		cout << "No se encuentra el archivo: " << nombrearch << endl;
		return false;
	}
	string linea;
	while (getline(arch, linea)) { //saca una linea del archivo y lo guarda en string linea
		if (linea.size() > 0) {
			vinilist.addSong(linea);
		}
	}

	arch.close();
	return true;
}

/////////////////escribir/////////////////
template <class T>
void List<T>::escribir(string myfile){
	ofstream arch;
    arch.open (myfile);
	Link<T> *p;
    p = head;
	while (p != 0) {
        arch << p->value << endl; //imprime el value de lo q esta apuntando p en el archivo
		//cout<<"\n";
        p = p->next;
	}
    arch.close();
}

//////////////// Ver canciones desde lista ////////////////////
template <class T>
void List<T>::verlista(){
    Link<T> *p;
    p = head;
	while (p != 0) {
        cout<< p->value << endl;
		cout<<"\n";
        p = p->next;
	}
}

/*
//////////////////////findSong desde list////////////////////////////
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
