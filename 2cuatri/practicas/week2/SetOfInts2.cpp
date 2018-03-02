
#include <iostream>
using namespace std;

#include "Error.h"
#include "SetOfInts2.h"


// Constructors

SetOfInts2::SetOfInts2() {
	size = 0;
}


// Public methods

bool SetOfInts2::isEmpty() const{
	return (size == 0);
}

void SetOfInts2::add(int x) throw (Error) {
	if (!contains(x)){
		if (isFull())
			throw Error("Cannot add: The set is full");
		else {
			elems[size] = x;
			size++;
		}
	}
}

void SetOfInts2::remove(int x){
	bool found;
	int pos;

	linSearch(x,0,size,found,pos);
	if (found){
		size--;
		elems[pos] = elems[size];
	}
}

bool SetOfInts2::contains(int x) const {
	bool found;
	int pos;

	linSearch(x,0,size,found,pos);
	return found;
}

void SetOfInts2::join(const SetOfInts2& set) {
	throw Error("Join operation not supported");
}

void SetOfInts2::intersect(const SetOfInts2& set) {
	throw Error("Intersection operation not supported");
}

istream& operator>>(istream& sIn, SetOfInts2& set) {
	int n;
	int d;
	sIn >> n;
	set.size = 0;
	if (sIn.fail()) return sIn;
	for (int i = 0; i < n; i++){
		sIn >> d;
		set.add(d);
	}
	return sIn;
}

ostream& operator<<(ostream& sOut, SetOfInts2& set) {
	sOut << "{";
	for (int i = 0; i < set.size-1; i++)
		sOut << set.elems[i] << ",";
	if (set.size > 0) sOut << set.elems[set.size-1];
	sOut << "}";
	return sOut;
}
bool SetOfInts2::operator==(SetOfInts2 &set){
	int pos = 0;
	bool equ = true;
	while(pos < set.size){
		if(!contains(set.elems[pos])){
			equ = false;
		}
		pos++;
	}
	pos = 0;
	while(pos < size){
		if(!set.contains(elems[pos])){
			equ = false;
		}
		pos++;
	}
	return equ;
}

// Private methods

bool SetOfInts2::isFull() const {
	return size == MAXSIZE;
}

void SetOfInts2::linSearch(int x, int left, int right, bool& found, int& pos) const {
// P: elems tiene al menos right elementos

	int i;

	if (left >= right) {
		found = false;
		pos = right;
	} else {
		found = false;
		i = left;
		while (!found && (i < right)) {
			found = elems[i] == x;
			if (!found)
				i++;
		}
		pos = i;
	}
	// Q :  found es true si existe un i en el intervalo left..right-1
	//        tal que elems[i] == x
	//      si found es true entonces pos = el minimo i en
	//        el intervalo left..right-1 tal que elems[i] == x
	//      si no found entonces pos == right
}
