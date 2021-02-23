#include <iostream>
using namespace std;

int main() {
  string usuarioLogin, passwordLogin, confirmarPassword, usuario, password;
  int op;
  do
  {
    cout<<"\n\t\tSISTEMA"<<endl;
    cout<<"1. Ingresar"<<endl;
    cout<<"2. Registrarse"<<endl;
    cout<<"3. Salir"<<endl;
    cout<<"Ingrese la opción: ";
    cin>>op;
    switch(op)
    {
      case 1:
      {
        cout<<"\n\t[INGRESO]"<<endl;
        cout<<"Usuario: ";
        cin>>usuarioLogin;
        cout<<"Contraseña: ";
        cin>>passwordLogin;
        if(usuario==usuarioLogin && password==passwordLogin)
        {
          cout<<"\nBIENVENIDO AL SISTEMA"<<endl;
        }
        else
        {
          cout<<"Usuario y/o contraseña incorrectos!"<<endl;
        }
      }
      break;
      case 2:
      {
        cout<<"\n\t[REGISTRO]"<<endl;
        cout<<"Usuario: ";
        cin>>usuario;
        cout<<"Contraseña: ";
        cin>>password;
        cout<<"Confirmar contraseña: ";
        cin>>confirmarPassword;
        if(password!=confirmarPassword)
        {
          do
          {
            cout<<"\nConfirmación incorrecta!"<<endl;
            cout<<"Vuelva a ingresar su contraseña: ";
            cin>>confirmarPassword;
          }
          while(password!=confirmarPassword);
        }
        cout<<"\n\tUSUARIO REGISTRADO!"<<endl;
      }
      break;
      case 3:
      break;
      default:
      cout<<"\nEsta opción no existe!\nPor favor, vuelva a ingresar."<<endl;
      break;
    }
  }
  while(op!=3);
}