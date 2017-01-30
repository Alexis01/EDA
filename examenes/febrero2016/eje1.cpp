#include <iostream>    // cin, cout
#include <algorithm>  // max
#include <limits>
using namespace std;

#define MAX 10000
/*
Diseñar y verificar, o bien derivar, un algoritmo iterativo eficiente que cumpla la

siguiente especificacion:

{0 ≤ n ≤ longitud(v) ∧ ∀k : 0 ≤ k < n : v[k] ≥ 0}

fun parImpar (int v[ ], int n) return int p

{p = # i, j : 0 ≤ i < j < n : v[i] %2 = 0 ∧ v[j] %2 = 1}

Indicar y justificar la complejidad del algoritmo.



*/
int solve(int V[], int N){
	int n = 1, p = 0;
    while(n < N){
        if( (V[n-1]%2) == 0 && V[n]%2==1){
            p++;
        }
        n++;
    }
    return p;
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