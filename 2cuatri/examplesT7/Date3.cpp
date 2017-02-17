#include <iostream>
using namespace std;

#include "Date3.h"
#include "Error.h"


TDate3::TDate3(int day,int month,int year) throw (Error) {
	// Asumimos que no hay años bisiestos
	if (!correctDate(day,month,year)) throw Error("Invalid date");
	value = 0;
	value += 365 * (year - 1);
	int m = month - 1;
	for (; m > 0; m--)
		value += daysInMonth(m);
	value += day;
}

TDate3::TDate3(const TDate3& date){
	value = date.value;
}

void TDate3::operator++(){
	value++;
}

void TDate3::operator+=(int n){
	for (int i = 0;i < n;i++)
		operator++();
}

int TDate3::diff(const TDate3& date) const {
	return (value - date.value);
}

void TDate3::print() const {
	int day, month, year;
	calculateDMY(day,month,year);
	cout << day << "/" << month << "/" << year << endl;
}


// Private operations

int TDate3::daysInMonth(int m) const {
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

void TDate3::calculateDMY(int& day,int& month,int& year) const {
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

bool TDate3::correctDate(int day,int month,int year) const {
	bool correct;
	if ((year <= 0) || (month < 1) || (month > 12) || (day < 1) || (day > daysInMonth(month)))
		correct = false;
	else
		correct = true;
	return correct;
}
