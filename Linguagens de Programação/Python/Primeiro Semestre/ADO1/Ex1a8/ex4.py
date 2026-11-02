#Calcular e exibir o valor do volume de uma lata de óleo, usando a fórmula: VOLUME <- 3.14159 * R * R * ALTURA.

#variaveis
pi = 3.14159
raio = float(input("Digite o valor do raio da lata: "))
altura = float(input("Digite o valor da altura da lata: "))

#calculo do volume
volume = pi*raio*raio*altura

#resultado
print("\nResultado do volume da lata de óleo:")
print(f"Volume:{volume}")