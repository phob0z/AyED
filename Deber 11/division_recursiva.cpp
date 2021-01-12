#include <iostream>
using namespace std;

int division(int a, int b) {
    if (a < b)
        return 0;
    else {
        if (a == b)
            return 1;
        else
            return 1 + division(a-b, b);
    }
};

int main() {
    int num1, num2;
    cout << "Introduzca el dividendo\n";
    cin >> num1;
    cout << "Introduzca el divisor\n";
    cin >> num2;
    if (num1 < num2)
        cout << "El dividendo debería ser mayor que el divisor\n";
    cout << "El cociente de " << num1 << "/" << num2 << " es " <<\
        division(num1, num2);
    return 0;
}