#include <iostream>
#include <fstream>
using namespace std;

//typedef enum tipoUva { A, B } tipoUva;
//typedef enum tamUva { 1, 2 } tamUva;

int main() {
    char tipo[1];
    int tam;
    float precio=0, kilos=0, ganancia=0;
    cout << "¿Cual es el precio actual del kilo de uva? ";
    cin >> precio;
    cout << "¿Cuantos kilos va a vender? ";
    cin >> kilos;
    while(true) {
        cout << "Introduzca el tipo de uva (A o B): ";
        cin >> tipo;
        if ((tipo[0]) != 'A' && toupper(tipo[0]) != 'B')
            cout << "Error: el tipo debe ser A o B\n";
        else
            break;
    };
    cout << "Introduzca el tamaño de la uva (1 o 2): ";
    cin >> tam;
    if (tipo[0] == 'A')
        if (tam == 1)
            precio+=0.2;
        else
            precio+=0.3;
    else
        if (tam == 1)
            precio-=0.3;
        else
            precio-=0.5;

    
    return 0;
}