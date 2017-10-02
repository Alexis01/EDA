#include <iostream>
#include <fstream>
#include <algorithm>  // max, min
using namespace std;

#ifndef DOMJUDGE
ifstream in("test.txt");
auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

int factorial(int num  ){
    int r;
    if(num < 2){
        r = 1;
    }else{
        if(num > 0){
            r = num * factorial(num - 1);
        }
    }
    return r;
}
int mcd( int a, int b ){
    int m;
    if ( a == b ) m = a;
    else if ( a > b ) m = mcd(a-b, b);
    else if ( a < b ) m = mcd(a, b-a);
    return m;
}
/*
una funci´on que dado un natural n calcule la suma
de los dobles de los naturales hasta n:
*/
int sumDoble(int n){
    int result;
    if(n == 0){
        result = 0;
    }else{
        if(n % 2 == 0){
            result = 2 * n  + sumDoble(n-1);
        } 
    }
    cout << result << endl;
    return result;
}
/*suma de las componentes de un vector de enteros.
{longitud(v) ≥ num}
fun sumaVec (int v[], int num) return int r
{r = Sumatorio : 0 ≤ i < num : v[i]}
*/
int sumaVec ( int v[], int num ) {
    // P re : longitud(v) ≥ num
    int r;
    if ( num <= 0 )
        r = 0;
    else{
        if ( num > 0 ){
            r = sumaVec(v, num-1) + v[num-1];
        }
    } 
    return r;
    // P o s t : r  Pi : 0 ≤ i < num : v[i]
}
int buscaBin( int V[], int x, int a, int b ){
    // Pre: v est´a ordenado entre 0 .. num−1
    // (0 ≤ a ≤ num) ∧ (−1 ≤ b ≤ num − 1) ∧ (a ≤ b + 1)
    // todos los elementos a la izquierda de ’a’ son ≤ x
    // todos los elementos a la derecha de ’b’ son> x
    int p, m;
    // cuerpo de la funci´on
    if(a == b + 1){//por el cruce
        p = a - 1;
    }else{
        if(a<=b){
            m = (a + b) / 2;
            if(V[m] <= x){
                p = buscaBin(V,x,m+1,b);
            }else{
                p = buscaBin(V,x,m-1,a);
            }
        }
    }
    return p;
    // Post: devuelve el mayor ´ındice i (0 ≤ i ≤ num − 1) que cumple v[i] <= x
    // si x es menor que todos los elementos de v, devuelve−1
}
int binarySearch(int V[], int toSearch, int N){
    return buscaBin(V,toSearch, 0, N - 1);
}
void particion(int V[],int a, int b, int &p){
    int i,j;
    int aux;
    i = a+1;
    j = b;
    while(i <= j ){
        if( (V[i]> V[a]) && (V[j] < V[a]) ){
            aux = V[i];
            V[i] = V[j];
            V[j] = aux;
            i = i + 1;
            j = j - 1;
        }else{
            if(V[i] <= V[a]){
                i = i + 1;
            }
            if(V[j] >= V[a]){
                j = j - 1;
            }
        }
    }
    p = j;
    aux = V[a];
    V[a] = V[p];
    V[p] = aux;
}
int quickSort(int V[], int a, int b){
    int p;
    if( a <= b ){
        particion(V,a,b,p);
        quickSort(V,a,p-1);
        quickSort(V,p+1,b);
    }
    return p;
}

