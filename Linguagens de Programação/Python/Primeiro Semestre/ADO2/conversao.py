#Fazer um programa em Python que converta temperatura Celsius em temperatura  Fahrenheit. Fazer a conversão das seguintes temperaturas:
#50 C, 70 C, 90 C, 102 C, 225 C, 376 C, 490 C e 800 C
#Elaborar um arquivo PDF com nome do estudante, código Python da solução do problema e uma tabela com as temperaturas em Fahrenheit.

#variaveis
celsius1 = float(input("Digite uma temperatura em Celsius: "))
celsius2 = float(input("Digite uma segunda temperatura em Celsius: "))
celsius3 = float(input("Digite uma terceira temperatura em Celsius: "))
celsius4 = float(input("Digite uma quarta temperatura em Celsius: "))
celsius5 = float(input("Digite uma quinta temperatura em Celsius: "))
celsius6 = float(input("Digite uma sexta temperatura em Celsius: "))
celsius7 = float(input("Digite uma sétima temperatura em Celsius: "))
celsius8 = float(input("Digite uma oitava temperatura em Celsius: "))

#conversao
F1 = (celsius1*1.8)+32
F2 = (celsius2*1.8)+32
F3 = (celsius3*1.8)+32
F4 = (celsius4*1.8)+32
F5 = (celsius5*1.8)+32
F6 = (celsius6*1.8)+32
F7 = (celsius7*1.8)+32
F8 = (celsius8*1.8)+32

#resultado
print("\nResultado das conversões de Celsius p/ Fahrenheint:")
print(f"Conversão de {celsius1}°C: {F1}°F")
print(f"Conversão de {celsius2}°C: {F2}°F")
print(f"Conversão de {celsius3}°C: {F3}°F")
print(f"Conversão de {celsius4}°C: {F4}°F")
print(f"Conversão de {celsius5}°C: {F5}°F")
print(f"Conversão de {celsius6}°C: {F6}°F")
print(f"Conversão de {celsius7}°C: {F7}°F")
print(f"Conversão de {celsius8}°C: {F8}°F")