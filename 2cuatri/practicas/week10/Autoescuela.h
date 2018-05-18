
#include <string>
#include "HashMap.h"
#include <list>
#include<iomanip>
#include "Exceptions.h"
#include <stdexcept>
using namespace std;

typedef string Profesor;
typedef string Alumno;
struct InfoAlumno{
    Profesor prof;
    int puntos;
};
typedef HashMap< Alumno, InfoAlumno >::Iterator _Iter;

class Autoescuela{

    private:
        HashMap< Alumno, InfoAlumno > _autoescuela;

    public:
        Autoescuela();
        void alta(Alumno al, Profesor prof);
        bool es_alumno(Alumno al, Profesor prof);
        list<Alumno> examen(Profesor, int notaCorte);
        void actualizar(Alumno al, int cantidad);
        int puntuacion(Alumno al);
        void aprobar(Alumno al);
        
};

Autoescuela::Autoescuela(){};
void Autoescuela::alta(Alumno al, Profesor prof){
    _Iter it = _autoescuela.find(al);
    if(it == _autoescuela.end()){ //no matriculado
        // cout << "Nuevo Alumno" << endl;
        InfoAlumno info;
        info.puntos = 0;
        info.prof = prof;
        _autoescuela.insert(al, info);
    }else{
        // cout << "Cambia profe" << endl;
        InfoAlumno info = it.value();
        if(info.prof != prof){ //cambia de prof
            InfoAlumno newInfo;
            newInfo.prof = prof;
            newInfo.puntos = info.puntos;
            _autoescuela.insert(al, newInfo);
        }
    }
    
};
bool Autoescuela::es_alumno(Alumno al, Profesor prof){
    _Iter it = _autoescuela.find(al);
    bool ok = false;
    if(it != _autoescuela.end()){
        InfoAlumno info = it.value();
        if( info.prof == prof){
            ok = true;
        }
    }
    return ok; 
};
list<Alumno> Autoescuela::examen(Profesor prof, int notaCorte){
    list<Alumno> result;
    // cout << "Buscando alumnos de " << prof << endl;
    _Iter it = _autoescuela.begin();
    while(it != _autoescuela.end()){
        InfoAlumno info = it.value();
        // cout << "Alumno " << it.key() << endl;
        // cout << "Profe " << info.prof << endl;
        if(info.prof == prof  && info.puntos >= notaCorte){
            result.push_back(it.key());
        }
        it.next();
    }
    return result;
};
void Autoescuela::actualizar(Alumno al, int cantidad){
    _Iter it = _autoescuela.find(al);
    if( it != _autoescuela.end()){
        InfoAlumno newInfo;
        newInfo.prof = it.value().prof;
        newInfo.puntos = it.value().puntos + cantidad;
        _autoescuela.insert(al, newInfo);
    }else{
        string msg = "El alumno "+al+" no esta matriculado";
        throw domain_error(msg);
    }
};
int Autoescuela::puntuacion(Alumno al){
    _Iter it = _autoescuela.find(al);
    if( it != _autoescuela.end()){
        return it.value().puntos;
    }else{
        string msg = "El alumno "+al+" no esta matriculado";
        throw domain_error(msg);
    }
};
void Autoescuela::aprobar(Alumno al){
    _Iter it = _autoescuela.find(al);
    if( it != _autoescuela.end()){
        _autoescuela.erase(it.key());
    }else{
        string msg = "El alumno "+al+" no esta matriculado";
        throw domain_error(msg);
    }
};