#include <iostream>
using namespace std;

#include "Error.h"
#include "AuxiliaryFuncs.h"
#include "SetOfInts4.h"


// Constructors

SetOfInts4::SetOfInts4() {
	size = 0;
}


// Public methods

bool SetOfInts4::isEmpty() const{
	return (size == 0);
}

void SetOfInts4::add(int x) {
	if (size < MAXSIZE) {
		elems[size] = x;
		size++;
	} else
		throw Error("Cannot add: The set is full");
}

void SetOfInts4::remove(int x){
	removeReps();
	int i = 0;
	bool found = false;
	while ((i < size) && (!found))
		if (elems[i] == x)
			found = true;
		else
			i++;

	if (found) {
		shiftLeftFrom(i);
		size--;
	}
}

bool SetOfInts4::contains(int x) const {
	int i = 0;
	bool found = false;
	while ((i < size) && (!found))
		if (elems[i] == x)
			found = true;
		else
			i++;
	return found;
}

void SetOfInts4::join(const SetOfInts4& set) {
	int newSize = size + set.size;
	if (newSize <= MAXSIZE) {
		for (int i = 0; i < set.size; i++)
			elems[size + i] = set.elems[i];
		size = newSize;
	} else
		throw Error("Cannot join: Not enough space");
}

void SetOfInts4::intersect(const SetOfInts4& set) {
	int newSize = 0;
	for (int i = 0; i < size; i++) {
		if (set.contains(elems[i]))
			elems[newSize++] = elems[i];
	}
	size = newSize;
}

istream& operator>>(istream& sIn, SetOfInts4& set) {
	int n;
	sIn >> n;
	for (int i = 0; i < n; i++)
		sIn >> set.elems[i];
	set.size = n;
	return sIn;
}

ostream& operator<<(ostream& sOut, SetOfInts4& set) {
	sOut << "{";
	for (int i = 0; i < set.size; i++)
		sOut << set.elems[i] << ",";
	sOut << "}";
	return sOut;
}


// Private methods

void SetOfInts4::removeReps() {
	int newSize = 0;
	for (int i = 0; i < size; i++)
		if (!isInSegment(elems[i],0,i))
			elems[newSize++] = elems[i];
	size = newSize;
}

bool SetOfInts4::isInSegment(int x,int i,int j) const {
	bool found = false;
	while ((i < j) && (!found))
		if (elems[i] == x)
			found = true;
		else
			i++;
	return found;
}

void SetOfInts4::shiftLeftFrom(int i){
	for (; i < size-1; i++)
		elems[i] = elems[i+1];
}

