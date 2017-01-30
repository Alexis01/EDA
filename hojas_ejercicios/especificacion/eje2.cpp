#include <iostream>    // cin, cout
#include <algorithm>  // max
#include <limits>
#include <limits.h>
using namespace std;

#define MAX 10000

void solve(int a[], int N){
    int ok = true, pos = 1, min = a[0];
    while(pos < N && ok){
        if(min >= a[pos]){
            ok = false;
        }else{
            min = a[pos];
        }
        pos++;
    }
    char esCreciente = ok ? 'y':'n';
	cout<<  esCreciente << endl;
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
		solve(A, N);
	}
	
	//Comentarlo para el juez
	char answer = 'd'; // new answer variable
	cout << "Press any key to continue, not enter";
	cin >> answer;
	cout << endl;
	
	return 0;
}