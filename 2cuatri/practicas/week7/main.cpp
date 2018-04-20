#include <iostream>
#include <algorithm>
#include "Arbin.h"
#include <fstream>
#include <cstdlib>
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
/*
Arbin<int> reconstruir( List<int> pO, List<int> iO ){
	//CASO BASE
	if ( pO.empty() && iO.empty()){
		return new Arbin();
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
		int currentInIz = 0;
		while( !iO.empty() ){
			currentInIz = pO.back();
			pO.pop_back();
			inIzq.push_front( currentInIz );

		}
		//Postorden izquierdo
		int currentPostIzq = 0;
		while( !pO.empty() ){
			currentPostIzq = pO.back();
			pO.pop_back();
			postIzq.push_front( currentPostIzq );

		}
		//una vez los tenemos llamamos a
		Arbin<int> iz = reconstruir( inIzq,  postIzq);
		Arbin<int> dr = reconstruir( inDer,  postDer);
		return new Arbin( iz, raiz, dr ); 
	}
}
*/
#ifndef DOMJUDGE
std::ifstream in("datos.txt");
auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
int main(){
	int n;
	List<int>* preordenlist = new List<int>();
	List<int>* inordenlist = new List<int>();
	char c;
	c = cin.peek();
	bool ok =true;
	while( ok ){
		while ( c != '\n' ){
			cin >> n;
			if( n != -1 ){
				preordenlist->push_back(n);		
				cout << "data " << preordenlist->front() << endl;
				preordenlist->pop_back();
			}
			c = cin.peek();
		}
		char x;
		x = cin.peek();
		while ( c != '\n' ){
			cin >> n;
			if( n == -1 ){
				inordenlist->push_back(n);		
				cout << "data " << inordenlist->front() << endl;
				inordenlist->pop_back();
			}
			x = cin.peek();
		}
	}
	
	
	//resolver y fuera
	delete preordenlist;
	delete inordenlist;
}