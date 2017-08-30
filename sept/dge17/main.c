#include <iostream>
#include <fstream>
#include <algorithm>  // max, min
using namespace std;

#ifndef DOMJUDGE
ifstream in("test.txt");
auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

int solve( int *V, int N ){
    //si solo hay uno
    if( N == 1 ){
        return V[0];
    }
    if( N == 2 ){
        return min(V[0], V[1]);
    }
    if( N > 2 ){
        //si hay más de dos
        int mitad = N/2;
        //si está en la mitad
        if( (V[mitad - 1] > V[mitad]) && (V[mitad] < V[mitad + 1]) ){
            return V[mitad];
        }
        //si está en la mitad de la derecha
        if( (V[mitad-1] > V[mitad]) && (V[mitad] >= V[mitad+1])  ){
            return solve( V+mitad, N - mitad  );
        }
        //si está en la mitad de la iz
        if( V[mitad - 1] < V[mitad] ){
            return solve(V,mitad);
        }
        if( V[mitad - 1] == V[mitad]){
            return min(solve(V,mitad),solve(V+mitad,N-mitad));
        }
    }
}

int main(){
    int numCasos, pos = 0;
    cin >> numCasos;
    while( pos < numCasos ){
        int posj = 0, numData, data[10000];
        cin >> numData;
        while( posj < numData ){
            cin >> data[posj];
            posj++;
        }
        cout << solve( data, numData ) << endl;
        pos++;
    }
    return 0;
}