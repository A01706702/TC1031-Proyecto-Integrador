/* ** Jose Pablo Miranda Berumen
   ** A01706702
   ** 2/nov/2020
   ** Entrega 3 Proyecto integrador
*/

#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <string>

#include <sstream>
#include <cstring>
#include <fstream>

using namespace std;

template <class T> class SplayTree;//friend class

/////////clase nodo///////
template <class T>
class Node{
private:
	T value;
	int size;
	Node *left, *right, *parent;

	Node<T>* succesor();
	Node<T>* rot_right(Node<T>*); //zig
	Node<T>* rot_left(Node<T>*); //zag

public:
	Node(T);
	Node(T,Node<T>*,Node<T>*,Node<T>*);
	Node<T>*add(T);
	Node<T>*add(T,T,T);
	Node<T>*find(T);
	Node<T>*remove(T);
	void removeChilds();
	void inorder(std::stringstream&) const;
	void verlista(std::stringstream&) const;
	void preorder(std::stringstream&) const;
	Node<T>* splay(Node<T>*,Node<T>*);

	friend class SplayTree<T>;
};

///////////////////////constructor///////////////////
template <class T>
Node<T>::Node(T val): value(val),size(0),left(0),right(0),parent(0) {}

template <class T>
Node<T>::Node(T val,Node<T> *le,Node<T> *ri,Node<T> *p)
: value(val),left(le),right(ri),parent(p){}

////////////////////////////add////////////////////
template <class T>
Node<T>* Node<T>::add(T val){
	if(val<value){ //comparacion ascii
		if(left!=0){
			return left->add(val);
		}
		else{
			left=new Node<T>(val);
			left->parent =this;
			return left;
		}
	}
	else{
		if(right !=0){
			return right->add(val);
		}else{
			right=new Node<T>(val);
			right->parent=this;
			return right;
		}
	}
	size++;
}

///////////////////sobrecarga add//////////////////////
template <class T>
Node<T>* Node<T>::add(T canc, T art, T ani){
	//T val= canc + " " + art + " " + ani;
	if(canc<value){ //comparacion ascii
		if(left!=0){
			return left->add(canc,art,ani);
		}
		else{
			T val = canc + " " + art + " " + ani;
			left=new Node<T>(val);
			left->parent =this;
			return left;
		}
	}
	else{
		if(right !=0){
			return right->add(canc,art,ani);
		}else{
			T val = canc + " " + art + " " + ani;
			right=new Node<T>(val);
			right->parent=this;
			return right;
		}
	}
}

////////////////////////////find///////////////////////////
template<class T>
Node<T>* Node<T>::find(T val){
	if(val==value){
		cout<<"La canción es: "<<value;
		return this;
	}
	else if (val<value){
		if(left!=0)
			return left->find(val);
		else
			return this;
	}
	else if (val>value){
		if(right!=0)
			return right->find(val);
		else
			return this;
	}
	cout<<"La canción es...: "<<value;
	return 0;
}

/////////////////////////////successor///////////////////////////
template<class T>
Node<T>* Node<T>::succesor(){
	Node<T> *le,*ri;

	le=left;
	ri=right;

	if(right==0){
		if(left !=0){
			left=0;
		}
		if(le)
			le->parent=0;
		return le;
	}

	if(right->left==0){
		right=right->right;
		if(right)
			right->parent =parent;
		if(ri){
			ri->right=0;
			ri->parent=0;
		}
		return ri;
	}

	Node<T> *p,*c;
	p=right;
	c=right->left;
	while(c->left !=0){
		p=c;
		c=c->left;
	}
	p->left=c->right;
	if(p->left !=0)
		p->left->parent=p;
	c->right=0;
	return c;
}

