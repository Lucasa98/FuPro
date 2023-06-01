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

int main() {
	
	/// Alternativa mejor (segun Lucas)
	// una fila mas para el sub-total de unidades por sucursal
	// una columna mas para el sub-total de unidades por articulo
	matrix<int> M(26,5,0);	// inicializo todo en 0
	
	/// Ingreso de datos + suma de totales
	for(size_t i=0; i<M.size(0)-1; ++i){
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
	cout << "\n=====================================" << endl;
	
	/// a) total de unidades de cada articulo
	// solo tenemos que mostrar la ultima columna
	for(size_t i=0; i<M.size(0)-1; ++i){
		cout << "Total articulo " << i << ": " << M[i][4] << endl;
	}
	
	/// b) total de unidades de la sucursal 3
	// solo nos fijamos la ultima fila, en la columna 2
	cout << "Total sucursal 3: " << M[25][2] << endl;
	
	/// c) Cantidad vendida por la sucursal 1 del articulo 6
	// la sucursal 1 está en la posicion 0
	// y el articulo 6 en la posicion 5
	cout << "Sucursal 1 - Articulo 6: " << M[5][0] << endl;
	
	/// d) Sucursal que mas vendio del articulo 8
	int posMayor = 0;
	for(size_t i=0; i<M.size(1)-1; ++i){	// recorremos las sucursales
		if(M[7][i] > M[7][posMayor])
			posMayor = i;
	}
	cout << "La sucursal que mas vendio del articulo 8 fue " << posMayor+1;
	cout << " con " << M[7][posMayor] << "articulos" << endl;
	
	return 0;
}

