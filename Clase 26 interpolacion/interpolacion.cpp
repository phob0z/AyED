#include <iostream>
#include <fstream>

using namespace std;

void ingresar(int vector[], int tam);
void imprimir(int vector[], int tam);
void ordenamientoInsercion(int vector[], int tam);
void busquedaInterpolacion(int arreglo[], int tam, int buscar);

int main()
{
    int pos;
    int buscar;
    int tam;
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
    archivo.open("interpolacion.txt", ios::out);
    cout << "\nArreglo original: ";
    imprimir(arreglo, tam);
    archivo << "Arreglo original: ";
    for (int i = 0; i < tam; i++)
    {
        archivo << "[" << arreglo[i] << "]";
    };
    archivo << "\n";
    ordenamientoInsercion(arreglo, tam);
    cout << "\nArreglo luego del ordenamiento por inseccion: ";
    imprimir(arreglo, tam);
    archivo << "Arreglo ordenado por seleccion: ";
    for (int i = 0; i < tam; i++)
    {
        archivo << "[" << arreglo[i] << "]";
    };
    archivo << "\n";
    cout << "\n";
    while (true)
    {
        cout << "Ingrese un elemento a buscar: ";
        cin >> buscar;
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
    archivo << "Elemento a buscar: " << buscar << "\n";
    archivo.close();
    busquedaInterpolacion(arreglo, tam, buscar);
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

void busquedaInterpolacion(int arreglo[], int tam, int buscar)
{
    fstream archivo;
    archivo.open("interpolacion.txt", ios::out | ios::app);
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
        archivo << "Se encontró " << buscar << " en la posición " << (encontrado + 1) << " del arreglo\n";
    }
    else
    {
        cout << "No se escontró el elemento en el arreglo\n";
        archivo << "No se escontró el elemento en el arreglo\n";
    }
        archivo.close();
}