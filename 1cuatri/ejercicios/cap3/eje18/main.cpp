/*
Dado X[N] de enteros, el índice i es un mirador si X[i] es el mayor elemento de X[i+1..n).
Especica y deriva un algoritmo de coste lineal que reciba un vector y calcule el
número de miradores que hay en X.
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
    int miradores = 0, n = 0, lastMax = INT_MIN;
    while(n < N){
        if(v[n] > lastMax ){
            miradores++;
            lastMax = v[n];
        }
        n++;
    }
    return miradores;
}

int solveRecursiveGen(int v[], int i, int tam, int &miradores, int &maxMirador){
    if( (i == tam) && (v[i] > maxMirador) ){
        miradores++;
        maxMirador = v[i];
    }else{
        if(i <= tam){
            if(v[i] > maxMirador){
                miradores++;
                maxMirador = v[i];
            }
            solveRecursiveGen(v,i+1,tam,miradores, maxMirador);
        }
    }
}

int solveRecursive(int V[], int n ){
    int miradores = 0, maxMirador = INT_MIN;
    solveRecursiveGen(V,0,n-1,miradores,maxMirador);
    return miradores;
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