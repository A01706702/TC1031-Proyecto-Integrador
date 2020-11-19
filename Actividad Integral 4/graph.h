#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

////////////////////////class graph/////////////////////
template <class T>
class Graph{
private:
    bool directed;
	vector<T> nodes_list;
	vector<vector<int>> adj_list;
    vector<T> song_details;
public:
    Graph(){}
    Graph(bool d);
    void add_node(T);
    void add_node(T,T,T); //addsong
	void add_edge(T nodo_origen, T nodo_destino); //add relacion
    vector<T> BFS(int nodo_origen, int nodo_destino);
    bool empty();
    int tam();
    bool find(string);
    string print_nodes_list();
    void escribir(string);
};


// template<class T>
// bool Graph<T>::empty(){
//     if (h==NULL){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

// template<class T>
// int Graph<T>::tam(){
//     int count=0;
//     Node<T> *aux;
//     aux=h;
//     while (aux!=0){
//         count ++;
//         aux = aux->next;
//     }
//     return count;
// }

template<class T>
string Graph<T>::print_nodes_list(){
	string result = "";
	for (int i=0; i<nodes_list.size(); i++){
		result += to_string(i) + " " + nodes_list[i] + " " + song_details[i] + "\n";
	}
	return result;
}

template<class T>
bool Graph<T>::find(string cancion){
    for (int i=0; i<nodes_list.size(); i++){
        if(nodes_list[i] == cancion){
            cout<<"La cancion es: "<<nodes_list[i]<<endl;
            return true;
        }
    }
    cout<<"La cancion no se encuentra en la lista"<<endl;
    return false;
}

template<class T>
void Graph<T>::add_node(T song){
	// Check if value already in nodes list
	for (int i=0; i<nodes_list.size(); i++){
		if (nodes_list[i] == song) return;
	}
	nodes_list.push_back(song);
	// Expand the adjecency list
	vector<int> new_row;
	adj_list.push_back(new_row);
}

template<class T>
void Graph<T>::add_node(T song, T artist, T year){
    T val = artist+" "+year;
	// Check if value already in nodes list
	for (int i=0; i<nodes_list.size(); i++){
		if (nodes_list[i] == song) {
            return;
        }
	}
	nodes_list.push_back(song);
    song_details.push_back(val);
	// Expand the adjecency list
	vector<int> new_row;
	adj_list.push_back(new_row);
}


template<class T>
void Graph<T>::add_edge(T valor_origen, T valor_destino){
    int nodo_origen = -1;
	int nodo_destino = -1;

	for (int i=0; i<nodes_list.size(); i++){
		if (nodes_list[i] == valor_origen) {
            nodo_origen = i;
        }
		if (nodes_list[i] == valor_destino){
            nodo_destino = i;
        }
	}
	if (nodo_origen == -1 || nodo_destino == -1){
        cout<<"Not found"<<endl;
		return;
	}
	adj_list[nodo_origen].push_back(nodo_destino);
	if (!directed)
		adj_list[nodo_destino].push_back(nodo_origen);
}

template<class T>
vector<T> Graph<T>::BFS(int nodo_origen, int nodo_destino){
	vector<int> queue;
	vector<bool> visited(nodes_list.size(), false);
	vector<T> path;
	int current;
	queue.push_back(nodo_origen);
	do {
		// Dequeue
		current = queue[0];
		queue.erase(queue.begin());
		// Checar si ya esta visitado
		if (!visited[current]){
			// Marcar como visitado
			visited[current] = true;
			path.push_back(nodes_list[current]);
			// Agregar hijos
			for (int item : adj_list[current])
				queue.push_back(item);
		}
	// Checar si es el valor
	} while (current != nodo_destino);

	return path;
}

////////////////////archivos////////////////////////
void info_archivo(Graph<string> &graph){
	// Read file
	ifstream file;
	file.open("canciones.txt");

	while(file.good()){
		string song;
		string artist;
		string year;
		// Read line
		getline(file, song, ' ');
		getline(file, artist, ' ');
		getline(file, year, '\n');
		// Add node
        //graph.add_node(song);
		graph.add_node(song,artist,year);
	}
	file.close();
}


void read_conections(Graph<string> &graph){
	// Read file
	ifstream file;
	file.open("cola.csv");

	while(file.good()){
		string cancion1;
		string cancion2;
		string playlist;
		// Read line
		getline(file, cancion1, ',');
		getline(file, cancion2, ',');
		getline(file, playlist, '\n');
		// Add edge
		graph.add_edge(cancion1, cancion2);
	}
	file.close();
}

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

template <class T>
void Graph<T>::escribir(string myfile){
	ofstream arch;
    arch.open (myfile);
    for(int i=0; i<nodes_list.size(); i++){
        arch << nodes_list[i]+" "+song_details[i] <<endl;
    }
    arch.close();
}
#endif