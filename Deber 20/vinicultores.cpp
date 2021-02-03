#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string nombreArch = "vinicultores.txt";
    fstream archivo;
    string tipo;
    int tam;
    float precioI, precio, kilos, ganancia;
    cout << "¿Cual es el precio actual del kilo de uva? ";
    cin >> precioI;
    precio = precioI;
    cout << "¿Cuantos kilos va a vender? ";
    cin >> kilos;
    while(true) {
        cout << "Introduzca el tipo de uva (A o B): ";
        cin >> tipo;
        tipo = toupper(tipo[0]);
        if (tipo != "A" && tipo != "B")
            cout << "Error: el tipo debe ser A o B\n";
        else
            break;
    };
    while (true) {
        cout << "Introduzca el tamaño de la uva (1 o 2): ";
        cin >> tam;
        if (cin.fail() || cin.get() != '\n') {
            cin.clear();
            while (cin.get() != '\n')
                ;
            cout << "Error: el tamaño debe ingresar un numero\n";
        } else if (tam != 1 && tam != 2)
            cout << "Error: el tipo debe 1 o 2\n";
            else
                break;
    };
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
    ganancia = precio * kilos;
    cout << "Precio Inicial: " << precioI << "\n";
    cout << "Kilos: " << kilos << "\n";
    cout << "Tipo: " << tipo[0] << "\n";
    cout << "Tamaño: " << tam << "\n";
    cout << "Precio final: " << precio << "\n";
    cout << "Ganancia: " << ganancia << "\n";
    archivo.open(nombreArch, ios::out | ios::app);
    archivo << "Precio Inicial: " << precioI << "\n";
    archivo << "Kilos: " << kilos << "\n";
    archivo << "Tipo: " << tipo[0] << "\n";
    archivo << "Tamaño: " << tam << "\n";
    archivo << "Precio final: " << precio << "\n";
    archivo << "Ganancia: " << ganancia << "\n";
    archivo.close();
    return 0;
}