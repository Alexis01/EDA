#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include "Autoescuela.h"
#include <list>
using namespace std;

typedef string alumno;
typedef string profesor;


#ifndef DOMJUDGE

ifstream in("autoescuela.txt");

auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt

#endif

bool resuelve() {  
    while(true){
        Autoescuela aut;
        string inst;
        cin >> inst;
        while(inst != "FIN"){
            alumno al;
            profesor prof;
            try{
                if(inst == "alta"){
                    cin >> al;
                    cin >> prof;
                    aut.alta(al, prof);
                }else{
                    if(inst == "es_alumno"){
                        cin >> al;
                        cin >> prof;
                        if(aut.es_alumno(al, prof)){
                            cout << al << " es alumno de " << prof << endl;
                        }else{
                            cout << al << " no es alumno de " << prof << endl;
                        }
                    }else{
                        if(inst == "examen"){
                            cin >> prof;
                            int notaCorte;
                            cin >> notaCorte;
                            cout << "Alumnos de "<< prof << " a examen:" << endl;;
                            list<alumno> listado = aut.examen(prof, notaCorte);
                            listado.sort();
                            list<alumno>::iterator it = listado.begin();
                            while(it != listado.end()){
                                cout << *(it) << endl;
                                it++;    
                            }
                        }else{
                            if(inst == "actualizar"){
                                cin >> al;
                                int aumentar;
                                cin >> aumentar;
                                aut.actualizar(al, aumentar);
                            }else{
                                if(inst == "puntuacion"){
                                    cin >> al;
                                    aut.puntuacion(al);
                                    cout << "Puntuacion de " << al << ": " << aut.puntuacion(al) << endl;
                                }else{
                                    if(inst == "aprobar"){
                                        cin >> al;
                                        aut.aprobar(al);
                                    }
                                }
                            }
                        }
                    }
                }
            }catch(domain_error e) { 
                cout << "ERROR" << endl;
            }
            
            cin >> inst;
        }
        cout << "------" << endl;
    }
    
    
    
}

int main() {
    resuelve();
    //while (){}
    return 0;
}