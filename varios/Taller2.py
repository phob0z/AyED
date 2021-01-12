import random

integrantes = ["Manuel Josué Auqui Sánchez","Jhael Darío Nicolalde Molina",\
            "Jimy Bryan Calvo Mullo","Raúl Alejandro Tenorio Mendieta",\
            "Leonel Alfonso Molina Troconis"]
print(f"Integrantes: {integrantes}")
aleatorio = random.randint(0,4)
print(f"Integrante aleatorio [posición {aleatorio+1}]: {integrantes[aleatorio]}\n")
caracter = chr(random.randint(33,126))
print(f"Caracter: {caracter}\n")
entero = random.randint(0,999)
print(f"Entero: {entero}\n")
decimal = random.random()
print(f"Decimal: {entero+decimal:.2f}\n")
cadena = "Esto es una cadena de texto"
print(f"Cadena: {cadena}\n")
if random.randint(0,1) == 1:
    booleano = True
else:
    booleano = False
print(f"Booleano: {booleano}\n")
unidimensional = [random.randint(1,10) for x in range(6)]
print(f"Arreglo unidimensional: ")
for x in unidimensional:
    print(f"{x}\t", end="")
print()
while True:
    x = input(f"¿Que item desea imprimir 1-{len(unidimensional)}?\n>> ")
    try:
        x = int(x)
    except:
        print("ERROR: ¡Ese no un número!")
        continue
    if x > len(unidimensional) or x < 1:
        print(f"ERROR: ¡El número debe estar entre 1 y {len(unidimensional)}")
        continue
    else:
        print(f"\nEl número en la posición [{x}] es: {unidimensional[x-1]}\n")
        break
bidimensional = [[random.randint(1,10) for x in range(3)] for y in range(3)] 
print(f"Arreglo bidimensional: ")
for x in bidimensional:
    for y in x:
        print(f"{y}\t", end="")
    print()
while True:
    x = input("¿De cual fila desea imprimir?\n>> ")
    try:
        x = int(x)
    except:
        print("ERROR: ¡Ese no un número!")
        continue
    if x > len(bidimensional) or x < 1:
        print(f"ERROR: ¡El número debe estar entre 1 y {len(bidimensional)}")
        continue
    else:
        while True:
            y = input("¿De cual columna desea imprimir?\n>> ")
            try:
                y = int(y)
            except:
                print("ERROR: ¡Ese no un número!")
                continue
            if y > len(bidimensional[x-1]) or y < 1:
                print(f"ERROR: ¡El número debe estar entre 1 y {len(bidimensional[x-1])}")
                continue
            else:
                print(f"\nEl número en la posición [{x}][{y}] es: {bidimensional[x-1][y-1]}\n")
                break
        break