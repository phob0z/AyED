#include <carro.h>
CCarro::CCarro(const CCarro& c) {
	this->modelo = c.modelo;
	this->placa  = c.placa;
	this->precio = c.precio;
}


CCarro::CCarro(const Cadena& placa,const Cadena& modelo,  float precio) {
	this->modelo = modelo;
	this->placa  = placa;
	this->precio = precio;
}

CCarro::CCarro(char* placa, char *modelo,  float precio) {
	this->modelo = modelo;
	this->placa  = placa;
	this->precio = precio;
}

Cadena CCarro::obtener_modelo() const {
	return modelo;
}


Cadena CCarro::obtener_placa() const {
	return placa;
}

int CCarro::operator<(CCarro& c) {
	// Cambio de la Ley de Orden
	return ( this->placa < c.placa );
}

ostream &operator<<(ostream &s, const CCarro &c) {
	if ( (c.placa).longitud() == 7 ) {
		s << c.placa << ":" << c.modelo << ":";
		s.setf(ios::fixed, ios::floatfield);
		s << setprecision(2);
		s << c.precio << '\n';
	}
	return (s);
}

istream &operator>>(istream &e, CCarro &c) {
	Cadena placa, marca;
	Oracion linea;
	float precio;

	c.asignar("","",0.0);

	e >> linea;
	linea.set_delimitador(':');
	if ( linea.cuenta_palabras() != 3 )
		return(e);

	linea.primera_pos();
	placa = linea.get_palabra();
	marca = linea.get_palabra();
	precio = (float) atof( (linea.get_palabra()).getch() );
	
	c.asignar(placa, marca, precio);
	return (e);
}

void CCarro::asignar(const Cadena& placa, const Cadena& modelo,  float precio) {
	this->modelo = modelo;
	this->placa  = placa;
	this->precio = precio;
}


void CCarro::asignar(char* placa, char *modelo,  float precio) {
	this->modelo = modelo;
	this->placa  = placa;
	this->precio = precio;
}

int CCarro::operator==(const CCarro& c) {
	return ( this->placa == c.placa);
}

CCarro& CCarro::operator=(const CCarro &p) {
	this->modelo = p.modelo;
	this->placa = p.placa;
	this->precio = p.precio;

	return( *this );
}
