#Faça o programa que calcule o salário líquido dos funcionários de uma empresa. O salário líquido é composto por descontos e adicionais, seguindo as seguintes regras: 
#Descontos: Salário bruto < 800,00 – não realizar nenhum desconto; 800,00 <= Salário bruto <=1600,00 – descontar 8% de Imposto de Renda e 5% de encargos.
#>1600,00 – descontar 15% de Imposto de Renda e 7% de encargos.
#Adicionais: Caso o funcionário tenha trabalhado mais de 160 horas no mês, divida o seu salário bruto por 160 (representa horas trabalhadas) e calcule 50% 
#de adicional nas horas que excederam a 160. O usuário deverá digitar o salário bruto e o número de horas trabalhadas no mês de cada funcionário, e deverá receber
#como resultado o salário líquido. 

#variaveis
salarioBruto = (float(input("Digite seu salário bruto: ")))
horaTB = (float(input("Digite a quantidade de horas trabalhadas: ")))
salarioLiq = 0

#calculo descontos
if salarioBruto < 800.00:
    salarioLiq = salarioBruto
elif 800.00 <= salarioBruto <= 1600.00:
    salarioLiq = salarioBruto - (salarioBruto * 8 / 100) - (salarioBruto * 5/100)
else:
    salarioLiq = salarioBruto - (salarioBruto * 15/100) - (salarioBruto * 7/100)

#calculo adi
if horaTB > 160:
    valorHora = salarioBruto / 160 
    horasExtras = horaTB - 160  
    adicional = horasExtras * (valorHora * 1.5)  
    salarioLiq += adicional  

print(f"Seu salário Líquido é de: {salarioLiq}")
