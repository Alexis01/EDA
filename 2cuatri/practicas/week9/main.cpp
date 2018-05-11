#include <iostream>
#include <list>
#include "TreeMap.h"
#include <string>
#include "List.h"
#include <fstream>

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
void imprimeLista(string simbol, List<string> aImprimir){
	if (!aImprimir.empty()){
		cout << simbol << " ";
		int pos = 0;
		while (pos < aImprimir.size() - 1){
			cout << aImprimir.at(pos) << " ";
			pos++;
		}
		cout << aImprimir.at(pos) << endl;
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
	while (itviejo != antiguo.end() && itnuevo != nuevo.end()){
        if( itviejo.key() < itnuevo.key() ){
            del.push_back(itviejo.key());
            itviejo.next();
		}else {
			if (itviejo.key() == itnuevo.key()){
				if (itviejo.value() != itnuevo.value()){
					mod.push_back(itviejo.key());
				}
				itviejo.next();
				itnuevo.next();
			}else{
				if (itviejo.key() > itnuevo.key()){
					add.push_back(itnuevo.key());
					itnuevo.next();
				}
			}
		}
    }

	if (itviejo != antiguo.end()){
		while (itviejo != antiguo.end()){
			del.push_back(itviejo.key());
			itviejo.next();
		}
	}
	if (itnuevo != nuevo.end()){
		while (itnuevo != nuevo.end()){
			add.push_back(itnuevo.key());
			itnuevo.next();

		}
	}
	if (add.empty() && del.empty() && mod.empty()){
		cout << "Sin cambios" << endl;
	}
	else{
		imprimeLista("+", add);
		imprimeLista("-", del);
		imprimeLista("*", mod);
	}
	
	cout << "----" << endl;
	//coment
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
