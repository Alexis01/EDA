#include <iostream>
#include <algorithm>
#include <climits>
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
		return Arbin<T>(hi, elem, hd);
	}
}

void buscaTesoro(const Arbin<int>& ruta, int& dragones, int& mejorSol){

	
	if (ruta.esVacio()){
		dragones = INT_MAX;
		mejorSol = -1;
	}else{
		
		if (ruta.raiz() >= 3){//es hoja
			mejorSol = ruta.raiz();
			dragones = 0;
		}
		else {
			int dragonesIz = 0, dragonesDr = 0, mejorSolIz = 0, mejorSolDr = 0;

			buscaTesoro(ruta.hijoIz(), dragonesIz, mejorSolIz);
			buscaTesoro(ruta.hijoDr(), dragonesDr, mejorSolDr);

			if (dragonesIz <= dragonesDr){
				dragones = dragonesIz;
				mejorSol = mejorSolIz;
			}
			else{
				dragones = dragonesDr;
				mejorSol = mejorSolDr;
			}
			if (ruta.raiz() == 1){
				dragones++;
			}
		}
		
		
	}
	
	
	/*
	
	*/
}

void resuelveCaso(){
	Arbin<int> ruta;
	int dragones, mejorSol;
	ruta = leerArbol(-1); // -1 es la repr. de arbol vacio
	buscaTesoro(ruta, dragones, mejorSol);
	cout << mejorSol << endl;
}

int main(){
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelveCaso();
}