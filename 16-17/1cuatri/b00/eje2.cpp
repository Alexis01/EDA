// Author : Rafael Martinez Torres

/*
  N >= 0 
  Q : s = # i : 1 <= i <= N : (A[i] % 2 = 0)
  I : Q[N/n] and 0 <= n <= N
  B : n<N 
  Init : n,s = 0, 0
  Step : n = n + 1
  Restore: s = s + \chi(A[n]%2==0)
           
  Quote : N-n

  Pseudo-code
  -------------
  n,s =  0 , 0
  while (n < N )
     s = s + \chi(A[n]%2==0)
     n = n + 1

Note: \chi(true)=1
      \chi(false)=0
*/

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