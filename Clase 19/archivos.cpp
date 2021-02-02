#include <iostream>
#include <fstream>
using namespace std;

int menu();
void ingresar();
void mostrar();
void error(string cadena);

bool salir;

int main() {
    salir = false;
    while (!salir) {
        switch(menu()) {
            case 0:
                cout << "Saliendo...\n";
                salir = true;
                break;
            case 1:
                ingresar();
                break;
            case 2:
                mostrar();
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
    cout << "\nOpciones:\n";
    cout << "1. Ingresar datos\n";
    cout << "2. Mostrar datos\n";
    cout << "0. Salir\n";
    cout << "> ";
    cin >> opc;
    if (cin.fail() || cin.get() != '\n') {
        cin.clear();
        while (cin.get() != '\n')
            ;
        opc = -1;
    }
    return opc;
};

void ingresar() {
    fstream archivo;
    string nombre_arch, texto, opc;
    int edad;
    cout << "Ingrese el nombre del archivo: ";
    cin.ignore();
    getline(cin, nombre_arch);
    while (true) {
        archivo.open(nombre_arch, ios::out | ios::app);
        cout << "\tIngrese el nombre:   ";
        getline(cin, texto);
        archivo << texto << "\n";
        cout << "\tIngrese el apellido: ";
        getline(cin, texto);
        archivo << texto << "\n";
        cout << "\tIngrese la carrera:  ";
        getline(cin, texto);
        archivo << texto << "\n";
        while (true) {
            cout << "\tIngrese la edad:     ";
            cin >> edad;
            if (cin.fail() || cin.get() != '\n') {
                cin.clear();
                while (cin.get() != '\n')
                    ;
                error("Debe ingresar un numero");
            } else if (edad <= 0)
                error("Debe ser mayor que 0");
                else
                    break;
        };
        archivo << edad << "\n";
        do {
            cout << "¿Desea agregar otro contacto? (s/n): ";
            cin >> opc;
            if (toupper(opc[0]) != 'S' && toupper(opc[0]) != 'N')
                error("Opcion invalida");
        } while(toupper(opc[0]) != 'S' && toupper(opc[0]) != 'N');
        archivo.close();
        if (toupper(opc[0]) == 'N')
            break;
    };
}

void mostrar() {
    fstream archivo;
    string linea, nombre_arch;
    cout << "Ingrese el nombre del archivo: ";
    cin.ignore();
    getline(cin, nombre_arch);
    archivo.open(nombre_arch, ios::in);
    if (archivo.fail()) {
        error("No se puede abrir el archivo " + nombre_arch);
    } else {
        while(!archivo.eof()) {
            getline(archivo, linea);
            if (linea != "") {
                cout << "Nombre:   " << linea << "\n";
                getline(archivo, linea);
                cout << "Apellido: " << linea << "\n";
                getline(archivo, linea);
                cout << "Carrera:  " << linea << "\n";
                getline(archivo, linea);
                cout << "Edad:     " << linea << "\n";
                cout << "---------------------\n";
            }
        }
        archivo.close();
    }
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