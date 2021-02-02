#include <iostream>
#include <fstream>
using namespace std;

int busqueda(int arr[], int t, int dato);
int solicitarNumero();

int main() 
{
  string texto;
  ofstream archivo;
  archivo.open("Lineal.txt",ios::out);
  int a[]={4,1,2,3,5};
  int dato=solicitarNumero();
  archivo<<"Arreglo: ";
  for(int i=0; i<5;i++)
  {
    archivo<<"|"<<a[i]<<"|";
  }
  archivo<<endl;
  archivo<<"Elemento a buscar: "<<dato<<endl;
  if(busqueda(a,5,dato)==3)
  {
    archivo<<"ELEMENTO NO ENCONTRADO";
  }
  else 
  {
    archivo<<"ELEMENTO ENCONTRADO!\nEn la posición: "<<busqueda(a,5,dato)+1;
  }
  archivo.close();

  ifstream archivoLectura;
  archivoLectura.open("Lineal.txt",ios::in);

  if(archivoLectura.fail())
  {
    cout<<"NO SE ENCONTRÓ NINGÚN ARCHIVO"<<endl;
  }
  else
  {
    while(!archivoLectura.eof())
    {
      if(!archivoLectura.eof())
      {
        getline(archivoLectura,texto);
        cout << texto << endl;
      }
    }
  }
  archivoLectura.close();
}

int busqueda(int arr[], int t, int dato)
{
  int i;
  for( i=0 ; i<5 ; i++)
  {
    if(arr[i]==dato)
    {
      return i;
    }
  }
  return 3;
}

int solicitarNumero()
{
  int n;
  cout<<"Ingresa el número a buscar:\n";
  cin>>n;
  return n;
}