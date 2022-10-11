import paho.mqtt.client as mqtt_client
import random
import time
import serial

broker = "broker.emqx.io"

client = mqtt_client.Client(f'lab_{random.randint(10000,99999)}')
client.connect(broker)

while True:
    client.publish('lab/room15/sensor', "")
