#Uma Universidade tem problemas com arredondamento das médias dos alunos, pois cada professor estipula um critério de arredondamento. 
#Devemos elaborar um programa, para a secretaria da Universidade, resolvendo esse problema. O programa deve solicitar uma nota e fazer o devido arredondamento. 
#Regras: Notas que ultrapassem 0,5 de resto serão arredondas para CIMA. Ex: 4,6 –>5,0 Notas que abaixo ou igual a 0,5 de resto serão arredondas para BAIXO. Ex: 4,5 –> 4,0

#variaveis
notaDigitada = float(input("Digite a sua nota: "))
parteInt = int(notaDigitada)
resto = notaDigitada - parteInt

if (resto > 0.5):
    notaFinal = parteInt + 1
    print(f"Nota arredondada igual a: {notaFinal} ")
else:
    if (resto <= 0.5):
     notaFinal = parteInt
     print(f"Nota arredondada igual a: {notaFinal} ")
