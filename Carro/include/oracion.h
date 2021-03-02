/*************************************
*	Clase Oracion, versión Básica
*
*       v 0.1   01/99
**************************************/ 
#ifndef ORACION
#define ORACION
#include <cadena.h>

class Oracion : public Cadena {
	int pos;
	char delimitador;
public:
	Oracion(const char * = "");
	Oracion(const Oracion &x);
    	~Oracion(){}

	int cuenta_palabras() const ;
	void primera_pos() {
		pos = 0;
	}
	Cadena get_palabra();
	void set_delimitador(char c) {
		delimitador =c;
	}
};
#endif
