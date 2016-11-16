#include <iostream>    // cin, cout
#include <algorithm>  // max
#include <limits>
using namespace std;

#define MAX 10000



int solve(int V[], int N){
	int sumPar = 0;
	int i = 0;
	int result[MAX];
	while (i < N ){
		sumPar += V[i];
		result[i] = sumPar;
		cout << result[i] << " ";
		i++;
	}
	cout << endl;
	return 0;
}


int main(int argc, char **argv){
	int	p = 1,
		A[MAX];
	int numElems = 0;
	//while (true){
		while ((cin >> p) && p != 0){
			A[numElems] = p;
			numElems++;
		}
		solve(A, numElems);
		numElems = 0;
	//}
	return 0;
}