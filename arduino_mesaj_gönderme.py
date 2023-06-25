import serial
import time

ser = serial.Serial('COM4', 9600)

def send_code(code):
    ser.write(code.encode('utf-8'))

while True:
    code = input("Arduino'ya gönderilecek kodu girin: ")
    send_code(code)
    time.sleep(2)
