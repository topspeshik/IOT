from ast import Not
from http import client
import time
from xmlrpc.client import MAXINT
import paho.mqtt.client as mqtt_client
import random
import serial
from statistics import mean

que = []
max_value = 0
min_value = 0

def get_connection(port):
    ser = serial.Serial(port, timeout=1)
    return ser


def task5(client, userdata, message):
    global min_value
    global max_value
    data = int(message.payload.decode("utf-8"))
    topic = message.topic
    if topic == "lab/4881/photo/max":
        max_value = data
    if topic == "lab/4881/photo/min":
        min_value = data
    
    if topic == "lab/4881/photo/instant":
        print("hui")
        
        if data > (min_value + max_value) / 2:

            ser.write(bytearray([1]))

        else:

            ser.write(bytearray([0]))





broker = "broker.emqx.io"

client = mqtt_client.Client(f'lab_{random.randint(10000, 99999)}')
client.on_message = task5


try:
    client.connect(broker)
except Exception:
    print('Failed to connect. Check network.')
    exit()

client.loop_start()
client.subscribe("lab/4881/photo/max")
client.subscribe("lab/4881/photo/min")
client.subscribe("lab/4881/photo/instant")

print("Sub")
ser = get_connection('COM10')

time.sleep(600)
client.disconnect()
client.loop_stop()
print('Stop communcation')