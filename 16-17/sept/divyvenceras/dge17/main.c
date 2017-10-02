#include <iostream>
#include <fstream>
#include <algorithm>  // max, min
using namespace std;

#ifndef DOMJUDGE
ifstream in("test.txt");
auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

int solve( int v[], int len ){
    if(len == 1){
        return v[0];
    }else{
        if(len == 2){
            return min(v[0],v[1]);
        }else{
            if(v[(len/2)-1] < v[len/2]){//a la izq
                return solve(v,len/2);
            }else{// a la derecha
                return solve(v+(len/2), len-(1/2));
            }
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