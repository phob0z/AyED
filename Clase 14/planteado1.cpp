#include <iostream>
using namespace std;

// Definición de variables
float t_peso = 0;
int t_animales = 0;

// Prototipo de funciones
void ingresar(string tipo);
void imprimir();

// Función principal, menú y llamado de función dependiendo de la opción
int main() {
    int salir = 0;
    char opc;
    do {
        cout << "\n\nMENÚ\n";
        cout << "a) Mamíferos\n";
        cout << "b) Reptiles\n";
        cout << "c) Aves\n";
        cout << "d) Número de animales y peso total\n";
        cout << "e) Salir\n";
        cin >> opc;
        switch(opc) {
            case 'a':
                ingresar("mamíferos");
                break;
            case 'b':
                ingresar("reptíles");
                break;
            case 'c':
                ingresar("aves");
                break;
            case 'd':
                imprimir();
                break;
            case 'e':
                cout << "Saliendo...\n";
                salir = 1;
                break;
            default:
                cout << "Opción invalida...\n";
                break;
        };
    } while(salir == 0);
    return 0;
}

// Dependiendo de tipo que recibe imprime y pregunta cuantos de ese tipo,
// el nombre, la cantidad de esos y el peso de ellos.
void ingresar(string tipo) {
    int c_tipo, c_animal;
    float p_animal;
    string n_animal;
    cout << "\n¿Cuant@s " << tipo << " ingresarán?\n" ;
    cin >> c_tipo;
    for(int i=0; i<c_tipo; i++) {
        cout << "#" << i + 1 << " ¿De que animal se trata?\n";
        cin >> n_animal;
        cout << "¿Cuantos " << n_animal << "s ingresarán?\n";
        cin >> c_animal;
        cout << "¿Cual es el peso de cada " << n_animal << " en Kg?\n";
        cin >> p_animal;
        t_peso += c_animal * p_animal;
        t_animales += c_animal;
    }
};

// Imprime el total de animale y el peso total.
void imprimir() {
    cout << "\nTotal de animales:\t\t" << t_animales << endl;
    cout << "Peso total:\t\t\t\t"<< t_peso << " Kg\n";
};