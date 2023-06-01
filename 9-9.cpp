#include <iostream>
#include <matrix>
#include <iomanip>
using namespace std;

void show(matrix<int> M){
	for(size_t i=0; i<M.size(0); ++i){
		cout << "| ";
		for(size_t j=0; j<M.size(1); ++j){
			cout << setw(4) << M[i][j] << ' ';
		}
		cout << "|" << endl;
	}
}

void show(vector<float> v){
	for(size_t i=0; i<v.size(); ++i){
		cout << "| ";
		cout << fixed << setw(6) << setprecision(2) << v[i] << " |" << endl;
	}
}
	
int main() {
	srand(time(0));
	
	/// Ingreso de datos
	matrix<int> M(26,5,0);		// inicializo todo en 0
	vector<float> precios(25);	// vector de precio por articulo

	for(size_t i=0; i<M.size(0)-1; ++i){
		precios[i] = 10+rand()%100 + (rand()%100)/100.f;	// precio random entre 10 y 99 + centavos
		for(size_t j=0; j<M.size(1)-1; ++j){
			//			cout << "M[" << i << "][" << j << "] = ";
			//			cin >> M[i][j];
			
			M[i][j] = rand()%10;	//random por comodidad
			
			M[25][j] += M[i][j];	//sumamos al sub-total de la sucursal j
			M[i][4] += M[i][j];		//sumamos al sub-total del articulo i
			M[25][4] += M[i][j];	//total de la empresa
		}
	}
	
	show(M);
	show(precios);
	cout << "\n=====================================" << endl;
	
	/// a) Recaudación de cada sucursal
	for(size_t i=0; i<M.size(1)-1; ++i){
		float total = 0;
		for(size_t j=0; j<M.size(0); ++j){
			total += M[j][i]*precios[j];	// unidades*precio
		}
		cout << "La sucursal " << i << " recaudo $" << total << endl;
	}
	
	
	
	return 0;
}


