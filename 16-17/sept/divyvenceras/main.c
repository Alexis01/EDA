#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

#ifndef DOMJUDGE
ifstream in("test.txt");
auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

/*
“Encontrar el valor
máximo en un array
de números enteros."
*/
int findMaxGen(int v[], int i, int j){
    if( i == j ){
        return v[i];
    }else{
        int miz,mder, medio = i + j / 2;
        miz = findMaxGen(v,i,medio);
        mder = findMaxGen(v,medio+1,j);
        if( miz > mder){
            return miz;
        }else{
            return mder;
        }
    }
}
int findMax(int v[], int len){
    return findMaxGen(v,0,len);
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
        cout << findMax( data, numData ) << endl;
        pos++;
    }
    return 0;
}