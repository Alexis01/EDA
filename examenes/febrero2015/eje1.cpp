#include <iostream>    // cin, cout
#include <algorithm>  // max
#include <limits>
using namespace std;

#define MAX 10000
/*
Dado un vector de n elementos (n ≥ 0), se desea obtener la suma de todos los

productos de valores situados en parejas de posiciones distintas (con una complejidad O(n)).

Ejemplo: para el array con contenido: [1, 3, 5, 7] se debe devolver 1∗3+1∗5+1∗7+3∗5+3∗7+5∗7.

Para el array con contenido [6, 2, 5, 9, 1, 2] se debe devolver:

6 ∗ 2 + 6 ∗ 5 + 6 ∗ 9 + 6 ∗ 1 + 6 ∗ 2 + 2 ∗ 5 + 2 ∗ 9 + 2 ∗ 1 + 2 ∗ 2 + 5 ∗ 9 + 5 ∗ 1 + 5 ∗ 2 + 9 ∗ 1 + 9 ∗ 2 + 1 ∗ 2

Se pide:

    1. Especificación del algoritmo.

    2. Diseño y verificación (o derivación) e implementación del algoritmo iterativo.

    3. Justificación de la complejidad.

*/
int solveprimerapensada(int V[], int N){
    int n = 0, centinela = V[N-1], sum = 0, marca = 0;
    while( n < (N - 1) ){
        if( n == (N-2) ){
            cout << V[n]<<  "*" << centinela << endl;
            sum = sum +(V[n] * centinela);
            marca++;
            n = marca;
            marca = n;
        }else{
            cout << V[n]<<  "*" << centinela << endl;
            sum = sum +(V[n] * centinela);
            n++;
        }
        
    }
    return sum;
}
int solve(int V[], int N){
    int n = 0, centinela = V[N-1], sum = 0, poscent = N-1;
    while( n <= poscent ){
        if( n == (poscent - 1) ){
            cout << V[n]<<  "*" << centinela << endl;
            sum = sum +(V[n] * centinela);
            poscent -= 1;
            centinela = V[poscent];
            n = 0;
        }else{
            cout << V[n]<<  "*" << centinela << endl;
            sum = sum +(V[n] * centinela);
            n++;
        }
        
    }
    return sum;
}

int main(int argc, char **argv){
	int n,
		N,
		A[MAX];

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> N;
		for (int j = 0; j < N; j++){
			cin >> A[j];
		}
		cout << solve(A, N) << endl;
	}
	//Comentarlo para el juez
	char answer = 'd'; // new answer variable
	cout << "Press any key to continue, not enter";
	cin >> answer;
	cout << endl;
	
	return 0;
}