#include <iostream>    // cin, cout
#include <algorithm>  // max
#include <limits>
using namespace std;

#define MAX 10000
/*
ISBN

*/
long long int digitoControl(long long int x){
    cout << x << endl;
    return 10-(x%10);
}

long long int solveRecursive(int V[], int N){
	int res;
    if( N == 1 ){
        if(N%2==1){
             res = V[0] * 1;
        }else{
             res = V[0] * 3;
        }
    }else{
        if( N%2 == 0 ){
            res = solveRecursive(V, N-1 );
        }else{
            res = solveRecursive(V, N-1 );
        }
    }
    return res;
    
}
long long int solveIterative(int V[], int N){
    int n = 0, suma = 0;
    while( n < N  ){
        if( (n%2) == 0){
            suma +=  V[n] * 1;
        }else{
            if( (n%2) == 1 ){
                suma += V[n] * 3;
            }
        }
        n++;
    }   
    return 10-(suma%10);
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
		//cout <<"Solution: " <<solveIterative(A, N) << endl;
        int sumPares = 0;
        int sumImpares = 0;
        /*solveRecursive(A, N, sumPares, sumImpares);
        cout <<"SumPares: " << sumPares << endl;
        cout <<"sumImpares: " <<  sumImpares << endl;*/
        cout <<"SumPares: " << digitoControl(solveRecursive(A, N)) << endl;
	}
	//Comentarlo para el juez
	char answer = 'd'; // new answer variable
	cout << "Press any key to continue, not enter";
	cin >> answer;
	cout << endl;
	
	return 0;
}