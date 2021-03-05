#include <iostream>
#include <string>
using namespace std;

string lineal(int vector[], int tam, int buscar);
string binaria(int vector[], int tam, int buscar);
string interpolacion(int vector[], int tam, int buscar);

string lineal(int vector[], int tam, int buscar) {
    string linea = "La búsqueda lineal ";
    int pos = -1;
    for (int i=0; i<tam; i++)
        if (vector[i] == buscar) {
            pos = i;
            break;
        }
    if (pos != -1)
        linea = "encontró " + to_string(buscar) + " en la posición " + to_string(pos + 1) + " del vector";
    else
        linea = "no escontró el elemento en el vector";
    return linea;
}

string binaria(int vector[], int tam, int buscar)
{
    string linea = "La búsqueda binaria ";
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
    if (pos != -1)
        linea = "encontró " + to_string(buscar) + " en la posición " + to_string(pos + 1) + " del vector";
    else
        linea = "no escontró el elemento en el vector";
    return linea;
}

string interpolacion(int vector[], int tam, int buscar)
{
    string linea = "La búsqueda por interpolación ";
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
    if (pos != -1)
        linea = "encontró " + to_string(buscar) + " en la posición " + to_string(pos + 1) + " del vector";
    else
        linea = "no escontró el elemento en el vector";
    return linea;
}