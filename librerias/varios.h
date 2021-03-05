#include <iostream>
using namespace std;

int menu(string vector[], int tam);
int leerEntero(string oracion, bool positivo);
int leerEntero(string oracion);
void importante(string cadena);
string fixtabs(string palabra, int max);
string fixespacios(string palabra, int max);

int menu(string opciones[], int tam)
{
    int opc, pos, except = 0;
    pos = opciones[0].find_first_of("áéíóúñÁÉÍÓÚÑ");
    while (pos != std::string::npos)
    {
        except++;
        pos = opciones[0].find_first_of("áéíóúñÁÉÍÓÚÑ", pos + 1);
    }
    except /= 2;
    cout << "\n"
         << opciones[0] << "\n";
    for (int i = 0; i < opciones[0].length() - except; i++)
        cout << "-";
    cout << "\n";
    for (int i = 1; i < tam - 1; i++)
        cout << i << ". " << opciones[i] << "\n";
    cout << "0. " << opciones[tam - 1];
    cout << "\n> ";
    cin >> opc;
    if (cin.fail() || cin.get() != '\n')
    {
        cin.clear();
        while (cin.get() != '\n')
            ;
        opc = -1;
    }
    return opc;
};

int leerEntero(string oracion, bool positivo) {
    int entero;
    while (true)
    {
        cout << oracion;
        cin >> entero;
        if (cin.fail() || cin.get() != '\n')
        {
            cin.clear();
            while (cin.get() != '\n')
                ;
            cout << "Error, debe ser un número entero\n";
        }
        else if (positivo && entero < 0)
            cout << "Error, debe ser un número entero positivo\n";
        else
            break;
    };
    return entero;
}

int leerEntero(string oracion) {
    int entero;
    while (true)
    {
        cout << oracion;
        cin >> entero;
        if (cin.fail() || cin.get() != '\n')
        {
            cin.clear();
            while (cin.get() != '\n')
                ;
            cout << "Error, debe ser un número entero\n";
        }
        else
            break;
    };
    return entero;
}

void imprimirVector(int vector[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        cout << "[" << vector[i] << "]";
    }
    cout << "\n";
}

void importante(string cadena)
{
    int except = 0, pos;
    pos = cadena.find_first_of("áéíóúñÁÉÍÓÚÑ");
    while (pos != std::string::npos)
    {
        except++;
        pos = cadena.find_first_of("áéíóúñÁÉÍÓÚÑ", pos + 1);
    }
    except /= 2;
    cadena = "  *** " + cadena + " ***  ";
    cout << "\n╔";
    for (int i = 0; i < cadena.length() - except; i++)
        cout << "═";
    cout << "╗\n║" << cadena << "║\n╚";
    for (int i = 0; i < cadena.length() - except; i++)
        cout << "═";
    cout << "╝\n";
};

string fixtabs(string palabra, int max)
{
    max *= 8;
    string espacios = "";
    if (max > palabra.length())
    {
        int tabs = ((max - palabra.length() + 7) / 8);
        for (int i=0; i<tabs; i++)
            espacios += "\t";
    }
    return (palabra+espacios);
}

string fixespacios(string palabra, int max)
{
    string espacios;
    espacios = palabra;
    int tamesp = 0;
    if (palabra.length() <= max - 2)
        tamesp = max - palabra.length() - 2;
    for (int i = 0; i < tamesp; i++)
        espacios += " ";
    if (palabra.length() <= max - 2)
        espacios += "\t";
    return espacios;
}