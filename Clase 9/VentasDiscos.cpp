#include <iostream>
using namespace std;

//Usando un arreglo
int main() {
    string ventas[3][4];
    for (int i=0; i<3; i++) {
		cout << "¿Nombre del vendedor #" << i+1 << "?\n";
		cin >> ventas[i][0];
		cout << "¿Cuantos discos vendio " << ventas[i][0] << " este mes?\n";
		cin >> ventas[i][1];
		cout << "¿Cual fue el disco que mas vendio " << ventas[i][0] << "?\n";
		cin >> ventas[i][2];
		cout << "¿Cuantos dolares vendio " << ventas[i][0] << " en total?\n$";
		cin >> ventas[i][3];
	};
	cout << endl;
	cout << "------------------------------\n";
	cout << endl;
	for (int i=0; i<3; i++) {
		cout << "Nombre: " << ventas[i][0] << endl;
		cout << "-Discos vendidos: " << ventas[i][1] << endl;
		cout << "-Disco mas vendido: " << ventas[i][2] << endl;
		cout << "-Ventas totales: $" << ventas[i][3] << endl;
		cout << endl;
	};
}