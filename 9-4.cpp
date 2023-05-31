#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Alumno{
	string nombre;
	int nota;
};

void show(vector<string> v){
	cout << '[';
	for(int i=0; i<v.size(); ++i){
		cout << v[i] << ' ';
	}
	cout << ']' << endl;
}

int main() {
	
	/// Ingreso de datos
	vector<Alumno> alumnos;
	int nota;
	// ingresa primer nota
	cout << "nota: ";
	cin >> nota;
	while (nota != 0){
		// ingresa nombre
		string nombre;
		cout << "nombre: ";
		cin >> nombre;
		// crear alumno
		Alumno a;
		a.nombre = nombre;
		a.nota = nota;
		// ingresar
		alumnos.push_back(a);
		
		// siguiente nota
		cout << "nota: " << endl;
	}
	
	vector<string> aprobados;
	vector<string> desaprobados;
	for(size_t i=0; i<alumnos.size(); ++i){
		if(alumnos[i].nota >= 6)
			aprobados.push_back(alumnos[i].nombre);	// aprobados
		else
			desaprobados.push_back(alumnos[i].nombre);	// desaprobados
	}
	
	cout << "aprobados: ";
	show(aprobados);
	cout << "desaprobados: ";
	show(desaprobados);
	
	return 0;
}

