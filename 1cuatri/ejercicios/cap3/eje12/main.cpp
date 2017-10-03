/*Especificaca y deriva una función iterativa de coste lineal que reciba como argumento
un vector de números enteros y calcule el producto de todos ellos.*/
#include <iostream>
#include <fstream>
using namespace std;

#define MAX 10000

#ifndef DOMJUDGE
ifstream in("test.txt");
auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


int solve(int V[],int N ){
    int prod = V[0], n = 1;
    while(n < N){
        prod *= V[n];
        n++;
    }
    return prod;
}

int solveRecursive(int V[], int n ){
    //cout << "n " << n << endl;
    //cout << "V[n] " << V[n] << endl; 
    if(n == 0){
        return V[n];
    }else{
        return V[n] * solveRecursive(V, n - 1);
    }
    
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
        cout << solveRecursive(V, posV-1) << endl;
       
        pos++;
    }
    return 0;
}