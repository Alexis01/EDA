/*Especica y deriva una función que reciba como argumento un vector de números y
calcule el máximo de todos ellos.*/
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
    int max = V[0], n = 1;
    while(n < N){
        if(V[n] > max ){
            max = V[n];
        }
        n++;
    }
    return max;
}

int solveRecursive(int V[], int n ){
    
    if(n == 0){
        return V[0];
    }else{
        return max(V[n], solveRecursive(V, n - 1));
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