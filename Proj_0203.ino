#include <LiquidCrystal.h>
#include <IRremote.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int LF = 9, LB = 8, RF = 7, RB = 6;
const int irpin = 10;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
IRrecv ir(irpin);
decode_results reso;

byte fwd[]={
  
  0b00100,
  0b01110,
  0b11111,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100
  
  };
byte bwd[]={
  
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b11111,
  0b01110,
  0b00100
  
  };
byte left[]={
  
  0b00000,
  0b00100,
  0b01100,
  0b11111,
  0b11111,
  0b01100,
  0b00100,
  0b00000
  
  };
byte right[]={
  
  0b00000,
  0b00100,
  0b00110,
  0b11111,
  0b11111,
  0b00110,
  0b00100,
  0b00000
  
  };
byte body[]={
  
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b11111,
  0b00000,
  0b00000,
  0b00000
  
  };
byte a;

void setup() {
  
  pinMode(LF,OUTPUT);
  pinMode(RF,OUTPUT);
  pinMode(LB,OUTPUT);
  pinMode(RB,OUTPUT);
  ir.enableIRIn();
  lcd.begin(16,2);
  lcd.createChar(1,fwd);
  lcd.createChar(2,bwd);
  lcd.createChar(3,left);
  lcd.createChar(4,right);
  lcd.createChar(5,body);
  
}

void loop() {
  
  if(ir.decode(&reso)){
    
    unsigned int res = reso.value;
    
    if(res==30879){
      //move forward
      lcd.setCursor(1,0);
      lcd.print("Moving forward");
      lcd.setCursor(7,1);
      lcd.write(1);
      digitalWrite(LF,HIGH);
      digitalWrite(RF,HIGH);
      delay(2000);
      lcd.clear();
      digitalWrite(LF,LOW);
      digitalWrite(RF,LOW);
      
    }
     
    if(res==5890){
      //turn left
      lcd.setCursor(2,0);
      lcd.print("Turning left");
      lcd.setCursor(7,1);
      lcd.write(3);
      lcd.write(5);
      digitalWrite(LB,HIGH);
      digitalWrite(RF,HIGH);
      delay(430);
      lcd.clear();
      digitalWrite(LB,LOW);
      digitalWrite(RF,LOW);
      
    }
    
    if(res==47939){
      //turn right
      lcd.setCursor(2,0);
      lcd.print("Turning right");
      lcd.setCursor(7,1);
      lcd.write(5);
      lcd.write(4);
      digitalWrite(LF,HIGH);
      digitalWrite(RB,HIGH);
      delay(430);
      lcd.clear();
      digitalWrite(LF,LOW);
      digitalWrite(RB,LOW);
      
    }
      
    if(res==16030){
      //move back
      lcd.setCursor(1,0);
      lcd.print("Moving backward");
      lcd.setCursor(7,1);
      lcd.write(2);
      digitalWrite(LB,HIGH);
      digitalWrite(RB,HIGH);
      delay(2000);
      lcd.clear();
      digitalWrite(LB,LOW);
      digitalWrite(RB,LOW);
      
    }
    ir.resume();
    
  }
  
}
