#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int IRsensor1= 7;
const int IRsensor2= 8;
const int relay= 9;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int count=0;
char a,b;

void setup(){
  lcd.begin(16,2);
  Serial.begin(9600);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("count= 0");
  pinMode (relay, OUTPUT);
  pinMode (IRsensor1, INPUT);
  pinMode (IRsensor2, INPUT);
}
  
void loop(){
  if(digitalRead (IRsensor1)==HIGH){
      count=count+1;
      delay(1000);
    }
    if(digitalRead (IRsensor2)==HIGH){
      count=count-1;
      delay(1000);
    }
    if(count>0){
      digitalWrite (relay, LOW);
    }  
    if(count<=0){
      count=0;
      digitalWrite (relay, HIGH);
    }  
    lcd.setCursor(7,0);
    lcd.print(count);
    Serial.println(count);
}