////////////////////////remove/////////////////////////////
template<class T>
Node<T>* Node<T>::remove(T val){
	Node<T> *succ,*old;
	if(val<value){
		if(left!=0){
			if(left->value==val){
				old=left;
				succ=left->succesor();
				if(succ !=0){
					succ->left=old->left;
					succ->right=old->right;
					succ->parent=old->parent;
					if(succ->left)
						succ->left->parent=succ;
					if(succ->right)
						succ->right->parent=succ;
				}
				left=succ;
				delete old;
				return this;
			}else{
				return left->remove(val);
			}
		}
	}else if (val >value){
		if(right!=0){
			if(right->value==val){
				old=right;
				succ=right->succesor();
				if(succ!=0){
					succ->left=old->left;
					succ->right=old->right;
					succ->parent=old->parent;
					if(succ->left)
						succ->left->parent=succ;
					if(succ->right)
						succ->right->parent=succ;
				}
				right=succ;
				delete old;
				return this;
			}else{
				return right->remove(val);
			}
		}
	}
	return 0;
}

template<class T>
void Node<T>::removeChilds(){
	if(left !=0){
		left->removeChilds();
		delete left;
		left=0;
	}
	if(right !=0){
		right->removeChilds();
		delete right;
		right=0;
	}
}

////////////////////////////ZIG///////////////////////////
template <class T>
Node<T>* Node<T>::rot_right(Node<T>* x){
	Node<T> *y=x->left;
	x->left = y->right;
	if(y->right)
		y->right->parent =x;
	y->right=x;

	y->parent=x->parent;
	x->parent=y;

	if(y->parent){
		if(y->parent->left && y->parent->left->value==x->value)
			y->parent->left=y;
		else
			y->parent->right=y;
	}
	return y;
}

////////////////////////////////////ZAG////////////////////////
template<class T>
Node<T>* Node<T>::rot_left(Node<T>*x){
	Node<T> *y=x->right;
	x->right=y->left;
	if(y->left)
		y->left->parent=x;
	y->left=x;

	y->parent=x->parent;
	x->parent=y;

	if(y->parent){
		if(y->parent->left && y->parent->left->value==x->value)
			y->parent->left=y;
		else
			y->parent->right=y;
	}
	return y;
}

//////////////////////////splay///////////////////////
template<class T>
Node<T>* Node<T>::splay(Node<T>* root, Node<T>* x){
	while(x->parent!=0){

		if(x->parent->value==root->value){
			if(x->parent->left && x->parent->left->value==x->value){
				rot_right(x->parent);
			}else{
				rot_left(x->parent);
			}
		}else{
			Node<T>*p = x->parent;
			Node<T>*g = p->parent;
			if(p->left && g->left &&
				x->value == p->left->value && p->value==g->left->value){
				rot_right(g);
				rot_right(p);
			}else if(p->right && g->right &&
			 x->value==p->right->value && p->value==g->right->value){
				rot_left(g);
				rot_left(p);
			}else if(p->left && g->right &&
			 x->value==p->left->value && p->value == g->right->value){
				rot_right(p);
				rot_left(g);
			}else{
				rot_left(p);
				rot_right(g);
			}
		}
	}

	return x;
}

////////////////////////////inorder///////////////////////////
template <class T>
void Node<T>::inorder(std::stringstream &aux) const {
	if(left !=0){
		left->inorder(aux);
	}
	if(aux.tellp()!=1){
		aux<<"\n";
	}
	aux<<value;
	if(right!=0){
		right->inorder(aux);
	}
}

////////////////////////////preorder//////////////////////////
template <class T>
void Node<T>::preorder(std::stringstream &aux) const {
	aux << value;
	if (left != 0) {
		aux << " ";
		left->preorder(aux);
	}
	if (right != 0) {
		aux << " ";
		right->preorder(aux);
	}
}

////////////////////////verlista///////////////////////////////////
template <class T>
void Node<T>::verlista(std::stringstream &aux) const {
	if (parent != 0){
		aux << "\n 		NODE: " << value << endl;
		aux << " 		PARENT: " << parent->value << endl;
	}else
		aux << "\n 		ROOT: " << value << endl;
	if (left != 0)
		aux << " <----- LEFT: " << left->value;
	if (right != 0)
		aux << " RIGHT -----> : " << right->value;
	aux << "\n";

	if (left != 0) {
		left->verlista(aux);
	}
	if (right != 0) {
		right->verlista(aux);
	}
}

///////////////////////////class splayTree///////////////////////
template<class T>
class SplayTree{
private:
	Node<T> *root;
	int size;

public:
	SplayTree();
	~SplayTree();
	void add(T);
	void add(T,T,T);
	bool find(T);
	void remove(T);
	void removeAll();
	string verlista() const;
	void escribir(string);
	bool search(SplayTree *,string n);

