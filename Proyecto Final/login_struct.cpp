#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream archivo;
    string dato;
    typedef struct login {
        string nombre;
        string pass;
    } login;

    login usuario, usuario2;
    cout << "Ingrese el nombre:\n";
    getline(cin, usuario.nombre);
    cout << "Ingrese el password:\n";
    getline(cin, usuario.pass);

    // Escritura
    archivo.clear();
    archivo.open("login.txt", ios::out | ios::binary);
    archivo.write(reinterpret_cast<char*>(&usuario),sizeof(login));
    archivo.close();

    // Lectura
    archivo.clear();
    archivo.open("login.txt", ios::in | ios::binary);
    archivo.read(reinterpret_cast<char*>(&usuario2),sizeof(login));
    archivo.close();

    cout << "Usuario2 nombre: " << usuario2.nombre << "\n";
    cout << "Usuario2 pass: " << usuario2.pass << "\n";
}