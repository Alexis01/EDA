#include <iostream>
#include <fstream>
using namespace std;

#ifndef DOMJUDGE
ifstream in("test.txt");
auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

void picosYvallesGen( int v[], int len, int &picos, int &valles,int index ){
    if(len == 0){
        picos = 0;
        valles = 0;
    }
    else{
        if(index >= 0 && index < len  ){
            if( (v[index - 1] < v[index]) && (v[index+1] < v[index])){
                picos++;
            }
            if((v[index - 1 ] > v[index]) && (v[index + 1] > v[index])){
                valles++;
            }
            picosYvallesGen(v,len,picos,valles,index + 1);
        }
          
    }
}
void picosYvalles( int v[], int len ){
    int picos = 0, valles = 0;
    picosYvallesGen(v,len, picos, valles, 1);
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
        picosYvalles( data, numData );
        pos++;
    }
    return 0;
}