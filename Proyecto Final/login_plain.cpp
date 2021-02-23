#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream archivo;
    string nombre, nombre1;
    string pass, pass1;
    bool correcto = false;
    int numlineas = 0;

    // Registro
    cout << "Ingrese el nombre a registrar:\n";
    getline(cin, nombre);
    cout << "Ingrese el password a registrar:\n";
    getline(cin, pass);

    // Escritura
    archivo.clear();
    archivo.open("login.txt", ios::out | ios::app);
    archivo << nombre << "\n"
            << pass << "\n";
    archivo.close();

    // Lectura de datos
    cout << "Ingrese el nombre:\n";
    getline(cin, nombre);
    cout << "Ingrese el password:\n";
    getline(cin, pass);

    // Lectura y comprobacion de datos con los guardados
    archivo.clear();
    archivo.open("login.txt", ios::in);
    if (archivo.fail())
    {
        cout << "No se puede abrir el archivo login.txt";
    }
    else
    {
        while (!archivo.eof())
        {
            getline(archivo, nombre1);
            getline(archivo, pass1);
            numlineas++;
            if (nombre == nombre1 && pass == pass1)
            {
                cout << "Correcto!\n";
                correcto = true;
                break;
            }
        }
        archivo.close();
        if (correcto == false)
            cout << "Incorrecto!\n";
        if (numlineas == 0)
            cout << "El archivo esta vacio\n";
    }
    archivo.close();
}