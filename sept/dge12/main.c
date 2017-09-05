#include <iostream>
#include <fstream>
#include <algorithm>  // max, min
using namespace std;

#ifndef DOMJUDGE
ifstream in("test.txt");
auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

int solve( int V[], int N,int transporte ){
    int n = 0, ini = 0, fin = 0, r = 0, s = 0;
    while(n < N){
        if( V[n] <= transporte ){
            s = n + 1;
        }
        if( r < (n + 1 - s) ){
            r = n + 1 - s;
            ini = s;
        }
        n++;
    }
    fin = ini + r - 1;
    cout << ini << " " << fin << endl;
}

int main(){
    int numCasos, pos = 0;
    cin >> numCasos;
    while( pos < numCasos ){
        int posj = 0, numData, transporte, data[10000];
        cin >> numData;
        cin >> transporte;
        while( posj < numData ){
            cin >> data[posj];
            posj++;
        }
        solve( data, numData, transporte );
        //cout <<  << endl;
        pos++;
    }
    return 0;
}