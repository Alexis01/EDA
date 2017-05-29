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
                if( inst == "addToPlaylist" ){
                    cin >> song;
                    ipud.addToPlaylist( song );
                } 
                if( inst == "current" ){
                    Can result = ipud.current();
                    cout << "Current " << result << endl;
                }
                if( inst == "play" ){
                    cout << "Sonando " << ipud.play() << endl;
                }
                if( inst == "totalTime" ){
                    cout << "Tiempo total " << ipud.totalTime() << endl;
                }
                if( inst == "recent" ){
                    int recent;
                    cin >> recent;
                    cout << "Las " << recent << " mas recientes" << endl;
                    auto vec = ipud.recent( recent );
                    for (auto p : vec) {
                        cout << "\t " << p << endl; 
                    }
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