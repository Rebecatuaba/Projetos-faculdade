#Formatação de nome completo. Peça o nome completo de uma pessoa e mostre: O nome em maiúsculas, o nome em minúsculas, quantas letras
#(desconsiderando espaços), quantas letras tem o primeiro nome

nome = input('Digite seu nome completo: ')

maiusculas = nome.upper()
minusculas = nome.lower()
print('Seu nome em maiúsculas é {}.'.format(maiusculas))
print('Seu nome em minúsculas é {}.'.format(minusculas))

remove = nome.strip() # remove espaços excedentes no início e no final de 'nome'
remove2 = remove.replace(' ', '') # substitui espaços pela 'falta de espaços', ''; aqui o nome será guardado sem espaços
contartodo = len(remove2) #conta as letras totais
nomelista = remove.split() #agora sim é uma lista, o primeiro nome ocupa a posição 'O', o segundo nome a posição '1' ...
contarprimeiro = len(nomelista[0])# para contar a quantidade de letras do primeiro nome preciso me referir à posição '0'
print('Seu nome completo é composto por {} letras.'.format(contartodo))
print('Sendo que o primeiro nome tem {} letras!'.format(contarprimeiro))