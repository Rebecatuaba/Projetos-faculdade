#Este código abre uma Imagem

import cv2 # Importa a biblioteca OpenCV (usada para processar imagens e vídeos)

# Lê a imagem chamada "imagem_teste.jpg" e armazena em uma variável
# Essa imagem precisa estar na mesma pasta que este arquivo Python
# O resultado é uma matriz (array) com os valores dos pixels da imagem
img = cv2.imread("imagem_teste.jpeg")

# Mostra a imagem em uma janela com o nome "Minha imagem"
# O primeiro parâmetro é o nome da janela, e o segundo é a imagem que será exibida
cv2.imshow("Minha imagem", img)

# Espera o usuário apertar alguma tecla antes de continuar
# O número 0 significa "espere indefinidamente" até uma tecla ser pressionada
cv2.waitKey(0)

# Fecha todas as janelas abertas pelo OpenCV
cv2.destroyAllWindows()
