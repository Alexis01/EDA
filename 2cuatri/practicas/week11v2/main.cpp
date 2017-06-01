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

#ifndef DOMJUDGE

ifstream in("cola.txt");

auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt

#endif


bool resuelve() {
    string operacion;
    cin >> operacion;
    if (!cin)
        return false;
    Can tit; Art aut; Dur dur;
    Ipud ipud;
    while (operacion != "FIN") {
        try {
            if (operacion == "addSong") {
                cin >> tit >> aut >> dur;
                ipud.addSong(tit, aut, dur);
            } else if (operacion == "addToPlaylist") {
                cin >> tit;
                ipud.addToPlaylist(tit);
            } else if (operacion == "current") {
                tit = ipud.current(); // aunque no se hace nada, puede producir error
            } else if (operacion == "play") {
                try {
                    string tocando = ipud.current(); // para saber si la lista es vacía
                    ipud.play();
                    cout << "Sonando " << tocando << '\n';
                } catch (invalid_argument e) {
                    cout << "No hay canciones en la lista\n";
                }
            } else if (operacion == "totalTime") {
                cout << "Tiempo total " << ipud.totalTime() << '\n';
            } else if (operacion == "recent") {
                int N;
                cin >> N;
                auto lista = ipud.recent(N);
                if (lista.empty())
                    cout << "No hay canciones recientes\n";
                else {
                    cout << "Las " << N << " mas recientes\n";
                    for (auto const& s : lista)
                        cout << "    " << s << '\n';
                }
            } else if (operacion == "deleteSong") {
                cin >> tit;
                ipud.deleteSong(tit);
            }
        } catch (invalid_argument e) {
            cout << "ERROR " << e.what() << '\n';
        }
        cin >> operacion;
    }
    cout << "----\n";
    return true;
}

int main(){
    while (resuelve()){}
        //return true;
    return 0;
}