#include <iostream>
#include <fstream>

using namespace std;

void ingresar(int vector[], int tam);
void imprimir(int vector[], int tam);
void ordenamientoSeleccion(int vector[], int tam);
int busquedaLineal(int vector[], int tam, int buscar);

int main() {
    int pos;
    int buscar;
    int tam;
    int sumaPos = 0, sumaNeg = 0;
    while(true) {
        cout << "\nIngrese el tamaño del arreglo: ";
        cin >> tam;
        if (cin.fail() || cin.get() != '\n') {
            cin.clear();
            while (cin.get() != '\n')
                ;
            cout << "Error, debe ser un numero entero\n";
        } else
            if (tam < 0)
                cout << "Error, debe ser un numero entero positivo\n";
            else
                break;
    };
    cout << "\n";
    int arreglo[tam];
    ingresar(arreglo, tam);
    for (int i=0; i<tam; i++) {
        if (arreglo[i] >= 0)
            sumaPos += arreglo[i];
        else
            sumaNeg += arreglo[i];
    }
    fstream archivo;
    archivo.open("ordenamiento.txt", ios::out);
    cout << "\nArreglo original: ";
    imprimir(arreglo, tam);
    archivo << "Arreglo original: ";
    for (int i=0; i<tam; i++) {
        archivo << "|" << arreglo[i] << "|";
    };
    archivo << "\n";
    cout << "\nLa suma de los positivos es: " << sumaPos << "\n";
    cout << "La suma de los negativos es: " << sumaNeg << "\n";
    ordenamientoSeleccion(arreglo, tam);
    cout << "\nArreglo luego del ordenamiento por selección: ";
    imprimir(arreglo, tam);
    archivo << "Arreglo ordenado por seleccion: ";
    for (int i=0; i<tam; i++) {
        archivo << "|" << arreglo[i] << "|";
    };
    archivo << "\n";
    archivo << "Suma de numeros positivos: " << sumaPos << "\n";
    archivo << "Suma de numeros negativos: " << sumaNeg << "\n";
    archivo.close();
    cout << "\n";
    while(true) {
        cout << "Ingrese un elemento a buscar: ";
        cin >> buscar;
        if (cin.fail() || cin.get() != '\n') {
            cin.clear();
            while (cin.get() != '\n')
                ;
            cout << "Error, debe ser un numero entero\n";
        } else
            break;
    }
    pos = busquedaLineal(arreglo, tam, buscar);
    archivo.open("busqueda.txt", ios::out);
    archivo << "Arreglo: ";
    for (int i=0; i<tam; i++) {
        archivo << "|" << arreglo[i] << "|";
    };
    archivo << "\n";
    archivo << "Buscar el elemento: " << buscar << "\n";
    if (pos == -1) {
        cout << "Error, no se encontro el elemento\n";
        archivo << "Error, no se encontro el elemento\n";
    } else {
        cout << "Elemento encontrado en la posicion " << pos+1 << "\n";
        archivo << "Elemento encontrado en la posicion " << pos+1 << "\n";
    }
    archivo.close();
    return 0;
}

void ingresar(int vector[], int tam) {
    for (int i=0; i<tam; i++) {
        while(true) {
            cout << "Ingrese el valor de la posición [" << i+1 << "]: ";
            cin >> vector[i];
            if (cin.fail() || cin.get() != '\n') {
                cin.clear();
                while (cin.get() != '\n')
                    ;
                cout << "Error, debe ser un numero entero\n";
            } else
                break;
        }
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