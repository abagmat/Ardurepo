const int motorPinA = 8;            // вывод двигателя
const int motorPinB = 9;            // вывод двигателя

// Функция настройки при включении (однократно)
void setup()
{
  // Настроить вывод motorPinA на выход сигнала (OUTPUT)
  pinMode(motorPinA, OUTPUT);
  // Настроить вывод motorPinB на выход сигнала (OUTPUT)
  pinMode(motorPinB, OUTPUT);
}

//--------------------------------------------------------------------------------------------
// Главная функция - кусок текста повторяется бесконечно
void loop()
{
  // включить поворот двигателя в одну сторону
  digitalWrite(motorPinA, HIGH);    // вывод motorPinA высокий сигнал
  digitalWrite(motorPinB, LOW);     // вывод motorPinB низкий сигнал
  delay(2000);                      // пауза 2 сек.

  // выключить двигатель
  digitalWrite(motorPinA, LOW);     // вывод motorPinA низкий сигнал
  digitalWrite(motorPinB, LOW);     // вывод motorPinB низкий сигнал
  delay(500);                       // пауза 0.5 сек

  // включить поворот двигателя в другую сторону
  digitalWrite(motorPinA, LOW);     // вывод motorPinA низкий сигнал
  digitalWrite(motorPinB, HIGH);    // вывод motorPinB высокий сигнал
  delay(2000);                      // пауза 2 сек.

  // выключить двигатель
  digitalWrite(motorPinA, LOW);     // вывод motorPinA низкий сигнал
  digitalWrite(motorPinB, LOW);     // вывод motorPinB низкий сигнал
  delay(500);                       // пауза 0.5 сек
}
