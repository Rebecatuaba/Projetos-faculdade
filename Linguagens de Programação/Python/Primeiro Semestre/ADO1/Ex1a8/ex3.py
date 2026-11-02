#Receber uma temperatura em graus Fahrenheit (valor direto na variável) e exibi-la convertida em graus Centígrados, com a fórmula: 
#C <- (((F-32) * 5) / 9), onde F é a temperatura em Fahrenheit e C em Centígrados.

#variaveis
temperaturaF = float(input("Digite a temperatura em Fahrenheit: "))

#calculo da conversão de temperatura
temperaturaC = ((temperaturaF - 32)*5)/9

# Exibe os resultados
print("\nResultados da Conversão:")
print(f"Temperatura em Centígrados: {temperaturaC}°C")