#include <stdlib.h> 
#include <iostream>
#include "Set.h"
using namespace std;
#define MAX 10000


template<class T>
void solve(Set<T> &set, int numk, int numElementos) {
	int diferencia = (numElementos) - numk;
	for (int i = 0; i < diferencia; i++) {
		set.removeMin();
	}
	for (int i = 0; i < numk; i++) {
		set.getMin();
		if (i==numk-1) {
			cout << set.getMin();
		}
		else {
			cout << set.getMin() << " ";
		}
		set.removeMin();
	}
	cout << endl;
}


int main() {
	int numK;
	char caracter;
	Set<int> *set = new Set<int>;
	Set<string> *setPalabra = new Set<string>;
	int numElementos = 0;
	int num = 0;
	cin >> caracter;
	while (!cin.fail()) {
		cin >> numK;
		if (caracter == 'N') {
			int num, pos = 0;
			int contador = 0;
			numElementos = 0;
			cin >> num;
			while (num != -1) {
				set->add(num);
				cin >> num;
				if (!set->contains(num)) {
					numElementos++;
				}
			}
			solve(*set, numK, numElementos);
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
		}
		cin >> caracter;
	}
	return 0;
}
