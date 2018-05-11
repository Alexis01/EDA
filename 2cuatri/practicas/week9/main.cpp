#include <iostream>
#include <list>
#include "TreeMap.h"
#include <string>
#include "List.h"

using namespace std;

typedef TreeMap<string,int> Diccionario;

void leerDiccionario(Diccionario& diccionario){
	char c;
	string clave;
	int valor;
	cin.get(c);
	while (c != '\n'){
		cin.unget();
		cin >> clave >> valor;
		diccionario.insert(clave,valor);
		cin.get(c);
	}
}


void resuelveCaso(){
	Diccionario antiguo;
	leerDiccionario(antiguo);
    Diccionario nuevo;
	leerDiccionario(nuevo);
    List<string> del;
    List<string> mod;
    List<string> add;
    Diccionario::Iterator itviejo = antiguo.begin();
    Diccionario::Iterator itnuevo = nuevo.begin();
    while(itviejo != antiguo.end() ){
        if( itviejo.value() < itnuevo.value() ){
            del.push_back(itviejo.value());
            itviejo.next();
        }
        if( itviejo.value() == itnuevo.value()){
            if( itviejo.key() != itnuevo.key()){
                mod.push_back(itviejo.value());
            }
            itviejo.next();
            itnuevo.next();
        }
        if( itviejo.value() > itnuevo.value() ){
            add.push_back(itviejo.value());
            itnuevo.next();
        } 
    }
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
	char c;
	cin >> numCasos;
	cin.get(c); //o cin.ignore(1);
	for (int i = 0; i < numCasos; i++){
		resuelveCaso();
	}

	// Para restablecer entrada. Comentar para acepta el reto
	#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
	#endif
	return 0;
}
