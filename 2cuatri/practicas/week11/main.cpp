#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
using namespace std;

#include "Ipud.h"

typedef string Can;
typedef string Art;
typedef int Dur;

/*#ifndef DOMJUDGE

ifstream in("cola.txt");

auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt

#endif
*/

void resuelve() {
    Ipud ipud;
    Can song;
    Art singer;
    Dur dur; 
    while(true){
        string inst;
        cin >> inst;
        while( inst != "FIN" ){
            try{
                if( inst == "addSong" ){
                    cin >> song;
                    cin >> singer;
                    cin >> dur;
                    ipud.addSong(song, singer, dur);
                }
            }catch(invalid_argument e) { 
                cout << e.what() << '\n' << "---\n";
            }
            
            cin >> inst;
        }
    }
   
    
}

int main() {
    resuelve();
    return 0;
}