void quickSort ( int V[], int N ) {
    // / P re : 0 ≤ a ≤ num && −1 ≤ b ≤ num−1 && a ≤ b+1
    // num ≥ 0
    quickSort(V, 0, N-1);
    int pos = 0;
    while(pos < N ){
        cout << V[pos] << endl;
        pos++;
    }
    // P o s t : v e s t ´a o r de na d o e n t r e a y b
}
void merge(int *v, int i, int m, int f) {
    int *aux = new int[m-i+1];
    for(int j=i; j<=m; j++)
     aux[j-i] = v[j];
     
    int c1=0, c2=m+1;
    for(int j=i; j<=f; j++) {
        if(aux[c1] < v[c2]) {
            v[j] = aux[c1++];
            if(c1==m-i+1)
                for(int k=c2; k<=f; k++)
                    v[++j] = v[k];
        }else {
            v[j] = v[c2++];
            if(c2==f+1)
                for(int k=c1; k<=m-i; k++)
                    v[++j] = aux[k];
        }
    }
    delete [] aux; 
}
void mergeSort(int V[], int a, int b){
    int m;
    if(a < b){
        m = (a+b)/2;
        mergeSort(V,a,m);
        mergeSort(V,m+1,b);
        merge(V,a,m,b);
    }
}
void mergeSort( int V[], int N){
    mergeSort(V, 0, N-1);
    int pos = 0;
    while(pos < N ){
        cout << V[pos] << endl;
        pos++;
    }
}
int numCortesDerGen(int V[], int num, int s){
    int r;
    if(num == 0 ){
        r = 0;
    }else{
        if( num > 0 ){
            if(s == V[num - 1] ){
                r = numCortesDerGen(V, num-1,s+V[num-1]) + 1;
            }else{
                r = numCortesDerGen(V, num-1,s+V[num - 1]);
            }
        }
    }

    return r;
}
/*
funcion que calcula cuantas componentes de un
vector son iguales a la suma de las componentes situadas a su
derecha:
*/
int numCortesDer(int V[], int num){
    return numCortesDerGen(V, num, num - 1 );
}
//r número de cortes que se tienen
//s suma desde entre 0 y n - 1  lineal
int numCortesIzqGen(int V[],int num,int &s, int &r){
    if(num == 0){
        r = 0;
        s = 0;
    }else{
        if( num > 0){
            numCortesIzqGen(V, num - 1, r, s);
            if( s == V[num-1]){
                r = r + 1;
            }
            s = s + V[num - 1];
        }
    }
}
//más optimo recorrer de izq a derecha
int numCortesIzqGen(int V[],int num,int a, int s, int i){
    int r;
    if( i == num ){
        r = a;
    }else{
        if(i < num){
            if(s == V[i]){
                r = numCortesIzqGen(V, num, a+1, s+V[i], i+1);
            }else{
                r = numCortesIzqGen(V, num, a, s+V[i], i+1);
            }
        }
    }
    return r;
}
/*
cu´antas componentes de un vector son iguales a la
suma de las componentes que la preceden.
*/
int numCortesIzq( int v[], int num ){
    /*int r, s; 
    numCortesIzqGen(V, num,r, s  );
    return r;*/
    return numCortesIzqGen( v, num, 0, 0, 0 );
}
int main(){
    int numCasos, pos = 0;
    cin >> numCasos;
    // while( pos < numCasos ){
    //     int numData, posD = 0, V[10000];
    //     cin >> numData;
    //     //cout << factorial(numData) << endl;
    //     //cout << sumDoble(a) << endl;
    //     while( posD < numData ){
    //         cin >> V[posD];
    //         posD++;
    //     }
    //     cout << sumaVec(V, numData) << endl;
    //     pos++;
    // }
    // int V[20] = {1,2,3,7,8};
    // cout<< binarySearch(V,8,5) << endl;
    // int A[20] = {2,3,4,5,10};
    // cout<< binarySearch(A,2,5) << endl;
    // int V[20] = {10,9,8,7,6};
    // quickSort(V,5);
    // int A[20] = {12,23,4,5,10};
    // quickSort(A,5); numCortesDer
    // int V[20] = {10,9,8,7,6};
    // mergeSort(V,5);
    // int A[20] = {12,23,4,5,10};
    // mergeSort(A,5);
    // int V[20] = {2,9,8,7,2};
    // cout << numCortesDer(V,5) << endl;
    // int A[20] = {1,1,1,1,1};
    // cout << numCortesDer(A,5) << endl;
    // int V[20] = {2,4,8,7,2};
    // cout << numCortesIzq(V,5) << endl;
    // int A[20] = {1,1,1,1,1};
    // cout << numCortesIzq(A,5) << endl;
    
    return 0;
}