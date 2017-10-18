/*
Diseñar un algoritmo iterativo de coste lineal que satisfaga la siguiente especicación:
{N ≥ 0}
    fun separación( bool A[N]) return bool r
{r = ∃p : 0 ≤ p ≤ N : (∀i : 0 ≤ i < p : A[i]) ∧ (∀j : p ≤ j < N : ¬A[j])}
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