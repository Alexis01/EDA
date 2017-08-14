#include <iostream>
#include <fstream>
using namespace std;


// #ifndef DOMJUDGE

// ifstream in("test.txt");

// auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt

// #endif

int solve( int data[], int N ){
    int pos = 0, result = 0;
    while( pos < N ){
        if( data[pos] % 2 == 0 ){
            result++;
        }
        pos++;
    }
    return result;
}

int main(){
    int numCasos, pos = 0;
    int decDist = 0;
    int muestra[10000];
    cin >> numCasos;
    while( pos < numCasos ){
        cin >> decDist;
        int posj = 0;
        while( posj < decDist ){
            cin >> muestra[posj];
            posj++;
        }
        pos++;
    }
    int result = solve(muestra, decDist);
    cout << "Result: " << result << endl;
    cout << "Press any key to continue, not enter";
    char answer;
    cin >> answer;
    cout << endl;
    return 0;
}