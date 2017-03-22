#ifndef Hours_H_
#define Hours_H_

#include<iostream>
#include "Error.h"
#include "Exceptions.h"
#include<iomanip>
using namespace std;


class Hours{
    private:
        int _horas;
        int _minutos;
        int _segundos;
    public:
        Hours(int hours, int minutes, int seconds);
        Hours(const Hours& hour);
        void write(ostream& sOut);
	    void read(istream& sIn);
        bool operator==(const Hours& hour) const;
		bool operator<(const Hours& hour) const;
};
//Constructors
Hours::Hours( int hours, int minutes, int seconds){
    if( hours >= 0 && hours <= 23){
        if( minutes >= 0 && minutes <= 59){
            if( seconds>= 0 && seconds <= 59 ){
                _horas = hours;
                _minutos = minutes;
                _segundos = seconds;
            }else{
                throw EgenericMessage("Seconds must be valid");    
            }
        }else{
            throw EgenericMessage("Minutes must be valid");    
        }
    }else{
        throw EgenericMessage("Hours must be valid");
    }
}

Hours::Hours( const Hours& hours ){

}

void Hours::write(ostream& sOut) {
	sOut << setfill('0') << setw (2) << _horas << ":"<< setfill('0') << setw (2) << _minutos << ":"<< setfill('0') << setw (2) << _segundos;
}


void Hours::read(istream& sIn) {
	int n;
	sIn >> n;
}
istream& operator >> (istream& hoursIn, Hours& hour) {
	hour.read(hoursIn);
	return hoursIn;
}


ostream& operator<<(ostream& hourOut, Hours& hour) {
	hour.write(hourOut);
	return hourOut;
}
//practica 1 
bool Hours::operator==(const Hours& hour)const{
	
	return _horas == hour._horas && _minutos == hour._minutos && _segundos == hour._segundos;
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