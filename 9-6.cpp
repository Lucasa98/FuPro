#include <iostream>
using namespace std;

void show(vector<float>& v){
	cout << '[';
	for(size_t i=0; i<v.size(); ++i){
		cout << v[i] << ' ';
	}
	cout << ']' << endl;
}

int main(){
	
	/// Ingreso de datos
	vector<float> meses(12);
	float monto;
	// Primer monto
	cin >> monto;
	while(monto != 0){
		int dia, mes;
		cin >> dia >> mes;
		meses[mes-1] += monto;
		
		// monto siguiente
		cin >> monto;
	}
	
	/// Total por mes
	show(meses);
	
	/// Mes de menor aporte
	int mes_menor = 0;
	for(int i=0; i<12; ++i){
		if(meses[i] < meses[mes_menor])
			mes_menor = i;
	}
	cout << "mes de mnor aporte: " << mes_menor+1 << endl;
	
	return 0;
}

