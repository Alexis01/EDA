
//#include "DateTests.h"
#include "SetOfInts1.h"
#include "SetOfInts2.h"
#include "SetOfInts3.h"
#include <stdlib.h> 
using namespace std;

void setOfInts1(){

	//constructor
	SetOfInts1 *set1 =  new SetOfInts1();
	int i = 0, max = 5;
	while(i < max){
		int randomInt = rand() % 1000 + 1;
		 set1->add(randomInt);
		i++;
	}

    cout << *set1 << endl;
	//Destructor
    delete set1;
}
void setOfInts2(){
	SetOfInts2 *set2 =  new SetOfInts2();
	int i = 0, max = 5;
    while(i < max){
		int randomInt = rand() % 1000 + 1;
		 set2->add(randomInt);
		i++;
	}
    cout << *set2 << endl;
	//Destructor
    delete set2;
}
void setOfInts3(){
	SetOfInts3 *set3 =  new SetOfInts3();
	int i = 0, max = 5;
    while(i < max){
		int randomInt = rand() % 1000 + 1;
		 set3->add(randomInt);
		i++;
	}
    cout << *set3 << endl;
	//Destructor
    delete set3;
}

int main(){
	cout << "setOfInts1" << endl;
	setOfInts1();
	cout << endl;
	cout << "setOfInts2" << endl;
	setOfInts2();
	cout << endl;
	cout << "setOfInts3" << endl;
	setOfInts3();
	cout << endl;

	char arg;
	cout << "Pres key to exit" << endl;
	cin >> arg;
	cout << "Bye";
	cout << endl;

    return 0;
}