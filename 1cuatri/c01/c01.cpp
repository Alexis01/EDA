/*
{b > 1 ∧ n > 1}
fun log(int b, int n) return int r
{ b^r−1 < n ≤ b^r }

*/

#include <iostream>    // cin, cout
#include <algorithm>  // max
#include <limits>
#include <limits.h>
#include <math.h>
using namespace std;

#define MAX 10000

unsigned long solve( int B, int N){
	unsigned long r = 0;
    bool found = false;
    while(!found){
        found = ( ( pow(B,r-1) < N ) && ( N <= pow(B,r) ) );
        if(!found){
            r++;
        } 
    }
    return r;
	
}

int main(int argc, char **argv){
	int n,
		B,
        N;

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