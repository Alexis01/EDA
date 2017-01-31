#include <iostream>    // cin, cout
#include <algorithm>  // max
#include <limits>

using namespace std;

#define MAX 10000
/*
ISBN
vueltaAtras(Tupla & sol, int k){
    prepararRecorridoNivel(k);
    while(!ultimoHijoNivel(k)){
        sol[k] = siguienteHijoNivel(k);
        if(esValida(sol,k)){
            if(esSolucion){
                tratarSolucion(sol);
            }else{
                vueltaAtras(sol, k+1)
            }
        }
    }
}
*/

struct Celda{
    int fila;
    int columna;
};
//es solución si hemos llegado a nuestro destino
bool esSolucion(Celda current, Celda dest){
    return current.fila == dest.fila && dest.fila == dest.columna;
}
bool esValida(int* V, Celda current, Celda ant, int hmax, int *marcas, int N){
    // esValida si no esta fuera, el desnivel no supera hmax, y no estaba amrcada
    return (current.fila >= 0 && current.fila < N) &&
            (current.columna >= 0 && current.columna < N) &&
            abs(V[current.fila][current.columna] - V[ant.fila][ant.columna]) <= hmax &&
            !(marcas[current.fila][curren.columna]);
}
/*
Tenemos 4 posibles direcciones, norte, sur este oest
        N
       
  O     pos   E

        S
por ello puedo ir a las 4 cada vez que esté en un nodo
0 --- este
1 --- sur
2 --- oeste
3 --- norte
*/
Celda siguienteHijoNivel(int dir, Celda pos){
    switch(dir){
        case 0:{
            pos.columna++;
            break;
        }
        case 1:{
            pos.fila++;
            break;
        }
        case 2:{
            pos.columna--;
            break;
        }
        case 3:{
            pos.fila--;
            break;
        }
    }
    return pos;
}
/**
 * llamar con
 * - V: alturas
 * - dest: destino
 * - solucion[0]: origen
 * - float hmax
 * - k: 1 ---nivel
 * - n: ancho y alto de lab y de las  marcas ES NXN 
 * - marcas: a false, excepto en casilla origen
 * - minLong: a INT_MAX
 */
/*
float lab[N][N], Celda dest, float hmax, Celda solucion[], int k, int n, 
bool marcas[N][N], Celda mejorSol[],int &mejorLong
*/
void solve(int *V, Celda dest, int hmax,
            Celda solucion[], int k , int n, bool *marcas,
            Celda mejorSol[], int &minLong ){
	//Prepara recorrido: En este caso al ser posiciones en la matriz ->  norte sur este oeste, 4 posibles destino
    int pos = 0;
    while(pos < 4){
        solucion[k] = siguienteHijoNivel(pos,solucion[k-1]);
        // esValida(float V[][], Celda current, Celda ant, int hmax, int marcas[][], int N)
        if(esValida(V,solucion[k], solucion[k-1], hmax, marcas, n)){
            //esSolucion(Celda current, Celda dest)
            if(esSolucion(solucion[k], dest)){
                //funcion de tratar solucion
                if( k < minLong ){
                    int i = 0;
                    while(i<n){
                        mejorSol[i] = solucion[i];
                        i++;
                    }
                    minLong = k;
                }
            }else{
                int longEstimada = k + Math.abs(dest.fila-solucion[k].fila)
                + Math.abs(dest.columna-solucion[k].columna);
                if(longEstimada < mejorSol){
                    marcas[solucion[k].fila][solucion[k].columna] = true;
                    solve(V, dest, hmax, solucion, k+1, n, marcas, mejorSol, minLong);
                    marcas[solucion[k].fila][solucion[k].columna] = false;//si no llega a ser solución lo desmarco
                }
            }
        }
        pos++;
    }
}
int main(int argc, char **argv){
	int xFrom,
        yFrom,
        xTo,
        yTo;
    int V[3][3];
    V[0][0] = 0;V[0][1] = 3;V[0][2] = 4;V[1][0] = 1;V[1][1] = 2;V[1][2] = 3;V[2][0] = 1;V[2][1] = 1;
    V[2][2] = 1;
    cin >> xFrom;
    cin >> yFrom;
    cin >> xTo;
    cin >> yTo;
    Celda dest, from;
    dest.fila = xTo;
    dest.columna = yTo;
    dest.from = xFrom;
    dest.columna = yFrom;
    for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			cout << V[i][j] << " ";
		}
        cout << endl;
	}
    /*
    float V[][], Celda dest, int hmax,
            Celda solucion[], int k , int n, bool marcas[N][N],
            Celda mejorSol[], int &minLong
    */
    Celda solucion[n];
    Celda mejorSol[n];
    bool marcas[3][3];
    solve(V, dest, 2,solucion,1,3,mejorSol, INT_MAX);
	//Comentarlo para el juez
	char answer = 'd'; // new answer variable
	cout << "Press any key to continue, not enter";
	cin >> answer;
	cout << endl;
	
	return 0;
}