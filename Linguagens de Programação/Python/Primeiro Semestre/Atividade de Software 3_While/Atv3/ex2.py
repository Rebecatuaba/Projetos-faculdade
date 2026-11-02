#Exibir o total da soma obtido dos cem primeiros números inteiros (1+2+3+4+5+.....+97+98+99+100).

n = 1
soma = 0

while n <= 100:
    soma += n
    n += 1

print(f"A soma dos 100 primeiros números inteiros é: {soma}")