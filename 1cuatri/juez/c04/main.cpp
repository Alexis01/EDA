
/*
Compute number of maximum values in a non-empty vector

P : N > 0

proc frecMax(V[0..N) of int, out int M, out int fr)

Q : M = max i : 0 <= i < N : V[i] && fr = #i : 0 <= i < N : V[i]==M
*/
#include <iostream>
#include <fstream>
#include <algorithm>    // std::max
#include <climits>

using namespace std;

#ifndef DOMJUDGE

ifstream in("test.txt");

auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt

#endif


#define MAXIMUM 20000


void solve(int v[], int N, int &num_max, int &cant){
	int i = 0, max = INT_MIN;
	while (i < N){
		if (v[i]> max){
			max = v[i];
			num_max = max;
		}
		i++;

	}
	int n = 0;
	while (n < N){
		if (v[n] == num_max){
			cant++;
		}
		n++;
	}
}
void solveV2(int v[], int N, int &num_max, int &cant){
	int i = 0, max = INT_MIN, frec = 0;
	while (i < N){
		if (v[i]> max){
			max = v[i];
			frec = 0;
		}
		if(v[i]  == max ){
			frec++;
		}
		i++;
	}
	num_max = max;
	cant = frec;
}
int main(){
	int C, c;
	int N, n;
	int M, fr;
	cin >> C;
	for (c = 0; c<C; c++){
		cin >> N;
		int V[MAXIMUM];
		for (n = 0; n < N; n++){
			cin >> V[n];
		}
		fr = 0;
		M = 0;
		solve(V, N, M, fr);
		cout << M << " " << fr << endl;
		solveV2(V, N, M, fr);
		cout << M << " " << fr << endl;
	}

}