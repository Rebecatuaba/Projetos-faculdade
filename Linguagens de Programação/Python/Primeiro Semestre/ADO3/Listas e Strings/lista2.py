# Soma dos elementos nas posições pares. Some apenas os elementos que estão nas posições pares de uma lista.

elementos = []

for i in range (4):
    num = int(input("Digite 4 valores inteiros: "))
    elementos.append(num)# append serve para acresentar um numero a lista

soma = 0
for i in range (0, len(elementos), 2):
    soma += elementos[i] 

print (f"A soma das posições é igual: {soma}")       