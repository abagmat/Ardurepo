const int VYVOD = 10;
const int PAUSA1 = 1000;
const int PAUSA2 = 1000;

void setup()
{
  pinMode(VYVOD, OUTPUT);
}

void loop()
{
  digitalWrite(VYVOD, HIGH);
  delay(PAUSA1);
  digitalWrite(VYVOD, LOW);
  delay(PAUSA2);
}