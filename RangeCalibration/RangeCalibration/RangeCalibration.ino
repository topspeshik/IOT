#define ITERATIONS 500

class Ultra_sensor_distance
{
  uint8_t pin_trig;
  uint8_t pin_echo;
  
public:
  Ultra_sensor_distance(uint8_t _pin_trig = 12, uint8_t _pin_echo = 11)
  {
    this->pin_trig = _pin_trig;
    this->pin_echo = _pin_echo;
    
    pinMode(_pin_trig, OUTPUT);
    pinMode(_pin_echo, INPUT);
  }

  float get_distance()
  {
    long duration;
    float distance_cm;
    
    // Сначала генерируем короткий импульс длительностью 2-5 микросекунд.

    digitalWrite(this->pin_trig, LOW);
    delayMicroseconds(5);
    digitalWrite(this->pin_trig, HIGH);

    // Выставив высокий уровень сигнала, ждем около 10 микросекунд. В этот момент датчик будет посылать сигналы с частотой 40 КГц.
    delayMicroseconds(10);
    digitalWrite(this->pin_trig, LOW);

    //  Время задержки акустического сигнала на эхолокаторе.
    duration = pulseIn(this->pin_echo, HIGH);

    // Теперь осталось преобразовать время в расстояние
    distance_cm = (duration / 2) / 29.1;
    
    return distance_cm;
  }
};

class IK_sensor_distance
{
  float last_depend = 0.0;
  
public:
  IK_sensor_distance()
  {
    pinMode(A0, INPUT);
  }

  float get_distance(float K = 12.298)
  {
    float distance_cm = 0.0;

    int16_t analog_value  = analogRead(A0);
    last_depend = analog_value * 0.0048828125;
    last_depend = pow(last_depend, -1.10);
    distance_cm = K * last_depend;

    return distance_cm;
 }

 float calibrate_K(const float ideal_distance)
 {
    float k = ideal_distance / this->last_depend;
    return k;
 }
};

Ultra_sensor_distance u_sensor;
IK_sensor_distance ik_sensor;

float K = 1.0;
  
void setup()
{
  Serial.begin (9600);  

  Serial.println("Calibrate start!");

  float d1 = u_sensor.get_distance();
  float d2 = ik_sensor.get_distance(K);
  int iterations = 0;
  bool is_first_iteration = true;

  while (iterations < ITERATIONS)
  {
    do
    {
      d1 = u_sensor.get_distance();
      d2 = ik_sensor.get_distance(K);
    } while (d1 > 80);
    
    Serial.print("d1 = ");
    Serial.println(d1);
    Serial.print("d2 = ");
    Serial.println(d2);
    Serial.print("K = ");
    
    if (is_first_iteration)
    {
      K = ik_sensor.calibrate_K(d1);
      is_first_iteration = false;
    }
    else
    {
      K = (K + ik_sensor.calibrate_K(d1)) / 2.0;
    }
    
    Serial.println(K);
  
    delay(50);

    ++iterations;
  }

  Serial.println("Calibrate is finished!");

  delay(500);
}

void loop()
{
  float cm_1 = u_sensor.get_distance();
  Serial.print("Показание ултрадатчика: ");
  Serial.print(cm_1);
  Serial.println(" см.");
  
  float cm_2 = ik_sensor.get_distance();
  Serial.print("Показание ik датчика:  ");
  Serial.print(cm_2);
  Serial.println(" см.");
  
  // Задержка между измерениями для корректной работы скеча
  delay(750);
}
