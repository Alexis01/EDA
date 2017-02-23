
//#include "DateTests.h"
#include "SetOfInts1.h"
using namespace std;

int main(){

	SetOfInts1 * set1 =  new SetOfInts1;
	set1->add(1);
	set1->add(2);
	cout << set1 << endl;
	delete set1;

	char arg;
	cout << "Pres key to exit" << endl;
	cin >> arg;
	cout << "Bye";
	//testSmallSet();
	//testSetOfInts();
	//testGenericSet();
	//testDate1();
	//testDate2();
	//testDate3();
	//testDate4();
    return 0;
}