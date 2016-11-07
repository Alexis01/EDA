#include <iostream>    // cin, cout
#include <algorithm>  // max
using namespace std;

#define MAX 10000



int solve(int A[], int N){
  int n;
  int s;
  for (n=s=0; n < N ; n++){
    s += ((A[n] % 2 )==0) ;
  }
  
  return s;
}
    



int main(int argc, char **argv){
    int n;
    int N;
    char answer = 'd'; // new answer variable
    int A[MAX];
    cin >> n;
    for (int i=0; i < n ; i++){
        cin >> N  ;
        for (int j=0; j < N ; j++){
            cin >> A[j];
        }
    }
    int result = solve(A,N);
    cout << "Resultado: " << result << endl;
    cout << "Press any key to continue, not enter";
    cin >> answer;
    cout << endl;
    return 0;
}