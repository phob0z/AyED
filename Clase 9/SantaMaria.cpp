#include <iostream>
using namespace std;

int main() {
	float desc = 0.0, total = 0.0;
    int tipos, cantidad, precio;
    string nombre;
	cout << "¿Cuantos tipos de producto compró?\n";
    cin >> tipos;
	cout << endl;
    for (int i=1; i<=tipos; i++) {
		cout << "Producto #" << i << ":\n";
		cout << "  ¿Como se llama el producto que compró?\n> ";
		cin >> nombre;
		cout << "  ¿Que cantidad de " << nombre << " compró?\n> ";
		cin >> cantidad;
		cout << "  ¿Cual es el precio de " << nombre << "?\n> ";
		cin >> precio;
		cout << endl;
		total = total + cantidad * precio;
	};
	cout << "El total de esos productos suma: $" << total << endl;
	if (total >= 100) {
		cout << "Felicidades! Aplica para el descuento del 45%\n";
		cout << "El nuevo valor a pagar es: " << total * (1-0.45) << endl;
	} else {
		cout << "Siga participando\n";
	}
}