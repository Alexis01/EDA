#include <iostream>    // cin, cout
#include <algorithm>  // max
#include <limits>
using namespace std;

#define MAX 10000

#define utilMax std::numeric_limits<int>::max()
#define utilMin std::numeric_limits<int>::min()

    
int solve(int V[], int N){
	int p = -1, n = 0;
    while(){
        
    }
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
        solve(A,N);
    }
    //Comentarlo para el juez
	char answer = 'd'; // new answer variable
    cout << "Press any key to continue, not enter";
    cin >> answer;
    cout << endl;

    return 0;
}