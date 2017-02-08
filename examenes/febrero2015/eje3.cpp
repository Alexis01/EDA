#include <iostream>
using namespace std;
#define MAX 10000

struct Producto {
    int pre;
    int prot;
    int cal;
};
//minimizar el número de calorías
void printProds(Producto prods[], int numprods){
    int i=0;
    while(i < numprods){
        Producto prod = prods[i];
        cout << "Precio: "<< endl;
        cin >> prod.precio;
        cout << "Proteinas: "<< endl;
        cin >> prod.prot;
        cout << "Precio: "<< endl;
        cin >> prod.cal;
        i++;
    }
}


int main(int arg, char **argv){
    int numcasos;
    cout << "Numero de productos de la lista"<< endl;
    cin >> numcasos;
    Producto prods[MAX];
    while(numcasos >= 0){
        Producto prod;
        cout << "Precio: "<< endl;
        cin >> prod.precio;
        cout << "Proteinas: "<< endl;
        cin >> prod.prot;
        cout << "Precio: "<< endl;
        cin >> prod.cal;
        prods[numcasos] =  prod;
        numcasos--;
    }


    char answer = 'd'; // new answer variable
	cout << "Press any key to continue, not enter";
	cin >> answer;
	cout << endl;
    return 0;
}