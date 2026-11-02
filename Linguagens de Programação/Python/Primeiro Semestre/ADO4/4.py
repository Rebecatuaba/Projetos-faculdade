def funcao_linear(x):
    return 2*x + 1

def funcao_quadratica(x):
    return x**2

def funcao_exponencial(x):
    return 2.0**x

# Valores de x de -2 a 4, de 1 em 1
x_values = np.arange(-2, 5, 1)  # vai até 4

# Calcular y
y_linear = funcao_linear(x_values)
y_quadratica = funcao_quadratica(x_values)
y_exponencial = funcao_exponencial(x_values)

# Plotar
plt.plot(x_values, y_linear, marker='o', color='#FF5AA1', label='Função Linear: 2x + 1')
plt.plot(x_values, y_quadratica, marker='o', color='yellow', label='Função Quadrática: x²')
plt.plot(x_values, y_exponencial, marker='o', color='#3784E0', label='Função Exponencial: 2^x')
plt.title('Gráficos!!!!')
plt.xlabel('x')
plt.ylabel('f(x)')
plt.grid(True)
plt.legend()
plt.show()
