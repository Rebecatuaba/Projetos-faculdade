#Exibir os resultados de uma tabuada de um número qualquer. Essa deverá ser impressa no seguinte formato: 2 X 1 = 2; 2 X 2 = 4 (....) 2 X 10 = 20

tabuada = int(input("Digite uma tabuada de um número qualquer: "))
i = 1

print (f"\nTabuada do {tabuada}:")

while i <= 10:
    mult= tabuada * i
    print (f"{tabuada}x{i}={mult}")
    i += 1