#include <iostream>
#include <fstream>
#include <algorithm>  // max, min
using namespace std;

// #ifndef DOMJUDGE
// ifstream in("test.txt");
// auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
// #endif

int merge(const int* v1, int len1,
    const int* v2, int len2,
    int* v3)
{
int n,i1,i2;
for (n=i1=i2=0; (i1<len1) && (i2<len2) ; n++)
  {
    if (v1[i1] <= v2[i2])
  v3[n]=v1[i1++];
    else
  v3[n]=v2[i2++] ;
  }
for ( ; (i2<len2) ; n++) v3[n]=v2[i2++];
for ( ; (i1<len1) ; n++) v3[n]=v1[i1++];

return n ;
}

int mergeSort(const int* A,int len,int *V){
    switch(len){
        case 0 :
            return 0;
        case 1 :
            V[0]=A[0];
            return 1;
        default:{
            int AUX[10000]; // Can use malloc for finer approach.
            int h=len/2;
            mergeSort(A,h,AUX);
            mergeSort(A+h,len-h,AUX+h);
            return merge(AUX,h,AUX+h,len-h,V);
        }
    }
}
int masLejanosGen(int v[], int len){
    int h, m1, m2;
    if( len == 2){
        return abs( v[0] - v[1] );
    }
    if( len == 3 ){
        return max( masLejanosGen(v,2), masLejanosGen(v+h, 2) );
    }else{
        h = len/2;
        m1 = masLejanosGen(v,h);
        m2 = masLejanosGen(v+h, h);
        return max(m1, max(m2, masLejanosGen(v+h-1,2)) );
    }
}
int masLejanos(int v[], int len){
    int a[10000];
    mergeSort(v,len, a);
    return masLejanosGen(v,len);
}
int main(){
    
    int V[20] = {2,4,8,1,1};
    cout << masLejanos(V,5) << endl;
    int A[20] = {1,1,1,10,1};
    cout << masLejanos(A,5) << endl;
    return 0;
}