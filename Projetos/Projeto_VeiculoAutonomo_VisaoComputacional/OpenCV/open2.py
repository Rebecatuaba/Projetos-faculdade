# Este código abre a câmera e mostra o vídeo em tempo real

import cv2

# Cria um objeto que representa a câmera
# O número (0) indica a câmera padrão do computador
# Se você tiver mais de uma câmera, pode testar 1, 2, etc.
cap = cv2.VideoCapture(0)

# Inicia um loop que vai rodar continuamente enquanto a câmera estiver ligada
while True:
    # 'ret' indica se o frame foi lido com sucesso (True ou False)
    # 'frame' contém a imagem atual capturada pela câmera
    ret, frame = cap.read()

    # Se 'ret' for False (erro ao capturar imagem), o loop é interrompido
    if not ret:
        break

    # Mostra o frame atual em uma janela chamada "Camera ao vivo"
    cv2.imshow("Camera ao vivo", frame)

    # Espera 1 milissegundo e verifica se a tecla ESC (código 27) foi pressionada
    # Se for, o loop é encerrado
    if cv2.waitKey(1) & 0xFF == 27:
        break

# Libera o acesso à câmera (importante para não travar o dispositivo)
cap.release()

# Fecha todas as janelas abertas pelo OpenCV
cv2.destroyAllWindows()
