#include <cadena.h>
#include <fstream.h>
#include <stdio.h>
#include <time.h>
#include <carro.h>

int agregar(char *, const CCarro&);
int eliminar(char *, const Cadena&);
int mostrar(char *);
void crear(char *, unsigned long);
int buscar(char *, CCarro&);
int mezcla(char *, char *, char *);
int partir_en_tres1(char *, char *, char *, char *);
int partir_en_tres2(char *, char *, char *, char *);
int partir_por_precio(char *, char *, char *, char *);
int partir_por_grupo(char *,int m, char *, char *, char *);
