#Transformar dois valores A e B, efetuar a troca dos mesmos de forma que a variável A passe a ter o valor da variável B e vice-versa. 
#Exibir os valores trocados.

#variaveis
A = input("Digite o valor de A: ")
B = input("Digite o valor de B: ")

#troca dos valores
A, B = B, A

#resultado
print("\nResultado da troca de valores:")
print(f"Valor de A:{A} ")
print(f"Valor de B:{B} ")