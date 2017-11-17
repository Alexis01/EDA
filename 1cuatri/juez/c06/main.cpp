
/*
Compute number of maximum values in a non-empty vector

P : N > 0

proc frecMax(V[0..N) of int, out int M, out int fr)

Q : M = max i : 0 <= i < N : V[i] && fr = #i : 0 <= i < N : V[i]==M
*/
#include <iostream>
#include <fstream>
#include <algorithm>    // std::max
#include <climits>

using namespace std;

#ifndef DOMJUDGE

ifstream in("test.txt");

auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt

#endif


#define MAXIMUM 20000

//fun auxiliatr que calcule la frecuencia 
bool esDdivertido(int v[], int N){
    int n = 0, frec[MAXIMUM];
    
    return ok;
}
bool esCrecientePorLosPelos(int v[], int N){
    int n = 0, ok = true;
    while(n < N - 1 && ok){
        int dif = abs(v[n] - v[n+1]);
        if(( dif < 0) || (dif > 1)){
            ok = false;
        }
        n++;
    }
    return ok;
}

bool solve(int v[], int N, int dRestriction){
    bool ok = false;
    int max_array = 0, frecuencia = 0;
    if(esCrecientePorLosPelos(v, N)){
        cout << "CP " << "SI" << endl;
    }else{
        cout << "CP " << "NO" << endl;
    }
    return ok;
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
        int p = 0;
        solve( data, numData);
        pos++;
    }
    return 0;

}