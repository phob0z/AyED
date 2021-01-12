#include <iostream>
using namespace std;

void invertir(int);

int main() {
    int num;
    cout << "Ingrese el número que desea invertir:\n> ";
    cin >> num;
    cout << "El número original es " << num << ", invertido ";
    invertir(num);
    cout << endl;
    return 0;
}

void invertir(int num) {
    cout << num%10;
    if(num >= 10)
        invertir(num/10);
}