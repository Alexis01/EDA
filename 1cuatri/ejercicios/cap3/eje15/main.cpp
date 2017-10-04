/*
Deriva un algoritmo que satisfaga la siguiente especicación:
    {N > 0}
        fun suma-buenos( int X[N]) return int s
    {s = (Σi : 0 ≤ i < N ∧ bueno(i, X) : X[i])}
donde bueno(i, X) ≡ (X[i] = 2 i ). No se pueden emplear operaciones que calculen potencias.
*/
#include <iostream>
#include <fstream>
#include <algorithm>    // std::max
using namespace std;

#define MAX 10000

#ifndef DOMJUDGE
ifstream in("test.txt");
auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


int solve(int v[],int N ){
    int sum = 0, n = 0;
    while(n < N){
        if(v[n] == pow(2,n) ){
            sum += v[n];
        }
        n++;
    }
    return sum;
}

int solveRecursiveGen(int v[], int i, int tam, int &sumBuenos){
    if( (i == tam) && (v[i] == pow(2,i)) ){
        sumBuenos += v[i];
    }else{
        if(i <= tam){
            if(v[i] == pow(2,i)){
                sumBuenos += v[i];
            }
            solveRecursiveGen(v,i+1,tam,sumBuenos);
        }
    }
}

int solveRecursive(int V[], int n ){
    int sumBuenos = 0;
    solveRecursiveGen(V,0,n-1,sumBuenos);
    return sumBuenos;
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
        cout << "Iterative: ";
        cout << solve( V,posV ) << endl;
        cout << "Recursive: ";
        cout << solveRecursive(V, posV) << endl;
       
        pos++;
    }
    return 0;
}