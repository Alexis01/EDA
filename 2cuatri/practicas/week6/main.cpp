#include <iostream>
#include <algorithm>
#include "Arbin.h"

using namespace std;

template <class T>
Arbin<T> leerArbol(const T& repVacio){
	T elem;
	cin >> elem;
	if (elem == repVacio)
		return Arbin<T>();
	else{
		Arbin<T> hi = leerArbol(repVacio);
		Arbin<T> hd = leerArbol(repVacio);
		return Arbin<T>(hi,elem,hd);
	}
}

void planificarRescate(Arbin<int> rutas, int& grupos,int& maximo ){
	int maxI, maxD, gruposI, gruposD;
	cout << "Soy" << rutas.raiz() << " ";
	if ( rutas.raiz() == 0 ){
		grupos = 0;
		maximo = 0;
	}else{
		planificarRescate(rutas.hijoIz(), gruposI, maxI);
		planificarRescate(rutas.hijoDr(), gruposD, maxD);
		
		if (gruposI == 0 && gruposD == 0 && rutas.raiz() != 0 ){
			grupos = 1;
		}else{
			grupos = gruposD + gruposI;
		}
		maximo = rutas.raiz() + max(maxI, maxD);
		cout << grupos << " ";
		cout << maximo << endl;
	}

}

void resuelveCaso(){
	Arbin<int> rutas;
	int grupos = 0, maximo = 0;
	rutas = leerArbol(-1); // -1 es la repr. de arbol vacio
	planificarRescate(rutas, grupos, maximo);
	cout << grupos << " ";
	cout << maximo << endl;
}

int main(){
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelveCaso();
}