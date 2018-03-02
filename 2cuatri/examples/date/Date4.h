#ifndef DATE4_H_
#define DATE4_H_

#include "Error.h"
#include <iostream>
using namespace std;

class TDate4{
	// Fechas representadas como <day,month,year> y además guardando el "value" para
	// acelerar computos

	private:
		int day;
		int month;
		int year;
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

		int calculateValue() const{
			// Asumimos que no hay años bisiestos
			int v = 0;
			v += 365 * (year - 1);
			int m = month - 1;
			for (; m > 0; m--)
				v += daysInMonth(m);
			v += day;
			return v;
		}
		bool correctDate() const{
			bool correct;
			if ((year <= 0) || (month < 1) || (month > 12) || (day < 1) || (day > daysInMonth(month)))
				correct = false;
			else
				correct = true;
			return correct;
		}

	public:
		TDate4(int d,int m,int y) throw (Error){
			// Asumimos que no hay años bisiestos
			day = d;
			month = m;
			year = y;
			if (!correctDate()) throw Error("Invalid date");
			value = calculateValue();
		}
		TDate4(const TDate4& date){
			day = date.day;
			month = date.month;
			year = date.year;
			value = date.value;
		}
		TDate4& operator++(){
			value++;
			day++;
			if (day > daysInMonth(month)){
				day = 1;
				month++;
				if (month > 12){
					month = 1;
					year++;
				}
			}
			return *this;
		}
		TDate4& operator+=(int n){
			for (int i = 0;i < n;i++)
				operator++();//incr();
			return *this;
		}
		int diff(const TDate4& date) const{
			return (value - date.value);
		}
		void print() const{
			cout << day << "/" << month << "/" << year << endl;
		}
};

#endif /* DATE4_H_ */
