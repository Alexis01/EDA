
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


void solve(int v[], int N, int &p){
    int i = N - 1;
    p = i;
	while (i >= 0 ){
        if(v[i] < 0 ){
            int temp = v[i];
            v[i] = v[p];
            v[p] = temp;
            p = p-1;
        }     
        i--;
	}
	p = p + 1;
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
        solve( data, numData, p );
        int cont = 0;
        while( cont < numData){
            cout << data[cont] << " ";
            cont++;
        }
        cout << endl;
        cout << p << endl;
        pos++;
    }
    return 0;

}