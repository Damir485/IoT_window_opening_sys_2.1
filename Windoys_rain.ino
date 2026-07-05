
#define RELAY_OPEN 3                   // Подключаем реле на открытие
#define RELAY_CLOSE 4                  // Подключаем реле на закрытие
#define RAIN_SENSOR_INPUT 12           // Подключаем датчик дождя
const unsigned long waitTime = 90000;  // Время закрытия окна
void setup() {
  // Устанавливаем выходы и входы
  pinMode(RELAY_OPEN, OUTPUT);             
  pinMode(RELAY_CLOSE, OUTPUT);        
  pinMode(RAIN_SENSOR_INPUT, INPUT_PULLUP);
  //     Выключаем реле
  digitalWrite(RELAY_CLOSE, 1);        
  digitalWrite(RELAY_OPEN, 1);         
}

void loop() {
  // Считываем показания датчика
  if (digitalRead(RAIN_SENSOR_INPUT) == 0) {
    // Закрываем окно
    digitalWrite(RELAY_CLOSE, 0);
    delay(waitTime);
    // Выключаем реле
    digitalWrite(RELAY_CLOSE, 1);
  } else {
    digitalWrite(RELAY_CLOSE, 1);
  }
  // Ждем 100 милисекунд
  delay(100);
}
