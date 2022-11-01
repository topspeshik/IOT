#define sensor_pin A5

void setup()
{
    pinMode(sensor_pin, INPUT);
    Serial.begin(9600);
}

void loop()
{
    int val = int(analogRead(sensor_pin) / 10.24);
    Serial.write(val);
    delay(50);
}
