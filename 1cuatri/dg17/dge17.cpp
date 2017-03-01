//dge17: Alexis (Template: Rafael Martinez Torres)

#include <iostream>  // cout, cin
#include <algorithm>  // max, min
#include <iterator> // distance, next, prev...
#include <sstream>  // istringstream

using namespace std;


/*   

Pseudocode:
------------
Note: Spliting on half preserves
      curve concavity.

// P : j-i >= 1 , concave(V)
// Q : m: min k : i <= j < k : V[k]
fun mincurve(V[i..j) of int) dev m:int
  case (j-i)==1
       dev V[i]
  case (j-i)==2
       dev min(V[i],V[i+1])
  case (j-i)>2
       let
          half=(i+j)/2
       in
          if (V[half-1] > V[half] <V[half+1])
	     return V[half]; 
	  if (V[half-1] > V[half] >= V[half+1])
	     return mincurve(V[half..end)) 
	  if (V[half-1] < V[half] 
	     return mincurve(V[i..half)) 
	  if (V[half-1] == V[half] )
	     return min(
	                mincurve(V[begin,half)),
			mincurve(V[half,end))) 
	                           
	  
A=2 , B=2 , k = 0 , hence O(n^log_b(a))=O(n)
 
*/


int solve(int *V, int len)
{
  if (len==1)
    return V[0];
  if (len==2)
    return min(V[0],V[1]);
  if (len>2)
    {
      int half=len/2;
      if ((V[half-1]> V[half]) and (V[half] < V[half+1]) )
	return V[half];
      if ((V[half-1]> V[half]) and (V[half] >= V[half+1]) )
	return solve(V+half,len-half);
      if (V[half-1] < V[half])
	return solve(V,half);
      if (V[half-1] == V[half]) 
	  return min(solve(V,half),solve(V+half,len-half)); // Fall in O(n)
    }
}




#define MAX 10000


int main(int argc, char **argv)
{
  int n,t,a,b;
  int N;
  int A[MAX];
  istringstream iss ;  
  string line;
  while (getline(cin,line))
    {
      iss.clear();
      iss.str(line);
      iss >> N ;
      getline(cin,line);
      iss.clear();
      iss.str(line);	    
      for (int i=0; i < N ; i++) iss >> A[i];
      cout << solve(A,N)  << endl;
    }
  return 0;
}
 