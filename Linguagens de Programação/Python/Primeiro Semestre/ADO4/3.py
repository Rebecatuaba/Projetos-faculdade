import matplotlib.pyplot as plt
import numpy as np # facilita trabalhar com listas numéricas e criar sequências de números.

def funcao_quadratica(x):
    return x**2 - 4*x + 3

# Criar um array de valores de x de -2 até 6, com passo 0.5
x_values = np.arange(-2, 6.5, 0.5)  # 6.5 pra incluir o 6

# Calcular f(x) para cada valor de x
y_values = funcao_quadratica(x_values)

# Plotar
plt.plot(x_values, y_values, marker='o')
plt.title('Gráfico de f(x) = x² - 4x + 3')
plt.xlabel('x')
plt.ylabel('f(x)')
plt.grid(True)
plt.show()
