#include <iostream>
#include <algorithm>
#include <climits>
#include <fstream>
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

void aguasLimpias(const Arbin<int>& ruta, int& tramos, int& caudal){
	if( ruta.esVacio() ){
		tramos = 0;
		caudal = 0;
	}else{
		if( ruta.hijoDr().esVacio() && ruta.hijoIz().esVacio()  ){ //hoja
			tramos = 0;
			caudal = 1;
		}else{
			
			int tramosIzq = 0, tramosDr = 0, caudalDr = 0, caudalIz = 0;
			aguasLimpias(ruta.hijoIz(), tramosIzq, caudalIz);
			aguasLimpias(ruta.hijoDr(), tramosDr, caudalDr);
			// calcular caudal   caudal < 0 => 0
			caudal = (caudalDr + caudalIz) - ruta.raiz(); // no hace falta contar embalse xq será un 0 
			if(caudal < 0) caudal = 0;
			// tramos
			tramos = tramosIzq + tramosDr;
			if( caudalIz >= 3) tramos++;
			if( caudalDr >= 3) tramos++;

		}
	}
	
}

void resuelveCaso(){
	Arbin<int> ruta;
	int tramos, caudal;
	ruta = leerArbol(-1); // -1 es la repr. de arbol vacio
	aguasLimpias(ruta, tramos, caudal);
	cout << tramos << endl;
}

int main(){
	
	//genRandomLeq(); return 0;
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
	#endif

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
	#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
	#endif
	return 0;
}