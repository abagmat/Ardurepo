const int buzzerPin = 8;    // вывод динамика
const int count = 50;       // количество импульсов
const int pause1 = 3;       // длина высокого уровня
const int pause2 = 3;       // длина низкого уровня
const int sleep = 1000;     // пауза между сериями

// Функция настройки при включении (однократно)
void setup()
{
  // Настроить вывод buzzerPin на выход сигнала (OUTPUT)
  pinMode(buzzerPin, OUTPUT);
}

//--------------------------------------------------------------------------------------------
// Главная функция - кусок текста выполняется бесконечно
void loop()
{
  for (int i = 0; i < count; i++)     // цикл - количество импульсов
  {
    digitalWrite(buzzerPin, HIGH);    // подать высокий уровень (HIGH) на вывод buzzerPin
    delay(pause1);                    // подождать pause1 милисекунд
    digitalWrite(buzzerPin, LOW);     // подать низкий уровень (LOW) на вывод buzzerPin
    delay(pause2);                    // подождать pause2 милисекунд
  }
  delay(sleep);                       // пауза перед тем как начать серию импульсов еще раз
}
