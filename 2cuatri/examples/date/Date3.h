#ifndef DATE3_H_
#define DATE3_H_

#include "Error.h"
#include <iostream>
using namespace std;

class TDate3{
	// Fechas representadas con un solo entero que guarda el nº de días transcurridos
	// desde la fecha 1/1/1

	private:
		int value;

		int daysInMonth(int m) const{
			// Asumimos que no hay años bisiestos
			int numDays = 0;
			switch (m) {
				case 1:case 3:case 5:case 7:case 8:case 10:case 12:
					numDays = 31;
					break;
				case 4:case 6:case 9:case 11:
					numDays = 30;
					break;
				case 2:
					numDays = 28;
					break;
				default:
					numDays = 0;
			}//switch
			return numDays;
		}
		void calculateDMY(int& day,int& month,int& year) const{
			// Asumimos que no hay años bisiestos
			year = value/365 + 1;
			int v = value%365;
			int m = 1;
			int daysInM = daysInMonth(m);
			while (v > daysInM){
				v = v - daysInM;
				m++;
				daysInM = daysInMonth(m);
			}
			month = m;
			day = v;
		}
		bool correctDate(int day,int month,int year) const{
			bool correct;
			if ((year <= 0) || (month < 1) || (month > 12) || (day < 1) || (day > daysInMonth(month)))
				correct = false;
			else
				correct = true;
			return correct;
		}

	public:
		TDate3(int day,int month,int year) throw (Error){
			// Asumimos que no hay años bisiestos
			if (!correctDate(day,month,year)) throw Error("Invalid date");
			value = 0;
			value += 365 * (year - 1);
			int m = month - 1;
			for (; m > 0; m--)
				value += daysInMonth(m);
			value += day;
		}
		TDate3(const TDate3& date){
			value = date.value;
		}
		void operator++(){
			value++;
		}
		void operator+=(int n){
			for (int i = 0;i < n;i++)
				operator++();
		}
		int diff(const TDate3& date) const{
			return (value - date.value);
		}
		void print() const{
			int day, month, year;
			calculateDMY(day,month,year);
			cout << day << "/" << month << "/" << year << endl;
		}
};


#endif /* DATE3_H_ */
