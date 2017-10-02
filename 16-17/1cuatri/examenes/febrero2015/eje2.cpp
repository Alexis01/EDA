#include <iostream>
using namespace std;
#define MAX 10000

int numCifras (int n) { 
    int cuenta = 1;
    n = n / 10;
    while(n != 0) {
        cuenta = cuenta + 1; // número de cifras identificadas
        n = n / 10; // elimina la cifra menos significativa
    }
    return cuenta; 
}

void getSpectro(unsigned int num, unsigned int &longitude, 
    unsigned int result[], unsigned int &cont){
    if(longitude == 1){
        result[cont] = num;
        cont++;    
    }else{
        result[cont] =  num % 10;
        num = num/10;
        longitude -= 1;
        cont++;
        return getSpectro(num,longitude, result, cont);
    }
} 

void solve(unsigned int N,unsigned int longi){
    unsigned int result[MAX];
    unsigned int cont = 0;
    cout<< "numero:  " << N << endl;
    cout<< "specular: ";
    getSpectro(N,longi, result, cont);
    int i = 0;
    while(i<cont){
        cout << result[i];
        i++;
    }
    cout << endl;
}


int main(int argc, char **argv){
    unsigned int N, n, longitude;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> N;
        longitude =  numCifras(N);
        solve(N, longitude);

    }
    char answer = 'd'; // new answer variable
	cout << "Press any key to continue, not enter";
	cin >> answer;
	cout << endl;


    return 0;
}