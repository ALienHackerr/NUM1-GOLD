#include <IRremote.h>
#include <LiquidCrystal.h>

IRrecv ir(10);
decode_results res;
LiquidCrystal lcd(12,11,5,4,3,2);

const int lf=6, lb=7, rf=8, rb=9;

void setup() {
  
  lcd.begin(16,2);
  lcd.setCursor();
  ir.enableIRIn();
  pinMode(lf,OUTPUT);
  pinMode(lb,OUTPUT);
  pinMode(rf,OUTPUT);
  pinMode(rb,OUTPUT); 
  
}

void loop() {
  
  if(ir.decode(&res){
    
    unsigned int reso=res.value;
    
    switch(reso){
      
      case :
      
    }
    
  }
  
}
