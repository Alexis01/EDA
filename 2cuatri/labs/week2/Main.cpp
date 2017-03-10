#include <iostream>
#include <stdlib.h> 
#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;


bool esContrario(char valor, char top){
	bool ok = false;
	if (valor == '}' ){
		ok = top == '{';
	}
	if (valor == ']'){
		ok = top == '[';
	}
	if (valor == ')'){
		ok = top == '(';
	}
	return ok;
}

void solve(string linea){
	stack<char> pila;
	unsigned int i = 0;
	int contOpen = 0;
	int contClose = 0;
	while ( i < linea.size()  ){
		if (linea[i] == '(' ||  linea[i] == '{' || linea[i] == '[' ){
			pila.push(linea[i]);
			contOpen++;
			//cout << "Apilo " << linea[i] << endl;
		}
		if ( (linea[i] == '}' || linea[i] == ')' || linea[i] == ']') ){
			contClose++;
			if (!pila.empty() && esContrario(linea[i], pila.top())){
				pila.pop();
				//cout << "Desapilo " << linea[i] << endl;
			}
		}
		i++;
	}
	if (pila.empty() && (contClose==contOpen)){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}

}

int main(){
	string linea;
	getline(cin,linea);
	while (linea != "." ) {
		if (linea.size() == 0){
			cout << "YES" << endl;
		}
		else{
			solve(linea);
		}
		
		
		getline(cin, linea);

	}
	return 0;
}