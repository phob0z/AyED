//
// Clase Cadena tomando como base la clase cadena de Stroustrup
//
//  Enero / 1999
//	Vers. 2.0
//
//	Mayo / 1999
//  Vers. 2.1
//
#ifndef CADENA
#define CADENA
#include <iostream.h>
#include <string.h>
#include <assert.h>

class Cadena{
protected:
	struct repcad {
		char* c;		
		int n;			
		repcad() { n = 1; }
	};
	repcad *p;

public:
		Cadena(const char * = "");		
		Cadena(const Cadena &);		
		~Cadena();
		Cadena& operator=(const char *);
		Cadena& operator=(const Cadena &);
		int longitud() const {
			return strlen(p->c);
		}
		char& operator[](int);
		int getch(int i){ return (int)this->operator[](i); }
		char* getch() const;
		Cadena sub(int,int);
		Cadena& sub(Cadena&, int, int);
		int indice(const Cadena&);
		Cadena& operator+=(const Cadena&);
		Cadena operator+(const Cadena&);
		void set(const char *);
		
		friend ostream& operator<<(ostream&, const Cadena&);
		friend istream& operator>>(istream&, Cadena &);

		friend int operator==(const Cadena &x, const char *c){ 
			return strcmp(x.p->c, c) == 0; 
		}

		friend int operator==(const Cadena &x, const Cadena &y){
			return strcmp(x.p->c, y.p->c) == 0;
		}

		friend int operator!=(const Cadena &x, const Cadena &y){
			return strcmp(x.p->c, y.p->c) != 0;
		}

		friend int operator!=(const Cadena &x, const char *c){
			return strcmp(x.p->c, c) != 0;
		}

		friend int operator<(const Cadena &x, const Cadena &y){
			return (strcmp(x.p->c, y.p->c) < 0);
		}

		friend int operator>(const Cadena &x, const Cadena &y){
			return (strcmp(x.p->c, y.p->c) > 0);
		}

		friend int operator>=(const Cadena &x, const Cadena &y){
			return (strcmp(x.p->c, y.p->c) >= 0);
		}

		friend int operator<=(const Cadena &x, const Cadena &y){
			return (strcmp(x.p->c, y.p->c) <= 0);
		}



};
#endif
