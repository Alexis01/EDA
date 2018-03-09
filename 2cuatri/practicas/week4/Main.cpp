#include "Error.h"
// Roberto Diaz Gomez
// Alexis Cumbal Calderón


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    /*char character;
	cin >> character;*/
	string line;
	getline(cin,line);
    if (! std::cin)
        return false;
	
	stack<char> datos;
	for(int i=0; i<line.size() ; i++){
		if (line[i] == '{' || line[i] == '(' || line[i] == '[') {
			datos.push(line[i]);
		}else{
			if(datos.size() > 0){
				if(line[i] == '}' && datos.top() == '{'){
					datos.pop();
				}else{
					if(line[i] == ')' && datos.top() == '('){
						datos.pop();
					} else {
						if(line[i] == ']' && datos.top() == '['){
							datos.pop();
						}
					}
				}
			}
		}
	}
    cout << line << endl;
	cout << datos.size() << endl;
	
    // escribir sol
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    

    while (resuelveCaso())
        ;
	 cout << "siu" << endl;
   
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}

