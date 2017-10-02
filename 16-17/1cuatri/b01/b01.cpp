#include <iostream>    // cin, cout
#include <algorithm>  // max
#include <limits>
using namespace std;

#define MAX 10000

#define utilMax std::numeric_limits<int>::max()
#define utilMin std::numeric_limits<int>::min()

bool esPico(int esPico, int V[], int pos,int N){
    int izq = ((pos-1) < 0) ? utilMax : V[pos - 1];
    int der = ((pos+1) >= N) ? utilMax : V[pos + 1];
    //cout << "pico izq: "<< izq << " der: " << der <<endl;
    return esPico > izq && esPico > der; 
}
bool esValle(int esValle, int V[], int pos, int N){
    int izq = ((pos-1) < 0) ? utilMin : V[pos - 1];
    int der = ((pos+1) >= N) ? utilMin : V[pos + 1];
    //cout << "valle izq: "<< izq << " der: " << der <<endl;
    return esValle < izq && esValle < der;
}
int solve(int A[], int N){
  int n;
  int picos = 0;
  int valles = 0;
  for (n=0; n < N ; n++){
    if( esPico( A[n], A, n, N ) ){
        picos++;
    }else{
        if( esValle( A[n], A, n, N ) ){
            valles++;
        }
    }
  }
  cout << picos << " " << valles << endl;
  return 0;
}
    



int main(int argc, char **argv){
    int n;
    int N;
    char answer = 'd'; // new answer variable
    int A[MAX];
    cin >> n;
    for (int i=0; i < n ; i++){
        cin >> N  ;
        for (int j=0; j < N ; j++){
            cin >> A[j];
        }
        solve(A,N);
    }
    //Comentarlo para el juez
    /*
    cout << "Press any key to continue, not enter";
    cin >> answer;
    cout << endl;*/
    return 0;
}