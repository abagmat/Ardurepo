const int motorPinA = 8;            // вывод двигателя
const int motorPinB = 9;            // вывод двигателя

// Функция настройки при включении (однократно)
void setup()
{
  pinMode(motorPinA, OUTPUT);
  pinMode(motorPinB, OUTPUT);
  
  digitalWrite(motorPinA, HIGH);
  digitalWrite(motorPinB, LOW);
}

void loop()
{
}
