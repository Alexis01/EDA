
#include <string>
#include "TreeMap.h"
#include "HashMap.h"
#include <list>
#include<iomanip>
using namespace std;
// throw EgenericMessage("Seconds must be valid");
typedef string Medico;
typedef string Paciente;
struct Cita{
	Fecha fecha;
	Paciente paciente;
};
class Consultorio{
	private:
		Medico medico;
		Paciente paciente;
		Fecha fecha;
		//Para un medico tenemos un treeMap con la fecha y el paciente
		HashMap< string, TreeMap<Fecha,Paciente> > dicMedPac;
	public:
		Consultorio();
		void nuevoMedico( Medico medico );
		void pideConsulta( Paciente paciente, Medico medico, Fecha fecha);
		Paciente siguientePaciente(Medico medico);
		void atiendeConsulta(Medico medico);
		list<Paciente> listaPacientes( Medico medico, Fecha dia );
		
};
Consultorio::Consultorio(){}
void Consultorio::nuevoMedico( Medico medico ){
	if( !dicMedPac.contains(medico) ){
		TreeMap<Fecha, Paciente> arbolFechaPaciente;
		dicMedPac.insert(medico, arbolFechaPaciente);
	}
}
void Consultorio::pideConsulta( Paciente paciente, Medico medico, Fecha fecha ){

	if (dicMedPac.contains(medico)) {

		TreeMap<Fecha, Paciente> arbolFechaPaciente;
		arbolFechaPaciente = dicMedPac.at(medico);

		if (!arbolFechaPaciente.contains(fecha)) {
			arbolFechaPaciente.insert(fecha, paciente);
			dicMedPac.insert(medico, arbolFechaPaciente);
		}
		else {
			//throw invalid_argument("Fecha ocupada");
			throw EgenericMessage("Fecha ocupada");
		}
	}else {
		//throw invalid_argument("Medico no existente");
		throw EgenericMessage("Medico no existente");
	}
}
Paciente Consultorio::siguientePaciente( Medico medico ){
	
	Fecha fechaComp;
	TreeMap<Fecha, Paciente> arbolFechaPaciente;
	if (dicMedPac.contains(medico)) {

		
		arbolFechaPaciente = dicMedPac.at(medico);

		if (!arbolFechaPaciente.empty()) {

			TreeMap<Fecha, Paciente>::Iterator it = arbolFechaPaciente.begin();

			fechaComp = it.key();
			it.next();

			while (it != arbolFechaPaciente.end()) {
				it.key() < fechaComp;

				if (it.key() < fechaComp) {
					fechaComp = it.key();
				}

				it.next();
			}
		}
		else {
			throw EgenericMessage("No hay pacientes");
		}

	}
	else {
		throw EgenericMessage("Medico no existente");
	}
	return arbolFechaPaciente.at(fechaComp);
}
void Consultorio::atiendeConsulta( Medico medico ){

	TreeMap<Fecha, Paciente> arbolFechaPaciente;
	if (dicMedPac.contains(medico)) {

		arbolFechaPaciente = dicMedPac.at(medico);
		if (!arbolFechaPaciente.empty()) {

			TreeMap<Fecha, Paciente>::Iterator it = arbolFechaPaciente.begin();

			Fecha fechaComp = it.key();
			it.next();

			while (it != arbolFechaPaciente.end()) {
				it.key() < fechaComp;

				if (it.key() < fechaComp) {
					fechaComp = it.key();
				}

				it.next();
			}

			arbolFechaPaciente.erase(fechaComp);

		}else {
			throw EgenericMessage("No hay pacientes");
		}

	}else {
		throw EgenericMessage("Medico no existente");
	}
}
list<Paciente> Consultorio::listaPacientes( Medico medico, Fecha dia ){
	
	list<Paciente> pacientes;
	
	if( dicMedPac.contains(medico) ){
		
		TreeMap<Fecha, Paciente> arbolFechaPaciente;
		arbolFechaPaciente = dicMedPac.at(medico);
		
		if( !arbolFechaPaciente.empty() ){

			TreeMap<Fecha, Paciente>::Iterator it = arbolFechaPaciente.begin();
			while( it != arbolFechaPaciente.end() ) {
				Fecha fkey = it.key();
				if( fkey.getDay() == dia.getDay() ){
					
					string hora = std::to_string(fkey.getHour());
					string minuto = std::to_string(fkey.getMinute());

					if(minuto == "0") minuto = "00";
					if(hora == "0") hora = "00";

					Paciente result = it.value() + " " + hora + ":" + minuto;
					pacientes.push_back( result ); 

				}
				it.next();
			}
		}
	}else{

		throw EgenericMessage("Medico no existente");

	}

	return pacientes;
}