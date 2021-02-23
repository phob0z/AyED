#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

void busquedaInterpolacion(int arreglo[], int tam, int buscar);
void ordenamientoBurbuja(int vector[], int tam);
void imprimir(int vector[], int tam);

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
    ordenamientoBurbuja(vector, tam);
    imprimir(vector, tam);
    cout << "Ingrese el elemento a buscar: ";
    cin >> buscar;
    busquedaInterpolacion(vector, tam, buscar);
    return 0;
}

void busquedaInterpolacion(int arreglo[], int tam, int buscar)
{
    int bajo = 0;
    int alto = tam - 1;
    int interp;
    int encontrado;
    int loop = 0;
    while ((arreglo[alto] != arreglo[bajo]) && (buscar >= arreglo[bajo]) && (buscar <= arreglo[alto]))
    {
        interp = bajo + ((buscar - arreglo[bajo]) * (alto - bajo) / (arreglo[alto] - arreglo[bajo]));
        if (arreglo[interp] < buscar)
            bajo = interp + 1;
        else if (arreglo[interp] > buscar)
            alto = interp - 1;
        else
        {
            encontrado = interp;
            break;
        }
        loop++;
    }
    if (buscar == arreglo[bajo])
        encontrado = bajo;
    if (encontrado != -1)
    {
        cout << "Se encontró " << buscar << " en la posición " << (encontrado + 1) << " del arreglo\n";
        cout << "Se necesitaron " << loop << " iteraciones para encontrarlo\n";
    }
    else
        cout << "No se escontró el elemento en el arreglo\n";
}

void ordenamientoBurbuja(int vector[], int tam)
{
    int aux;
    for (int i = 0; i < tam; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            if (vector[j] < vector[i])
            {
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
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