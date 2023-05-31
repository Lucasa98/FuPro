#include <iostream>
using namespace std;

struct Participante{
	int dni;
	vector<int> pruebas = {0,0,0};	// 0: mate, 1: fisica, 2: computacion
};

int main() {
	
	/// Ingreso de datos
	// cantidad de participantes
	int N;
	cin >> N;
	
	vector<Participante> participantes(N);
	
	// Por cada inscripto, DNI y numero para la competencia
	// usamos el numero en la competencia como el indice en el vector
	for(size_t i=0; i<participantes.size(); ++i){
		int dni;
		int numCompetencia;
		cin >> dni, numCompetencia;
		participantes[numCompetencia-1].dni = dni;
	}
	
	// Se ingresa numParticipante, codPrueba y puntaje.
	for(size_t i=0; i<participantes.size()*3; ++i){
		int numParticipantes, codPrueba, puntaje;
		cin >> numParticipante;
		cin >> codPrueba >> puntaje;
		
		participantes[numParticipante].pruebas[codPrueba-1] = puntaje;
	}
	
	/// DNI y puntaje del ganador y el segundo
	int posGanador = 0;
	int puntajeGanador = 0;
	int posSegundo = 1;
	int puntajeSegundo = 0;
	
	// Buscar ganador y segundo
	for(int i=0; i<participantes.size(); ++i){
		puntaje = participantes[i].pruebas[0] + participantes[i].pruebas[1] + participantes[i].pruebas[2];
		
		if(puntaje > puntajeGanador){
			posGanador = i;
			puntajeGanador = puntaje;
		}else if(puntaje > puntajeSegundo){
			posSegundo = i;
			puntajeSegundo = puntaje;
		}
	}
	// Mostrar ganador y segundo
	cout << "Ganador: " << participantes[posGanador].dni << endl;
	cout << puntajeGanador << " pts" << endl;
	
	cout << "Segundo: " << participantes[posSegundo].dni << endl;
	cout << puntajeSegundo << " pts" << endl;
	
	// Mostrar puntaje en computacion
	// fijense que es facil porque nos guardamos la POSICION del ganador
	cout << "Puntaje en computacion del ganador: " << participantes[posGanador].pruebas[2]; << endl;
	
	return 0;
}

