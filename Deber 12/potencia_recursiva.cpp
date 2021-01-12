#include <iostream>
using namespace std;

int potencia(int base, int exp) {
    if (exp == 0)
        return 1;
    else
        return base * potencia(base, exp-1);
};

int main() {
    int num1, num2;
    cout << "Introduzca la base\n";
    cin >> num1;
    cout << "Introduzca el exponente\n";
    cin >> num2;
    if (num2 < 0)
        cout << "El exponente debe ser mayor que 0\n";
    else
        cout << "El resultado de " << num1 << "^" << num2 << " es " <<\
            potencia(num1, num2);
    return 0;
}