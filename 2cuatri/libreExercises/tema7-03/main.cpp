
#include <iostream>
#include "Hours.h"
#include "Error.h"
#define MAX 10000


int main(){
    int numTrenes, numHoras; 
    Hours V[MAX];
    Hours consulta;
    cin >> numTrenes;
    cin >> numHoras;
    while( numTrenes != 0 && numHoras!=0 ){
        for (int i = 0; i < numTrenes; i++){
            cin >> V[i];
        }
        for (int i = 0; i < numHoras; i++){
            try{
                cin >> consulta;
                pos = solve(V, nTrenes, consulta);
                if(pos < numTrenes) cout << V[pos];
                else cout << "NO" << endl;
            }catch( Error e){
                cout << e.getMessage() << endl;
            }
        }

        cin >> numTrenes;
        cin >> numHoras;
    }
    return 0;
}