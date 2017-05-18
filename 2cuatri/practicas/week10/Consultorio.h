#include "Fecha.h"
#include <string>
#include "TreeMap.h"
#include <list>
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
		TreeMap< string, TreeMap<Fecha,Paciente> > dicMedPac;
	public:
		Consultorio();
		void nuevoMedico( Medico medico );
		void pideConsulta( Paciente paciente, Medico medico, Fecha fecha);
		void siguientePaciente(Medico medico);
		void atiendeConsulta(Medico medico);
		list<string> listaPacientes( Medico medico, Fecha dia );
		
};
Consultorio::Consultorio(){}