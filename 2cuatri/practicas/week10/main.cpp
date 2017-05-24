#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

#include "Fecha.h"
#include "Consultorio.h"

//typedef TreeMap<...> InfoMedico
typedef string medico;
typedef string paciente;
bool resuelve() {
    
    int N;
    cin >> N;
    if (!cin) return false;
    
    string inst;
    medico med; 
	paciente pac; 
	int d, h, m;
    Consultorio con;
    
    for (int i = 0; i < N; ++i) {
        try {
            cin >> inst;
            if (inst == "nuevoMedico") {
                cin >> med;
                con.nuevoMedico(med);
            }else if (inst == "pideConsulta") {
                cin >> pac >> med >> d >> h >> m;
                con.pideConsulta(pac, med, Fecha(d,h,m));
            }
        } catch (invalid_argument e) { 
            cout << e.what() << '\n' << "---\n"; 
        }
    }
    cout << "------\n";
    
    return true;
}

int main() {
    while (resuelve())
    return 0;
}