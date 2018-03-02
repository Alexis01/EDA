#include "Set.h"
#include "Error.h"
// Roberto Diaz Gomez
// Alexis Cumbal Calderón


#include <iostream>
#include <iomanip>
#include <fstream>




#ifndef DOMJUDGE

ifstream in("datos.txt");

auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt

#endif

template<class T>
void solve(Set<T> &set, int numk, int numElems){
    /*int diff = numElems - numk;
    for (int i = 0; i < diff; i++) set.removeMin();
    for (int i = 0; i < numk; i++) {
        set.getMin();
        if ( i == numk - 1 ) {
            cout << set.getMin();
        } else {
            cout << set.getMin() << " ";
        }
        set.removeMin();
    }
    cout << endl;*/
}

int main() {
    
    int numK;
	char caracter;
	
	int numElementos = 0;
	int num = 0;
	cin >> caracter;
	while (!cin.fail()) {
		cin >> numK;
        Set<int> *set = new Set<int>;
	    Set<string> *setPalabra = new Set<string>;
		if (caracter == 'N') {
			int num;
			numElementos = 0;
			cin >> num;
			while (num != -1) {
				
				if(numElementos <= numK && !set->contains(num)){
					set->add(num);
					numElementos++;
				}else{
					if( numElementos > numK){
						if( num > set->getMin()){
							set->removeMin();
							set->add(num);
						}
					}
				}
				
				cin >> num;
			}
			cout<< *set << endl;
			// solve(*set, numK, numElementos);
            /*cout<< *set << endl;
            cout << " Max num " << set->getMax() << endl;
            set->removeMax();
            cout << " Min num " <<set->getMin() << endl;
            set->removeMin();
            cout<< *set << endl;*/
		}
		else if (caracter == 'P') {
			string fin;
			numElementos = 0;
			cin >> fin;
			while (fin != "FIN") {
				setPalabra->add(fin);
				cin >> fin;
				if (!setPalabra->contains(fin)) {
					numElementos++;
				}
			}
			solve(*setPalabra, numK, numElementos);
            /*cout<< *setPalabra << endl;
            cout << " Max Palabra " << setPalabra->getMax() << endl;
            setPalabra->removeMax();
            cout << " Min Palabra " << setPalabra->getMin() << endl;
            setPalabra->removeMin();
            cout<< *setPalabra << endl;*/
		}
		cin >> caracter;
        delete set;
        delete setPalabra;
	}
	return 0;
}

