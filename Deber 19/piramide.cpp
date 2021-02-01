#include <iostream>
#include <fstream>
using namespace std;

const string nombre_arch = "piramide.txt";

void imprimir();
void error(string cadena);

int main() {
    fstream archivo;
    string letra;
    int niveles;
    archivo.open(nombre_arch, ios::out);
    while (true) {
        cout << "Ingrese los niveles de la piramide: ";
        cin >> niveles;
        if (cin.fail() || cin.get() != '\n') {
            cin.clear();
            while (cin.get() != '\n')
                ;
            error("Debe ingresar un numero");
        } else if (niveles <= 0)
            error("Debe ser mayor que 0");
            else
                break;
    };
    cout << "\n";
    for (int i=niveles; i>0; i--) {
        if (i%2 == 0)
            letra = "*  ";
        else
            letra = "-  ";
        for (int j=0; j<i; j++) {
                //cout << letra;
                archivo << letra;
        }
        //cout << "\n";
        archivo << "\n";
    }
    archivo.close();
    //cout << "\n";
    imprimir();
};

void imprimir() {
    fstream archivo;
    string linea;
    archivo.open(nombre_arch, ios::in);
    if (archivo.fail()) {
        error("No se puede abrir el archivo " + nombre_arch);
    } else {
        while(!archivo.eof()) {
            getline(archivo, linea);
            if (linea != "") {
                cout << linea << "\n";
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