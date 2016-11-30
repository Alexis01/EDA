#include <iostream>    // cin, cout
#include <algorithm>  // max
#include <limits>
using namespace std;

#define MAX 10000


    
int solve(int V[], int N){
	int p = 0, n = 1, m = V[0], s = V[0];
	while ( n < N ){
		s = max(s, V[n]);
		if (V[n] <= m){
			p = n;
			m = max( m, s);
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
    for (int i=0; i < n ; i++){
        cin >> N ;
        for (int j=0; j < N ; j++){
            cin >> A[j];
        }
		cout << solve(A,N) << endl;
    }
    //Comentarlo para el juez
	/*char answer = 'd'; // new answer variable
    cout << "Press any key to continue, not enter";
    cin >> answer;
    cout << endl;
*/
    return 0;
}