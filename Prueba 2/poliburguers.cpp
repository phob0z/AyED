#include <iostream>
using namespace std;

int main() {
    bool salir;
    float precio[3] = {1.5, 2.5, 3.25};
    float recargo[2] = {1, 1.05};
    int tipo, cantidad, pago;
    string nombre[3] = {"sencilla", "doble", "triple"};
    salir = false;
    while(!salir) {
        cout << "Tenemos 3 tipos de poliburguers, ¿de que tipo desea comprar?"\
        " (1, 2, 3)\n";
        cin >> tipo;
        switch(tipo) {
            case 1: case 2: case 3:
                salir = true;
                break;
            default:
                cout << "Opción invalida ...\n";
                break;
        };
    };
    cout << "¿Cuantas poliburguers " << nombre[tipo-1] << "s desea comprar?\n";
    cin >> cantidad;
    salir = false;
    while(!salir) {
        cout << "¿Como desea pagar efectivo (1), crédito (2)?\n";
        cin >> pago;
        switch((pago)) {
            case 1: case 2:
                salir = true;
                break;
            default:
                cout << "Opción invalida...\n";
                break;
        };
    };
    if(cantidad == 1)
        cout << "El monto a pagar por la poliburguer " << nombre[tipo-1] <<\
        " es de $" << cantidad*precio[tipo-1]*recargo[pago-1] << endl;
    else
        cout << "El monto a pagar por " << cantidad << " poliburguers "\
        << nombre[tipo-1] << "s es de $" << cantidad*precio[tipo-1]*\
        recargo[pago-1] << endl;
}