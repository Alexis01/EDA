#ifndef Hours_H_
#define Hours_H_

#include<iostream>
#include "Error.h"
#include "Exceptions.h"

using namespace std;


class Hours{
    private:
        int horas;
        int minutos;
        int segundos;
    public:
        Hours(int hours, int minutes, int seconds);
        Hours(const Hours& hour);
        void write(ostream& sOut);
	    void read(istream& sIn);
};
//Constructors
Hours::Hours( int hours, int minutes, int seconds){
    if( hours >= 0 && hours <= 23){
        if( minutes >= 0 && minutes <= 59){
            if( seconds>= 0 && seconds <= 59 ){
                horas = hours;
                minutos = minutes;
                segundos = seconds;
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
	sOut << horas << ":" << minutos << ":" << segundos;
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
#endif /* Hours_H_ */