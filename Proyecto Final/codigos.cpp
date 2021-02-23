#include <iostream>
#include <fstream>

using namespace std;

bool salir = false;
const string nombreArch = "lineal.txt";

int menu();
void ingresar(int vector[], int tam);
void imprimir(int vector[], int tam);
void ordenamientoSeleccion(int vector[], int tam);
void ordenamientoBurbuja(int vector[], int tam);
int busquedaLineal(int vector[], int tam, int buscar);
int busquedaBinaria(int vector[], int tam, int buscar);
void ingresarArch(string nombreArch);
void imprimirArch(string nombreArch);
int busquedaLinealArch(string nombreArch);
void error(string cadena);

int main() {
    int buscar;
    int tam;
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> tam;
    int arreglo[tam];
    while (!salir) {
        switch(menu()) {
            case 0:
                cout << "Saliendo...\n";
                salir = true;
                break;
            case 1:
                ingresar(arreglo, tam);
                imprimir(arreglo, tam);
                ordenamientoSeleccion(arreglo, tam);
                imprimir(arreglo, tam);
                cout << "Elemento a buscar: ";
                cin >> buscar;
                cout << "BLineal posicion: " << busquedaLineal(arreglo, tam, buscar)+1 << "\n";
                ingresar(arreglo, tam);
                imprimir(arreglo, tam);
                ordenamientoBurbuja(arreglo, tam);
                imprimir(arreglo, tam);
                cout << "Elemento a buscar: ";
                cin >> buscar;
                cout << "BBinaria posicion: " << busquedaBinaria(arreglo, tam, buscar)+1 << "\n";
                break;
            case 2:
                ingresarArch(nombreArch);
                imprimirArch(nombreArch);
                busquedaLinealArch(nombreArch);
                break;
            default:
                error("Opcion invalida");
                break;
        };
    };

    return 0;
}

int menu() {
    int opc;
    cout << "\nOpciones:\n";
    cout << "1. Vector\n";
    cout << "2. Archivo\n";
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

void ingresar(int vector[], int tam) {
    for (int i=0; i<tam; i++) {
        cout << "Ingrese el valor de la posición [" << i+1 << "]: ";
        cin >> vector[i];
    }
}

void imprimir(int vector[], int tam) {
    for (int i=0; i<tam; i++) {
        cout << "|" << vector[i] << "|";
    }
    cout << "\n";
}

void ordenamientoSeleccion(int vector[], int tam) {
    int aux, min;
    for (int i=0; i<tam; i++) {
        min = i;
        for(int j=i+1; j<tam ; j++) {
            if(vector[j] < vector[min]) {
                min = j;
            }
        }
        aux = vector[i];
        vector[i] = vector[min];
        vector[min] = aux;
    }
}

void ordenamientoBurbuja(int vector[], int tam) {
    int aux;
    for (int i=0; i<tam; i++) {
        for (int j=i+1; j<tam; j++) {
            if (vector[j] < vector[i]) {
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
}

int busquedaLineal(int vector[], int tam, int buscar) {
    int pos = -1;
    for (int i=0; i<tam; i++) {
        if (vector[i] == buscar) {
            pos = i;
            break;
        }
    }
    return pos;
}

int busquedaBinaria(int vector[], int tam, int buscar) {
    int ini = 0;
    int fin = tam - 1;
    int mitad;
    int pos = -1;
    while (ini <= fin) {
        mitad = (ini + fin) / 2;
        if (vector[mitad] == buscar) {
            pos = mitad;
            break;
        } else
            if (vector[mitad] < buscar)
                ini = mitad + 1;
            else
                fin = mitad - 1;
    }
    return pos;
}

void ingresarArch(string nombreArch) {
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

void imprimirArch(string nombreArch) {
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

int busquedaLinealArch(string nombreArch) {
    fstream archivo;
    string linea, dato;
    archivo.open(nombreArch, ios::in);
    int pos = -1, numlineas = 0;
    cout << "Introduzca el dato que desea buscar\n";
    cin >> dato;
    if (archivo.fail()) {
        error("No se puede abrir el archivo " + nombreArch);
    } else {
        while(!archivo.eof()) {
            numlineas++;
            getline(archivo, linea);
            if (linea == dato) {
                pos = numlineas;
                break;
                //cout << "Elemento encontrado en la linea " << pos << "\n";
            }
        }
        // if (pos == -1)
        //     cout << "Elemento no encontrado\n";
        archivo.close();
        if (numlineas == 0)
            cout << "El archivo esta vacio\n";
    }
    return pos;
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