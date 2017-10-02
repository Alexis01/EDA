#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

#ifndef DOMJUDGE
ifstream in("test.txt");
auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
/*
Se tienen n participantes para un torneo de ajedrez y hay que organizar un calendario
para que todos jueguen contra todos de forma que:
    1. Cada participante juegue exactamente una partida con cada uno de los n − 1
        restantes.
    2. Cada participante juegue a lo sumo una partida diaria.
    3. El torneo se complete en el menor número posible de días.

    En este tema veremos una solución para el caso, más sencillo, en que n es potencia
    de 2.
*/
void rellena( int a[10000][10000], int c, int f ){
    int dim = f - c + 1;
    int mitad = dim/2;
    if(dim == 2){
        a[c+1][c] = 1;
    }else{
        if(dim > 2){
            rellena(a,c, c+mitad-1); //cuadrante superior izquierdo
            rellena(a,c+mitad,f); //cuadrante inferior derecho
            for(int i=c+mitad; i<=f; i++){ //cuadrante inferio izquierdo
                for(int j=c; j<=c+mitad-1; j++){
                    a[i][j] = mitad + (i+j) %mitad;
                }
            }
        }
    }
}
/*
Dada una nube de n puntos en el plano, n ≥ 2, se trata de encontrar el par de puntos
cuya distancia euclídea es menor (si hubiera más de un par con esa distancia mínima,
basta con devolver uno de ellos). El problema tiene interés práctico. Por ejemplo, en
un sistema de control del tráfico aéreo, el par más cercano nos informa del mayor
riesgo de colisión entre dos aviones.
*/
struct Punto{
    double x;
    double y;
}
double absolute(double x){ 
    if (x>=0) {
        return x;
    }
    else{
        return -x;
    }
}
double distancia(Punto p1,Punto p2){
    return (sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));
};
double minimo(double x, double y){ 
    double z;
    if(x<=y){ 
        z = x;
    }else{
        z=y;
    };
    return z;
};
/*
Los límites c y f. Las llamadas correctas cumplen 0 ≤ c∧f ≤ long(v)−1∧f ≥ c + 1.
La distancia d entre los puntos más cercanos.
Los puntos p1 y p2 más cercanos.
Un vector de posiciones indY y un índice inicial ini que representa cómo se
ordenan los elementos de p con respecto a la coordenada y. El índice inicial ini
*/
void parMasCercano(Punto p[], int c, int f, int indY[], int& ini,
    double& d, int& p1, int& p2){

}

int main(){
    return 0;
}