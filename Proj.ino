#include <LiquidCrystal.h>
#include <IRremote.h>

const int rs = 12, en = 11, irpin = 10, d4 = 5, d5 = 4, d6 = 3, d7 = 2, LF = 6, RF = 7, LB = 8, RB = 9;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
IRrecv ir(irpin);
decode_results reso;

void setup() {
  
  pinMode(LF,OUTPUT);
  pinMode(RF,OUTPUT);
  pinMode(LB,OUTPUT);
  pinMode(RB,OUTPUT);
  ir.enableIRIn();
  lcd.begin(16,2);
  
}

void loop() {
  
  if(ir.decode(&reso)){
    
    unsigned int res = reso.value();
    switch(res){
      
      case 2:
      //move forward
      lcd.setCursor(7,0);
      lcd.write();
      lcd.write();
      lcd.setCursor(7,1);
      lcd.write();
      lcd.write();
      while(ir.decode(&reso)){
        
        digitalWrite(LF,HIGH);
        digitalWrite(RF,HIGH);
        
      }
      lcd.clear();
      digitalWrite(LF,LOW);
      digitalWrite(RF,LOW);
      break;
      
      case 4:
      //turn left
      lcd.setCursor(7,0)
      lcd.write();
      lcd.write();
      lcd.setCursor(7,1);
      lcd.write();
      lcd.write();
      while(ir.decode(&reso)){
        
        digitalWrite(LB,HIGH);
        digitalWrite(RF,HIGH);
        
      }
      lcd.clear();
      digitalWrite(LB,LOW);
      digitalWrite(RF,LOW);
      break;
      
      case 6:
      //turn right
      lcd.setCursor(7,0);
      lcd.write();
      lcd.write();
      lcd.setCursor(7,1);
      lcd.write();
      lcd.write();
      while(ir.decode(&reso)){
        
        digitalWrite(LF,HIGH);
        digitalWrite(RB,HIGH);
        
      }
      lcd.clear();
      digitalWrite(LF,LOW);
      digitalWrite(RB,LOW);
      break;
      
      case 8:
      //move back
      lcd.setCursor(7,0);
      lcd.write();
      lcd.write();
      lcd.setCursor(7,1);
      lcd.write();
      lcd.write();
      while(ir.decode(&reso)){
        
        digitalWrite(LB,HIGH);
        digitalWrite(RB,HIGH);
        
      }
      lcd.clear();
      digitalWrite(LB,LOW);
      digitalWrite(RB,LOW);
      break;
      
    }
    
  }
  
}
