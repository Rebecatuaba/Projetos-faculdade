lista1 = [2, 5, 8]
lista2 = [5, 2, 8]
lista3 = [3, 2, 1]

def em_ordem(lista):
    for i in range(len(lista) - 1):
        if lista[i] > lista[i + 1]:
            return False
    return True

def em_ordem_descrescente(lista):
    for i in range(len(lista) - 1):
        if lista[i] < lista[i + 1]:
            return False
    return True

print("em_ordem(lista1):", em_ordem(lista1))  # True
print("em_ordem(lista2):", em_ordem(lista2))  # False
print("em_ordem(lista3):", em_ordem(lista3))  # False

if not em_ordem(lista1):
    print("em_ordem_descrescente(lista1):", em_ordem_descrescente(lista1))  # False
if not em_ordem(lista2):
    print("em_ordem_descrescente(lista2):", em_ordem_descrescente(lista2))  # False
if not em_ordem(lista3):
    print("em_ordem_descrescente(lista3):", em_ordem_descrescente(lista3))  # True
