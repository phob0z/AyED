//    Lee los tres lados de un triangulo rectangulo, determina 
// si corresponden (por Pitargoras) y en caso afirmativo 
// calcula el area

#include <iostream>
using namespace std;

int main() {
    float l1, l2, l3, cat1, cat2, hip, area;
    // cargar datos
    cout << "Ingrese el lado 1:\n";
    cin >> l1;
    cout << "Ingrese el lado 2:\n";
    cin >> l2;
    cout << "Ingrese el lado 3:\n";
    cin >> l3;
    // encontrar la hipotenusa (mayor lado)
    if(l1 > l2) {
        cat1 = l2;
        if(l1 > l3) {
            hip = l1;
            cat2 = l3;
        } else {
            hip = l3;
            cat2 = l1;
        }
    } else {
        cat1 = l1;
        if(l2 > l3) {
            hip = l2;
            cat2 = l3;
        } else {
            hip = l3;
            cat2 = l2;
        }
    }
    // ver si cumple con Pitagoras
    if(hip*hip == cat1*cat1 + cat2*cat2) {
        // calcualar area
        area = (cat1*cat2)/2;
        cout << "El area es: " << area << endl;
    } else
        cout << "No es un triangulo rectangulo.\n";
}