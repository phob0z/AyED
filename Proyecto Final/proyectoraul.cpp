/*
PROGRAMA DESARROLLADO POR:
> Raúl Tenorio
> Leonel Molina
> Manuel Auqui
> Jimy Calvo
> Jhael Nicolalde
*/
#include <iostream>
#include <fstream>
using namespace std;

void menu();
void busquedaBinaria(int arreglo[], int tam, int buscar);
void busquedaInterpolacion(int arreglo[], int tam, int buscar);
void ordenamientoBurbuja(int arreglo[], int tam);
void ordenamientoInsercion(int arreglo[], int tam);
int bugFixer(int op);

int main()
{
    fstream archivo;
    string usuarioLogin, passwordLogin, confirmarPassword;
    string usuario, password, nombre, apellido, telf;
    bool correcto = false;
    int numlineas = 0;
    int op;
    do
    {
        cout << "\n\t\t[SISTEMA]\n"
             << endl;
        cout << "1. Ingresar" << endl;
        cout << "2. Registrarse" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese la opción:\n► ";
        cin >> op;
        bugFixer(op);
        switch (op)
        {
        case 1:
        {
            cout << "\n\t[INGRESO]" << endl;
            cout << "Usuario:\n> ";
            getline(cin, usuarioLogin);
            cout << "Contraseña:\n> ";
            getline(cin, passwordLogin);
            archivo.clear();
            archivo.open("login.txt", ios::in);
            if (archivo.fail())
            {
                cout << "\nNO SE HA REGISTRADO NINGÚN USUARIO\n";
            }
            else
            {
                while (!archivo.eof())
                {
                    getline(archivo, usuario);
                    getline(archivo, password);
                    numlineas++;
                    if (usuario == usuarioLogin && password == passwordLogin)
                    {
                        correcto = true;
                        break;
                    }
                }
                archivo.close();
                if (correcto == false)
                    cout << "\nUsuario y/o contraseña incorrecto.\n";
                else
                    menu();
                if (numlineas == 0)
                    cout << "\nARCHIVO VACIO!\n";
            }
            archivo.close();
        }
        break;
        case 2:
        {
            cout << "\n\t[REGISTRO]" << endl;
            cout << "Nombre:\n> ";
            cin >> nombre;
            cout << "Apellido:\n> ";
            cin >> apellido;
            cout << "Número de teléfono:\n> ";
            cin >> telf;
            cout << "Usuario:\n> ";
            cin >> usuario;
            cout << "Contraseña:\n> ";
            cin >> password;
            cout << "Confirmar contraseña:\n> ";
            cin >> confirmarPassword;
            if (password != confirmarPassword)
            {
                do
                {
                    cout << "\nConfirmación incorrecta!" << endl;
                    cout << "Vuelva a ingresar su contraseña: ";
                    cin >> confirmarPassword;
                } while (password != confirmarPassword);
            }
            cout << "\n\tUSUARIO REGISTRADO!" << endl;
            // Escritura
            archivo.clear();
            archivo.open("login.txt", ios::out);
            archivo << usuario << "\n"
                    << password << "\n";
            archivo.close();
            // Registro
            archivo.clear();
            archivo.open("datosUsuario.txt", ios::out);
            archivo << "NOMBRE: " << nombre << " " << apellido << endl;
            archivo << "TELÉFONO: " << telf << endl;
            archivo << "USUARIO: " << usuario << endl;
            archivo << "CONTRASEÑA: " << password << endl;
            archivo.close();
        }
        break;
        case 3:
        {
            cout << "\nSaliendo..." << endl;
        }
        break;
        default:
            cout << "\nEsta opción no existe!\nPor favor, vuelva a ingresar." << endl;
            break;
        }
    } while (op != 3);
}

