#4- Interseção de listas: Crie uma script que retorne os elementos comuns entre duas listas.
#lista_a = [1, 2, 3, 4, 5]
#lista_b = [4, 5, 6, 7, 8]
# Saída: [4, 5]

lista_a = [1, 2, 3, 4, 5]
lista_b = [4, 5, 6, 7, 8]

um_elemento_comum	= False

for i in range(len(lista_a)):
    for j in range(len(lista_b)):
        if (lista_a[i] == lista_b[j]):
            um_elemento_comum	= True # há elemento comum
            print(str(lista_a[i]))
            
if not um_elemento_comum: print("Não tem elemento comum.")


