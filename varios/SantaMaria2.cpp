#include <iostream>
using namespace std;

int main() {
	float total = 0.0;
    int tipos;
    struct producto {
        string nombre;
        int cantidad, precio;
    };
	cout << "¿Cuantos tipos de producto compró?\n";
    cin >> tipos;
    cout << endl;
    producto venta[tipos];
    for (int i=0; i<tipos; i++) {
		cout << "Producto #" << i+1 << ":\n";
		cout << "  ¿Como se llama el producto que compró?\n> ";
		cin >> venta[i].nombre;
		cout << "  ¿Que cantidad de " << venta[i].nombre << " compró?\n> ";
		cin >> venta[i].cantidad;
		cout << "  ¿Cual es el precio de " << venta[i].nombre << "?\n> ";
		cin >> venta[i].precio;
		cout << endl;
		total = total + venta[i].cantidad * venta[i].precio;
	};
	cout << "El total de esos productos suma: $" << total << endl;
	if (total >= 100) {
		cout << "Felicidades! Aplica para el descuento del 45%\n";
		cout << "El nuevo valor a pagar es: " << total * (1-0.45) << endl;
	} else {
		cout << "Siga participando\n";
	}
}