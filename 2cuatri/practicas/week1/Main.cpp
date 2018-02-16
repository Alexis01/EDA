
#include "SetOfInts1.h"
#include "Error.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


void sumaCuadrado(int num, int &acum){
	cout << "Entra " << num << endl;
	int numero = num;
	while(numero > 0 ){
		int module = numero % 10;
		acum += pow(module,2);
		numero = numero/10;		
	}
	cout << endl;
}
void esFeliz(int num, SetOfInts1 set){
	set.add(num);
	int acum = 0;
	while( acum != 1 && !set.contains(acum)){
		sumaCuadrado(num,acum);
		cout << set << endl;
		set.add(acum);
		cout << " acumsssss " << acum << endl;
		cout << !set.contains(acum) << endl; 
	}
	cout << set << endl;
}


int main(){
	SetOfInts1 set;
	esFeliz(7,set);
	/*SetOfInts1 set1;
	esFeliz(38,set1);
	SetOfInts1 set2;
	esFeliz(1,set2);
	SetOfInts1 set3;
	esFeliz(0,set3);
	SetOfInts1 set4;
	esFeliz(24,set4);*/
}

