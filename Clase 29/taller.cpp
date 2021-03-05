#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int menu();
void ejercicio1();
void ejercicio2();
void ejercicio3();
void ingresar(int vector[], int tam);
void imprimir(int vector[], int tam);
void ordenamientoMergesort(int vector[], int pinicial, int pfinal);
void merge(int vector[], int pinicial, int pfinal, int medio);
void busquedaLineal(int arreglo[], int tam, int buscar);

int main()
{
    bool salir = false;
    while (!salir)
    {
        switch (menu())
        {
        case 0:
            cout << "Saliendo...\n";
            salir = true;
            break;
        case 1:
            ejercicio1();
            break;
        case 2:
            ejercicio2();
            break;
        case 3:
            ejercicio3();
            break;
        default:
            cout << "\nOpción inválida\n";
            break;
        };
    };

    return 0;
}

void ejercicio1()
{
    ofstream archivo;
    archivo.open("ejercicio1.txt", ios::app);
    int num;
    srand(time(0));
    cout << "\nIngrese el número de elementos a imprimir: ";
    cin >> num;
    int numeros[num];
    cout << endl;
    archivo << "------------------------------------------------------------" << endl;
    archivo << "\nNúmero de elementos del vector: " << num << endl;
    int mayor = 0, menor, i, contMayor = 0, contMenor = 0;
    for (i = 0; i < num; i++)
    {
        numeros[i] = rand() % 100;
        numeros[i] = 1 + rand() % (99 - 1);
        if (mayor < numeros[i])
        {
            mayor = numeros[i];
        }
    }
    menor = mayor;
    for (i = 0; i < num; i++)
    {
        if (menor > numeros[i])
        {
            menor = numeros[i];
        }
    }
    archivo << "\nVECTOR: ";
    cout << "\nVECTOR: ";
    for (i = 0; i < num; i++)
    {
        archivo << "[" << numeros[i] << "]";
        cout << "[" << numeros[i] << "]";

        if (numeros[i] == mayor)
        {
            contMayor++;
        }
        else if (numeros[i] == menor)
        {
            contMenor++;
        }
    }
    archivo << endl;
    cout << endl;
    cout << "\nEl número mayor es: " << mayor << endl;
    cout << "El número menor es: " << menor << endl;
    cout << "\nEl número mayor se repite " << contMayor << " veces." << endl;
    cout << "El número menor se repite " << contMenor << " veces." << endl;

    archivo << "\nEl número mayor es: " << mayor << endl;
    archivo << "El número menor es: " << menor << endl;
    archivo << "\nEl número mayor se repite " << contMayor << " veces." << endl;
    archivo << "El número menor se repite " << contMenor << " veces." << endl;
    archivo << "------------------------------------------------------------" << endl;
    archivo.close();
}

void ejercicio2()
{
    int tam;
    int buscar;
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
    archivo.open("ejercicio2.txt", ios::out);
    cout << "\nArreglo original: ";
    imprimir(arreglo, tam);
    archivo << "Arreglo original: ";
    for (int i = 0; i < tam; i++)
    {
        archivo << "[" << arreglo[i] << "]";
    };
    archivo << "\n";
    ordenamientoMergesort(arreglo, 0, tam - 1);
    cout << "\nArreglo luego del ordenamiento por Mergesort: ";
    imprimir(arreglo, tam);
    archivo << "Arreglo ordenado por Mergesort: ";
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
    busquedaLineal(arreglo, tam, buscar);
}

void ejercicio3() {
    string nombre, ciudad, codigo, estado;
    int telefono, precio, cantidad, c_total = 0, p_total = 0;
    fstream archivo;
    archivo.open("productos.txt", ios::out);
    archivo << "******* DATOS DEL PROVEEDOR *******\n";
    archivo << "Código\tNombre\tCiudad\tTeléfono\n";
    archivo.close();
    archivo.open("productos.txt", ios::out | ios::app);
    do
    {
        cout << "Ingrese el codigo del provedor (* para continuar): ";
        cin >> codigo;
        if (codigo != "*")
        {
            cout << "Ingrese el nombre del provedor: ";
            cin >> nombre;
            cout << "Ingrese la ciudad: ";
            cin >> ciudad;
            cout << "Ingrese su telefono: ";
            cin >> telefono;
            archivo << codigo << "\t" << nombre << "\t" << ciudad << "\t" << telefono << "\n";
        }
    } while (codigo != "*");
    archivo << "\n\n******* DATOS DEL PRODUCTO *******\n";
    archivo << "Nombre\tPrecio\tCantidad\tEstado\n";
    do
    {
        cout << "Ingrese el nombre del producto (* para continuar): ";
        cin >> nombre;
        if (nombre != "*")
        {
            cout << "Ingrese el precio del producto: ";
            cin >> precio;
            cout << "Ingrese la cantidad de productos: ";
            cin >> cantidad;
            cout << "Ingrese el estado del producto: ";
            cin >> estado;
            archivo << nombre << "\t" << precio << "\t" << cantidad << "\t\t" << estado << "\n";
            c_total += cantidad;
            p_total += precio;
        }
    } while (nombre != "*");
    archivo << "\n\nEl precio total de productos:\t\t$" << p_total << "\n";
    archivo << "Cantidad de productos ingresados:\t" << c_total << "\n";
    archivo << "El valor total:\t\t\t\t$" << p_total*c_total << "\n";
    archivo.close();
    archivo.open("productos.txt", ios::in);
    if (archivo.fail())
    {
        cout << "No se pudo leer el archivo\n";
    }
    else
    {
        while (!archivo.eof())
        {
            getline(archivo, nombre);
            cout << nombre << "\n";
        }
        archivo.close();
    }
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

void busquedaLineal(int arreglo[], int tam, int buscar)
{
    fstream archivo;
    archivo.open("ejercicio2.txt", ios::out | ios::app);
    int encontrado = -1;
    for (int i = 0; i < tam; i++)
        if (arreglo[i] == buscar)
            encontrado = i;
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

void ordenamientoMergesort(int vector[], int pinicial, int pfinal)
{
    int mitad;
    if (pinicial < pfinal)
    {
        mitad = (pinicial + pfinal) / 2;
        ordenamientoMergesort(vector, pinicial, mitad);
        ordenamientoMergesort(vector, mitad + 1, pfinal);
        merge(vector, pinicial, pfinal, mitad);
    }
}

void merge(int vector[], int pinicial, int pfinal, int medio)
{
    int i, j, k, temp[pfinal - pinicial + 1];
    i = pinicial;
    k = 0;
    j = medio + 1;
    while (i <= medio && j <= pfinal)
    {
        if (vector[i] < vector[j])
        {
            temp[k] = vector[i];
            i++;
        }
        else
        {
            temp[k] = vector[j];
            j++;
        }
        k++;
    }
    while (i <= medio)
    {
        temp[k] = vector[i];
        k++;
        i++;
    }
    while (j <= pfinal)
    {
        temp[k] = vector[j];
        k++;
        j++;
    }
    for (i = pinicial; i <= pfinal; i++)
    {
        vector[i] = temp[i - pinicial];
    }
}

int menu()
{
    int opc;
    cout << "\nOpciones:\n";
    cout << "1. Mayor y menor números\n";
    cout << "2. Mergesort\n";
    cout << "3. SuperMaxi\n";
    cout << "0. Salir\n";
    cout << "> ";
    cin >> opc;
    if (cin.fail() || cin.get() != '\n')
    {
        cin.clear();
        while (cin.get() != '\n')
            ;
        opc = -1;
    }
    return opc;
};