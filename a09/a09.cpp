// Author : Alexis, Cristina

#include <iostream>    // cin, cout
#include <algorithm>  // max
using namespace std;

#define MAX 10000
int solve( int cotaSup ){
	int days = 0, s = 0, s0,s1,s2;
	while( s < cotaSup ){
		switch( s ){
			case 0: {
				s0 = 1;
				break;
			}
			case 1: {
				s1 = s0;
				s0 = 1;
				break;
			}
			default: {
				s2 = s1;
				s1 = s0; 
				s0 = 2*s2 + s1;
				break;
			}
		}
		s = s + s0;
		days ++;
	}
	cout << days << endl;
	return days;
}




int main(int argc, char **argv){
	int n;
	int cotaSup;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> cotaSup;
		solve(cotaSup);
	}
	return 0;
}
