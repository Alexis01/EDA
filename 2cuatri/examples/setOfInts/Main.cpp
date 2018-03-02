
#include "SetOfInts3.h"
#include "Set.h"
#include "Error.h"
#include <iostream>
using namespace std;

void testSetOfInts(){
	char op;
	int n;
	SetOfInts3 set = SetOfInts3();
	SetOfInts3 set2 = set;
	cin >> set;
	cout << set << endl;
	do{
		cout << "Choose option ((a)dd, (r)emove, (j)oin, (i)ntersect, "
				"(c)ontains, (e)xit)" << endl;
		cin >> op;
		if (op == 'a'){
			cin >> n;
			try {
				set.add(n);
			} catch (Error& e){
				cout << e.getMessage() << endl;
			}
		} else if (op == 'j') {
			cin >> set2;
			try {
				set.join(set2);
			} catch (Error& e) {
				cout << e.getMessage() << endl;
			}
		} else if (op == 'i') {
			cin >> set2;
			set.intersect(set2);
		} else if(op == 'r'){
			cin >> n;
			set.remove(n);
		} else if(op == 'c'){
			cin >> n;
			cout << set.contains(n) << endl;
		}
		cout << set << endl;
	} while (op != 'e');
	cout << "Program finished" << endl;
}
void testGenericSet(){
	char op;
	string n;
	Set<string> set = Set<string>();
	cin >> set;
	Set<string> set2 = set; // llama al constructor por copia
	cout << set << endl;
	do{
		cout << "Choose option ((a)dd, (r)emove, (c)ontains, (e)xit)" << endl;
		cin >> op;
		if (op == 'a'){
			cin >> n;
			try {
				set.add(n);
			} catch (Error& e){
				cout << e.getMessage() << endl;
			}
		} else if(op == 'r'){
			cin >> n;
			set.remove(n);
		} else if(op == 'c'){
			cin >> n;
			cout << set.contains(n) << endl;
		}
		cout << set << endl;
	} while (op != 'e');
	cout << "Program finished" << endl;
}
int main(){
	//testSetOfInts();
	testGenericSet();
	
}

