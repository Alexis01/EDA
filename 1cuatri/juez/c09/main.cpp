
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


/**
 * N antigua longitud
 * NN nueva longitud
 * */
void solve(int v[], int N, int &NN ){
   // hay que ir verificando que v[i] no tenga un menor a la izquierda y un mayor a la derecha
}

int main(){
	int N,NN;
    int* V;
    for( (cin >> N); N >= 0 ; (cin >> N) ){
        V = new int[N];
        for (int n = 0; n < N; n++){
            cin >> V[n];
            
        } 
        NN = 0;
        solve(V,N,NN);
        //for (int n = 0; n < NN; n++) cout << V[n] << " ";
        cout << "NN " << NN << endl;
        for (int n = 0; n < NN; n++) cout << V[n] << " ";
        cout << endl;
        delete[] V;
    }
    return 0;
}