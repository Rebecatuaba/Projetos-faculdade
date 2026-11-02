#Este código identica objetos e pessoas

from ultralytics import YOLO  # importa a biblioteca Ultralytics YOLO
import cv2                     

# Carrega o modelo pré-treinado YOLOv8
# "yolov8n.pt" = versão nano, mais leve e rápida para testes
model = YOLO("yolov8n.pt")

cap = cv2.VideoCapture(0)

while True:
    # Captura um frame da webcam
    ret, frame = cap.read()
    if not ret:  # se não conseguir ler a câmera, sai do loop
        break

    # Passa o frame para o modelo YOLO detectar objetos
    results = model(frame)

    # 'plot()' desenha diretamente no frame as caixas delimitadoras,
    # nomes das classes e scores de confiança
    annotated_frame = results[0].plot()

    # Mostra a imagem com as detecções
    cv2.imshow("YOLOv8 - Detecção", annotated_frame)

    # Sai do loop se apertar ESC (código 27)
    if cv2.waitKey(100) & 0xFF == 27:
        break

# Libera a câmera e fecha as janelas
cap.release()
cv2.destroyAllWindows()
