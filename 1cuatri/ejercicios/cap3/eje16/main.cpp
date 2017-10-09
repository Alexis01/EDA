/*
Denición : 
Dado V[N] de enteros, el índice i es un pico si V[i] es el mayor elemento
de V[0..i].
Especica y deriva un algoritmo de coste lineal que reciba un vector y calcule la suma
de todos los valores almacenados en los picos de V.
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
    int sumPicos = 0, n = 0, lastPico = INT_MIN;
    while(n < N){
        if(v[n] > lastPico ){
            sumPicos += v[n];
            lastPico = v[n];
        }
        n++;
    }
    return sumPicos;
}

int solveRecursiveGen(int v[], int i, int tam, int &sumPicos, int &maxPico){
    if( (i == tam) && (v[i] > maxPico) ){
        sumPicos += v[i];
        maxPico = v[i];
    }else{
        if(i <= tam){
            if(v[i] > maxPico){
                sumPicos += v[i];
                maxPico = v[i];
            }
            solveRecursiveGen(v,i+1,tam,sumPicos, maxPico);
        }
    }
}

int solveRecursive(int V[], int n ){
    int sumPicos = 0, maxPico = INT_MIN;
    solveRecursiveGen(V,0,n-1,sumPicos,maxPico);
    return sumPicos;
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