	std::string inorder() const;
	std::string preorder() const;

	bool empty() const;
};

//////////////////constr///////////////////
template <class T>
SplayTree<T>::SplayTree():root(0), size(0) {}

template<class T>
SplayTree<T>::~SplayTree() {
	removeAll();
}

///////////////////////////empty///////////////////////////
template<class T>
bool SplayTree<T>::empty() const{
	return (root==0);
}

//////////////////////////add/////////////////////////////
template<class T>
void SplayTree<T>::add(T val){
	if(root !=0){
		Node<T>* added= root->add(val);
		root=root->splay(root,added);
	}
	else{
		root=new Node<T>(val);
	}
	size++;
}

//////////////////////////sobrecarga add/////////////////////////////
template<class T>
void SplayTree<T>::add(T canc, T art, T ani){
	//T val= canc + " " + art + " " + ani;
	if(root !=0){
		Node<T>* added= root->add(canc, art, ani);
		root=root->splay(root,added);
	}
	else{
		T val = canc + " " + art + " " + ani;
		root=new Node<T>(val);
	}
	size++;
}

//////////////////////////remove///////////////////////////
template<class T>
void SplayTree<T>::remove(T val){
	if(root!=0){
		if(val==root->value){
			Node<T> *succ=root->succesor();
			if(succ !=0){
				succ->left = root->left;
				succ->right=root->right;
				succ->parent=0;
				if(succ->left)
					succ->left->parent=succ;
				if(succ->right)
					succ->right->parent=succ;
			}
			delete root;
			root=succ;
		}else {
			Node<T>*p = root->remove(val);
			if (p != 0)
				root=root->splay(root,p);
		}
	}
	size--;
}

template<class T>
void SplayTree<T>::removeAll(){
	if(root !=0){
		root->removeChilds();
	}
	delete root;
	root=0;
}

//////////////////////////////find//////////////////////////
template<class T>
bool SplayTree<T>::find(T val){
	if(root!=0){
		Node<T>* found=root->find(val);
		if (found == 0){
			cout<<"la cancion no existeee"<<endl;
			return false;
		}
		root=root->splay(root,found);
		cout<<"La cancion es.....: "<<root->value;
		return(root->value==val);
	}

	else{
		cout<<"La cancion no existe..."<<endl;
		return false;
	}
}

//////////////////////////inorder////////////////////////////////
template<class T>
std::string SplayTree<T>::inorder() const{
	std::stringstream aux;

	aux<<"";
	if(!empty()){
		root->inorder(aux);
	}
	aux<<"";
	return aux.str();
}

//////////////////////////preorder/////////////////////////
template<class T>
std::string SplayTree<T>::preorder() const{
	std::stringstream aux;

	aux<<"[";
	if(!empty()){
		root->preorder(aux);
	}
	aux<<"]";
	return aux.str();
}


////////////////////////////////verlista////////////////////////////
template<class T>
std::string SplayTree<T>::verlista() const{
	std::stringstream aux;

	aux<<"\n ====================== ";
	if(!empty()){
		root->verlista(aux);
	}
	aux<<" ==================== \n";
	return aux.str();
}

/////////////////////////llenar arbol////////////////////////////
template <class T>
bool verArchivo(SplayTree<T>& vinitree, string nombrearch) {
	ifstream arch(nombrearch);
	if (!arch) {
		cout << "No se encuentra el archivo: " << nombrearch << endl;
		return false;
	}
	string linea;
	while (getline(arch, linea)) { //saca una linea del archivo y lo guarda en string linea
		if (linea.size() > 0) {
			vinitree.add(linea);
		}
	}
	arch.close();
	return true;
}

/////////////////escribir/////////////////
template <class T>
void SplayTree<T>::escribir(string myfile){
	ofstream arch;
    arch.open (myfile);
	if (arch.is_open()){
		arch<<inorder();
	}
	arch.close();
}

//////////////////////findSong desde archivo///////////////////////////
void findSong(ifstream &archivo, string cancionbuscada){
    archivo.open("newlist.txt", ios::in);
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

#endif
