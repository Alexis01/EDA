
//#include "DateTests.h"
#include "SetOfInts1.h"
#include "SetOfInts2.h"
#include "SetOfInts3.h"
#include <stdlib.h> 
using namespace std;

#define MAX 5

void setOfInts1(){

	//constructor
	SetOfInts1 *set1 =  new SetOfInts1();
	int i = 0, max = 5;
	while(i < max){
		int randomInt = rand() % 1000 + 1;
		 set1->add(randomInt);
		i++;
	}

    cout << *set1 << endl;
	//Destructor
    delete set1;
}
void setOfInts2(){
	SetOfInts2 *set2 =  new SetOfInts2();
	int i = 0, max = 5;
    while(i < max){
		int randomInt = rand() % 1000 + 1;
		 set2->add(randomInt);
		i++;
	}
    cout << *set2 << endl;
	//Destructor
    delete set2;
}
void setOfInts3(){
	SetOfInts3 *set3 =  new SetOfInts3();
	int i = 0, max = 5;
    while(i < max){
		int randomInt = rand() % 1000 + 1;
		 set3->add(randomInt);
		i++;
	}
    cout << *set3 << endl;
	//Destructor
    delete set3;
}
void solve(){
	SetOfInts3 *set3 = new SetOfInts3();
	SetOfInts3 *setToCompare = new SetOfInts3();
	int i = 0, max = MAX;
	while (i < max){
		int randomInt = rand() % 1000 + 1;
		set3->add(randomInt);
		randomInt = rand() % 1000 + 1;
		setToCompare->add(randomInt);
		i++;
	}
	cout << *set3 << endl;
	cout << *setToCompare << endl;
	if ( *set3 == *setToCompare){
		cout << "Son iguales" << endl;
	}else{
		cout << "Son distintos" << endl;
	}

	//Destructor
	delete set3;
	delete setToCompare;
}

int main(){
	/*cout << "setOfInts1" << endl;
	setOfInts1();
	cout << endl;
	cout << "setOfInts2" << endl;
	setOfInts2();
	cout << endl;
	cout << "setOfInts3" << endl;
	setOfInts3();
	cout << endl;*/
	/*
	1. Implementa la relaci´on de equivalencia del TAD SetOfInts mediante el m´etodo bool operator==(const
	SetOfInts& set) para las tres implementaciones del TAD vistas en clase y disponibles en el CV.
	Escribe una funci´on que permita hacer pruebas repetidamente con conjuntos introducidos por el
	usuario.
	*/

	solve();

	//Pare el programa
	char arg;
	cout << "Pres key to exit" << endl;
	cin >> arg;
	cout << "Bye";
	cout << endl;

    return 0;
}