#include <iostream>
using namespace std;

// Usando una estructura
int main() {
    struct ventas {
        string nombre;
        int discos;
        string masvendido;
        int total;
    };
    ventas vendedor[3];
    for (int i=0; i<3; i++) {
		cout << "¿Nombre del vendedor #" << i+1 << "?\n";
		cin >> vendedor[i].nombre;
		cout << "¿Cuantos discos vendio " << vendedor[i].nombre << " este mes?\n";
		cin >> vendedor[i].discos;
		cout << "¿Cual fue el disco que mas vendio " << vendedor[i].nombre << "?\n";
		cin >> vendedor[i].masvendido;
		cout << "¿Cuantos dolares vendio " << vendedor[i].nombre << " en total?\n$";
		cin >> vendedor[i].total;
	};
	cout << endl;
	cout << "------------------------------\n";
	cout << endl;
	for (int i=0; i<3; i++) {
		cout << "Nombre: " << vendedor[i].nombre << endl;
		cout << "-Discos vendidos: " << vendedor[i].discos << endl;
		cout << "-Disco mas vendido: " << vendedor[i].masvendido << endl;
		cout << "-Ventas totales: $" << vendedor[i].total << endl;
		cout << endl;
	};
}