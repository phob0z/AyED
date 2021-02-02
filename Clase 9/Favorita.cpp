#include <iostream>
using namespace std;

int main() {
    int sum_par = 0, sum_impar = 0, n_cam;
    cout << "¿Cuantos camiones va a ingresar?\n";
    cin >> n_cam;
    int camiones[n_cam][2];
    for (int i=0; i<n_cam; i++) {
        cout << "Ingrese el rango del camión #" << i + 1 << endl;
        cin >> camiones[i][0];
        cout << "Ingrese el identificador del camión #" << i + 1 << endl;
        cin >> camiones[i][1];
    }
    cout << "\n--------------------\n";
    for (int i=0; i<n_cam; i++)
        if (camiones[i][1] % 2 == 0)
            sum_par++;
        else
            sum_impar++;
    cout << sum_par << " camiones van Sur\n";
    cout << sum_impar << " camiones van Norte\n";
}