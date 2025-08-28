const int ledPin1 = 12;     // вывод светодиода1
const int ledPin2 = 11;     // вывод светодиода2
const int ledPin3 = 10;     // вывод светодиода3
const int ledPin4 = 9;      // вывод светодиода4
const int ledPin5 = 8;      // вывод светодиода5
const int pause = 300;		// пауза между шагами

// Функция настройки при включении (однократно)
void setup()
{
  // Настроить выводы ledPinX на выход сигнала (OUTPUT)
  pinMode(ledPin1 , OUTPUT);
  pinMode(ledPin2 , OUTPUT);
  pinMode(ledPin3 , OUTPUT);
  pinMode(ledPin4 , OUTPUT);
  pinMode(ledPin5 , OUTPUT);
}

//--------------------------------------------------------------------------------------------
// Главная функция - кусок текста повторяется бесконечно
void loop()
{
  lightOn(ledPin1);
  lightOn(ledPin2);
  lightOn(ledPin3);
  lightOn(ledPin4);
  lightOn(ledPin5);
  lightOn(ledPin5);
  lightOn(ledPin4);
  lightOn(ledPin3);
  lightOn(ledPin2);
  lightOn(ledPin1);
}

void lightOn(int ledPin)
{
  digitalWrite(ledPin1, ledPin1 == ledPin ? HIGH : LOW);
  digitalWrite(ledPin2, ledPin2 == ledPin ? HIGH : LOW);
  digitalWrite(ledPin3, ledPin3 == ledPin ? HIGH : LOW);
  digitalWrite(ledPin4, ledPin4 == ledPin ? HIGH : LOW);
  digitalWrite(ledPin5, ledPin5 == ledPin ? HIGH : LOW);
  delay(pause);
}