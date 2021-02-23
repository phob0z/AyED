#include<iostream>
#include<fstream>
using namespace std;

typedef struct musica{
  char cantante[100];
  char disco[100];
  char cancion[100];
  int anyo;
  long int vendidos;
  char tipo[50];
};

int main(){
  char nombre[100];
  musica aux;
  fstream in;
  fstream out;
  int opcion;
  while (1){
    cout << "1- Mostrar Todos los cantantes "<<endl;
    cout << "2- Eliminar un cantante "<<endl;
    cout << "3- salir"<<endl;
    cout << "Opcion ? ";
    cin  >> opcion;
    if (opcion == 1){
      in.clear();
      in.open("datos.dat", ios::in | ios::binary);
      while (in.read(reinterpret_cast<char*>(&aux),sizeof(musica)))
	cout << "Nombre "<<aux.cantante<<" Cancion " <<aux.cancion<<endl;      
      in.close();
    }
    if (opcion == 2){
      in.clear();
      out.clear();
      in.open("datos.dat", ios::in | ios::binary);
      out.open("aux.aux", ios::out | ios::binary);
      cout << "Nombre del cantante a eliminar "<<endl;
      cin  >> nombre;
      while (in.read(reinterpret_cast<char*>(&aux),sizeof(musica)))
	if (strcmp(aux.cantante,nombre)!=0)
	  out.write(reinterpret_cast<char*>(&aux),sizeof(musica));
      in.close();
      out.close();
      rename("aux.aux","datos.dat");
    }
    if (opcion == 3)
      return 0;  
  }
}