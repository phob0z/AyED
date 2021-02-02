#include <iostream>
#include <string.h>
using namespace std;

int potencia(int base, int exp);
int main() {
//DEFINICIÓN DE VARIABLES
//VARIABLE MENÚ
int opcion;
//VARIABLES OPCIÓN 1
float total, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12;
//VARIABLES OPCIÓN 2
int num1, num2;
//VARIABLES OPCIÓN 3
float c1;
char c[20],p[20];
int n;
//VARIABLES OPCIÓN 4
float Sueldo, SueldoN;
int Cat;
//MENÚ
do
{
cout<<"-------------------------------------"<<endl;
cout<<"\t\t\tTALLER GRUPAL"<<endl;
cout<<"\t\t\t EJERCICIOS"<<endl;
cout<<"-------------------------------------"<<endl;
cout<<"\t\t\t [MENÚ]"<<endl;
cout<<"\t\t 1. Ejercicio N°3"<<endl;
cout<<"\t\t 2. Ejercicio N°7"<<endl;
cout<<"\t\t 3. Ejercicio N°8"<<endl;
cout<<"\t\t 4. Ejercicio N°9"<<endl;
cout<<"\t\t 5. Salir"<<endl;
cout<<"-------------------------------------"<<endl;
cout<<"Ingrese una opción:"<<endl;
cin>>opcion;
cout<<"-------------------------------------"<<endl;
switch(opcion)
{
case 1:
{
cout<<"\t\t EJERCICIO N°3"<<endl;
cout<< " ► AHORROS DE JUANITO ◄\n";
cout<< "======================================\n";
cout<< " Depositar dinero\n";
cout<< "======================================\n";
cout<< "En Enero voy a ahorrar: ";
cin>> m1;
cout<< "--------------------------------------\n";
cout<< "En Febrero voy a ahorrar: ";
cin>> m2;
cout<< "--------------------------------------\n";
cout<< "En Marzo voy a ahorrar: ";
cin>> m3;
cout<< "--------------------------------------\n";
cout<< "En Abril voy a ahorrar: ";
cin>> m4;
cout<< "--------------------------------------\n";
cout<< "En Mayo voy a ahorrar: ";
cin>> m5;
cout<< "--------------------------------------\n";
cout<< "En Junio voy a ahorrar: ";
cin>> m6;
cout<< "--------------------------------------\n";
cout<< "En Julio voy a ahorrar: ";
cin>> m7;
cout<< "--------------------------------------\n";
cout<< "En Agosto voy a ahorrar: ";
cin>> m8;
cout<< "--------------------------------------\n";
cout<< "En Septiembre voy a ahorrar: ";
cin>> m9;
cout<< "--------------------------------------\n";
cout<< "En Octubre voy a ahorrar: ";
cin>> m10;
cout<< "--------------------------------------\n";
cout<< "En Noviembre voy a ahorrar: ";
cin>> m11;
cout<< "--------------------------------------\n";
cout<< "En Diciembre voy a ahorrar: ";
cin>> m12;
cout<< "--------------------------------------\n";
cout<< "======================================\n";
cout<< " REGISTRO\n";
cout<< "======================================\n";
cout<< "El dinero ahorrado en cada mes es: \n";
cout<< "Enero: "<<m1<<" Julio: "<<m7<<"\n";
cout<< "Febrero: "<<m2<<" Agosto: "<<m8<<"\n";
cout<< "Marzo: "<<m3<<" Septiembre: "<<m9<<"\n";
cout<< "Abril: "<<m4<<" Octubre: "<<m10<<"\n";
cout<< "Mayo: "<<m5<<" Noviembre: "<<m11<<"\n";
cout<< "Junio: "<<m6<<" Diciembre: "<<m12<<"\n";
cout<< "======================================\n";
total = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9 + m10 + m11 + m12;
cout<< "El total ahorrado en el año es de: "<<total<<"\n";
}
break;
case 2:
{
cout<<"\t\t EJERCICIO N°7"<<endl;
cout<<"\t POTENCIA RECURSIVA"<<endl;
cout << "\nIntroduzca la base:\n";
cin >> num1;
cout << "Introduzca el exponente:\n";
cin >> num2;
if (num2 < 0)
cout << "El exponente debe ser mayor que 0\n";
else
cout << "El resultado de " << num1 << "^" << num2 << " es: " <<\
potencia(num1, num2)<<endl;
}
break;
case 3:
{
cout<<"\t\t EJERCICIO N°8"<<endl;
cout<<"\t “McDonald's - Ecuador” "<<endl;
cout<<"\nCuántas hamburguesas va a adquirir?"<<endl;
cin>>n;
cout<<"Que tipo de hamburguesa desea comprar?"<<endl;
cout<<"(sencilla,doble o triple)"<<endl;
cin>>c;
cout<<"Cómo desea pagar? (tarjeta o efectivo):"<<endl;
cin>>p;
if (!(strcmp(c,"sencilla")))
{
c1=n*1.5;
}
else if(strcmp(c,"doble"))
{
c1=n*2.5;
}
else if(strcmp(c,"triple"))
{
c1=n*3.5;
}
else
{
cout<<"El tipo de hamburguesa no está registrado!";
}
if (!(strcmp(p,"tarjeta")))
{
c1=c1+(c1*0.05);
}
cout<<"El total a pagar es: $"<<c1<<endl;
}
break;
case 4:
{
cout<<"\t\t EJERCICIO N°9"<<endl;
cout <<endl<<"Ingrese el sueldo del empleado:"<<endl;
cin >>Sueldo;
cout <<endl<<"\t\t-----Categorías-----"<<endl;
cout <<"\t\t\t 1) 10% "<<endl;
cout <<"\t\t\t 2) 20% "<<endl;
cout <<"\t\t\t 3) 50% "<<endl;
cout <<"\nIngrese la categoría a la cuál pertenece el empleado:"<<endl;
cin >>Cat;
switch (Cat)
{
case 1:
SueldoN=Sueldo+Sueldo*0.10;
break;
case 2:
SueldoN=Sueldo+Sueldo*0.20;
break;
case 3:
SueldoN=Sueldo+Sueldo*0.50;
break;
default:
cout <<"ERROR, escribiste mal La categoría: ";
break;
}
cout <<"\nEl sueldo inicial del empleado es de: "<<Sueldo<<" $";
cout <<"\nEl sueldo nuevo del empleado es de: "<<SueldoN<<" $"<<endl;
}
break;
case 5:
cout<<"HASTA PRONTO!"<<endl;
break;
default:
cout<<"Esta opción no existe!"<<endl;
cout<<"Por favor, vuelva a ingresar"<<endl;
break;
}
}
while(opcion!=5);
}
int potencia(int base, int exp)
{
if (exp == 0)
return 1;
else
return base * potencia(base, exp-1);
}