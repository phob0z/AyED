#include <iostream>
#include <fstream>
using namespace std;

int menu();
int busquedaLineal(string nombreArch);
void ingresarElementos(string nombreArch);
void imprimirElementos(string nombreArch);
void error(string cadena);

bool salir;

int main() {
    string nombreArch = "lineal.txt";
    salir = false;
    while (!salir) {
        switch(menu()) {
            case 0:
                cout << "Saliendo...\n";
                salir = true;
                break;
            case 1:
                ingresarElementos(nombreArch);
                break;
            case 2:
                imprimirElementos(nombreArch);
                break;
            case 3:
                busquedaLineal(nombreArch);
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
    cout << "3. Busqueda lineal\n";
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

int busquedaLineal(string nombreArch) {
    fstream archivo;
    string linea, dato;
    archivo.open(nombreArch, ios::in);
    int pos = -1, numlinea = 0;
    cout << "Introduzca el dato que desea buscar\n";
    cin >> dato;
    if (archivo.fail()) {
        error("No se puede abrir el archivo " + nombreArch);
    } else {
        while(!archivo.eof()) {
            numlinea++;
            getline(archivo, linea);
            if (linea == dato) {
                pos = numlinea;
                cout << "Elemento encontrado en la linea " << pos << "\n";
            }
        }
        if (pos == -1)
            cout << "Elemento no encontrado\n";
        archivo.close();
    }
    return pos;
}

void ingresarElementos(string nombreArch) {
    fstream archivo;
    string dato;
    archivo.open(nombreArch, ios::out | ios::app);
    while (true) {
        cout << "\tIngrese el dato (\"salir\" para parar):   ";
        getline(cin, dato);    
        archivo << dato << "\n";
        if (dato == "salir")
            break;
    };
    archivo.close();
}

void imprimirElementos(string nombreArch) {
    fstream archivo;
    string linea;
    int numlineas = 0;
    archivo.open(nombreArch, ios::in);
    if (archivo.fail()) {
        error("No se puede abrir el archivo " + nombreArch);
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