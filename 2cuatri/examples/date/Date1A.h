
#ifndef DATE1A_H_
#define DATE1A_H_

#include <iostream>
using namespace std;
#include "Error.h"

typedef struct {
	int day;
	int month;
	int year;
} TDate1A;

// Private operations
int daysInMonth(int m) {
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
int calculateValue(const TDate1A& date) {
	int v = 0;
	v += 365 * (date.year - 1);
	int m = date.month - 1;
	for (; m > 0; m--)
		v += daysInMonth(m);
	v += date.day;
	return v;
}


bool correctDate1A(int d,int m,int y){
	bool correct;
	if ((y <= 0) || (m < 1) || (m > 12) || (d < 1) || (d > daysInMonth(m)))
		correct = false;
	else
		correct = true;
	return correct;
}

// Public operations
TDate1A newDate1A(int d,int m,int y) throw (Error){
	TDate1A date;
	if (!correctDate1A(d,m,y)) throw Error("Invalid date");
	date.day = d;
	date.month = m;
	date.year = y;
	return date;
}
TDate1A incr(const TDate1A& date){
	TDate1A date_p = date;
	date_p.day++;
	if (date_p.day > daysInMonth(date_p.month)){
		date_p.day = 1;
		date_p.month++;
		if (date_p.month > 12){
			date_p.month = 1;
			date_p.year++;
		}
	}
	return date_p;
}
int diff(const TDate1A& date,const TDate1A& date_p){
	return calculateValue(date) - calculateValue(date_p);
}
void print(const TDate1A& date){
	cout << date.day << "/" << date.month << "/" << date.year << endl;
}


// Private operations
int calculateValue(const TDate1A& date);
int daysInMonth(int m);
bool correctDate1A(int d,int m,int y);


#endif /* DATE1A_H_ */
