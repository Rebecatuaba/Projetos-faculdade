# Exibir todos os valores numéricos inteiros ímpares situados na faixa de 0 a 20. Para verificar se o número é ímpar, efetuar dentro da malha a verificação 
# lógica dessa condição com a instrução SE, perguntando se o número é ímpar, sendo, exiba-o, não sendo, passe para o próximo passo.

n = 0

while n <= 20:
    if n % 2 != 0: # o resto da divisao nao deve ser igual a zero, pq ai vai ser impar
        print(n)
    n += 1    

