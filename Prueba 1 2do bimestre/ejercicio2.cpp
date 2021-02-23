#include <iostream>
#include <fstream>

using namespace std;

void ingresarArch(string nombreArch);
void imprimirArch(string nombreArch);

int main() {
    cout << "Bienvenido al sistema de inventario de ETAFASHION\n\n";
    cout << "*** Para salir del sistema, introduzca * cuando se pida el nombre ***\n";
    ingresarArch("inventario.txt");
    cout << "\n\n";
    imprimirArch("inventario.txt");
    cout << "\n";
    return 0;
}

void ingresarArch(string nombreArch) {
    fstream archivo;
    float precio, precioT = 0;
    int cantidad, cantidadT = 0, total = 0;
    string texto;
    archivo.open(nombreArch, ios::out);
    archivo << "*******  INVENTARIO ETAFASHION PELUCHES  *******\n\n";
    archivo << "nombre\t\tprecio\t\tcantidad\tcolor\n\n";
    while (true) {
        cout << "\nIngrese el nombre del peluche: ";
        getline(cin, texto);
        if (texto == "*")
            break;
        archivo << texto << "\t\t";
        while(true) {
            cout << "Ingrese el precio de " << texto << ": ";
            cin >> precio;
            if (cin.fail() || cin.get() != '\n') {
                cin.clear();
                while (cin.get() != '\n')
                    ;
                cout << "Error, debe ser un numero\n";
            } else
                if (precio < 0)
                    cout << "Error, debe ser un numero positivo\n";
                else
                    break;
        };
        archivo << "$" << precio << "\t\t";
        precioT += precio;
        while(true) {
            cout << "Ingrese la cantidad de " << texto << " que entran: ";
            cin >> cantidad;
            if (cin.fail() || cin.get() != '\n') {
                cin.clear();
                while (cin.get() != '\n')
                    ;
                cout << "Error, debe ser un numero\n";
            } else
                if (cantidad < 0)
                    cout << "Error, debe ser un numero positivo\n";
                else
                    break;
        };
        archivo << cantidad << "\t\t";
        cantidadT += cantidad;
        cout << "Ingrese el color de " << texto << ": ";
        getline(cin, texto);
        archivo << texto << "\n";
        total++;
    };
    archivo << "\nNúmero total de peluches ingresado\t" << total << "\n";
    archivo << "Cantidad de peluches adquiridos\t\t" << cantidadT << "\n";
    archivo << "El valor total de los peluches\t\t$" << precioT << "\n";
    archivo.close();
}

void imprimirArch(string nombreArch) {
    fstream archivo;
    string linea;
    int numlineas = 0;
    archivo.open(nombreArch, ios::in);
    if (archivo.fail()) {
        cout << "No se puede abrir el archivo " + nombreArch << "\n";
    } else {
        while(!archivo.eof()) {
            getline(archivo, linea);
            if (linea != "") {
                numlineas++;
                cout << linea << "\n";
            }
        }
        archivo.close();
        if (numlineas == 0)
            cout << "El archivo esta vacio\n";
    }
}