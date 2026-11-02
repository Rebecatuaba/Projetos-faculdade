#Crie um programa que exiba no final o somatório dos valores pares existentes na faixa de 1 até 500.

i = 1
soma = 0

while i <= 500:
    if i % 2 == 0:
        soma += i
    i += 1
print (f"O final do somatório dos valores pares existentes na faixa de 1 até 500 é: {soma}")