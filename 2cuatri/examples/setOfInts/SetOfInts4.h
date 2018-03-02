#include <iostream>

#ifndef SETOfInts4_H_
#define SETOfInts4_H_


class SetOfInts4 {
	private:
		static const int MAXSIZE = 5;

		int elems[MAXSIZE];
		int size;

		void removeReps();
		bool isInSegment(int x,int i,int j) const;
		void shiftLeftFrom(int i);

	public:
		SetOfInts4();
		bool isEmpty() const;
		void add(int x);
		bool contains(int x) const;
		void remove(int x);
		void join(const SetOfInts4& set);
		void intersect(const SetOfInts4& set);
		friend istream& operator>>(istream& sIn,SetOfInts4& set);
		friend ostream& operator<<(ostream& sOut,SetOfInts4& set);
};

#endif /* SETOfInts4_H_ */
