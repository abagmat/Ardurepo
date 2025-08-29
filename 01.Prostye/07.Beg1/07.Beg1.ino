const int ledPins[] = { 11, 10, 9, 6, 5 };   // вывод светодиодов
const int br_high = 255;					 // максимальная яркость
const int br_low = 127;						 // минимальная яркость
const int pause = 300;   		             // задержка

// Функция настройки при включении (однократно)
void setup()
{
  // Настроить выводы ledPins на выход сигнала (OUTPUT)
  for(auto pin : ledPins)
  {
    pinMode(pin , OUTPUT);
  }
}

//--------------------------------------------------------------------------------------------
// Главная функция - кусок текста повторяется бесконечно
void loop()
{
  lightOn(-2);
  lightOn(-1);
  lightOn(0);
  lightOn(1);
  lightOn(2);
  lightOn(3);
  lightOn(4);
  lightOn(5);
  lightOn(6);

  lightOn(6);
  lightOn(5);
  lightOn(4);
  lightOn(3);
  lightOn(2);
  lightOn(1);
  lightOn(0);
  lightOn(-1);
  lightOn(-2);
}

void lightOn(int index)
{
  static int count = int(sizeof(ledPins) / sizeof(ledPins[0]));
  for (int i = 0; i < count; i++)
  {
    int value = 0;
    if (i == index)
    {
      value = br_high;
    }
    else if (i == (index - 1) || i == (index + 1))
    {
      value = br_low;
    }
    analogWrite(ledPins[i], value);
  }
  delay(pause);
}