/*
 el primer d´ıa le dar´a un
c´entimo de euro, el segundo otro c´entimo de euro y a partir del tercero siempre le dar´a el doble de lo que
le dio dos d´ıas antes m´as lo que le dio justo el d´ıa antes. Jaime calcula cu´antos d´ıas tardar´a en tener el
dinero suficiente, pero... a veces se pregunta cu´anto tardar´ıa en hacerse millonario

g++ -std=c++11 main.c -o main

*/
#include <iostream>
#include <fstream>
using namespace std;


#ifndef DOMJUDGE

ifstream in("test.txt");

auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt

#endif

void solve( int moneyToGet  ){
    int s = 0, s0,s1,s2;
    int days = 0;
    while( s < moneyToGet ){
        switch(days){
            case 0:{
                s0 = 1;
                break;
            }
            case 1:{
                s1 = s0;
                s0 = 1;
                break;
            }
            default:{
                s2 = s1;
                s1 = s0;
                s0 = 2 * s2 + s1;
                break;
            }
        }
        s = s + s0;
        days++;
    }
    cout << days << endl;
}

int main(){
    int numCasos, pos = 0;
    int money = 0;
    cin >> numCasos;
    while( pos < numCasos ){
        cin >> money;
        solve( money );
        pos++;
    }
    return 0;
}