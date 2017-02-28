
//#include "DateTests.h"
//#include "SetOfInts1.h"
//#include "SetOfInts2.h"
#include "SetOfInts3.h"
#include <stdlib.h> 
using namespace std;

#define MAX 10000


void eje1(){
	SetOfInts3 *set3 = new SetOfInts3();
	SetOfInts3 *setToCompare = new SetOfInts3();
	int i = 0, max = MAX;
	while (i < max){
		int randomInt = rand() % 1000 + 1;
		set3->add(randomInt);
		randomInt = rand() % 1000 + 1;
		setToCompare->add(randomInt);
		i++;
	}
	cout << *set3 << endl;
	cout << *setToCompare << endl;
	if ( *set3 == *setToCompare){
		cout << "Son iguales" << endl;
	}else{
		cout << "Son distintos" << endl;
	}

	//Destructor
	delete set3;
	delete setToCompare;
}
void eje2(){
	SetOfInts3 *content = new SetOfInts3();
	SetOfInts3 *container = new SetOfInts3();
	//Destructor
	//content
	content->add(1000);
	content->add(400);
	content->add(80);
	//container
	container->add(1000);
	container->add(200);
	container->add(30);
	container->add(400);
	container->add(80);
	//el que llama es subconjunto del pasado como parámetro
	if( *content < *container ){
		cout << *content << " Contenido en "<< *container << endl;
	}else{
		cout << "NO está contenido" << endl;
	}
	cout << *content << endl;
	cout << *container << endl;
	cout << content->getMin() << endl;
	cout << container->getMin() << endl;
	content->removeMin();
	container->removeMin();
	cout << *content << endl;
	cout << *container << endl;
	delete content;
	delete container;

}
//TODO Indica en un comentario la complejidad de los algoritmos implementados
/*
orden 
	constante hasta los números que necesitemos
	el getMin es constante 1
	el remove es (O(log n)).

	=> n   + 1 + O(log n)  ====>    n + O(log n)  ORDEN DE LA FUNCIÓN
*/
void solve(int V[],int numK, SetOfInts3& data){
	int pos = 0;
	while(pos < numK){
		if(numK == 1 || pos == numK - 1){
			cout << data.getMin();
		}else{
			cout << data.getMin() << " ";
		}
		data.removeMin();
		pos++;
	}
	cout << endl;
}
int main(){
	
	/*setOfInts1();
	cout << endl;
	cout << "setOfInts2" << endl;
	setOfInts2();
	cout << endl;
	cout << "setOfInts3" << endl;
	setOfInts3();
	cout << endl;*/
	/*
	1. Implementa la relaci�on de equivalencia del TAD SetOfInts mediante el m�etodo bool operator==(const
	SetOfInts& set) para las tres implementaciones del TAD vistas en clase y disponibles en el CV.
	Escribe una funci�on que permita hacer pruebas repetidamente con conjuntos introducidos por el
	usuario.
	*/

	//eje1();

	/*
	2. An ̃ade una nueva operaci ́on al TAD SetOfInts3 que compruebe si un conjunto es un subcon- 
	junto de otro mediante la redefinici ́on del operador de orden <, es decir, 
	mediante el m ́etodo bool operator<(const SetOfInts3& set). 
	Escribe una funci ́on que permita hacer pruebas repetida- mente con conjuntos introducidos por el usuario.
	*/

	//eje2();

    /*
	3. Escribe una funci ́on (fuera del TAD) que dada una serie de n nu ́meros enteros (en un array o vector), 
	encuentre los k nu ́meros menores distintos, 
	devolviendo el resultado en un conjunto SetOfInts3 (como par ́ametro por referencia). 
	Se extender ́a la clase SetOfInts3 an ̃adiendo dos m ́etodos, 
	uno para consultar el menor elemento del conjunto (getMin) y otro para eliminarlo (removeMin), 
	y por tanto el algoritmo disen ̃ado para la funci ́on deber ́a usarlos. 
	Indica en un comentario la complejidad de los algoritmos implementados.*/
	int numK;
	int V[MAX];
	cin >> numK;
	while( numK != 0 ){
		SetOfInts3 *data = new SetOfInts3();
		int num, pos = 0;
		cin >> num;
		data->add(num);
		while( num != -1 ){
			V[pos] = num;
			data->add(num);
			pos++;
			cin >> num;
		}
		solve(V,numK, *data); // Indica en un comentario la complejidad de los algoritmos implementados
		delete data;
		cin >> numK;
	}
	//Pare el programa
	/*char arg;
	cout << "Pres key to exit" << endl;
	cin >> arg;
	cout << "Bye";
	cout << endl;*/

    return 0;
}