#include <iostream>
#include <fstream>
#include <climits>
#include <algorithm>

using namespace std;

#ifndef DOMJUDGE
ifstream in("test.txt");
auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

void solve( int data[], int N ){
   int p = 0, q = 1, min = INT_MAX;
   
   while( q < N ){
       int temp = abs(data[p] - data[q]);
       if( temp <= min ){
           min = temp;
       }
       p++;
       q++;
   }
   cout << min << endl;
}

int main(){
    int numCasos, pos = 0;
    cin >> numCasos;
    while( pos < numCasos ){
        int data[10000], posj = 0, limit;
        cin >> limit;
        while( posj < limit ){
            cin >> data[posj];
            posj++;
        }
        //Now we call the sort function std::begin(v), std::end(v)
        sort( data ,  data + 10000 );
        posj = 0;
        while( posj < limit ){
            cout << data[posj] << " " ;
            posj++;
        }
        //solve( data, limit );
        pos++;
    }
    return 0;
}