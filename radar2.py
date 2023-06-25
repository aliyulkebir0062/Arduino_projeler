import serial
import numpy as np
import matplotlib.pyplot as plt

ser = serial.Serial('COM4', 9600)

plt.ion()
fig = plt.figure()
ax = fig.add_subplot(111)
#sınırları ayarlayın
ax.set_xlim([0, 360])  #Xekseni 
ax.set_ylim([0, 200])  #Yekseni
ax.set_xlabel('Açı (derece)')
ax.set_ylabel('Mesafe (cm)')
ax.grid(True)

while True:
    data = ser.readline().decode().rstrip()
    distance = float(data)
    
    print("Mesafe: {} cm".format(distance))
    
    angle = np.random.uniform(0, 360)
    
    ax.clear()
    ax.plot([angle], [distance], 'ro')
    
    ax.set_xticks([0, 90, 180, 270, 360])  # Açı etiketlerini ayarla
    ax.set_yticks([50, 100, 150, 200])  # Mesafe etiketlerini ayarla
    
    plt.draw()
    plt.pause(0.001)
