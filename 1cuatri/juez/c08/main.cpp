
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


#define MAX 20000
//pendiente la mitad refrescar
int uniqueGen(int v[], int i, int j, int N){
    int mitad = N/2;
    while( j - i > 0 && !((v[mitad-1]!=v[mitad]) && (v[mitad+1]!= v[mitad]))){//solo entro en el caso de no estar en la mitad
        if(v[mitad-1] == v[mitad]){ //mi par a la izquierda
            //si longitud par de los extremos sin incluirme
            if((mitad-i) % 2 == 0){ 
                //a la izquierda
                j = mitad - 2;
                
            }
            //si longitud impar de los extremos sin incluirme
            if((mitad-i)%2 != 0){
                //a la derecha
                i = mitad + 1;
            }
        }
        if( v[mitad+1] == v[mitad]){//mi par a la derecha
            //si longitud par de los extremos sin incluirme
            if( (mitad-1) - i % 2 == 0){
                i = mitad + 2;
            }
            //si longitud impar de los extremos sin incluirme
            if( (mitad-1) - i % 2 != 0 ){
                j = mitad - 1;
            } 
        }
        i++;
    }
    return mitad;
}
int unique(int v[], int N){
    return uniqueGen(v, 0, N, N);
}

int main(){
	int N,cases ;
    int V[MAX] ;
    cin >> cases ;
    for (int n = 0; n < cases; n++){
        cin >> N;
        for (int i = 0; i < N; i++) cin>>V[i];
        //unique(V,N);
        cout <<  unique(V,N) << endl;
    }
    return 0;
}