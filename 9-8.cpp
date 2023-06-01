#include <iostream>
#include <matrix>
using namespace std;

int main() {
	
	/// Ingreso de datos
	matrix<int> M(25,4);
	
	for(size_t i=0; i<M.size(0); ++i){		// articulo
		for(size_t j=0; j<M.size(1); ++j){	// sucursal
			cout << "M[" << i << "][" << j << "] = ";
			cin >> M[i][j];					// unidades vendidas
		}
	}
	
	/// a) Total de unidades vendidas de cada articulo
	// recorremos los articulos
	for(size_t i=0; i<M.size(0); ++i){
		int total = 0;
		for(size_t j=0; j<M.size(1); ++j)
			total += M[i][j];
		cout << "Total articulo " << i << ": " << total << endl;
	}
	
	/// b) Total de unidades vendidas por la sucursal 3
	// la sucursal 3 está en la posicion 2
	int totalSuc3 = 0;
	for(size_t i=0; i<M.size(0); ++i){
		totalSuc3 += M[i][2];
	}
	cout << "Total sucursal 3: " << totalSuc3 << endl;
	
	/// c) Cantidad vendida por la sucursal 1 del articulo 6
	// la sucursal 1 está en la posicion 0
	// y el articulo 6 en la posicion 5
	cout << "Sucursal 1 - Articulo 6: " << M[5][0] << endl;
	
	/// d) Sucursal que mas vendio del articulo 8
	int posMayor = 0;
	for(size_t i=0; i<M.size(1); ++i){	// recorremos las sucursales
		if(M[7][i] > M[7][posMayor])
			posMayor = i;
	}
	cout << "La sucursal que mas vendio del articulo 8 fue " << posMayor+1;
	cout << " con " << M[7][posMayor] << "articulos" << endl;
	
	return 0;
}