void menu()
{
    int op;
    do
    {
        cout << "\n\t\t  [BIENVENIDO]" << endl;
        cout << "\n\tGESTIÓN DE CALIFICACIONES\n"
             << endl;
        cout << "1. Ingresar datos del docente" << endl;
        cout << "2. Ingresar materia" << endl;
        cout << "3. Ingresar el número de estudiantes y rango de notas" << endl;
        cout << "4. Ingresar notas por estudiante" << endl;
        cout << "5. Ver reporte de calificaciones" << endl;
        cout << "6. Ordenar calificaciones" << endl;
        cout << "7. Ver calificaciones ordenadas" << endl;
        cout << "8. Buscar calificación" << endl;
        cout << "9. Salir\n> ";
        cin >> op;
        bugFixer(op);
        switch (op)
        {
        case 1:
        {
        }
        break;
        case 2:
        {
        }
        break;
        case 3:
        {
        }
        break;
        case 4:
        {
        }
        break;
        case 5:
        {
        }
        break;
        case 6:
        {
        }
        break;
        case 7:
        {
        }
        break;
        case 8:
        {
        }
        break;
        case 9:
        {
            cout << "\nHASTA PRONTO!" << endl;
        }
        break;
        default:
            cout << "\nEsta opción no existe!\nPor favor, vuelva a ingresar." << endl;
            break;
        }
    } while (op != 9);
}

void busquedaBinaria(int arreglo[], int tam, int buscar)
{
    int ini = 0;
    int fin = tam - 1;
    int mitad;
    int pos = -1;
    while (ini <= fin)
    {
        mitad = (ini + fin) / 2;
        if (arreglo[mitad] == buscar)
        {
            pos = mitad;
            break;
        }
        else if (arreglo[mitad] < buscar)
            ini = mitad + 1;
        else
            fin = mitad - 1;
    }
    if (pos != -1)
        cout << "Se encontró " << buscar << " en la posición " << pos + 1 << " del arreglo\n";
    else
        cout << "No se escontró el elemento en el arreglo\n";
}

void busquedaInterpolacion(int arreglo[], int tam, int buscar)
{
    int bajo = 0;
    int alto = tam - 1;
    int interp;
    int encontrado;
    int loop = 0;
    while ((arreglo[alto] != arreglo[bajo]) && (buscar >= arreglo[bajo]) && (buscar <= arreglo[alto]))
    {
        interp = bajo + ((buscar - arreglo[bajo]) * (alto - bajo) / (arreglo[alto] - arreglo[bajo]));
        if (arreglo[interp] < buscar)
        {
            bajo = interp + 1;
        }
        else
        {
            if (arreglo[interp] > buscar)
            {
                alto = interp - 1;
            }
            else
            {
                encontrado = interp;
                break;
            }
        }
        loop++;
    }
    if (buscar == arreglo[bajo])
        encontrado = bajo;
    if (encontrado != -1)
    {
        cout << "Se encontró " << buscar << " en la posición " << encontrado + 1 << " del arreglo\n";
        cout << "Se necesitaron " << loop << " iteraciones para encontrarlo\n";
    }
    else
    {
        cout << "No se escontró el elemento en el arreglo\n";
    }
}

void ordenamientoBurbuja(int arreglo[], int tam)
{
    int aux;
    for (int i = 0; i < tam; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            if (arreglo[j] < arreglo[i])
            {
                aux = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = aux;
            }
        }
    }
}

void ordenamientoInsercion(int arreglo[], int tam)
{
    int pos, aux;
    for (int i = 0; i < tam; i++)
    {
        pos = i;
        aux = arreglo[i];
        while (pos > 0 && arreglo[pos - 1] > aux)
        {
            arreglo[pos] = arreglo[pos - 1];
            pos--;
        }
        arreglo[pos] = aux;
    }
}

int bugFixer(int op)
{
    if (cin.fail() || cin.get() != '\n')
    {
        cin.clear();
        while (cin.get() != '\n')
            ;
        op = -1;
    }
    return op;
}
