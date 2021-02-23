#include <iostream>
#include <fstream>

using namespace std;

void ingresar(int vector[], int tam);
void imprimir(int vector[], int tam);
void ordenamientoInsercion(int vector[], int tam);

int main()
{
    int pos;
    int buscar;
    int tam;
    int suma = 0;
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
    for (int i = 0; i < tam; i++)
        suma += arreglo[i];
    fstream archivo;
    archivo.open("ordenamiento.txt", ios::out);
    cout << "\nArreglo original: ";
    imprimir(arreglo, tam);
    archivo << "Arreglo original: ";
    for (int i = 0; i < tam; i++)
    {
        archivo << "[" << arreglo[i] << "]";
    };
    archivo << "\n";
    // cout << "\nLa suma de los positivos es: " << sumaPos << "\n";
    // cout << "La suma de los negativos es: " << sumaNeg << "\n";
    cout << "\nArreglo luego del ordenamiento por inseccion: ";
    imprimir(arreglo, tam);
    archivo << "Arreglo ordenado por seleccion: ";
    for (int i = 0; i < tam; i++)
    {
        archivo << "[" << arreglo[i] << "]";
    };
    archivo << "\n";
    // archivo << "Suma de numeros positivos: " << sumaPos << "\n";
    // archivo << "Suma de numeros negativos: " << sumaNeg << "\n";
    archivo << "Suma de todos los elementos: " << suma << "\n";
    archivo.close();
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