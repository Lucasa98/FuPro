#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

/// Suponemos que la posicion p es en base 0 (0 para el primer elemento)
/// No retornamos un valor porque directamente modificamos el vector
/// original (parametro por referencia).
void insertar(vector<int>& v,int m,int p){
	// aumentamos de tamanio el vector
	v.resize(v.size()+1);
	
	// movemos todos los elementos a partir de p un lugar
	// hacia delante (en "reversa")
	for(size_t i=v.size()-1; i>p; --i){
		v[i] = v[i-1];
	}
	v[p] = m;
}

void show(vector<int> v){
	cout << '[';
	for(size_t i=0; i<v.size(); ++i){
		cout << v[i] << ' ';
	}
	cout << ']' << endl;
}

int main() {
	
	// nueva seed para rand.
	srand(time(0));
	
	vector<int> v(20);
	for(int i=0; i<20; ++i)
		v[i] = 100 + rand()%51;
	
	show(v);
	
	int m,p;
	cin >> m >> p;
	insertar(v,m,p);
	
	show(v);
	
	return 0;
}

