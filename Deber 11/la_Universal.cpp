#include <iostream>
using namespace std;

int main() {
    int total_h = 0, horas;
    string dia = "";
    cout << "Registro del pasante\n";
    for(int i=1; i<=5; i++) {
        switch(i) {
            case 1:
                dia = "Lunes";
                break;
            case 2:
                dia = "Martes";
                break;
            case 3:
                dia = "Miercoles";
                break;
            case 4:
                dia = "Jueves";
                break;
            case 5:
                dia = "Viernes";
                break;
            default:
                dia = "Error en el día";
                break;
        }
        cout << "¿Cuantas horas trabajo el día " << dia << "?\n";
        cin >> horas;
        total_h += horas;
    }
    cout << "El pasante trabajó " << total_h << " horas esta semana\n";
	cout << "Debe recibir $" << total_h * 6.75 << " por su trabajo\n";
    return 0;
}