
#include <string>
#include "TreeMap.h"
#include "HashMap.h"
#include <list>
#include<iomanip>
#include "Fecha.h"
#include "Exceptions.h"
#include <stdexcept>
using namespace std;
// throw invalid_argument("Seconds must be valid");
typedef string Medico;
typedef string Paciente;
class Consultorio{
	private:

		HashMap< Medico, TreeMap<Fecha,Paciente> > _consultorio;
	public:

		Consultorio();
		void nuevoMedico( Medico medico );
		void pideConsulta( Paciente paciente, Medico medico, Fecha fecha);
		Paciente siguientePaciente(Medico medico);
		void atiendeConsulta(Medico medico);
		list< pair<Fecha,Paciente> > listaPacientes( Medico medico, Fecha dia );
		
};
Consultorio::Consultorio(){}
void Consultorio::nuevoMedico( Medico medico ){

	if( !_consultorio.contains(medico) ){
		_consultorio.insert(medico, TreeMap<Fecha, Paciente>());
	}

}

void Consultorio::pideConsulta( Paciente paciente, Medico medico, Fecha fecha ){

	HashMap<Medico,TreeMap<Fecha,Paciente>>::Iterator it = _consultorio.find(medico);
	
	if(it == _consultorio.end()) throw invalid_argument("Medico no existente");
	else{
		
		if( it.value().contains(fecha) ) throw invalid_argument("Fecha ocupada");
		else{
			it.value().insert( fecha, paciente );
		}
	}
}

Paciente Consultorio::siguientePaciente( Medico medico ){
	
	Paciente siguiente;
	HashMap<Medico,TreeMap<Fecha,Paciente>>::Iterator it = _consultorio.find(medico);

	if(it == _consultorio.end()) throw invalid_argument("Medico no existente");
	else{
		TreeMap<Fecha, Paciente>::Iterator itTreeMap = it.value().begin();
		if (itTreeMap == it.value().end()) throw invalid_argument("No hay pacientes");
		else{
			siguiente = itTreeMap.value();
		}
	}
	return siguiente;
}

void Consultorio::atiendeConsulta( Medico medico ){

	HashMap<Medico,TreeMap<Fecha,Paciente>>::Iterator it = _consultorio.find(medico);

	if(it == _consultorio.end()) throw invalid_argument("Medico no existente");
	else{
		TreeMap<Fecha, Paciente>::Iterator itTreeMap = it.value().begin();
		if (itTreeMap == it.value().end()) throw invalid_argument("No hay pacientes");
		else{
			it.value().erase( itTreeMap.key() );
		}
	}
}
list< pair<Fecha,Paciente> > Consultorio::listaPacientes( Medico medico, Fecha dia ){
	
	list< pair<Fecha,Paciente> > pacientes;
	HashMap<Medico, TreeMap<Fecha,Paciente>>::Iterator it = _consultorio.find( medico );

	if( it == _consultorio.end() ) throw invalid_argument("Medico no existente");
	else{

		TreeMap<Fecha, Paciente>::Iterator itMap = it.value().begin();
		while( itMap != it.value().end() ){
			Fecha fAux = itMap.key();
			if( fAux.getDay() == dia.getDay() ){
				pair<Fecha,Paciente> par;
				par.first = fAux;
				par.second = itMap.value();
				pacientes.push_back( par );
			}
			itMap.next();
		}
	}
	return pacientes;
}