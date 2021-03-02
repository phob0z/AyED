/*********************************************
* CLASE CARRO
* Vers 2.1
*
* Mayo, 2001
***********************************************/					
#ifndef CARRO
#define CARRO

#include <cadena.h>
#include <oracion.h>
#include <stdlib.h>
#include <iomanip.h>

//
//---------------------------------------------------------> CLASE Carro
//
class CCarro {
protected:
	Cadena modelo, placa;
	float precio;

public:
	CCarro() { precio = 0;}
	CCarro( const CCarro &);
	~CCarro() {}

	CCarro(const Cadena&, const Cadena&, float);
	CCarro(char *, char *, float);
	
	Cadena obtener_modelo() const;
	Cadena obtener_placa() const;
	inline float obtener_precio() const { return precio; }
	
	void asignar( const Cadena&, const Cadena&, float);
	void asignar( char *, char *, float);
	
	int operator<(CCarro& );
	int operator==(const CCarro &);
	CCarro& operator=(const CCarro &);

	friend ostream &operator<<(ostream &, const CCarro &);
	friend istream &operator>>(istream &, CCarro&);
	
};
#endif
