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
	int maxI=0, maxD=0, gruposI=0, gruposD=0;

	if ( rutas.esVacio()){
		grupos = 0;
		maximo = 0;
		return;
	}else{
		planificarRescate(rutas.hijoIz(), gruposI, maxI);
		planificarRescate(rutas.hijoDr(), gruposD, maxD);
		
		if (gruposI == 0 && gruposD == 0 && rutas.raiz() != 0 ){
			grupos += 1;
		}else{
			grupos = gruposD + gruposI;
		}
		maximo = rutas.raiz() + max(maxI, maxD);
		
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

Arbin<int> reconstruir( List<int> pO, List<int> iO ){
	//CASO BASE
	
	
	
	if ( pO.empty() && iO.empty()){
		return;
	}else{
		List<int> inDer;
		List<int> postDer;
		List<int> inIzq;
		List<int> postIzq;
		
		//1 Raiz
		int raiz = pO.back();
		pO.pop_back();

		//2
		//inorde derecho
		int currentIo = 0,
			longInDr = 0;
		while (currentIo != raiz){
			currentIo = iO.back();
			iO.pop_back();
			inDer.push_front(currentIo);
			longInDr++;
		}
		iO.pop_back();
		//post orden derecho
		int currentPo = 0;
		while (currentPo < longInDr){
			currentPo = pO.back();
			pO.pop_back();
			postDer.push_front( currentPo );
		}

		//Inorden izquierdo

		//Postorden izquierdo

		//una vez los tenemos llamamos a
			//arbin iz = recon( inZ, postIzq)
			//arbin dr = recon( inD, postDr )
	}
	//CASO RECURSIVO
		//LO DE LA IZ 
		//LO DE LA DR
	
	return NULL;
}


int main(){
	List<int> postOrden;
	List<int> inOrden;
	int postVal, auxPos = 0;
	int inVal, auxIn = 0;
	cin >> postVal;
	while (auxPos != -1 && auxIn != -1){
		while (postVal != -1){
			postOrden.push_back(postVal);
			cin >> postVal;
		}
		cin >> inVal;
		while (inVal != -1){
			inOrden.push_back(inVal);
			cin >> inVal;
		}
		//llamar a reconstruir
		Arbin<int> arbol = reconstruir( postOrden, inOrden );
		// niveles y te devuelve una lista e imprimir
		cin >> auxPos;
		cin >> auxIn;
	}
		
		

}