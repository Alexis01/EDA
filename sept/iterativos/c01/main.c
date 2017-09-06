#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

#ifndef DOMJUDGE
ifstream in("test.txt");
auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

unsigned long solve( unsigned long b, unsigned long n ){
    unsigned long long int r = 0;
	bool found = false;
	while(!found){
		found = ((pow(b,r-1) < n) && (n <= pow(b,r)));
		if(!found){
			r++;
        }
	}
	return r;
}

int main(){
    int numCasos, pos = 0;
    cin >> numCasos;
    while( pos < numCasos ){
        unsigned long b, n;
        cin >> b >> n;
        unsigned long result = solve( b, n );
        cout << result << endl;
        pos++;
    }
    return 0;
}