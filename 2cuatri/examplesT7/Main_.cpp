
#include "DateTests.h"
//#include "SetTests.h"
#include "DateTests.h"
#include "Date1A.h"
#include "Date1B.h"
#include "Date2.h"

#include "Date4.h"

int main(){
	//testSmallSet();
	//testSetOfInts();
	//testGenericSet();
	//testDate1();
	//testDate2();
	//testDate3();
	//testDate4();
	TDate2 date(31,12,1981);
	TDate2 date_p = date;
	date_p += 2;
	date_p.print();
	cout << date_p.diff(date);
}

