import serial
import matplotlib.pyplot as plt

ser = serial.Serial('COM4', 9600)


plt.ion()
fig, ax = plt.subplots()
x = []
y = []

while True:
    data = ser.readline().decode().rstrip()
    distance = float(data)
    
    print("Mesafe: {} cm".format(distance))
    
    x.append(len(x) + 1)
    y.append(distance)
    
    ax.clear()
    ax.plot(x, y)
    ax.set_xlabel('Ölçüm')
    ax.set_ylabel('Mesafe (cm)')
    ax.set_title('Radar Uygulaması')
    
    plt.draw()
    plt.pause(0.001)
