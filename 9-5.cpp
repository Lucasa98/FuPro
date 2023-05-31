#include <iostream>
#include <vector>
using namespace std;

size_t buscar(vector<int>& v,int x){
	size_t pos = 0;
	
	while (pos < v.size() && v[pos] != x)
		++pos;
	
	/// Si no lo encontró (llegó al final)
	if(pos == v.size()){
		return -1;
	}
	
	return pos;
}

/// Suponemos que pos es menor al tamanio del arreglo
void eliminar(vector<int>& v, size_t pos){
	for(size_t i=pos; i<v.size()-1; ++i)
		v[i] = v[i+1];
	
	v.resize(v.size()-1);
}

void show(vector<int>& v){
	cout << '[';
	for(size_t i=0; i<v.size(); ++i){
		cout << v[i] << ' ';
	}
	cout << ']' << endl;
}

int main() {
	
	/// Ingreso de datos
	size_t N;
	cout << "N: ";
	cin >> N;
	
	vector<int> v(N);
	for(size_t i=0; i<N; ++i){
		cout << "v[" << i << "] = ";
		cin >> v[i];
	}
	
	show(v);
	size_t pos = buscar(v,523);
	eliminar(v,pos);
	
	show(v);
	
	return 0;
}

