#include <iostream>
#include <string>
#include <vector>
using namespace std;

/// Presuponemos que el vector v está ordenado de menor a mayor
/// (si no esto no funcionaria (ni tendria sentido))
size_t busca_pos(vector<string> v, string s){
	// si el elemento en v[pos] es menor a s, insertar s en pos
	// romperia el orden creciente
	size_t pos = 0;
	while (pos < v.size() && v[pos] < s)	/// CUIDADO! Leer linea 64***
		++pos;
	
	return pos;
}

/// Suponemos que la posicion p es en base 0 (0 para el primer elemento)
/// No retornamos un valor porque directamente modificamos el vector
/// original (parametro por referencia).
void inserta(vector<string>& v,string m,size_t p){
	// aumentamos de tamanio el vector
	v.resize(v.size()+1);
	
	// movemos todos los elementos a partir de p un lugar
	// hacia delante (en "reversa")
	for(size_t i=v.size()-1; i>p; --i){
		v[i] = v[i-1];
	}
	v[p] = m;
}

void show(vector<string> v){
	cout << '[';
	for(size_t i=0; i<v.size(); ++i){
		cout << v[i] << ' ';
	}
	cout << ']' << endl;
}

int main() {
	
	/// Leer datos (suponemos que se ingresan en forma creciente)
	vector<string> palabras(4);
	for(int i=0; i<4; ++i)
		cin >> palabras[i];
	
	/// Mostrar vector
	show(palabras);
	
	/// Insertar palabra nueva
	string s;
	cin >> s;
	
	size_t pos = busca_pos(palabras,s);
	inserta(palabras,s,pos);
	
	/// Mostrar arreglo nuevo
	show(palabras);
	
	return 0;
}

/// ***Si en la condicion ponemos
///		v[pos] < s && pos < v.size()
/// (las condiciones al revez) nos va a dar error si el elemento que vamos a insertar va en el ultimo
/// lugar (es mayor a todos)
/// Esto es porque, si v tiene un tamanio de 100, cuando el elemento
/// a insertar sea mayor a todos los del arreglo, (v[pos] < s) va a ser siempre
/// verdadera hasta que pos llegue a 100 y corte por la segunda condicion
/// (pos < v.size()). ESTO NO ES ASI, porque si pos llega a 100, ante de
/// verificar pos<v.size() (y salir, porque es falso), va a tratar de verificar
/// v[pos]<s, PERO v tiene hasta la posicion 99, por eso nos da error.
