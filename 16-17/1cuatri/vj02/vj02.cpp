#include <iostream>    // cin, cout
#include <algorithm>  // max
#include <limits>
#include <limits.h>
using namespace std;

#define MAX 10000

void solve(int V[], int N, int P){
	int n = 0;
    bool yes = false;
    if( P == N - 1 ){
        yes = true;
    }else{
        // 1 < n < 10000 -> 0 < p < 9999 
        //[0..p] < [p+1...n-1]
        int mayorIzq = INT_MIN, menorDerecha = INT_MAX;
        while( n < N ){
            if( n <= P ){
                mayorIzq = ( V[n] > mayorIzq ) ? V[n] : mayorIzq;
            }else{
                menorDerecha = ( V[n] < menorDerecha ) ? V[n] : menorDerecha;
            }
            n++;
        }
        yes = ( mayorIzq < menorDerecha );
    }
	if(yes){
        cout << "SI" << endl;
    }else{
        cout << "NO" << endl;
    }
 
	
}

int main(int argc, char **argv){
	int n,
		N,
        P,
		A[MAX];

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> N;
        cin >> P;
		for (int j = 0; j < N; j++){
			cin >> A[j];
		}
		solve(A, N, P);
	}
	//Comentarlo para el juez
	/*char answer = 'd'; // new answer variable
	cout << "Press any key to continue, not enter";
	cin >> answer;
	cout << endl;*/
	
	return 0;
}