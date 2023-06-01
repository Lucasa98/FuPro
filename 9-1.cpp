#include <iostream>
#include <vector>
using namespace std;

int main() {
	/*
	vector<int> notas(30);
	
	///===== Leer notas =====
	for(int i=0; i<30; ++i){
		cin >> notas[i];
	}
	
	///===== Calcular promedio =====
	float prom = 0;
	for(int i=0; i<30; ++i){
		prom += notas[i];
	}
	prom = prom/30;
	
	///===== Mostrar por encima del promedio =====
	for(int i=0; i<30; ++i){
		if(notas[i] > prom)
			cout << notas[i] << endl;
	}
	*/
	
	///-----------------------------------------------
	/// ========== Alternativa ==========
	
	vector<int> notas(30);
	
	///===== Leer notas/calcular promedio =====
	float prom = 0;
	for(int i=0; i<30; ++i){
		cin >> notas[i];
		prom += notas[i];
	}
	prom /= 30;
	
	///===== Mostrar por encima del promedio =====
	for(int i=0; i<30; ++i){
		if(notas[i] > prom)
			cout << notas[i] << endl;
	}
	
	return 0;
}
