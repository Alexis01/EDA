#include <iostream>    // cin, cout
#include <algorithm>  // max
#include <limits>
using namespace std;

#define MAX 10000

#define utilMax std::numeric_limits<int>::max()
#define utilMin std::numeric_limits<int>::min()

    
int solve(int p,int V[], int N){
    int pos = 0,
        minDer = V[p+1],
        maxIzq = V[0];
    while( pos < N ){
        if( pos <= p ){
            maxIzq = (V[pos] > maxIzq) ? V[pos] : maxIzq; 
        }
        if( pos > p ){
            minDer = (V[pos] < minDer) ? V[pos] : minDer;
        }
        pos++;
    }
    
    if( maxIzq < minDer ){
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
    //char answer = 'd'; // new answer variable
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
    /*cout << "Press any key to continue, not enter";
    cin >> answer;
    cout << endl;*/
    return 0;
}