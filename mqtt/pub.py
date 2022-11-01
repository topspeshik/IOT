import time
import paho.mqtt.client as mqtt_client
import serial

def get_connection(port):
    ser = serial.Serial(port, timeout=1)
    return ser


client = mqtt_client.Client()

broker = "broker.emqx.io"
try:
    client.connect(broker)
except Exception:
    print('Failed to connect, check network')
    exit()

ser = get_connection('COM3')

que = []

while True:
    if ser.in_waiting > 0:
        data = ser.read(1)
        client.publish("lab/4881/photo/instant", data[0])
        que.append(data[0])
        if len(que) >= 100:
            client.publish("lab/4881/photo/averge", sum(que)/len(que))
            client.publish("lab/4881/photo/max", max(que))
            client.publish("lab/4881/photo/mix", min(que))

            que = []
    time.sleep(0.01)
