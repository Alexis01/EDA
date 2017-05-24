#ifndef __FECHA_H
#define __FECHA_H

class Fecha{
protected:
	int _dia, _hora, _minuto;
public:
	Fecha();
	Fecha(int d, int h, int m);
	int getDay();
	int getHour();
	int getMinute();
	bool operator<(const Fecha& fec) const;
	bool operator==(const Fecha& fec) const;
};
Fecha::Fecha(){}
Fecha::Fecha(int d, int h, int m){
    _dia = d;
    _hora = h;
    _minuto = m;
}
int Fecha::getDay() {
    return _dia;
}

int Fecha::getHour() {
    return _hora;
}

int Fecha::getMinute() {
    return _minuto;
}
bool Fecha::operator<( const Fecha& fec ) const{
    return _dia < fec._dia || (_dia == fec._dia && _hora < fec._hora)
			|| (_dia == fec._dia && _hora == fec._hora && _minuto < fec._minuto);
}
bool Fecha::operator==(const Fecha& fec) const {
    return (_dia == fec._dia && _hora == fec._hora && _minuto == fec._minuto);
}
#endif // __FECHA_H