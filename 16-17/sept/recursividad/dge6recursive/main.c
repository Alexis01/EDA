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
    int n = 1;
	while( n < N ){
		V[n] += V[ n - 1 ];
		n++;
	}
    
}
void acumValsGen(int v[], int len, int index){
	if(index < len){
		v[index] = v[index-1];
		acumValsGen(v,len,index+1);	
	}
}
void acumVals( int v[],int len ){
	acumValsGen(v,len,1);
}
int main(){
    int N;
	string line;
	stringstream iss;
	int V[MAX];
	while(cin){
		getline(cin,line);
		iss.clear();
		iss.str(line);
		for( N = 0; iss;  ){
			iss >> V[N++];
		}
		N -= 2;
		solve( V, N );
		for(int i = 0; i < N; i++ ){
			cout << V[i] << " ";
		}
		cout << endl;
	}
    return 0;
}