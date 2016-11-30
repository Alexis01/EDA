#include <iostream>    // cin, cout
#include <algorithm>  // max
#include <limits>
using namespace std;

#define MAX 10000

#define utilMax std::numeric_limits<int>::max()
#define utilMin std::numeric_limits<int>::min()

    
int solve(int p,int V[], int N){
	int max = V[0],
		pos = 1;
	bool correct = true;
    while( pos < N ){
		if (pos <= p){
			if (V[pos] >= max){
				max = V[pos];
			}
		}
		if (pos > p){
			if ( V[pos] <= max){
				correct = false;
			}
		}
        pos++;
    }
    if( correct ){
        cout << "SI" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}


int main(int argc, char **argv){
    int n, 
        N,
        p,
        A[MAX];
    
    cin >> n;
    for (int i=0; i < n ; i++){
        cin >> N ;
        cin >> p;
        for (int j=0; j < N ; j++){
            cin >> A[j];
        }
        solve(p,A,N);
    }
    //Comentarlo para el juez
	/*char answer = 'd'; // new answer variable
    cout << "Press any key to continue, not enter";
    cin >> answer;
    cout << endl;*/

    return 0;
}