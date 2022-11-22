import time
import serial


def get_connection(port):
    ser = serial.Serial(port, timeout=1)
    return ser


ser = get_connection('COM13')

while True:
    if ser.in_waiting > 0:
        data = ser.read(2)
        print(data[0], data[1])
