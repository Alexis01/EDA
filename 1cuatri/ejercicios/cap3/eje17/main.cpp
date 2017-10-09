/*
Dado un vector de enteros X[N], el índice se llama heroico si X[i] es estrictamente
mayor que el i-ésimo número de la sucesión de Fibonacci. Especica y deriva un
algoritmo de coste lineal que reciba como argumento un vector y determine cuántos
índices heroicos tiene.

fn = f(n-1) + f(n-2)
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
int fibonacciRec(int n){
    if(n < 2){
        return n;
    }else{
        return fibonacciRec(n-1) + fibonacciRec(n - 2);
    }

}

void solve(int v[],int N ){
    int  n = 0;
    while(n < N){
        int fibN = fibonacciRec(n);
        if(v[n] > fibN ){
            cout << " " << v[n];
        }
        n++;
    }
    cout << endl;
}

void solveRecursiveGen(int v[], int n, int tam){
    int fibN = fibonacciRec(n);
    if( (n == tam) && (v[n] > fibN) ){
        cout << " " << v[n];
    }else{
        if(n <= tam){
            if(v[n] > fibN){
                cout << " " << v[n];
            }
            solveRecursiveGen(v,n+1,tam);
        }
    }
}

int solveRecursive(int V[], int n ){
    solveRecursiveGen(V,0,n-1);
    cout << endl;
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
        cout << "Iterative: "<< endl;
        solve( V,posV );
        cout << "Recursive: "<< endl;
        solveRecursive(V, posV);
       
        pos++;
    }
    return 0;
}