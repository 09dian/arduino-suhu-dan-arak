#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
float temp;
float tempKe=0;
int tempPin = 0;
int trigPin = 9;
int echoPin = 8;
long duration, cm, inches;
void setup() {
  lcd.begin(16, 2); 
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
// utrasonic
digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74;
//  akhir utrasonic


//  teperatur
   temp = analogRead(tempPin);
   // read analog volt from sensor and save to variable temp
   temp = temp * 0.48828125;
   // convert the analog volt to its temperature equivalent
   lcd.clear();
   lcd.setCursor(2,0); 
   lcd.print("TEMP = ");
   lcd.print(temp); // display temperature value
   delay(1000); // update sensor reading each one second
  lcd.setCursor(2,2);
   lcd.print("Kel = ");
  lcd.print(tempKe=((temp)+ 273.15 ));
  delay(1000);
  
lcd.clear();
  delay(1000);
lcd.setCursor(1,0);  
  lcd.print("panjang ");
   lcd.print(cm);
   lcd.print(" cm");
  lcd.setCursor(7,1);  
  lcd.print(inches);        
  lcd.print(" in "); 
   delay(1000);
}
