#include <iostream>
#include <string>
using namespace std;

int lineal(float vector[], int tam, float buscar);
int binaria(float vector[], int tam, float buscar);
int interpolacion(float vector[], int tam, float buscar);

int lineal(float vector[], int tam, float buscar)
{
    int pos = -1;
    for (int i = 0; i < tam; i++)
        if (vector[i] == buscar)
        {
            pos = i;
            break;
        }
    return pos;
}

int binaria(float vector[], int tam, float buscar)
{
    int ini = 0;
    int fin = tam - 1;
    int mitad;
    int pos = -1;
    while (ini <= fin && pos == -1)
    {
        mitad = (ini + fin) / 2;
        if (vector[mitad] == buscar)
            pos = mitad;
        else if (vector[mitad] < buscar)
            ini = mitad + 1;
        else
            fin = mitad - 1;
    }
    return pos;
}

int interpolacion(float vector[], int tam, float buscar)
{
    int bajo = 0;
    int alto = tam - 1;
    int interp;
    int pos = -1;
    while ((vector[alto] != vector[bajo]) && (buscar >= vector[bajo]) && (buscar <= vector[alto]) && pos == -1)
    {
        interp = bajo + ((buscar - vector[bajo]) * (alto - bajo) / (vector[alto] - vector[bajo]));
        if (vector[interp] < buscar)
            bajo = interp + 1;
        else if (vector[interp] > buscar)
            alto = interp - 1;
        else
            pos = interp;
    }
    if (buscar == vector[bajo])
        pos = bajo;
    return pos;
}