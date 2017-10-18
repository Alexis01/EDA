/*
Dado un conjunto de valores, la moda es el valor (o valores) que más se
repite en dicho conjunto. Diseñar un algoritmo iterativo de coste lineal que dado un
vector de enteros positivos menores que 1000 devuelva una moda del vector.

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


int solve1(int v[],int N ){
    int  n = 0, frecAux[MAX] = {0};
    while(n < N){
        frecAux[v[n]]++;
        n++;
    }
    int pos = 1, mas_grande = 0, valor_moda = 0;
    for ( ; pos <= N; pos++ ) {
        if ( frecAux[pos] > mas_grande ) {
            mas_grande = frecAux[pos];
            valor_moda = pos;
        }
    }
    return valor_moda;
}
int solve2(int v[],int N ){
    int valor_moda = 0, contModa = 0;
    int  n = 0;
    while(n < N){
        cout << v[n] << endl;
        n++;
    }
    return valor_moda;
}
bool solveRecursiveGen(int v[], int n, int tam, int &maxResta){
    /*if(tam - 1 == n){
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
    }*/
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
        cout << solve1( V,posV ) << endl;
        cout << "Iterative----V2: \t ";
        sort(V,V+longArray);
        cout << solve2( V,posV ) << endl;
        //cout << "Recursive:\t ";
        //cout << solveRecursive(V, posV) << endl;
       
        pos++;
    }
    return 0;
}