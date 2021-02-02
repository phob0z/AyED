#include <iostream>
#include <fstream>
using namespace std;

int busquedaLineal(int arreglo[], int dato, int tam);
int ingresarElementos(int arreglo[], int tam);
int imprimirElementos(int arreglo[], int tam);
int validarNumero(string pedir);
void error(string cadena);

int main() {
    int tam;
    tam = validarNumero("Ingrese el tamaño del vector:");
    int vector[tam];
    //int tam = sizeof(vector)/sizeof(int);
    busquedaLineal(vector, 5, tam);
    return 0;
}

int busquedaLineal(int arreglo[], int dato, int tam) {
    int pos = -1;
    for (int i=0; i<tam; i++) {
        if (arreglo[i]==dato) {
            pos = i;
            break;
        }
    }
    if (pos != -1)
        cout << "Elemento encontrado en la posición " << pos << "\n";
    else
        cout << "Elemento no encontrado\n";
    return pos;
}

int ingresarElementos(int arreglo[], int tam) {
    cout << "Ingresar elementos...\n";
    return 0;
}

int imprimirElementos(int arreglo[], int tam) {
    cout << "Imprimir elementos...\n";
    return 0;
}

int validarNumero(string pedir) {
    int entrada;
    while (true) {
        cout << pedir << "\n";
        cin >> entrada;
        if (cin.fail() || cin.get() != '\n') {
            cin.clear();
            while (cin.get() != '\n')
                ;
            error("Debe ingresar un numero");
        } else if (entrada <= 0)
            error("Debe ser mayor que 0");
            else
                break;
    };
    return entrada;
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