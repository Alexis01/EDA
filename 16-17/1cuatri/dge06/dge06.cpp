#include <iostream>    // cin, cout
#include <algorithm>  // max
#include <limits>
#include <sstream>
using namespace std;

#define MAX 10000



int solve(int V[], int N){
	int n = 1;
	while( n < N ){
		V[n] += V[ n - 1 ];
		n++;
	}
	
}


int main(int argc, char **argv){
	int N;
	string line;
	stringstream iss;
	int V[MAX];
	while(cin){
		getline(cin,line);
		iss.clear();
		iss.str(line);
		for( N = 0; iss;  ){
			iss >> V[N++];
		}
		N -= 2;
		solve( V, N );
		for(int i = 0; i < N; i++ ){
			cout << V[i] << " ";
		}
		cout << endl;
	}
	return 0;
}