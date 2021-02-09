#include <iostream>
#include <fstream>
using namespace std;

int menu();
void intercambiar();
void ordenar();
void pichincha();
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
                ordenar();
                break;
            case 3:
                pichincha();
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
    for (int i=0; i<tam; i++) {
        cout << "[" << vector[i] << "]";
    }
    cout << "\n";
    for (int i=0; i<tam; i++) {
        intercambiado[tam-i-1]=vector[i];
    }
    cout << "Vector intercambiado: ";
    for (int i=0; i<tam; i++) {
        cout << "[" << intercambiado[i] << "]";
    }
    cout << "\n";
}

void ordenar() {
    int tam, aux;
    cout << "\n\nORDENAMIENTO DE UN VECTOR\n";
    cout << "-------------------------\n";
    cout << "Ingrese el tamaño del vector: ";
    cin >> tam;
    int vector[tam];
    for (int i=0; i<tam; i++) {
        cout << "Ingrese el valor de la posición #" << i+1 << ": ";
        cin >> vector[i];
    }
    cout << "\nVector original: ";
    for (int i=0; i<tam; i++) {
        cout << "[" << vector[i] << "]";
    }
    cout << "\n";
    for (int i=0; i<tam; i++) {
        for (int j=i+1; j<tam; j++) {
            if (vector[j] < vector[i]) {
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
    cout << "Vector ordenado: ";
    for (int i=0; i<tam; i++) {
        cout << "[" << vector[i] << "]";
    }
    cout << "\n";
}

void pichincha() {
    float buscar;
    bool band = false;
    string meses[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",\
    "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
    float ahorros[12];
    cout << "\n\nCUENTA DE AHORROS BANCO PICHINCHA\n";
    cout << "---------------------------------\n";
    for(int i=0; i<12; i++) {
        cout << "Ingrese los ahorros de " << meses[i] << ": ";
        cin >> ahorros[i];
    }
    cout << "\nIngrese la cantidad de dinero a buscar: ";
    cin >> buscar;
    cout << "\n";
    for (int i=0; i<12; i++) {
        if (buscar == ahorros[i]) {
            if (!band)
                cout << "La cantidad de ahorro $" << buscar << " se ha "\
                "encontrado en el mes de " << meses[i];
            else
                cout << ", " << meses[i];
            band = true;
        }
    }
    cout << ".\n";
    if (!band)
        cout << "El ahorro ingresado no se encuentro registrado en ningun "\
        "mes.\n";
    cout << "GRACIAS!\n";
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