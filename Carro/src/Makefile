CC = g++
OPC = -g -Wno-deprecated
INCDIR = -I ../include

%.o:	%.cpp
	$(CC) $(OPC) $(INCDIR) -c $< -o $@

default:	arch_carros.exe

arch_carros.exe:	../src/cadena.o ../src/oracion.o ../src/carro.o ../src/util_arch_carros.o arch_carros.o
	$(CC) $(OPC) arch_carros.o ../src/cadena.o ../src/oracion.o ../src/carro.o ../src/util_arch_carros.o  -o arch_carros.exe 

clean: 
	rm -f *.o arch_carros.exe 
