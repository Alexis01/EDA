#include <iostream>
#include <fstream>
#include "Queue.h"
#include <cstdlib>

using namespace std;

bool leerCola(Queue<int>& q){
	int n;
	cin >> n;
    if (cin.fail()) return false;
	while (n != 0) {
		q.push_back(n);
		cin >> n;
	}
	return true;
}

void mostrarYVaciarCola(Queue<int>& q){
	while (q.size() > 1){
		cout << q.front() << " ";
		q.pop_front();
	}
	if (!q.empty()) cout << q.front();
	cout << endl;
	q.push_back(0); q.pop_front(); // Para manifestar posibles errores de memoria
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCasoInvQ() {
    // leer los datos de la entrada
	Queue<int> q;
	if (leerCola(q)){
		q.duplicateAll();
		mostrarYVaciarCola(q);
		return true;
	} else return false;
}

// #define DOMJUDGE
int main() {
	//genRandomLeq(); return 0;
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	#ifndef DOMJUDGE
	std::ifstream in("pruebas.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
	#endif

	while (resuelveCasoInvQ()) ;

	// Para restablecer entrada. Comentar para acepta el reto
	#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
	#endif
	return 0;
}



