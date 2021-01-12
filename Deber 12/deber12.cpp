#include <iostream>
using namespace std;

int ahorro_mes[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const string mes[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo",\
        "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre",\
        "Diciembre"};
const float tabla_sueldos[3] = {0.1, 0.2, 0.5};
bool salir;

int menu();

int menu_ahorros();

int potencia(int, int);

void script_potencia();

void script_ahorros();

void script_mcdonalds();

void script_bunky();

int main() {
    bool salir = false;
    while (!salir) {
        switch(menu()) {
            case 0:
                cout << "Saliendo...\n";
                salir = true;
                break;
            case 1:
                script_ahorros();
                break;
            case 2:
                script_potencia();
                break;
            case 3:
                script_mcdonalds();
                break;
            case 4:
                script_bunky();
                break;
            default:
                cout << "Opción invalida...\n";
                break;
        };
    };
    return 0;
};

int menu() {
    int opc;
    cout << "\nMenú de opciones:\n";
    cout << "----------------\n";
    cout << "1. Ahorros de Juanito\n";
    cout << "2. Potenciación\n";
    cout << "3. Mc Donald's - Ecuador\n";
    cout << "4. Calzados BUNKY\n";
    cout << "0. Salir\n";
    cout << ">  ";
    cin >> opc;
    return opc;
};

int menu_ahorros() {
    int opc;
    cout << "\nAhorros Juanito:\n";
    cout << "---------------\n";
    cout << "1. Depositar dinero\n";
    cout << "2. Consultar dinero\n";
    cout << "0. Salir\n";
    cout << ">  ";
    cin >> opc;
    return opc;
};

int potencia(int base, int exp) {
    return exp == 0? 1: base * potencia(base, exp-1);
};

void script_potencia() {
    cout << "\nPotenciación\n";
    cout << "------------\n";
    int num1, num2;
    cout << "Introduzca la base\n";
    cin >> num1;
    cout << "Introduzca el exponente\n";
    cin >> num2;
    if (num2 < 0)
        cout << "El exponente debe ser mayor que 0\n";
    else
        cout << "El resultado de " << num1 << "^" << num2 << " es " <<\
            potencia(num1, num2) << "\n";
};

void script_ahorros() {
    salir = false;
    int total = 0;
    while (!salir) {
        switch(menu_ahorros()) {
            case 0:
                salir = true;
                break;
            case 1:
                for(int i=0; i<=11; i++) {
                    cout << "Introduzca la cantidad a depositar en "\
                        << mes[i] << endl;
                    cin >> ahorro_mes[i];
                }
                break;
            case 2:
                for(int i=0; i<=11; i++) {
                    cout << "La cantidad depositada en " << mes[i]\
                        << " fue: " << ahorro_mes[i] << endl;
                    total += ahorro_mes[i];
                }
                cout << "El total ahorrado es: " << total << endl;
                break;
            default:
                cout << "Opción invalida...\n";
                break;
        };
    };
};

void script_mcdonalds() {
	float precio[3] = {1.5, 2.5, 3.25};
    float recargo[2] = {1, 1.05};
    int tipo, cantidad, pago;
    string nombre[3] = {"sencilla", "doble", "triple"};
    salir = false;
    cout << "\nMc Donald's:\n";
    cout << "-----------\n";
    while(!salir) {
		cout << "Tenemos 3 tipos de hamburguesas, ¿de que tipo desea comprar?"\
        " (1, 2, 3)\n";
		cin >> tipo;
		switch(tipo) {
            case 1:	case 2:	case 3:
                salir = true;
                break;
			default:
                cout << "Opción invalida...\n";
                break;
		};
	};
	cout << "¿Cuantas hamburguesas " << nombre[tipo-1] << "s desea comprar?\n";
	cin >> cantidad;
    salir = false;
	while(!salir) {
		cout << "¿Como desea pagar efectivo (1), credito (2)?\n";
		cin >> pago;
		switch((pago)) {
			case 1:	case 2:
                salir = true;
                break;
			default:
				cout << "Opción invalida...\n";
                break;
		};
	};
	if(cantidad == 1)
		cout << "El monto a pagar por la hamburguesa " << nombre[tipo-1] <<\
        " es de $" << cantidad * precio[tipo-1] * recargo[pago-1] << endl;
	else
		cout << "El monto a pagar por " << cantidad << " hamburguesas "\
        << nombre[tipo-1] << "s es de $" << cantidad * precio[tipo-1] *\
        recargo[pago-1] << endl;
};

void script_bunky() {
    int categoria;
    float sueldo_old;
    cout << "\nCalzados BUNKY:\n";
    cout << "--------------\n";
    cout << "¿Cual es su sueldo actual?\n> $";
    cin >> sueldo_old;
    salir = false;
	while(!salir) {
		cout << "¿Cual es su categoría? (1,2,3)\n";
        cin >> categoria;
		switch((categoria)) {
			case 1: case 2: case 3:
                salir = true;
                break;
			default:
				cout << "Opción invalida...\n";
                break;
		};
	};
    cout << "\nSu categoría es: " << categoria << endl;
    cout << "Su sueldo anterior era $" << sueldo_old << endl;
    cout << "Su nuevo sueldo con el aumento del " <<\
    tabla_sueldos[categoria-1] * 100 << "% será $" << sueldo_old\
    * (1 + tabla_sueldos[categoria-1]) << endl;
};