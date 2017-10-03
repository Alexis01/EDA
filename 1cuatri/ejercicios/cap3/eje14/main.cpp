/*
{N > 0}
    fun pares( int V[N]) return int x
{x = (#i : 0 ≤ i < N : V [i]mod 2 = 0)}
X es igual al productorio de todos los elementos en posiciones pares
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


int solve(int V[],int N ){
    int prod = 1, n = 0;
    while(n < N){
        if(n % 2 == 0 ){
            prod *= V[n];
        }
        n++;
    }
    return prod;
}

int solveRecursiveGen(int v[], int i, int tam, int &prodPares){
    if( (i == tam) && (i%2==0) ){
        prodPares *= v[i];
    }else{
        if(i <= tam){
            if(i%2 == 0){
                prodPares *= v[i];
            }
            solveRecursiveGen(v,i+1,tam,prodPares);
        }
    }
}

int solveRecursive(int V[], int n ){
    int prodPares = 1;
    solveRecursiveGen(V,0,n-1,prodPares);
    return prodPares;
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