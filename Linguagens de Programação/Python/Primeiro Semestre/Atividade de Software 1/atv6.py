#Ex.6
#variaveis
valor = float(input("Digite um valor: "))
taxa = float(input("Digite o valor da taxa: "))
tempo = float(input("Digite o tempo: "))

#calculo
prestação = (valor + (valor * (taxa / 100))) * tempo

#resultado
print("\nCalculo da prestação atrasada:")
print(f"Valor da Prestação:{prestação} ")