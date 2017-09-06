/*
2. (3 puntos) La imagen especular de un número natural es el número que resulta
al invertir el orden de sus dígitos.
Por ejemplo, la imagen especular de 13492 es 29431 y la imagen especular del 1000 es el 1.
 Implementa dos algoritmos recursivos, uno final y otro no final, que calculen la
 imagen especular de un número natural representado como unsigned int.
 Indicar la llamada inicial a cada algoritmo con los valores iniciales de cada parámetro.
 Justica el coste de cada algoritmo.
 NOTA: Ten en cuenta que no se pide la especicación, ni la derivación / vericación formal de los algoritmos.
*/
#include <iostream>
#include <fstream>
#include <algorithm>  // max, min
using namespace std;

#ifndef DOMJUDGE
ifstream in("test.txt");
auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

unsigned int solve(unsigned int num ){
    int res;
    if( num < 10){
        res = num;
    }else{
        int e, H, r=num%10;
        for(H=1,e=num/10; e>0; e=e/10){
            H*=10;
        }
        res = r*H+solve(num/10);
    }
    cout <<"res" <<  res << endl; 
    return res;
}
// RECURSIVO FINAL
int solveFinal(unsigned int n, unsigned int resultado){
    return (n<10)?(10*resultado + n):(solveFinal(n/10, (10*resultado+n%10)));
}
int main(){
    int numCasos, pos = 0;
    cin >> numCasos;
    while( pos < numCasos ){
        unsigned int num;
        cin >> num;
        cout << solve( num ) << endl;
        unsigned int res;
        solveFinal( num, res );
        cout << res << endl;
        pos++;
    }
    return 0;
}