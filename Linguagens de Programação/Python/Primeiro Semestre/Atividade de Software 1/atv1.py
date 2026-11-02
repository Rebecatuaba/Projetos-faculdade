#Ex.1
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
