# Ler um número N qualquer menor ou igual a 50 e exibir o valor obtido da multiplicação sucessiva de N por 3 enquanto o produto for menor que 250 (N*3, N*3*3, N*3*3*3, etc.)

N = int(input("Digite um número menor ou igual a 50: "))

if N <= 50:
    print(f"\nA multiplicação sucessiva de {N} por 3 enquanto for menor que 250 é:\n")
    while N < 250:
        mult = N * 3
        print(N)
        N *= 3
else:
    print("O número deve ser menor ou igual a 50, por favor tente novamente.")
   

