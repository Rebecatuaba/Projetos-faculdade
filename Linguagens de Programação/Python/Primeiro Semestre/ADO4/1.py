def pares_ate(n):
    pares = []
    for num in range(n + 1):
        if num % 2 == 0:
            pares.append(num)
    return pares        
print("\nResultado:")   
print(pares_ate(8))       