#include <iostream>
using namespace std;

#include "DateTests.h"
#include "Date1A.h"
#include "Date1B.h"
#include "Date2.h"
#include "Date3.h"
#include "Date4.h"

void testDate1(){
	TDate1A date = newDate1A(31,12,1981);
	TDate1A date_p = incr(incr(incr(date)));
	print(date_p);
	cout << diff(date_p,date);
}

void testDate2(){
	TDate2 date(31,12,1981);
	TDate2 date_p = date;
	date_p += 2;
	date_p.print();
	cout << date_p.diff(date);
}

void testDate3(){
	TDate3 date(31,12,1981);
	TDate3 date_p = date;
	date_p += 5;
	date_p.print();
	cout << date_p.diff(date);
}

void testDate4(){
	TDate4 date(31,12,1981);
	TDate4 date_p = date;
	date_p += 7;
	++date_p;
	date_p.print();
	cout << date_p.diff(date);
}
