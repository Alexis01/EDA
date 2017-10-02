#include <iostream>
using namespace std;

#include "Date2.h"
#include "Error.h"


TDate2::TDate2(int d,int m,int y) throw (Error) {
	day = d;
	month = m;
	year = y;
	if (!correctDate()) throw Error("Invalid date");
}

TDate2::TDate2(const TDate2& date){
	day = date.day;
	month = date.month;
	year = date.year;
}

void TDate2::operator++(){
	// Asumimos que no hay años bisiestos
	day++;
	if (day > daysInMonth(month)){
		day = 1;
		month++;
		if (month > 12){
			month = 1;
			year++;
		}
	}
}

void TDate2::operator+=(int n){
	for (int i = 0;i < n;i++)
		operator++();
}

int TDate2::diff(const TDate2& date) const{
	return (calculateValue() - date.calculateValue());
}

void TDate2::print() const {
	cout << day << "/" << month << "/" << year << endl;
}


// Private operations

int TDate2::calculateValue() const{
	// Asumimos que no hay años bisiestos
	int v = 0;
	v += 365 * (year - 1);
	int m = month - 1;
	for (; m > 0; m--)
		v += daysInMonth(m);
	v += day;
	return v;
}

int TDate2::daysInMonth(int m) const {
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

bool TDate2::correctDate() const {
	bool correct;
	if ((year <= 0) || (month < 1) || (month > 12) || (day < 1) || (day > daysInMonth(month)))
		correct = false;
	else
		correct = true;
	return correct;
}
