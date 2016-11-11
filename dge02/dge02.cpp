#include <iostream>    // cin, cout
#include <algorithm>  // max
#include <limits>
using namespace std;

#define MAX 10000

#define utilMax std::numeric_limits<int>::max()
#define utilMin std::numeric_limits<int>::min()


int minDer(int p, int V[],int N){
    int i = p + 1;
    int _min = V[i];
    while( i < N ){
        if( V[i]< _min ){
            _min = V[i];
        }
        i++;
    }
    return min;
}
int maxIzq(int p, int V[],int N){
    int i = p;
    int max = V[i];
    while( i >= 0 ){
        if( V[i] >  max ){
            min = V[i];
        }
        i--;
    }
    return max;
}

int solve(int p,int A[], int N){
  int n;
  int x = minDer(p,A,N);
  int y = maxIzq(p,A,N);
  cout << "minDer  " << x << endl;
  cout << "maxIzq  " << y << endl;
  cout << (x < y) ? "SI" : "NO" ;<< endl;
  return 0;
}
    



int main(int argc, char **argv){
    int n, 
        N,
        p,
        A[MAX];
    char answer = 'd'; // new answer variable
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
    /*
    cout << "Press any key to continue, not enter";
    cin >> answer;
    cout << endl;*/
    return 0;
}