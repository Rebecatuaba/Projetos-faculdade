#Calcular a quantidade de litros de combustível gasta numa viagem, utilizando- se um automóvel que faz 12Km por litro. 
#Para obter o cálculo, o usuário deverá fornecer o tempo gasto na viagem e a velocidade média durante a mesma. 
#Assim, será possível calcular a distância percorrida com a fórmula: DISTÂNCIA <- TEMPO * VELOCIDADE. 
#Tendo o valor da distância, calcule a quantidade de litros de combustível usada na viagem com a fórmula: 
#LITROS_USADOS <- DISTÂNCIA / 12. O programa deverá exibir os valores da velocidade média, tempo gasto na viagem,
# a distância percorrida e a quantidade de litros usada na viagem.

#variaveis
tempoGasto = float(input("Digite o tempo gasto na viagem (horas): "))
velocidadeM = float(input("Digite a velocidade média (km/h): "))

#calculo da distância
distancia = tempoGasto * velocidadeM
# Calculo da quantidade de litros de combustível usada
litros_usados = distancia / 12  

# Exibe os resultados
print("\nResultados da viagem:")
print(f"Velocidade média: {velocidadeM} km/h")
print(f"Tempo gasto: {tempoGasto} horas")
print(f"Distância percorrida: {distancia} km")
print(f"Combustível gasto: {litros_usados:.2f} litros")
