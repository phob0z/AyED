#include <iostream>
using namespace std;

int main() {
    string integrantes[5] = {"Manuel Auqui", "Jhael Nicolalde","Jimy Calvo",
        "Raúl Tenorio","Leonel Molina"};
    cout << "Integrantes: " << integrantes[0] << ", " << integrantes[1]
         << ", " << integrantes[2] << ", " << integrantes[3] << ", "
         << integrantes[4] << "." << endl;
    char letra = 'a';
    cout << "Caracter: " << letra << endl;
    int entero = 1;
    cout << "Entero: " << entero << endl;
    float decimal = 1.1;
    cout << "Decimal: " << decimal << endl;
    string cadena = "Esto es una cadena de texto";
    cout << "Cadena: " << cadena << endl;
    bool booleano = true;
    cout << "Booleano: " << (booleano? "True": "False") << endl;
    string unidimensional[3] = {"0","1","2"};
    cout << "El número en la posición unidimensional[1] es: "
         << unidimensional[1] << endl;
    string bidimensional[3][3] = {{"0","1","2"},{"3","4","5"},{"6","7","8"}};
    cout << "El número en la posición bidimensional[1][1] es: "
         << bidimensional[1][1] << endl;
}