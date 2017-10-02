#include <iostream>    // cin, cout
#include <algorithm>  // max
#include <limits>
using namespace std;

#define MAX 10000



int solve(int V[], int N){
	int p = -1, nz = 0, nu = 0, n = 0;
	while (n < N){
		if (V[n] == 0){
			nz++;
		}
		if (V[n] == 1){
			nu++;
		}
		if (nz == nu){
			p = n;
		}
		n++;
	}
	return p;
}


int main(int argc, char **argv){
	int n,
		N,
		A[MAX];

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> N;
		for (int j = 0; j < N; j++){
			cin >> A[j];
		}
		cout << solve(A, N) << endl;
	}
	//Comentarlo para el juez
	/*char answer = 'd'; // new answer variable
	cout << "Press any key to continue, not enter";
	cin >> answer;
	cout << endl;*/
	
	return 0;
}