# Faça um programa que lê uma string e imprime “Palíndromo” caso a string seja um palíndromo e “Não é palíndromo” caso não seja.
#Assuma que a entrada não tem acentos e que todas as letras são minúsculas.
#Obs: Um palíndromo é uma palavra ou frase, que é igual quando lida da esquerda para a direita ou da direita para a esquerda 
#(espaços em brancos são descartados).
#Exemplos de palíndromo: “ovo”, “reviver”, “mega bobagem”, “anotaram a data da maratona”

texto = input("Digite um texto: ")# remove os espaços em branco

texto = texto.replace(" ","")# inverte a string

texto_inverso = texto[::-1]# verifica se texto é igual ao texto_inverso

if (texto == texto_inverso):
    print("Palíndromo")
else:
    print("Não é palíndromo")