#include <iostream>
#include <fstream>

using namespace std;

bool salir = false;
// El primer string es para el titulo, el ultimo es para la opcion de salir/volver
// Ejemplo string menu[] = {"titulo", "opcion1", "opcion2", "salir"}
string menu_ppl[] = {"[GESTIÓN DE CALIFICACIONES]", "Ingresar datos del docente",
                     "Ingresar materia", "Ingresar el número de estudiantes y rango de notas",
                     "Ingresar notas por estudiante", "Ver reporte de calificaciones",
                     "Ordenar calificaciones", "Ver calificaciones ordenadas", "Buscar calificación",
                     "Ver registro de búsquedas", "Salir"};
string menu_ordenar[] = {"[MENÚ ORDENAR]", "Burbuja", "Heap Sort", "Merge Sort",
                         "Quick Sort", ".....", "Volver"};
string menu_buscar[] = {"[MENÚ BUSCAR]", "Lineal", "Binaria", "Interpolación",
                        ".....", "Volver"};
string menu_login[] = {"[SISTEMA]", "Ingresar", "Registrarse", "Salir"};

int menu(string vector[], int tam);
int login();
void busquedaBinaria(int arreglo[], int tam, int buscar);
void busquedaInterpolacion(int arreglo[], int tam, int buscar);
void ordenamientoBurbuja(int arreglo[], int tam);
void ordenamientoInsercion(int arreglo[], int tam);
void importante(string cadena);

int main()
{
    if (login())
    {
        salir = false;
        while (!salir)
        {
            switch (menu(menu_ppl, (int)sizeof(menu_ppl) / sizeof(string)))
            {
            case 0:
                importante("Adios");
                salir = true;
                break;
            case 1:
                importante(menu_ppl[1]);
                break;
            case 2:
                importante(menu_ppl[2]);
                break;
            case 3:
                importante(menu_ppl[3]);
                break;
            case 4:
                importante(menu_ppl[4]);
                break;
            case 5:
                importante(menu_ppl[5]);
                break;
            case 6:
                switch (menu(menu_ordenar, (int)sizeof(menu_ordenar) / sizeof(string)))
                {
                case 1:
                    importante(menu_ordenar[1]);
                    break;
                default:
                    break;
                }
                break;
            case 7:
                importante(menu_ppl[7]);
                break;
            case 8:
                switch (menu(menu_buscar, (int)sizeof(menu_buscar) / sizeof(string)))
                {
                case 1:
                    importante(menu_buscar[1]);
                    break;
                default:
                    break;
                }
                break;
            case 9:
                importante(menu_ppl[9]);
                break;
            default:
                importante("Opción inválida");
                break;
            };
        };
    }
    return 0;
}

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

int login()
{
    fstream archivo;
    string usuarioLogin, passwordLogin, confirmarPassword;
    string usuario, password, nombre, apellido;
    int telf;
    bool correcto = false;
    int numlineas = 0;
    salir = false;
    while (!salir)
    {
        switch (menu(menu_login, (int)sizeof(menu_login) / sizeof(string)))
        {
        case 0:
            importante("Adios");
            salir = true;
            break;
        case 1:
            cout << "\n\t[INGRESO]" << endl;
            cout << "Usuario:\n> ";
            getline(cin, usuarioLogin);
            cout << "Contraseña:\n> ";
            getline(cin, passwordLogin);
            archivo.clear();
            archivo.open("login.txt", ios::in);
            if (archivo.fail())
                importante("No se ha registrado ningún usuario");
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
                    importante("Datos incorrectos");
                else
                {
                    importante("Datos correctos");
                    salir = true;
                }
                if (numlineas == 0)
                    importante("Archivo vacío!");
            }
            archivo.close();
            break;
        case 2:
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
                do
                {
                    importante("Confirmación incorrecta!");
                    cout << "Vuelva a ingresar su contraseña: ";
                    cin >> confirmarPassword;
                } while (password != confirmarPassword);
            importante("Usuario registrado!");
            archivo.clear();
            archivo.open("login.txt", ios::out);
            archivo << usuario << "\n"
                    << password << "\n";
            archivo.close();
            archivo.clear();
            archivo.open("datosUsuario.txt", ios::out);
            archivo << "NOMBRE: " << nombre << " " << apellido << endl;
            archivo << "TELÉFONO: " << telf << endl;
            archivo << "USUARIO: " << usuario << endl;
            archivo << "CONTRASEÑA: " << password << endl;
            archivo.close();
            break;
        default:
            importante("Opción inválida");
            break;
        }
    }
    if (correcto)
        return 1;
    else
        return 0;
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
            bajo = interp + 1;
        else if (arreglo[interp] > buscar)
            alto = interp - 1;
        else
        {
            encontrado = interp;
            break;
        }
        loop++;
    }
    if (buscar == arreglo[bajo])
        encontrado = bajo;
    if (encontrado != -1)
    {
        cout << "Se encontró " << buscar << " en la posición " << (encontrado + 1) << " del arreglo\n";
        cout << "Se necesitaron " << loop << " iteraciones para encontrarlo\n";
    }
    else
        importante("No se escontró el elemento en el arreglo");
}

void ordenamientoBurbuja(int arreglo[], int tam)
{
    int aux;
    for (int i = 0; i < tam; i++)
        for (int j = i + 1; j < tam; j++)
            if (arreglo[j] < arreglo[i])
            {
                aux = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = aux;
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

