#Digitar um número inteiro entre 0 e 100, informar o quanto ele está distante de um determinado número chave, carregado no próprio programa. 
#Ex.: Número chave=20, número digitado=15, resposta=5. Número chave=17, número digitado=20, resposta=3 (Obs.: a resposta deverá ser sempre um número positivo).

#varaveis
numeroInteiro = int(input("Digite um número inteiro entre 0 e 100"))
numeroChave = 88
resposta = 0

#calculo
if (numeroInteiro >= numeroChave):
 resposta = numeroInteiro - numeroChave
 print  ("A distância entre", numeroChave, "e", numeroInteiro, "é de:", resposta)
else:
 resposta = numeroChave - numeroInteiro
 print  ("A distância entre", numeroChave, "e", numeroInteiro, "é de:", resposta)


 