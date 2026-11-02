def dobro(x):
    return 2*x
    
def incrementa(x):
    return x + 1
    
def composta(x):
    return incrementa(dobro(x))
    
print(composta(3))  #2.3=6+1=7
print(composta(0))  #2.0=0+1=1 
print(composta(-1)) # 2.-1 =-2 +1 =-1
