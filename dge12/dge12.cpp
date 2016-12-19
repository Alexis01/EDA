#include <iostream>    // cin, cout
#include <algorithm>  // max
#include <limits>
using namespace std;

#define MAX 10000

void solve(int V[], int N, int T){
	int r = 0, s = 0,n = 0, a = 0, b =0;
	while (n < N){
        if( V[n] <= T ){
            s = n + 1;
        }
        if( r < ( n + 1 - s ) ){
            r = n + 1 - s;
            a = s;
        }
		n++;
	}
    b = a + r - 1;
	cout << a << " " << b << endl;
}


int main(int argc, char **argv){
	int n,
		N,
        T,
		A[MAX];

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> N;
        cin >> T;
		for (int j = 0; j < N; j++){
			cin >> A[j];
		}
		solve(A, N, T);
	}
	//Comentarlo para el juez
	/*char answer = 'd'; // new answer variable
	cout << "Press any key to continue, not enter";
	cin >> answer;
	cout << endl;*/
	
	return 0;
}