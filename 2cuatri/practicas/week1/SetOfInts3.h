
#ifndef SETOFINTS3_H_
#define SETOFINTS3_H_

#include "Error.h"
#include<iostream>
using namespace std;
class SetOfInts3 {
	// Conjuntos de enteros representados como vectores ordenados sin repeticiones
	private:
		static const int MAXSIZE = 10000;

		int elems[MAXSIZE];
		int size;

		bool isFull() const;
		void binSearch(int x,bool& found,int& pos) const;
		int binSearchAux(int x, int a, int b) const;
		void shiftRightFrom(int i);
		void shiftLeftFrom(int i);

	public:
		SetOfInts3();
		bool isEmpty() const;
		void add(int x) throw (Error);
		bool contains(int x) const;
		void remove(int x);
		friend istream& operator>>(istream& sIn,SetOfInts3& set);
		friend ostream& operator<<(ostream& sOut,SetOfInts3& set);
		//eje 1
		bool operator==(const SetOfInts3& set) const;//M�todo observador
		//eje 2
		bool operator<(const SetOfInts3& set) const;
		//eje 3
		//observadora
		int getMin() const;
		//modificadora
		void removeMin();

};

#endif /* SETOFINTS3_H_ */
