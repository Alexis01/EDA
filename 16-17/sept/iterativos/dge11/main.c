#include <iostream>
#include <fstream>
#include <climits>
#include <algorithm>
#include <sstream>

using namespace std;
#define MAX 10000
#ifndef DOMJUDGE
ifstream in("test.txt");
auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
/*
Dado un vector de n´umeros enteros obtener un nuevo vector tal que el valor de cada componente sea
la suma de los valores de todas las componentes anteriores o iguales que ella en el vector original.
*/
void solve( int V[], int N ){
    int p = -1, nz = 0, nu = 0, n = 0;
	while (n < N){
		if (V[n] == 0){
			nz++;
		}
		if (V[n] == 1){
			nu++;
		}
		if (nz == nu){
			p = n;
		}
		n++;
	}
	cout << p << endl;
    
}

int main(){
    int numCasos, pos = 0;
    cin >> numCasos;
    while( pos < numCasos ){
        int posj = 0, numData, data[10000];
        cin >> numData;
        while( posj < numData ){
            cin >> data[posj];
            posj++;
        }
        solve( data, numData );
        pos++;
	}
	return 0;
}