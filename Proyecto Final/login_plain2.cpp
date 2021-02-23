#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream archivo;
    string linea, nombre, nombre1, pass, pass1, telefono, ciudad, ocupacion;
    int startPass;
    bool correcto = false;
    int numlineas = 0;
    
    // Registro
    cout << "Ingrese el nombre a registrar: ";
    getline(cin, nombre);
    cout << "Ingrese el password a registrar: ";
    getline(cin, pass);
    cout << "¿Cual es su telefono? ";
    getline(cin, telefono);
    cout << "¿En que ciudad vive? ";
    getline(cin, ciudad);
    cout << "¿Cual es su ocupacion? ";
    getline(cin, ocupacion);
    cout << "\n";
    // Escritura
    archivo.clear();
    archivo.open("login.txt", ios::out | ios::app);
    archivo << "NOMBRE:" << nombre << "#CONTRASENA:" << pass
            << "#" << telefono << "#" << ciudad << "#" << ocupacion << "\n";
    archivo.close();

    // Lectura de datos
    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Password: ";
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
            getline(archivo, linea);
            if (linea != "")
            {
                nombre1 = linea.substr(7, linea.find("CONTRASENA:") - 7);
                cout << "\tnombre: " << nombre1 << "\n";
                linea = linea.substr(linea.find("CONTRASENA:") + 11);
                pass1 = linea.substr(0, linea.find("#"));
                cout << "\tpassword: " << pass1 << "\n";
                linea = linea.substr(linea.find("#") + 1);
                telefono = linea.substr(0, linea.find("#"));
                cout << "\ttelefono: " << telefono << "\n";
                linea = linea.substr(linea.find("#") + 1);
                ciudad = linea.substr(0, linea.find("#"));
                cout << "\tciudad: " << ciudad << "\n";
                linea = linea.substr(linea.find("#") + 1);
                ocupacion = linea.substr(0, linea.find("#"));
                cout << "\tocupacion: " << ocupacion << "\n";
                numlineas++;
                if (nombre == nombre1 && pass == pass1)
                {
                    cout << "Correcto!\n";
                    correcto = true;
                    break;
                }
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