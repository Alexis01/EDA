#include <iostream>
#include <fstream>
using namespace std;

#ifndef DOMJUDGE
ifstream in("test.txt");
auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

void solve( int data[], int N ){
    int picos = 0, valles = 0;
    //empezamos en pos = 1 por que así hay día anterior
    int pos = 1;
    while( pos < N - 1 ){
        if(data[pos-1] < data[pos] &&  data[pos+1] < data[pos] ){
            picos++;
        }
        if(data[pos-1] > data[pos] &&  data[pos+1] > data[pos] ){
            valles++;
        }
        pos++;
    }
    cout << picos << " " << valles << endl;
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
        solve( data, numData );
        pos++;
    }
    return 0;
}