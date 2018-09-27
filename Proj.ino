#include <LiquidCrystal.h>
#include <IRremote.h>

const int rs = 12, en = 11, irpin = 10, d4 = 2, d5 = 3, d6 = 4, d7 = 5, LF = 6, RF = 7, LB = 8, RB = 9;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
IRrecv ir(irpin);
decode_results reso;

byte fwd1[]={
  
  0b00001,
  0b00011,
  0b00111,
  0b01111,
  0b11111,
  0b00011,
  0b00011,
  0b00011
  
  };
byte fwd2[]={
  
  0b10000,
  0b11000,
  0b11100,
  0b11110,
  0b11111,
  0b11000,
  0b11000,
  0b11000
  
  };
byte fwd3[]={
  
  0b00011,
  0b00011,
  0b00011,
  0b00011,
  0b00011,
  0b00011,
  0b00011,
  0b00011
  
  };
byte fwd4[]={
  
  0b11000,
  0b11000,
  0b11000,
  0b11000,
  0b11000,
  0b11000,
  0b11000,
  0b11000
  
  };
byte bwd1[]={
  
  0b00011,
  0b00011,
  0b00011,
  0b00011,
  0b00011,
  0b00011,
  0b00011,
  0b00011
  
  };
byte bwd2[]={
  
  0b11000,
  0b11000,
  0b11000,
  0b11000,
  0b11000,
  0b11000,
  0b11000,
  0b11000
  
  };
byte bwd3[]={
  
  0b00011,
  0b00011,
  0b00011,
  0b11111,
  0b01111,
  0b00111,
  0b00011,
  0b00001
  
  };
byte bwd4[]={
  
  0b11000,
  0b11000,
  0b11000,
  0b11111,
  0b11110,
  0b11100,
  0b11000,
  0b10000
  
  };
byte left1[]={
  
  0b00000,
  0b00000,
  0b00000,
  0b00001,
  0b00011,
  0b00111,
  0b01111,
  0b11111
  
  };
byte left2[]={
  
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b11111
  
  };
byte left3[]={
  
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b11111
  
  };
byte left4[]={
  
  0b11111,
  0b01111,
  0b00111,
  0b00011,
  0b00001,
  0b00000,
  0b00000,
  0b00000
  
  };
byte left5[]={
  
  0b11111,
  0b11111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
  
  };
byte left6[]={
  
  0b11111,
  0b11111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
  
  };
byte right1[]={
  
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b11111
  
  };
byte right2[]={
  
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b11111
  
  };
byte right3[]={
  
  0b00000,
  0b00000,
  0b00000,
  0b10000,
  0b11000,
  0b11100,
  0b11110,
  0b11111
  
  };
byte right4[]={
  
  0b11111,
  0b11111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
  
  };
byte right5[]={
  
  0b11111,
  0b11111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
  
  };
byte right6[]={
  
  0b11111,
  0b11110,
  0b11100,
  0b11000,
  0b10000,
  0b00000,
  0b00000,
  0b00000
  
  };

void setup() {
  
  pinMode(LF,OUTPUT);
  pinMode(RF,OUTPUT);
  pinMode(LB,OUTPUT);
  pinMode(RB,OUTPUT);
  ir.enableIRIn();
  lcd.begin(16,2);
  lcd.createChar(11,fwd1);
  lcd.createChar(12,fwd2);
  lcd.createChar(13,fwd3);
  lcd.createChar(14,fwd4);
  lcd.createChar(21,bwd1);
  lcd.createChar(22,bwd2);
  lcd.createChar(23,bwd3);
  lcd.createChar(24,bwd4);
  lcd.createChar(31,left1);
  lcd.createChar(32,left2);
  lcd.createChar(33,left3);
  lcd.createChar(34,left4);
  lcd.createChar(35,left5);
  lcd.createChar(36,left6);
  lcd.createChar(41,right1);
  lcd.createChar(42,right2);
  lcd.createChar(43,right3);
  lcd.createChar(44,right4);
  lcd.createChar(45,right5);
  lcd.createChar(46,right6);
  
}

void loop() {
  
  if(ir.decode(&reso)){
    
    unsigned int res = reso.value;
    
    if(res==6375){
      //move forward
      lcd.setCursor(7,0);
      lcd.write(11);
      lcd.write(12);
      lcd.setCursor(7,1);
      lcd.write(13);
      lcd.write(14);
      while(ir.decode(&reso)){
        
        digitalWrite(LF,HIGH);
        digitalWrite(RF,HIGH);
        
      }
      //lcd.clear();
      digitalWrite(LF,LOW);
      digitalWrite(RF,LOW);
      
    }
     
    if(res==4335){
      //turn left
      lcd.setCursor(6,0);
      lcd.write(31);
      lcd.write(32);
      lcd.write(33);
      lcd.setCursor(6,1);
      lcd.write(34);
      lcd.write(35);
      lcd.write(36);
      while(ir.decode(&reso)){
        
        digitalWrite(LB,HIGH);
        digitalWrite(RF,HIGH);
        
      }
      lcd.clear();
      digitalWrite(LB,LOW);
      digitalWrite(RF,LOW);
      
    }
    
    if(res==23205){
      //turn right
      lcd.setCursor(6,0);
      lcd.write(41);
      lcd.write(42);
      lcd.write(43);
      lcd.setCursor(6,1);
      lcd.write(44);
      lcd.write(45);
      lcd.write(46);
      while(ir.decode(&reso)){
        
        digitalWrite(LF,HIGH);
        digitalWrite(RB,HIGH);
        
      }
      lcd.clear();
      digitalWrite(LF,LOW);
      digitalWrite(RB,LOW);
      
    }
      
    if(res==19125){
      //move back
      lcd.setCursor(7,0);
      lcd.write(21);
      lcd.write(22);
      lcd.setCursor(7,1);
      lcd.write(23);
      lcd.write(24);
      while(ir.decode(&reso)){
        
        digitalWrite(LB,HIGH);
        digitalWrite(RB,HIGH);
        
      }
      lcd.clear();
      digitalWrite(LB,LOW);
      digitalWrite(RB,LOW);
      
    }
    
  }
  
}
