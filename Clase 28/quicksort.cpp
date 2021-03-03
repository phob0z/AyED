#include <iostream>
#include <fstream>
#include "ordenamiento.h"

using namespace std;

void ingresar(int vector[], int tam);
void imprimir(int vector[], int tam);

int main()
{
    int pos;
    int buscar;
    int tam = 10;
    while (true)
    {
        cout << "\nIngrese el tamaño del arreglo: ";
        cin >> tam;
        if (cin.fail() || cin.get() != '\n')
        {
            cin.clear();
            while (cin.get() != '\n')
                ;
            cout << "Error, debe ser un numero entero\n";
        }
        else if (tam < 0)
            cout << "Error, debe ser un numero entero positivo\n";
        else
            break;
    };
    cout << "\n";
    int arreglo[tam];
    ingresar(arreglo, tam);
    fstream archivo;
    archivo.open("quicksort.txt", ios::out);
    cout << "\nArreglo original: ";
    imprimir(arreglo, tam);
    archivo << "Arreglo original: ";
    for (int i = 0; i < tam; i++)
    {
        archivo << "[" << arreglo[i] << "]";
    };
    archivo << "\n";
    ordenamientoQuicksort(arreglo, 0, tam-1);
    cout << "\nArreglo luego del ordenamiento por quicksort: ";
    imprimir(arreglo, tam);
    archivo << "Arreglo ordenado con quicksort: ";
    for (int i = 0; i < tam; i++)
    {
        archivo << "[" << arreglo[i] << "]";
    };
    archivo << "\n";
    cout << "\n";
    return 0;
}

void ingresar(int vector[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        while (true)
        {
            cout << "Ingrese el valor de la posición [" << i + 1 << "]: ";
            cin >> vector[i];
            if (cin.fail() || cin.get() != '\n')
            {
                cin.clear();
                while (cin.get() != '\n')
                    ;
                cout << "Error, debe ser un numero entero\n";
            }
            else
                break;
        }
    }
}

void imprimir(int vector[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        cout << "[" << vector[i] << "]";
    }
    cout << "\n";
}