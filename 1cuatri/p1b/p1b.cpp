/*
{b > 1 ∧ n > 0}
fun log(int b, int n) return int r
{b^r ≤ n < b^(r+1)}

I : 1 <= n0 and n0 = n / b^r
B : n0 >= b
C(n): n0

*/

#include <iostream>    // cin, cout
#include <algorithm>  // max
#include <limits>
#include <limits.h>
#include <math.h>
using namespace std;

#define MAX 10000

int solve( int B, int N){
	int r = 0;
    bool found = false;
    while(!found){
        found = ( ( pow(B,r) <= N ) && ( N < pow(B,r+1) ) );
        if(!found){
            r++;
        } 
    }
    return r;
	
}

int main(int argc, char **argv){
	int n,
		B,
        N,
		V[MAX];

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> B;
        cin >> N;
		cout << solve( B, N ) << endl;
	}
	//Comentarlo para el juez
	/*char answer = 'd'; // new answer variable
	cout << "Press any key to continue, not enter";
	cin >> answer;
	cout << endl;*/
	
	return 0;
}