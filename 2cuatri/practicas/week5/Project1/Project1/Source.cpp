#include <iostream>
#include <fstream>
#include "List.h"
#include <cstdlib>

using namespace std;

void mostrarLista(List<int>* l, int contCasos){
	List<int>::ConstIterator it = l->cbegin();
	cout << contCasos << ": ";
	if (it != l->cend()){
		cout << it.elem();
		it.next();
	}
	while (it != l->cend()){
		cout << " " << it.elem();
		it.next();
	}
	cout << endl;
}

void duplicarPicos( List<int>* l , int &contCasos){
	List<int>::Iterator it = l->begin();
	int sumaParcial = 0;
	while (it != l->end()){
		if ( it.elem() == sumaParcial ){
			//insertar at 
			l->insert(it.elem(),it);
			contCasos++;

		}
		sumaParcial += it.elem();
		it.next();
	}
}


int main(){
	int n, numCasos;
	cin >> numCasos;
	char x;
	cin.get(x);
	for (int i = 0; i < numCasos; i++){
		List<int>* l = new List<int>();
		int contCasos = 0;
		char c;
		c = cin.peek();
		while ( c != '\n' ){
			cin >> n;
			l->push_back(n);
			c = cin.peek();
		}
		duplicarPicos(l, contCasos);
		mostrarLista(l, contCasos);
		delete l;
		cin.get(x);
	}
	return 0;
}