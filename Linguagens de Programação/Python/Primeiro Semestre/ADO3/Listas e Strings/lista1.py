# Ler 5 números inteiros e identificar o maior e o menor valor, exibir os mesmos.

# Variáveis
numeros = []

for i in range(5):  # usamos para dizer a quantidade de vezes que irá repetir o for, nesse caso 5 (0,1,2,3,4)
    n = int(input(f"Digite o {i+1}º número: "))
    numeros.append(n)  # Corrigido: adiciona n dentro da lista numeros

maior = numeros[0]  # Corrigido: inicializa usando a lista numeros
menor = numeros[0]

for num in numeros:  # Corrigido: percorre a lista numeros
    if num > maior:
        maior = num
    if num < menor:
        menor = num

print(f"O maior número é: {maior}")
print(f"O menor número é: {menor}")
