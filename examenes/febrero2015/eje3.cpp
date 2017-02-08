#include <iostream>
#include <climits>
using namespace std;
#define MAX 10000
#define MP 20
#define QP 20


struct Producto {
    int pre;
    int prot;
    int cal;
};
bool esValida(){
    return true;
}
bool esSolucion(int maxprecio, int maxproteinas, int mincal,
                    int sumprecio, int sumprote, int sumcal){
    //si no supera maxprecio, y no supera maxprot, y es < que minmincal
    return (sumprecio < maxprecio) && 
                (sumprote < maxproteinas) && 
                      (sumcal < mincal);
}
void sumarDatos(Producto sol[], int tam, int &sumpre, int &sumprot, int &sumcal){
    
    int i = 0;
    while(i<=tam){
        Producto prod;
        prod = sol[i];
        sumpre += prod.pre;
        sumprot += prod.prot;
        sumcal += prod.cal;
        i++;
    }
}

/*
solve(prods,numcasos,sol,mejorSol, MP, QP);
*/
void solve(Producto prods[], int N, Producto sol[], Producto mejorSol[],int maxprecio, int maxproteinas, int &minCal, int nivel){
    int i = 0;
    while(i < N){
        sol[i] = prods[i];
        if(esValida()){
            cout << "Es valida"<< endl; 
            int sumpre = 0, sumprot = 0, sumcal = 0;
            sumarDatos(sol,i,sumpre,sumprot,sumcal);
            /*(int maxprecio, int maxproteinas, int mincal,
                    int sumprecio, int sumprote, int sumcal)*/
            if(esSolucion(maxprecio, maxproteinas, minCal, sumpre,sumprot, sumcal)){
                cout << "esSolucion"<< endl;
                mejorSol[i] = sol[i];
                /*cout << "esSolucion"<< endl;
                int j = 0;
                while(j < N ){
                    mejorSol[j] = sol[j];
                    j++;
                }
                minCal = sumcal;*/
            }else{

            }
        }
        i++;
    }
}


//minimizar el número de calorías
void printProds(Producto prods[], int numprods){
    int i=0;
     cout << "PRODUCTOS "<<endl;
    while(i < numprods){
        Producto prod = prods[i];
        cout << "Precio: ";
        cout << prod.pre;
        cout << endl;
        cout << "Proteinas: ";
        cout << prod.prot;
        cout << endl;
        cout << "Calorias: ";
        cout << prod.cal;
        cout << endl;
        cout << endl;
        i++;
    }
}


int main(int arg, char **argv){
    int numcasos;
    cout << "Numero de productos de la lista"<< endl;
    cin >> numcasos;
    Producto prods[MAX];
    int i = 0;
    while(i < numcasos){
        Producto prod;
        cout << "Precio: "<< endl;
        cin >> prod.pre;
        cout << "Proteinas: "<< endl;
        cin >> prod.prot;
        cout << "Calorias: "<< endl;
        cin >> prod.cal;
        prods[i] =  prod;
        i++;
    }
    Producto sol[MAX], mejorSol[MAX];
    int minCal = INT_MAX;
    solve(prods,numcasos,sol,mejorSol, MP, QP, minCal,0);
    printProds(mejorSol,numcasos);
    char answer = 'd'; // new answer variable
	cout << "Press any key to continue, not enter";
	cin >> answer;
	cout << endl;
    return 0;
}