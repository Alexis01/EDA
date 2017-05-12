#include <iostream>
#include <list>
#include "TreeMap.h"
#include "List.h"
#include <string>

using namespace std;

void printLista(const list<int>& l, ostream& sout){
	list<int>::const_iterator it = l.cbegin();
	if (it != l.cend()){
		sout << *it;
		++it;
	}
	while (it != l.end()){
		sout << " " << *it;
		++it;
	}
	sout << endl;
}

void aMinusculas(std::string& palabra) {
	for (char& c : palabra) {
		if (c >= 'A' && c <= 'Z')
			c = c - 'A' + 'a';
	}
}

void resuelveCaso(int numLineas){
	char c;
	string palabra;
	//...
	TreeMap<string, list<int> > sol;

	for (int linea = 1; linea <= numLineas; linea++){
		cin.get(c);
		while (c != '\n'){
			cin.unget();
			cin >> palabra;
			aMinusculas(palabra);
			if (palabra.length() > 2){
				//si ya aparecido y mi linea no está en la última posición entonces me añado
				if (sol.contains(palabra)) {
					if (sol.at(palabra).back() != linea){
						sol[palabra].push_back(linea);
					}
					// at observadora , sol[] accede 
				}
				else{ //si no estoy al finale
					list<int> temp = list<int>();
					temp.push_back(linea);
					sol.insert(palabra, temp);
				}
			}
			cin.get(c);
		}
	}
	TreeMap<string, list<int>>::ConstIterator it = sol.cbegin();
	while (it != sol.cend()){
		cout << it.key() << " ";
		printLista(it.value() , cout);
		++it;
	}
	cout << "----" << endl;

}

int main(){
	int numLineas;
	char c;
	cin >> numLineas; cin.get(c);
	while (numLineas != 0){
		resuelveCaso(numLineas);
		cin >> numLineas; cin.get(c);
	}
}