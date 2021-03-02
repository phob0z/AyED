
#include <oracion.h>
//
// DEFINICION DE LOS METODOS DE LA CLASE ORACION
//
Oracion::Oracion(const char* x) : Cadena(x){ 
		pos = 0;
		delimitador = ' ';
}

Oracion::Oracion(const Oracion& x): Cadena ((Cadena)x){
		pos = 0;
		delimitador = ' ';
}

int Oracion::cuenta_palabras() const {
	
	if ( !longitud()) 
		return (0);

	Cadena tmp, aux= *this;
	int n =0, p, sw = 1;
	char* pdest;
	
	while ( aux != "" && sw) {
		if ( aux[0] != delimitador ) {
			pdest = strchr(aux.getch(),delimitador);
			if ( pdest != NULL ){
				p = pdest - aux.getch();
			
				if ( p < 0 ) 
					break;
				tmp = aux.sub(p+1,0);
				aux = tmp;
			} else
				sw = 0;
			n++;
		} else {
			tmp = aux.sub(1,0);
			aux = tmp;
		}
	}

	return n;
}

Cadena Oracion::get_palabra() {
	Cadena res;

	pos++;
	if ( pos > cuenta_palabras()  ) {
		pos--;
		return res;
	}
	int p, sw = 1;
	Cadena tmp, aux=*this;
	char* pdest;
	for( int i= 0 ;  i < pos; ) {
	
		if ( aux[0] != delimitador ) {
			pdest = strchr(aux.getch(),delimitador);
			if ( pdest != NULL ){
				p = pdest - aux.getch();
			
				if ( p < 0 ) 
					break;
				if ( i == (pos -1) )
					res = aux.sub(0,p);
				tmp = aux.sub(p+1,0);
				aux = tmp;
			} else
				if ( i == ( pos -1 ))
					res = aux;
			i++;
		} else {
			tmp = aux.sub(1,0);
			aux = tmp;
		}
	}	

	return res;
}
