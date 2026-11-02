# Exibir todos os números divisíveis por 4 que sejam menores que 200. Use a instrução Se dentro da malha do programa. A variável Contador deverá iniciar com o valor 1.

contador = 1

while contador < 200:
    if contador % 4 == 0: # o resto da divisao deve ser igual a zero 
        print(contador)
    contador += 1 
