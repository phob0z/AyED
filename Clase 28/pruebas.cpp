#include <iostream>
#include "../librerias/ordenamientos.h"
#include "../librerias/busquedas.h"
#include "../librerias/varios.h"

using namespace std;


int main()
{
    int pos;
    float buscar;
    int tam = -1;
    do {
        tam = leerEntero("Ingrese el tamaño del arreglo: ");
        if (tam <=0)
            importante("El número debe ser mayor que 0");
    } while (tam <= 0);
    cout << "\n";
    float arreglo[tam];
    // ingresar(arreglo, tam);
    vectorAleatorio(arreglo, tam, 0, 20);
    cout << "123456789012345678901234567890123\n";
    cout << fixespacios("Leonel", 30) << "|\n";
    cout << fixespacios("Leo", 30) << "|\n";
    cout << fixespacios("Leoñel", 30) << "|\n";
    cout << fixespacios("Léóñel", 30) << "|\n";
    cout << fixespacios("12345678901234567890123456789", 30) << "|\n";
    cout << fixespacios("1234567890123456789012345678", 30) << "|\n";
    cout << fixespacios("123456789012345678901234567890", 30) << "|\n";
    cout << fixespacios("1234567890123456789012345678901", 30) << "|\n";
    cout << fixespacios("1", 30) << "|\n";
    cout << fixespacios("", 30) << "|\n";
    cout << "\nArreglo original: ";
    imprimirVector(arreglo, tam);
    heapSort(arreglo, tam);
    cout << "\nArreglo luego del ordenamiento por heapSort: ";
    imprimirVector(arreglo, tam);
    buscar = leerReal("¿Que número desea buscar? ");
    pos = lineal(arreglo, tam, buscar);
    if (pos != -1)
        cout << "Se encontró " << buscar << " en la posición " << pos << "\n";
    else
        cout << "No se encontró " << buscar << " en el vector\n";
    return 0;
}