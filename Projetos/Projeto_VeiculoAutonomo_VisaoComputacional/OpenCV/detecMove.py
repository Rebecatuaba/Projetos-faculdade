import cv2

# Abre a webcam
cap = cv2.VideoCapture(0)

# Captura o primeiro frame para referência
ret, frame1 = cap.read()
frame1_gray = cv2.cvtColor(frame1, cv2.COLOR_BGR2GRAY)
frame1_gray = cv2.GaussianBlur(frame1_gray, (21, 21), 0)

while True:
    ret, frame2 = cap.read()
    if not ret:
        break

    # Converte o frame atual para cinza e aplica borrão
    gray = cv2.cvtColor(frame2, cv2.COLOR_BGR2GRAY)
    gray = cv2.GaussianBlur(gray, (21, 21), 0)

    # Calcula a diferença absoluta entre os frames
    diff = cv2.absdiff(frame1_gray, gray)

    # Aplica threshold para destacar movimento
    _, thresh = cv2.threshold(diff, 25, 255, cv2.THRESH_BINARY)

    # Dilata a imagem para preencher buracos
    thresh = cv2.dilate(thresh, None, iterations=2)

    # Mostra a diferença
    cv2.imshow("Movimento", thresh)
    cv2.imshow("Original", frame2)

    # Atualiza o frame de referência
    frame1_gray = gray

    if cv2.waitKey(1) & 0xFF == 27:
        break

cap.release()
cv2.destroyAllWindows()
