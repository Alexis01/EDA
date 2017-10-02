//C01
//Axel Junestrand

//-----------------------------------------
//P={(b > 1) and (n > 1)}
//I={(0 <= y < 64) and (pow(b,y-11) < n <= pow(b,y))}
//Q={pow(b,r-1) < n <= pow(b,r)}
//B={i < nCases}
//-----------------------------------------

#include <iostream>
#include <math.h>
using namespace std;

int log(long long unsigned int b, long long unsigned int n);

int main(){
	int nCases; //Number of cases
	long long unsigned int b, n;

	//User input
	cin >> nCases;
	for(int i = 0; i < nCases; i++){
		cin >> b >> n;
		cout << log(b,n) << endl;
	}
	return 0;
}

int log(long long unsigned int b, long long unsigned int n){
	unsigned long long int r = 0;
	bool found = false;
	while(!found){
		found = ((pow(b,r-1) < n) && (n <= pow(b,r)));
		if(!found)
			r++;
	}
	return r;
}