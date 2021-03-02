#include <cadena.h>
/************************************************************
 * Definicion de los metodos de la clase cadena
 *
 * **********************************************************/

//
//----------------------------------------------->CONSTRUCTORES
//
Cadena::Cadena(const Cadena& x){
	x.p->n++;
	p = x.p;
}

Cadena::Cadena(const char* c) {
	p = new repcad;
	p->c = new char[strlen(c) + 1];
	assert( p->c != 0 );
	strcpy(p->c,c);
}

Cadena::~Cadena() {
	if ( --p->n == 0 ) {
		delete[] p->c;
		delete p;
	}
}

//----------------------------------------------->COPIA
Cadena& Cadena::operator=(const char* cad){
	if ( p->n > 1 ) {
		p->n--;
		p = new repcad;
	} else
		delete [] p->c;

	p->c = new char[strlen(cad) + 1];
	assert( p->c != 0 );
	strcpy(p->c,cad);
	return *this;
}

Cadena& Cadena::operator=(const Cadena& x){
	x.p->n++;
	if ( --p->n == 0 ){
		delete[] p->c;
		delete p;
	}
	p = x.p;
	return *this;
}

//-----------------------------------------------> ENTRADA Y SALIDA TIPO TEXTO

ostream& operator<<(ostream& s, const Cadena& x){
	return s << x.p->c;
}


istream& operator>>(istream& e, Cadena& x){
	const int MAX_STR=1024;
	static char buf[MAX_STR];
	int  i=0, sw = 0;

	while (sw < 1 ) {
		e.getline(buf,MAX_STR);
		if ( e.fail() ){
			x = "";
			return e;
		}
		sw = e.gcount() -1;
	}
	x = buf;
	return e;
}

//-----------------------------------------------> OPERADORES ADICIONALES

void Cadena::set(const char *c) {
	*this = (const char *)c;
}

Cadena& Cadena::operator+=(const Cadena& x){
	char *aux = new char[this->longitud() + 1];
	assert( aux != 0);
	strcpy(aux,	this->getch());

	if ( p->n > 1 ) {
		p->n --;
		p = new repcad;
	} else
		delete[] p->c;

	this->p->c = new char [strlen(aux) + strlen(x.getch()) + 1];
	assert ( p->c != 0 );
	strcpy(this->p->c, aux);
	strcat(this->p->c,x.getch());
	delete[] aux;
	
	return *this;
}

Cadena Cadena::operator+(const Cadena& x) {
	Cadena res;
	res = *this;
	res += x;
	return(res);
}


Cadena& Cadena::sub(Cadena& cad, int inicio, int longitud) {
	int k, tam;
	
	
	k = longitud;
	tam = strlen(p->c);
	if((inicio < 0) || (longitud < 0)||(inicio > tam)) {
		cad = "";
		return (cad);
	}

	if(( longitud == 0) || ( tam < inicio + longitud )) 
		k = tam - inicio + 1;

	if ( cad.p->n > 1 ) {
		cad.p->n --;
		cad.p = new repcad;
	} else
		delete[] cad.p->c;

	cad.p->c=new char[k + 1];
	assert (cad.p->c != 0);

	cad.p->c[0] = '\0';

	for(int j=0;j<k;j++){
		cad.p->c[j] = p->c[inicio + j]; 
		cad.p->c[j + 1] = '\0';
	}

	return cad;
}

int Cadena::indice(const Cadena &x){
	int i, tam1, tam2;
	tam2 = x.longitud();
	tam1 = this->longitud();

	if ( !tam2 ) 
		return(0);

	if ( tam2 > tam1)
		return(-1);

	Cadena cad;
	for( i=0; i + tam2 <= tam1; i++) {
		sub(cad,i,tam2);
		if ( cad == x )
			return(i);
	}
	return( -1);
}

char& Cadena::operator[](int i){
	assert( (i >= 0) && (i < this->longitud()) );
	return p->c[i];
}

Cadena Cadena::sub(int inicio, int longitud) {
	int k, tam;
	Cadena cad;
	
	k = longitud;
	tam = strlen(p->c);
	if((inicio < 0) || (longitud < 0)||(inicio > tam))
		return cad;

	if(( longitud == 0) || ( tam < inicio + longitud )) 
		k = tam - inicio + 1;

	cad.p->c=new char[k + 1];
	assert (cad.p->c != 0);

	cad.p->c[0] = '\0';

	for(int j=0;j<k;j++){
		cad.p->c[j] = p->c[inicio + j]; 
		cad.p->c[j + 1] = '\0';
	}

	return cad;
}
//
//	Metodo Peligroso:
char* Cadena::getch() const{
	return( p->c );
}
