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
    
    if(res==6375){
      //move forward
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Moving forward");
      lcd.setCursor(7,1);
      lcd.write(1);
      digitalWrite(LF,HIGH);
      digitalWrite(RF,HIGH);
      
    }
     
    if(res==4335){
      //turn left
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print("Turning left");
      lcd.setCursor(7,1);
      lcd.write(3);
      lcd.write(5);
      digitalWrite(LB,HIGH);
      digitalWrite(RF,HIGH);
      
    }
    
    if(res==23205){
      //turn right
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print("Turning right");
      lcd.setCursor(7,1);
      lcd.write(5);
      lcd.write(4);
      digitalWrite(LF,HIGH);
      digitalWrite(RB,HIGH);
      
    }
      
    if(res==19125){
      //move back
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Moving backward");
      lcd.setCursor(7,1);
      lcd.write(2);
      digitalWrite(LB,HIGH);
      digitalWrite(RB,HIGH);
      
    }
    if(res==14535){
      
      lcd.clear();
      lcd.setCursor(4,0);
      lcd.print("Stopping");
      digitalWrite(LF,LOW);
      digitalWrite(LB,LOW);
      digitalWrite(RF,LOW);
      digitalWrite(RB,LOW);
      delay(100);
      lcd.clear();
      lcd.setCursor(4,0);
      lcd.print("Stopped");
      
    }
    ir.resume();
    
  }
  
}
