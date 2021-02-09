#include <iostream>
#include <fstream>
using namespace std;

int menu();
void intercambiar();
void error(string cadena);

bool salir;

int main() {
    salir = false;
    while (!salir) {
        switch(menu()) {
            case 1:
                intercambiar();
                break;
            case 2:
                cout << "Opcion 2\n";
                break;
            case 3:
                cout << "Opcion 3\n";
                break;
            case 4:
                cout << "Saliendo...\n";
                salir = true;
                break;
            default:
                error("Opcion invalida");
                break;
        };
    };
    return 0;
};

int menu() {
    int opc;
    cout << "\n\t\tTRABAJO EN GRUPO\n\n";
    cout << "\tALGORITMOS Y ESTRUCTURAS DE DATOS\n\n";
    cout << "\tSELECCIONE UNA OPCION DEL MENU\n\n";
    cout << "1.- INTERCAMBIAR POSICIONES DE UN VECTOR\n";
    cout << "2.- ORDENAMIENTO DE UN VECTOR\n";
    cout << "3.- CUENTA DE AHORROS VIRTUAL DEL BANCO PICHINCHA\n";
    cout << "4.- SALIR\n";
    cout << "OPCION: ";
    cin >> opc;
    if (cin.fail() || cin.get() != '\n') {
        cin.clear();
        while (cin.get() != '\n')
            ;
        opc = -1;
    }
    return opc;
};

void intercambiar() {
    int tam = 6;
    string vector[tam], intercambiado[tam];
    cout << "\n\nINTERCAMBIAR POSICIONES DE UN VECTOR\n";
    cout << "------------------------------------\n";
    for (int i=0; i<tam; i++) {
        cout << "Ingrese el valor de la posición #" << i+1 << ": ";
        cin >> vector[i];
    }
    cout << "\nVector original: ";
    for (int i=0; i<tam-1; i++) {
        cout << vector[i] << "|";
    }
    cout << vector[tam-1] << "\n";
    for (int i=0; i<tam; i++) {
        intercambiado[tam-i-1]=vector[i];
    }
    cout << "Vector intercambiado: ";
    for (int i=0; i<tam-1; i++) {
        cout << intercambiado[i] << "|";
    }
    cout << intercambiado[tam-1] << "\n";
}

void error(string cadena) {
    cadena = "  *** " + cadena + " ***  ";
    cout << "\n╔";
    for (int i=0; i<cadena.length(); i++) {
        cout << "═";
    }
    cout << "╗\n║" << cadena << "║\n╚";
    for (int i=0; i<cadena.length(); i++) {
        cout << "═";
    }
    cout << "╝\n";
};