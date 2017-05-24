#ifndef Hours_H_
#define Hours_H_

#include<iostream>
#include "Error.h"
#include "Exceptions.h"
#include<iomanip>
using namespace std;


class Hours {
    private:
        int _horas;
        int _minutos;
        int _segundos;
    public:
        Hours();
        void setHora( int hours, int minutes, int seconds );
        void write(ostream& sOut);
        bool operator==(const Hours& hour) const;
		bool operator<(const Hours& hour) const;
        friend istream &operator>>(istream &sIn, Hours &hora);
        friend ostream &operator<<(ostream &sOut, Hours &hora);
};
//Constructors
Hours::Hours( ){
    _horas = 00;
    _minutos = 00;
    _segundos = 00;
}

void Hours::write(ostream& sOut) {
	sOut << setfill('0') << setw (2) << _horas << ":"<< setfill('0') << setw (2) << _minutos << ":"<< setfill('0') << setw (2) << _segundos;
}
ostream& operator<<(ostream& hourOut, Hours& hour) {
	hour.write(hourOut);
	return hourOut;
}

void Hours::setHora( int hours, int minutes, int seconds ){
    _horas = hours;
    _minutos = minutes;
    _segundos = seconds;
}
istream& operator>>(istream &sIn, Hours &hour) {
    int h, m, s;
    char c;
    sIn >> h;
    sIn.get(c);
    sIn >> m;
    sIn.get(c);
    sIn >> s;
    if( h >= 0 && h <= 23 && 
        m >= 0 && m <= 59 && 
        s>= 0 && s <= 59 ){
        hour.setHora( h, m, s );
    }else{
        throw EgenericMessage("Hours must be valid");
    }
    return sIn;
}

bool Hours::operator<(const Hours& hour)const{
    bool ok = false;
	if( _horas < hour._horas ){
        ok = true;
    }else{
        if( _horas == hour._horas ){
            if( _minutos < hour._minutos ){
                ok = true;
            }else{
                if( _segundos < hour._segundos ){
                    ok = true;
                }
            }
        }
    }
    return ok;
}
#endif /* Hours_H_ */