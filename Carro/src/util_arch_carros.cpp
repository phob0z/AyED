#include <util_arch_carros.h>
int agregar(char* n_arch, const CCarro& c) {
	ofstream f;
	f.open(n_arch, ios::app);

	if ( !f )
		return(0);

	f << c ;

	if ( f.fail())
		return(0);

	f.close();
	return(1);
}

int eliminar(char* n_arch, const Cadena& cad1) {
	ifstream f1;
	ofstream f2;

	f1.open(n_arch);
	if ( !f1 )
		return(0);

	char n_temp[] = "arch.tmp";
	f2.open(n_temp);
	if (!f2 )
		return(0);

	CCarro c;
	Cadena aux;

	while( ! f1.eof() ) {
		f1 >> c; 
		aux = c.obtener_placa();
		if ( aux != cad1) 
			f2 << c;
	}

	f1.close();
	f2.close();
	remove(n_arch);
	rename(n_temp,n_arch);
	return(1);
}

int mostrar(char* n_arch) {
	ifstream f;
	f.open(n_arch);

	if ( ! f )
		return(0);

	CCarro c;
	long i = 0, sw= 1;

	while ( !f.eof() && sw) {
		f >> c;
		if ( (c.obtener_placa()).longitud() == 7 ) {
			cout << ++i <<" : " <<  c << '\n';
		} else {
			sw = 0;
		}
	}
	cout << flush;
	f.close();
	return(1);
}
		
int buscar(char *n_arch, CCarro& c){
	ifstream f;
	f.open(n_arch);

	if ( ! f ) {
		cerr << "Archivo no existe" << endl;
		return (0);
	}

	CCarro c1;
	int encontro = 0;
	while ( !f.eof() && ! encontro ) {
		f >> c1;
		if ( c1 == c ) {
			encontro = 1;
			c = c1;
		}
	}
	f.close();
	return ( encontro );
}


void crear(char* n_arch, unsigned long n_elementos) {
	char *modelos[] = { "Mazda", "Toyota", "Ford"}; 
	
	ofstream f;
	f.open(n_arch);
	CCarro c;
	char placa[8];
	float precio;
	int j;
	unsigned long i;

	srand( (unsigned)time( NULL ) );

	for( i = 0; i < n_elementos; i++) {
		placa[0] = char( (float)rand()/(float)RAND_MAX*26 + 65);
		placa[1] = char( (float)rand()/(float)RAND_MAX*26 + 65);
		placa[2] = char( (float)rand()/(float)RAND_MAX*26 + 65);
		placa[3] = '-';
		placa[4] = char( (float)rand()/(float)RAND_MAX*10 + 48);
		placa[5] = char( (float)rand()/(float)RAND_MAX*10 + 48);
		placa[6] = char( (float)rand()/(float)RAND_MAX*10 + 48);
		placa[7] = '\0';

		precio = ((float)rand())/(float)RAND_MAX * 15000000 + 5000000;

		j= (int)(((float)rand()/RAND_MAX)*3);
	
		c.asignar(placa, modelos[j], precio);
		
		f << c;
	}
	f.close();
	
}
			
int  mezcla(char* n_arch1, char* n_arch2, char* n_arch3) {
	fstream arch_ent1, arch_ent2, arch_ord;


	arch_ent1.open(n_arch1, ios::in);
	arch_ent2.open(n_arch2, ios::in);
	arch_ord.open(n_arch3, ios::out);

	if ( (! arch_ent1)  || ( ! arch_ent2 ) || ( ! arch_ord )) {
		cerr << "Error: problema al abrir los archivos" << endl;
		return 0;
	}

	int sw1 = 1, sw2 = 1;
	CCarro c1, c2;
	Cadena placa1, placa2;

	arch_ent1 >> c1;
	placa1 = c1.obtener_placa();
	if ( arch_ent1.fail() || placa1.longitud() != 7 ) {
		sw1 = 0;
	}

	arch_ent2 >> c2;
	placa2 = c2.obtener_placa();
	if( arch_ent2.fail() || placa2.longitud() != 7 ) {
		sw2 = 0;
	}
	while (sw1  && sw2 ) {

		if ( placa1 < placa2 ) {
			arch_ord << c1;
			arch_ent1 >> c1;
			placa1 = c1.obtener_placa();
			if ( arch_ent1.fail() || placa1.longitud() != 7 ) {
				sw1 = 0;
				break;
			}
		} else {
			arch_ord << c2;
			arch_ent2 >> c2;
			placa2 = c2.obtener_placa();
			if( arch_ent2.fail() || placa2.longitud() != 7 ) {
			         sw2 = 0;
			 } 
		}
	}

	if ( sw1 ) 
		while ( placa1.longitud() == 7 ) {
			arch_ord << c1;
			arch_ent1 >> c1;
			placa1 = c1.obtener_placa();
		}
	if ( sw2 )  
		while (  placa2.longitud() == 7 ) {
			arch_ord << c2;
			arch_ent2 >> c2;
			placa2 = c2.obtener_placa();
		}
	arch_ord.close();
	arch_ent1.close();
	arch_ent2.close();
	
	return 1;
}


