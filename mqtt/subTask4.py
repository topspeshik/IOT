from http import client
import time
import paho.mqtt.client as mqtt_client
import random
import serial
from statistics import mean

que = []


def get_connection(port):
    ser = serial.Serial(port, timeout=1)
    return ser


def task4(client, userdata, message):
    data = int(message.payload.decode("utf-8"))
    que.append(data)
    if len(que) >= 100:
        print(mean(que[:50]), " ", mean(que[50:]))
        if (mean(que[:50]) > mean(que[50:])):
            ser.write(bytearray([1]))
        else:
            ser.write(bytearray([0]))
        que.clear()




broker = "broker.emqx.io"

client = mqtt_client.Client(f'lab_{random.randint(10000, 99999)}')
client.on_message = task4

try:
    client.connect(broker)
except Exception:
    print('Failed to connect. Check network.')
    exit()

client.loop_start()
client.subscribe("lab/4881/photo/instant")
print("Sub")
ser = get_connection('COM10')

time.sleep(600)
client.disconnect()
client.loop_stop()
print('Stop communcation'