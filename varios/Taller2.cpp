#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
    string integrantes[5] = {"Manuel Josué Auqui Sánchez","Jhael Darío Nicolalde Molina",
            "Jimy Bryan Calvo Mullo","Raúl Alejandro Tenorio Mendieta",
            "Leonel Alfonso Molina Troconis"};
    for (int i=0; i<5; i++) {
        cout << integrantes[i] + "\t";
    }
    cout << endl;
    cout << "Integrante en la posición 4: " << integrantes[3] << endl << endl;
    char letra = 'a';
    cout << "Caracter: " << letra << endl << endl;
    int entero = 1;
    cout << "Entero: " << entero << endl << endl;
    float decimal = 1.1;
    cout << "Decimal: " << decimal << endl << endl;
    string cadena = "Esto es una cadena de texto";
    cout << "Cadena: " << cadena << endl << endl;
    bool booleano = true;
    cout << "Booleano: " << (booleano? "True": "False") << endl << endl;
    string unidimensional[3] = {"0","1","2"};
    cout << "Arreglo unidimensional: ";
    for (int i=0; i<3; i++) {
        cout << unidimensional[i] + "\t";
    }
    cout << endl;
    cout << "El número en la posición [1] es: " << unidimensional[1] << endl << endl;

    string bidimensional[3][3] = {{"0","1","2"},{"3","4","5"},{"6","7","8"}};
    cout << "Arreglo bidimensional: " << endl;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cout << bidimensional[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "El número en la posición [1][1] es: " << bidimensional[1][1] << endl;
}