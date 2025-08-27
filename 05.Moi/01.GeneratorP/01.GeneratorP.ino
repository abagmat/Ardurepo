const long freq = 1000;       // Частота Hz, 1000 Гц (1 кГц)
const int outputPin = 9;      // Пин OC1A на Arduino Uno

void setup() {
  // Устанавливаем пин в режим OUTPUT
  pinMode(outputPin, OUTPUT);

  // Настраиваем Timer1
  TCCR1A = 0; // Сброс регистров TCCR1A и TCCR1B
  TCCR1B = 0; 
  
  // Установка режима CTC (Clear Timer on Compare Match)
  // WGM12 = 1
  TCCR1B |= (1 << WGM12); 

  // Установка делителя (prescaler). 
  // Выбираем делитель 8 для широкого диапазона частот.
  // Это даёт частоту таймера 16 МГц / 8 = 2 МГц
  TCCR1B |= (1 << CS11); 

  // Вычисление значения для регистра OCR1A на основе желаемой частоты
  // Formula: OCR1A = (F_CPU / prescaler / (2 * freq)) - 1
  // OCR1A = (16000000 / 8 / (2 * freq)) - 1
  const long ocrValue = (16000000L / 8L / (2L * freq)) - 1L;
  OCR1A = ocrValue; 

  // Включение режима переключения OC1A (Toggle on Compare Match)
  // COM1A0 = 1. Это заставит пин 9 переключать состояние (HIGH/LOW) при совпадении.
  TCCR1A |= (1 << COM1A0); 
}

void loop() {
  // Основной цикл loop() пуст, так как генерация импульсов
  // происходит аппаратно в фоновом режиме
}
