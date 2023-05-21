#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

int buzzer = 9; // sinais sonoros
int lightSensorPin = A1; // pino do Potenciometro


void setup()
{
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  pinMode(buzzer, OUTPUT);
  pinMode(lightSensorPin, INPUT);

  Serial.begin(9600);
}

void loop()
{
  
  //int lightValue = analogRead(lightSensorPin);
  int potValue = analogRead(lightSensorPin);
  
  int lightValue = map(potValue, 1023, 0, 100, 0);
	Serial.println(lightValue);
  
   if (lightValue < 60) 
  {
    digitalWrite(buzzer, HIGH);
    
    lcd.setCursor(0, 0);
    lcd.print("Umid. Solo BAIXA");
    lcd.setCursor(0, 1);
    lcd.print("Umidade = ");
    lcd.print(lightValue);
    lcd.print("%");
  }
  else if (lightValue >= 60 && lightValue <= 70) 
  {
    digitalWrite(buzzer, LOW);
    
    lcd.setCursor(0, 0);
    lcd.print("Umid. Solo OK");
    lcd.setCursor(0, 1);
    lcd.print("Umidade = ");
    lcd.print(lightValue);
    lcd.print("%");
  } else 
  {
    digitalWrite(buzzer, LOW);
    
    lcd.setCursor(0, 0);
    lcd.print("Umid. Solo ALTA");
    lcd.setCursor(0, 1);
    lcd.print("Umidade = ");
    lcd.print(lightValue);
    lcd.print("%");
  }
  delay(3000);
  lcd.clear();
  
 
}