int partir_en_tres1(char *arch, char *arch1, char *arch2, char *arch3) {
	ifstream f;
	f.open(arch);
	if ( !f )
		return 1;

	ofstream f1,f2,f3;
	f1.open(arch1);
	if ( ! f1 )
		return 2;

	f2.open(arch2);
	if ( ! f2 )
		return 3;

	f3.open(arch3);
	if ( ! f3 )
		return 4;

	int n = 0, sw = 1;
	CCarro c;

	while ( ! f.eof() && sw ) {
		f >> c;
		if ( (c.obtener_placa()).longitud() == 7 ) {
			switch ( n ) {
			case 0:
				f1 << c;
				break;
			case 1:
				f2 << c;
				break;
			case 2:
				f3 << c;
				break;
			}

			n = ( n + 1 ) % 3;
		} else
			sw = 0;
	}

	f1.close();
	f2.close();
	f3.close();
	f.close();
	return(0);
}

int partir_en_tres2(char *arch, char *arch1, char *arch2, char *arch3) {
	ifstream f;
	f.open(arch);
	if ( !f )
		return 1;
	CCarro c;
	int n_elementos = 0, sw = 1;
	while( ! f.eof() && sw ) {
		f >> c;
		if ( (c.obtener_placa()).longitud() == 7 ) 
			n_elementos++;
	}

	f.close();
	
   
	ofstream f1,f2,f3;
	f1.open(arch1);
	if ( ! f1 )
		return 2;

	f2.open(arch2);
	if ( ! f2 )
		return 3;

	f3.open(arch3);
	if ( ! f3 )
		return 4;

	int n = 0, m = 0, i = 0;
	
	f.open(arch);
	m = n_elementos/ 3;
	if ( (n_elementos % 3 ) != 0 )
		m++;

	while ( ! f.eof() && sw ) {
		f >> c;
		if ( (c.obtener_placa()).longitud() == 7 ) {
			switch ( n ) {
			case 0:
				f1 << c;
				break;
			case 1:
				f2 << c;
				break;
			case 2:
				f3 << c;
				break;
			}
            if ( ++i == m ) {
				n = ( n + 1 ) % 3;
				i = 0;
			}
		} else
			sw = 0;
	}

	f1.close();
	f2.close();
	f3.close();
	f.close();
	return(0);
}

int partir_por_grupo(char *arch, int m,char *arch1, char *arch2, char *arch3) {
	ifstream f;
	f.open(arch);
	if ( !f )
		return 1;

	ofstream f1,f2,f3;
	f1.open(arch1);
	if ( ! f1 )
		return 2;

	f2.open(arch2);
	if ( ! f2 )
		return 3;

	f3.open(arch3);
	if ( ! f3 )
		return 4;

	int n = 0, sw = 1, i = 0;
	CCarro c;

	while ( ! f.eof()) {
									f >> c;
									if (c.obtener_modelo()=="Mazda")
																	f1 << c;									
									if (c.obtener_modelo()=="Toyota")
																	f2 << c;									
									if (c.obtener_modelo()=="Ford")
																	f3 << c;
}

	f1.close();
	f2.close();
	f3.close();
	f.close();
	return(0);
}

int partir_por_precio(char *arch, char *arch1, char *arch2, char *arch3) {
	ifstream f;
	f.open(arch);
	if ( !f )
		return 1;

	ofstream f1,f2,f3;
	f1.open(arch1, ios::out);
	if ( ! f1 )
		return 2;

	f2.open(arch2, ios::out);
	if ( ! f2 )
		return 3;

	f3.open(arch3, ios::out);
	if ( ! f3 )
		return 4;

	int  sw = 1;
	CCarro c;

	while ( ! f.eof() && sw ) {
		f >> c;
		if ( (c.obtener_placa()).longitud() == 7 ) {
			if ( c.obtener_precio() <  10000000 ) {
				f1 << c;
			} else {
				if ( c.obtener_precio() < 15000000 ) {
					f2 << c;
				} else {
					f3 << c;
				}
			}
		} else 
			sw = 0;
	}

	f1.close();
	f2.close();
	f3.close();
	f.close();
	return(0);
}

