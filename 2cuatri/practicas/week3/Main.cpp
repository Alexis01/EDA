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



int main() {
    
    int numK;
	char caracter;
	int numElementos = 0;
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
				if(numElementos < numK && !set->contains(num)){
					set->add(num);
					numElementos++;
				}else{
					if( numElementos >= numK){
						if (num > set->getMin() && !set->contains(num)){
							set->removeMin();
							set->add(num);
						}
					}
				}
				cin >> num;
			}
			cout<< *set << endl;
		}
		else if (caracter == 'P') {
			string fin;
			numElementos = 0;
			cin >> fin;
			while (fin != "FIN") {
				if (numElementos < numK && !setPalabra->contains(fin)){
					setPalabra->add(fin);
					numElementos++;
				}
				else{
					if (numElementos >= numK){
						if (fin > setPalabra->getMin() && !setPalabra->contains(fin)){
							setPalabra->removeMin();
							setPalabra->add(fin);
						}
					}
				}
				cin >> fin;
				
			}
			cout << *setPalabra << endl;
		}
		cin >> caracter;
        delete set;
        delete setPalabra;
	}
	return 0;
}