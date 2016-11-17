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
	stringstream ssin(line);
	int V[MAX];
	int pos = 0;
	while(cin){
		getline(cin,line);
		
		solve(V,sizeof(V));
		cout << "Press any key to continue, not enter";
		char answer = 'd';
		cin >> answer;
		cout << endl;
		
		
	}
}