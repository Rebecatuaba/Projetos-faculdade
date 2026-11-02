#Uma loja petshop precisa de um programa para calcular os custos de criação de coelhos. O custo é calculado com a fórmula: 
#CUSTO <- (NR_COELHOS * 0.70)/18 + 10. O programa deve atribuir o valor para a variável NR_COELHOS e exibir o valor da variável CUSTO.

#variaveis
numeroCoelhos = float(input("Digite o número de coelhos: "))

#calculo
custo = (numeroCoelhos * 0.70)/18 + 10

#resultado
print("\nResultado do custo da criação de coelho:")
print(f"Custo: {custo}")