#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

void ordenamientoInsercion(int vector[], int tam);
void imprimir(int vector[], int tam);
void busquedaBinaria(int arreglo[], int tam, int buscar);

int main()
{
    int buscar, tam;
    // tam = 10;
    // int vector[] = {0, 2, 12, 14, 31, 53, 76, 723, 854, 965};
    srand(time(NULL));
    cout << "Ingrese el tamaño del vector: ";
    cin >> tam;

    int vector[tam];
    for (int i = 0; i < tam; i++)
        vector[i] = rand() % 100 + 1;
    imprimir(vector, tam);
    ordenamientoInsercion(vector, tam);
    imprimir(vector, tam);
    cout << "Buscar: ";
    cin >> buscar;
    busquedaBinaria(vector, tam, buscar);
    return 0;
}

void ordenamientoInsercion(int vector[], int tam)
{
    int pos, aux;
    for (int i = 0; i < tam; i++)
    {
        pos = i;
        aux = vector[i];
        while (pos > 0 && vector[pos - 1] > aux)
        {
            vector[pos] = vector[pos - 1];
            pos--;
        }
        vector[pos] = aux;
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

void busquedaBinaria(int arreglo[], int tam, int buscar)
{
    int ini = 0;
    int fin = tam - 1;
    int mitad;
    int pos = -1;
    while (ini <= fin)
    {
        mitad = (ini + fin) / 2;
        if (arreglo[mitad] == buscar)
        {
            pos = mitad;
            break;
        }
        else if (arreglo[mitad] < buscar)
            ini = mitad + 1;
        else
            fin = mitad - 1;
    }
    if (pos != -1)
        cout << "Se encontró " << buscar << " en la posición " << pos + 1 << " del arreglo\n";
    else
        cout << "No se escontró el elemento en el arreglo\n";
}