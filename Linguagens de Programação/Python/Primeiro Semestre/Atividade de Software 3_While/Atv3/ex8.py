#Crie um programa que exiba a série de Fibonacci até o décimo quinto termo. A série de Fibonacci é formada pela seqüência: 1, 1, 2, 3, 5, 8, 13, 21, 34....etc. Essa série se caracteriza pela soma de um termo posterior com seu anterior subseqüente.
CÓDIGO:
# Série de Fibonacci até o 15º termo usando while

# Primeiros dois termos da série
termo1 = 1
termo2 = 1

# Contador de termos exibidos
contador = 2

print(termo1)
print(termo2)

while contador < 15:
    proximo = termo1 + termo2
    print(proximo)
    termo1 = termo2
    termo2 = proximo
    contador += 1
