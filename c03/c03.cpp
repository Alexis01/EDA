#include <iostream>  // cin, cout
#include <algorithm> // max, min
#include <cstdlib> // abs

#define  MAX 10000

using namespace std;

// The C-Code has a different flavour.

int merge(const int* v1, int len1,
	const int* v2, int len2,
	int* v3){
	int n, i1, i2;
	for (n = i1 = i2 = 0; (i1<len1) && (i2<len2); n++){
		if (v1[i1] <= v2[i2]) {
			v3[n] = v1[i1++];
		}
		else{
			v3[n] = v2[i2++];
		}
	}
	for (; (i2 < len2); n++){
		v3[n] = v2[i2++];
	}
	for (; (i1 < len1); n++){
		v3[n] = v1[i1++];
	}

	return n;
}

int mergeSort(const int* A, int len, int *V){
	switch (len){
	case 0:{
		return 0;
	}
	case 1:{
		V[0] = A[0];
		return 1;
	}
	default:{
		int AUX[MAX]; // Can use malloc for finer approach.
		int h = len / 2;
		mergeSort(A, h, AUX);
		mergeSort(A + h, len - h, AUX + h);
		return merge(AUX, h, AUX + h, len - h, V);
	}
	}
}

/*
P : len>=2 and sorted(AA)
*/
int isolve(const int AA[], int len){
	switch (len){
		case 2:{
			return abs(AA[0] - AA[1]);
		}
		case 3:{
			int m1 = abs(AA[0] - AA[1]),
				m2 = abs(AA[1] - AA[2]);
			return max(m1, m2);
		}
		default:{
			int h = len / 2,
				min1 = isolve(AA, h),
				min2 = isolve(AA + h, len - h);
			return max(max(min1, min2), abs(AA[len - 1] - AA[len]));
		}
	}
}


int solve(const int A[], int len){
	int AA[MAX];
	mergeSort(A, len, AA);
	return isolve(AA, len);
}


int main(int argc, char **argv)
{
	int n;
	int N;
	int A[MAX];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> N;
		for (int j = 0; j < N; j++)
			cin >> A[j];
		cout << solve(A, N) << endl;
	}
	//Comentarlo para el juez
	char answer = 'd'; // new answer variable
	cout << "Press any key to continue, not enter";
	cin >> answer;
	cout << endl;
	return 0;
}
