/*
*	Programa de ejemplo de uso de las particiones y mezcla de archivos
*
*
*
*
*/
#include <util_arch_carros.h>

int main() {
	int sw1 = 1, sw2, tam;
	unsigned long n;
	Cadena aux; 
	char arch[20], n_arch1[20], n_arch2[20], n_arch3[20], n_arch4[20];
	CCarro carro1;

	cout << "Nombre del archivo: ";
	cin >> arch;

while (sw1) {
		cout << "\nFunciones Disponibles:\n";
		cout << "\tAgregar .....................1\n";
		cout << "\tMostrar .....................2\n";
		cout << "\tElimina .....................3\n";
		cout << "\tCrear aleatorio .............4\n";
		cout << "\tBuscar ......................5\n";
		cout << "\tMezcla  .....................6\n";
		cout << "\tParticion simple 1 ..........7\n";
		cout << "\tParticion simple 2 ..........8\n";
		cout << "\tParticion por grupos ........9\n";
		cout << "\tParticion por seleccion.....10\n";
		cout << "\tFin ......................OTRO\n";
		cout << "Opcion:";
		cin >> sw2;
		switch(sw2) {
		case 1:
			cout << "Datos del Carro (placa:modelo:precio) :";
			cin >> carro1;
			agregar(arch, carro1);
			break;

		case 2:
			cout << "Archivo a mostrar:";
			cin >> arch;
			if ( !mostrar(arch) )
				cout << "Archivo: " << arch << " no existe" <<endl;
			break;

		case 3:
			cout << "Placa del carro a Eliminar:";
			cin >> aux;
			eliminar(arch,aux); 
			break;

		case 4:
			cout << "Cuantos datos a crear: ";
			cin >> n;
			cout << "Nombre del nuevo archivo:";
			cin >> n_arch2;
			crear(n_arch2, n);
			break;

		case 5:
			cout << "Placa a buscar :";
			cin >> aux;
			carro1.asignar(aux.getch(),"",0.0);
			if ( buscar(arch, carro1) ) {
				cout << "Modelo: " << carro1.obtener_modelo() << '\n';
				cout << "Precio: ";
				cout.setf(ios::fixed, ios::floatfield);
				cout << setprecision(2);
				cout << carro1.obtener_precio() << "Bs." << endl;
			} else
				cout << "No encontrado !! " << endl;
			break;
		case 6:
			cout << "Archivo 1 a mezclar: ";
			cin >> n_arch1;
			cout << "Archivo 2 a mezclar: ";
			cin >> n_arch2;
			cout << "Archivo mezcla: ";
			cin >> n_arch3;
			if ( ! mezcla(n_arch1, n_arch2, n_arch3) ) {
				cerr << "Error al abrir los Archivos" << endl;
			} else {
				cout << "O.K." << endl;
			}
			break;

		case 7:
			cout << "Archivo fuente: ";
			cin >> n_arch1;
			cout << "Archivo destino 1: ";
			cin >> n_arch2;
			cout << "Archivo destino 2: ";
			cin >> n_arch3;
			cout << "Archivo destino 3: ";
			cin >> n_arch4;

			if (  partir_en_tres1(n_arch1, n_arch2, n_arch3, n_arch4) ) {
				cerr << "Error al abrir los Archivos" << endl;
			} else {
				cout << "O.K." << endl;
			}
			break;
		case 8:
			cout << "Archivo fuente: ";
			cin >> n_arch1;
			cout << "Archivo destino 1: ";
			cin >> n_arch2;
			cout << "Archivo destino 2: ";
			cin >> n_arch3;
			cout << "Archivo destino 3: ";
			cin >> n_arch4;

			if (  partir_en_tres2(n_arch1, n_arch2, n_arch3, n_arch4) ) {
				cerr << "Error al abrir los Archivos" << endl;
			} else {
				cout << "O.K." << endl;
			}
			break;

		case 9:
			cout << "Archivo fuente: ";
			cin >> n_arch1;
			cout << "Archivo destino 1: ";
			cin >> n_arch2;
			cout << "Archivo destino 2: ";
			cin >> n_arch3;
			cout << "Archivo destino 3: ";
			cin >> n_arch4;
			cout << "Tamaño del grupo:";
			cin >> tam;

			if (  partir_por_grupo(n_arch1, tam, n_arch2, n_arch3, n_arch4) ) {
				cerr << "Error al abrir los Archivos" << endl;
			} else {
				cout << "O.K." << endl;
			}
			break;

		case 10:
			cout << "Archivo fuente: ";
			cin >> n_arch1;
			cout << "Archivo destino 1: ";
			cin >> n_arch2;
			cout << "Archivo destino 2: ";
			cin >> n_arch3;
			cout << "Archivo destino 3: ";
			cin >> n_arch4;

			if (  partir_por_precio(n_arch1, n_arch2, n_arch3, n_arch4) ) {
				cerr << "Error al abrir los Archivos" << endl;
			} else {
				cout << "O.K." << endl;
			}
			break;

		default:
			sw1 = 0;
		}
		
	}
}

