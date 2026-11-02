def remove_acentos(palavra):
    acentos = "áàãâäéèêëíìîïóòõôöúùûüç"
    sem_acentos = "aaaaaeeeeiiiiooooouuuuc"
    palavra_sem_acentos = ""
    for letra in palavra.lower():
        if letra in acentos:
            indice = acentos.index(letra)
            palavra_sem_acentos += sem_acentos[indice]
        else:
            palavra_sem_acentos += letra
    return palavra_sem_acentos

def eh_palindromo(palavra):
    palavra = remove_acentos(palavra)
    return palavra == palavra[::-1]

print(eh_palindromo("radar"))     # True
print(eh_palindromo("Python"))    # False
print(eh_palindromo("Arara"))     # True
print(eh_palindromo("Açaí"))      # False
print(eh_palindromo("óó"))        # True 
