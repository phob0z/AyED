#include <iostream>
using namespace std;

int main() {
    string nombre;
    int redes;
    float dist, conectores, t_cable, t_conectores, costo;
    cout << "\t\t*** Empresa Electrocables ***\n\n";
    cout << "\t\t Este es un software contable\n\n";
    cout << "Ingrese el nombre del lugar de la instalación\n";
    cin >> nombre;
    cout << "Ingrese el número de puntos de red que van a ser instalados\n";
    cin >> redes;
    for (int i=0; i<redes; i++) {
        cout << "Punto de red #" << i + 1 << endl;
        cout << "Ingrese la distancia entre el conector del punto de red"\
            " hasta el equipo de conectividad:\n";
        cin >> dist;
        cout << "Ingrese el número de conectores para el punto de red:\n";
        cin >> conectores;
        t_cable += (dist * conectores) * 1.05;
        t_conectores += conectores * 1.15 * 2;
    }
    cout << "\t\tEl detalle de la instalación es la siguiente\n\n";
    printf("La distancia total del cable utilizado en la instalación es: "\
        "%.2f\n", t_cable);
    printf("El costo del cable según la categoría 5e es: %.2f\n", t_cable\
        * 0.9); //En el cálculo del pdf del deber hay un error porque no toma
                //en cuenta el 5% extra de cable para los cálculos de precio
    printf("El precio total de los conectores RJ45 (hembra y macho) es: "\
        "%.2f\n", t_conectores * 0.5);
    costo = (t_cable * 0.9) + (t_conectores * 0.5);
    printf("El total del material utilizado es: %.2f\n", costo);
    printf("La ganancia total es: %.2f\n", costo * 0.45);
    printf("El total a pagar por su instalación es: %.2f\n", costo * 1.45);
}