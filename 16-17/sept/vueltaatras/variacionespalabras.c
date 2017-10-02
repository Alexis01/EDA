#include <iostream>
#include <fstream>
#include <algorithm>  // max, min
using namespace std;

#ifndef DOMJUDGE
ifstream in("test.txt");
auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

void tratarSolucion(int solucion[], int m){
    cout << "Solucion: ";
    for(int i = 0; i < m; i++)
        cout << solucion[i] << " ";
    cout << endl;
}
bool esSolucion(int k, int m){
    return k == (m - 1);
}

bool esValida(int solucion[], int k) {
    int i = 0;
    while(i < k && solucion[i] != solucion[k]){
         i++;
    }
    return (i == k);
}
void variaciones(int solucion[], int k, int n, int m){
    for(int letra = 0; letra < n; letra++){
        solucion[k] = letra;
        if(esValida(solucion, k)){
            if(esSolucion(k, m))
                tratarSolucion(solucion,m);
            else
                variaciones(solucion, k + 1, n, m);
        }
    }
}
void variacionesMarca(int sol[], int k, int n, int m, bool marcas[]){
    for(int letra = 0; letra < n; letra++){
        if(!marcas[letra]){
            sol[k] = letra;
            if( k == m-1 ){
                tratarSolucion(sol, m);
            }else{
                marcas[letra] = true;
                variacionesMarca(sol,k + 1, n, m, marcas);
                marcas[letra] = false;
            }
        }
    }
}

void variaciones(int n, int m){
    int solucion[m];
    //variaciones(solucion, 0, n, m);
    bool marcas[m];
    variacionesMarca(solucion, 0, n, m, marcas);
}

int main(){
    variaciones(27,5);
    return 0;
}