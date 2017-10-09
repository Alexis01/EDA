/*
Un vector A[N] de enteros es gaspariforme (A[0]+...+A[i],0 ≤ i < n )
si todas sus sumas parciales son no negativas y además la suma total es cero.
Especica y deriva una función de coste lineal que decida si A[N] es gaspariforme.

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


bool solve(int v[],int N ){
    int  n = 0, ok = true, sumPar = 0, sumTot = 0;
    while(n < N  & ok){
        sumPar += v[n];
        sumTot += v[n]; 
        if(sumPar < 0){
            ok = false;
        }
        n++;
    }
    return sumTot == 0;
}

bool solveRecursiveGen(int v[], int n, int tam, int &sumPar, int &sumTot){
    bool result = true;
    if( n == tam ){
        sumPar += v[n];
        sumTot += v[n];
    }else{
        if(n < tam){
            sumPar += v[n];
            sumTot += v[n];
            if(sumPar < 0){
                result = false;
            }
            solveRecursiveGen(v,n+1,tam,sumPar,sumTot);
        }
    }
    return result;
}

bool solveRecursive(int V[], int n ){
    int sumPar = 0, sumTot = 0;
    return solveRecursiveGen(V,0,n-1, sumPar, sumTot) && sumTot == 0;
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
        if(solve( V,posV )){
            cout << "\t\tsi" << endl;
        }else{
            cout << "\t\tno" << endl;
        }
        cout << "Recursive: "<< endl;
        if(solveRecursive(V, posV)){
            cout << "\t\tsi" << endl;
        }else{
            cout << "\t\tno" << endl;
        }
       
        pos++;
    }
    return 0;
}