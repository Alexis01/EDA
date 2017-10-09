/*
Derivar algoritmos de coste lineal (con respecto a la lon-gitud del vector),
para resolver los siguientes problemas de segmento de longitud
máxima:
{ N ≥ 0 }
    fun seg-long-máx( int X[N]) return int r
{ r = (máx p, q : 0 ≤ p ≤ q ≤ N ∧ A(p, q) : q − p) }
donde
a ) A(p, q) = (∀i : p ≤ i < q : X[i] = 0) .
b ) A(p, q) = (∀i, j : p ≤ i ≤ j < q : X[i] = X[j]) .

*/
#include <iostream>
#include <fstream>
#include <algorithm>    // std::max
#include <climits>
using namespace std;

#define MAX 10000

#ifndef DOMJUDGE
ifstream in("test.txt");
auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


int solve(int v[],int N ){
    int  n = 0, maxResta = 0;
    while(n < N-1){
        int resta = v[n] - v[n+1];
        if(resta > maxResta){
            maxResta = resta;
        }
        n++;
    }
    return maxResta;
}

bool solveRecursiveGen(int v[], int n, int tam, int &maxResta){
    if(tam - 1 == n){
        int resta =   v[n] - v[n + 1];
        cout << " v[n] " << v[n] << endl;
        cout << "" << v[] << endl;
        if(resta > maxResta){
            maxResta = resta;
        }
    }else{
        if(n < tam - 1){
            int resta =   v[n] - v[n + 1];
            if(resta > maxResta){
                maxResta = resta;
            }
            solveRecursiveGen(v,n+1, tam, maxResta);
        }
    }
}

int solveRecursive(int V[], int n ){
    int maxResta = 0;
    solveRecursiveGen(V,0,n-1, maxResta);
}

int main(){
    int numCasos, pos = 0, longArray = 0;
    int V[MAX];
    cin >> numCasos;
    while( pos < numCasos ){
        int posV = 0;
        cin >> longArray;
        while(posV < longArray){
            cin >> V[posV];
            posV++;
        }
        cout << "Iterative:\t ";
        cout << solve( V,posV ) << endl;
        cout << "Recursive:\t ";
        cout << solveRecursive(V, posV) << endl;
       
        pos++;
    }
    return 0;
}