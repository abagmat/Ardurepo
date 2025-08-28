const int ledPin = 9;       // вывод светодиода
const int pause = 30;       // пауза между шагами

// Функция настройки при включении (однократно)
void setup()
{
  // Настроить вывод ledPin на выход сигнала (OUTPUT)
  pinMode(ledPin , OUTPUT);
}

//--------------------------------------------------------------------------------------------
// Главная функция - кусок текста повторяется бесконечно
void loop()
{
  for (int value = 0 ; value <= 255; value += 5)
  {
    analogWrite(ledPin, value);
    delay(pause);
  }
  for (int value = 255 ; value >=0; value -= 5)
  {
    analogWrite(ledPin, value);
    delay(pause);
  }
}
