
#ifndef DATE1B_H_
#define DATE1B_H_

#include "Error.h"

typedef struct {
	int value;
} TDate1B;


// Public operations
TDate1B newDate1B(int day,int month,int year) throw (Error);
TDate1B incr(const TDate1B& date);
int diff(const TDate1B& date,const TDate1B& date_p);
void print(const TDate1B& date);


// Private operations
void calculateDMY(const TDate1B& date,int& day,int& month,int& year);
int daysInMonth1B(int m);
bool correctDate1B(int d,int m,int y);

#endif /* DATE1B_H_ */
