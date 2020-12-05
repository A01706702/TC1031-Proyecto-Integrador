#ifndef FTREE_H
#define FTREE_H

#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

class Ftree{
private:
    vector<int> array;
public:
    Ftree(vector<int>);
	Ftree(string);
    int sum(int);
    int sum(int,int);
    void add(int, int);
    void add(int);
	string format_tree();
	vector<int> reconstruct();
	int get_tree_size();
};

//////////////////constructor//////////////
Ftree::Ftree(vector<int> arr){
	for(int i = 0; i < arr.size(); i++)
		array.push_back(0);
	for(int i = 0; i < arr.size(); i++)
		add(i, arr[i]);
}

////////////////////////getsize////////////////////
int Ftree::get_tree_size(){
	return array.size();
}

/////////////////////recostruir vector//////////////
vector<int> Ftree::reconstruct(){
	vector<int> recons;
	for(int i = 0; i < array.size(); i++)
		recons.push_back(sum(i, i));
	return recons;
}

/////////////////////////sum//////////////////////////
int Ftree::sum(int index){
    int sum=0;
    for(; index >= 0; index = (index & (index + 1)) - 1){
		sum += array[index];
    }
    return sum;
    cout<<sum;
}

////////////////////////sum real/////////////////
int Ftree::sum(int limleft, int limright){
	return sum(limright) - sum(limleft - 1);
}

/////////////////////////add///////////////////////////
void Ftree::add(int index, int value){
	for(; index < array.size(); index = index | (index + 1)){
    	array[index] += value;
    }
}

/////////////////////////edobrecarga add///////////////////////////
void Ftree::add(int value){
    int index = 0;
	for(int i=0; i<array.size(); i++){
        for(; index < array.size(); index = index | (index + 1)){
        	array[index] += value;
        }
        index++;
    }

}

/////////////////////dar formato (imprimir)//////////////////
string Ftree::format_tree(){
	string s = "[";
	for(int i = 0; i < array.size(); i ++){
		s += to_string(array[i]);
		if(i != array.size() -1)
			s += ",";
	}
	return s + "]";
}

#endif