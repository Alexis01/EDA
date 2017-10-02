#ifndef DATE4_H_
#define DATE4_H_

#include "Error.h"


class TDate4{
	// Fechas representadas como <day,month,year> y además guardando el "value" para
	// acelerar computos

	private:
		int day;
		int month;
		int year;
		int value;

		int daysInMonth(int m) const;
		int calculateValue() const;
		bool correctDate() const;

	public:
		TDate4(int d,int m,int y) throw (Error);
		TDate4(const TDate4& date);
		TDate4& operator++();
		TDate4& operator+=(int n);
		int diff(const TDate4& date) const;
		void print() const;
};

#endif /* DATE4_H_ */
