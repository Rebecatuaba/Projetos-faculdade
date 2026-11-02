# Este código abre a câmera e mostra o vídeo em tempo real só que em preto em branco

import cv2

# Cria um objeto que representa a câmera (0 = câmera padrão do computador)
cap = cv2.VideoCapture(0)

# Loop que vai rodar continuamente enquanto a câmera estiver aberta
while True:
    # Lê um frame da câmera
    # 'ret' indica se a leitura deu certo (True ou False)
    # 'frame' é a imagem capturada no momento
    ret, frame = cap.read()

    # Se não conseguiu capturar um frame, interrompe o loop
    if not ret:
        break

    # Converte o frame colorido (BGR) para preto e branco (escala de cinza)
    # Isso é útil para economizar processamento ou destacar formas e bordas
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Mostra a imagem original capturada pela câmera
    cv2.imshow("Original", frame)

    # Mostra a imagem convertida em preto e branco
    cv2.imshow("Preto e Branco", gray)

    # Espera 1 milissegundo e verifica se a tecla ESC (código 27) foi pressionada
    # Se for, o loop é encerrado
    if cv2.waitKey(1) & 0xFF == 27:
        break

# Libera o acesso à câmera (importante para não travar o dispositivo)
cap.release()

# Fecha todas as janelas abertas pelo OpenCV
cv2.destroyAllWindows()
