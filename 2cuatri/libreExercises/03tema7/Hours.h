#ifndef Hours_H_
#define Hours_H_

#include<iostream>
#include "Error.h"
#include "Exceptions.h"

using namespace std;

template<class T>
class Hours{
    private:
        int horas;
        int minutos;
        int segundos;
    public:
        Hours(int hours, int minutes, int seconds);
        Hours(const Hours<T>& hour);
};
//Constructors
template<class T>
Hours<T>::Hours( int hours, int minutes, int seconds){
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
template<class T>
Hours<T>::Hours( const Hours<T>& hours ){

}
template<class T>
istream& operator >> (istream& hoursIn, Hours<T>& hour) {
	hour.read(hoursIn);
	return hoursIn;
}

template<class T>
ostream& operator<<(ostream& hourOut, Hours<T>& hour) {
	hour.write(hourOut);
	return hourOut;
}
#endif /* Hours_H_ */