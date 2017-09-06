#include <iostream>
#include <fstream>
#include <algorithm>  // max, min
using namespace std;

#ifndef DOMJUDGE
ifstream in("test.txt");
auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

int solve( int v[], int len ){
    if( len == 1){
        return v[0];
    }
    if( len == 2 ){
        return min(v[0],v[1]);
    }
    if( len == 3 ){
        return min(v[0], min(v[1],v[2]));
    }
    if(len > 3){
        return min(solve(v,len/2),solve(v+len/2,len/2));
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