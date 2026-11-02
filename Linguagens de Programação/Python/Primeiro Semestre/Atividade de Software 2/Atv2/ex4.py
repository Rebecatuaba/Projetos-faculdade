# Faça um programa que leia 3 números e exiba:O maior número;O menor número;O número do meio

#variaveis
numero1 = int(input("Digite um número: "))
numero2 = int(input("Digite um segundo número: "))
numero3 = int(input("Digite um terceiro número: "))

#nMaior
if numero1 >= numero2 and numero1 >= numero3:
    maior = numero1
elif numero2 >= numero1 and numero2 >= numero3:
    maior = numero2
else:
    maior = numero3

#nMenor
if numero1 <= numero2 and numero1 <= numero3:
    menor = numero1
elif numero2 <= numero1 and numero2 <= numero3:
    menor = numero2
else:
    menor = numero3

#nMeio
meio = numero1 + numero2 + numero3 - maior - menor

print(f"O maior número é {maior}")
print(f"O número do meio é {meio}")
print(f"O menor número é {menor}")
 

