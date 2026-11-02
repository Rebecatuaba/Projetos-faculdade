# Importa OpenCV e NumPy (para manipular arrays)
import cv2
import numpy as np

# Abre a webcam
cap = cv2.VideoCapture(0)

while True:
    # Captura o frame
    ret, frame = cap.read()
    if not ret:
        break

    # Converte o frame de BGR para HSV (melhor para trabalhar com cores)
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    # Define o intervalo da cor a ser detectada (exemplo: azul)
    lower_blue = np.array([100, 150, 50])
    upper_blue = np.array([140, 255, 255])

    # Cria uma máscara que deixa apenas a cor azul visível
    mask = cv2.inRange(hsv, lower_blue, upper_blue)

    # Aplica a máscara na imagem original
    result = cv2.bitwise_and(frame, frame, mask=mask)

    # Mostra a imagem original e o resultado da detecção
    cv2.imshow("Original", frame)
    cv2.imshow("Rastreio de Azul", result)

    # Sai com ESC
    if cv2.waitKey(1) & 0xFF == 27:
        break

cap.release()
cv2.destroyAllWindows()
