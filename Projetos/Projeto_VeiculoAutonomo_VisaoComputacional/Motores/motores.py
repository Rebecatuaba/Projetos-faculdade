import RPi.GPIO as GPIO
import time

# Definindo os pinos
IN1 = 17
IN2 = 18
ENA = 22

GPIO.setmode(GPIO.BCM)
GPIO.setup(IN1, GPIO.OUT)
GPIO.setup(IN2, GPIO.OUT)
GPIO.setup(ENA, GPIO.OUT)

# Configura o pino ENA como saída PWM (velocidade)
pwm = GPIO.PWM(ENA, 1000)  # 1000Hz
pwm.start(0)  # começa parado

def frente(velocidade):
    GPIO.output(IN1, GPIO.HIGH)
    GPIO.output(IN2, GPIO.LOW)
    pwm.ChangeDutyCycle(velocidade)

def tras(velocidade):
    GPIO.output(IN1, GPIO.LOW)
    GPIO.output(IN2, GPIO.HIGH)
    pwm.ChangeDutyCycle(velocidade)

def parar():
    GPIO.output(IN1, GPIO.LOW)
    GPIO.output(IN2, GPIO.LOW)
    pwm.ChangeDutyCycle(0)

try:
    print("Girando para frente...")
    frente(70)  # 70% da velocidade
    time.sleep(3)

    print("Girando para trás...")
    tras(70)
    time.sleep(3)

    print("Parando o motor.")
    parar()

finally:
    pwm.stop()
    GPIO.cleanup()
