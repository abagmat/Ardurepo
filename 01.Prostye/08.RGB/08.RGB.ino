const int redPin = 11;        // вывод красного светодиода
const int greenPin = 10;      // вывод зеленого светодиода
const int bluePin = 9;        // вывод синего светодиода

// Функция настройки при включении (однократно)
void setup()
{
  pinMode(redPin, OUTPUT); 
  pinMode(greenPin, OUTPUT); 
  pinMode(bluePin, OUTPUT); 
}

//--------------------------------------------------------------------------------------------
// Главная функция - кусок текста повторяется бесконечно
void loop()
{
  // базовые цвета:  
  color(255, 0, 0);   // красный
  delay(500);  
  color(0, 255, 0);   // зеленый
  delay(500);  
  color(0, 0, 255);   // синий
  delay(500); 
  
  // смешанные цвета  
  color(255, 0, 252); // красный
  delay(500);  
  color(237, 109, 0); // оранжевый 
  delay(500);  
  color(255, 215, 0); // желтый
  delay(500);  
  color(34, 139, 34); //  зеленый
  delay(500); 
  color(0, 112, 255); // синий
  delay(500); 
  color(0, 46, 90);   // индиго
  delay(500); 
  color(128, 0, 128); // пурпурный 
  delay(500); 
}     

void color (unsigned char red, unsigned char green, unsigned char blue)
{    
  analogWrite(redPin, red);   
  analogWrite(greenPin, green); 
  analogWrite(bluePin, blue); 
}
