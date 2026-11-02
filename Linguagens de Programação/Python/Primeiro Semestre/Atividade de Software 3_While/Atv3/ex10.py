# Ler 5 números inteiros e identificar o maior e o menor valor, exibir os mesmos. Exemplo: Durante cada pergunta verificar se é maior ou menor. 
# Digite o 1º número: 10; Digite o 2º número: 5; Digite o 3º número: 20; Digite o 4º número: 7; Digite o 5º número: 3; Maior número: 20; Menor número: 3

i = 1
maior = menor = int(input(f"Digite o {i}º número: "))

while i < 5:
    i += 1
    num = int(input(f"Digite o {i}º número: "))
    
    if num > maior:
        maior = num
    if num < menor:
        menor = num

print(f"Maior número: {maior}")
print(f"Menor número: {menor}")


