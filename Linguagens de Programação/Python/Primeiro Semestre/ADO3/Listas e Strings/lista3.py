#Misturar duas listas de forma intercalada, ou seja, pegue duas listas e embaralhe os elementos intercalando um de cada 
# (ex: [1, 2], [A, B] → [1, A, 2, B]).

lista1 = [1, 2, 3, 4]
lista2 = ["A", "B", "C", "D"]

intercalar = []

for i in range(len(lista1)):# len esta vendo o tamanho da lista e o range as sua posições
    intercalar.append(lista1[i])
    intercalar.append(lista2[i])

print(intercalar)