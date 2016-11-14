// Author : Alexis, Cristina

#include <iostream>    // cin, cout
#include <algorithm>  // max
using namespace std;

#define MAX 10000


int calculaDatos(int cotaSup){
	int result = 0;
	int dia1 = 1;
	int dia2 = 1;
	int contDays = 2;
	//cout << "cota sup: " << cotaSup << endl;
	result = dia1 + dia2;
	//cout << "Acumulo: " << result << " en  Días " << contDays << endl;
	//cout << "Día: #1 " << dia1 << endl;
	//cout << "Día: #2 " << dia1 << endl;
	//cout << "**********************" << endl;
	while (result <= cotaSup){
		//cout << "Inserto " << (dia1 * 2) + dia2 << endl;
		result = result + (dia1 * 2) + dia2;
		contDays++;
		//cout << "Acumulo: " << result << " en  " << contDays <<" #Días "  << endl;
		int tempDia1 = dia2;
		int tempDia2 = (dia1 * 2) + dia2;
		dia1 = tempDia1;
		dia2 = tempDia2;
		//cout << "Día: #1 "<< dia1 << endl;
		//cout << "Día: #2 " << dia2 << endl;
		//cout << "**********************" << endl;
		
	}
	//cout << "Value: " << cotaSup << " #Days: " << contDays << endl;
	cout << contDays << endl;
	return contDays;
}


int solve(int A[], int N){
	int n;
	int s = 0;
	for (n = 0; n < N; n++){
		//cout << A[n] << endl;
		A[n] = calculaDatos(A[n]);

	}
	return s;
}




int main(int argc, char **argv){
	int n;
	//int N;
	char answer = 'd'; // new answer variable
	int A[MAX];
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> A[i];
	}
	solve(A, n);

	//cout << "Press any key to continue, not enter";
	cin >> answer;
	cout << endl;
	return 0;
}
