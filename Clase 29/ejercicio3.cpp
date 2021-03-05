#include <iostream>
#include <fstream>
// #include <cstring>
using namespace std;

int main(void)
{
    string nombre, ciudad, codigo, estado;
    int telefono, precio, cantidad;
    fstream archivo;
    archivo.open("productos.txt", ios::out | ios::app);
    archivo << "***** DATOS DEL PROVEEDOR	*******\n";
    archivo << "Código\tNombre\tCiudad\tTeléfono\n";
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
        // cin.ignore();
    } while (codigo != "*");
    archivo << "\n***** DATOS DEL PRODUCTO	*******\n";
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
        }
        // cin.ignore();
    } while (nombre != "*");
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
        return 0;
    }
}