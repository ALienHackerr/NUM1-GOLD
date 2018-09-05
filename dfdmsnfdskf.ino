#include <LiquidCrystal.h>
#include <IRremote.h>

const int irpin = 10, rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
IRrecv ir(irpin);
decode_results reso;

void setup() {
  
  ir.enableIRIn();
  lcd.begin(16,2);
  lcd.setCursor(6,0);
  
}

void loop() {
  
  if(ir.decode(0)){
    
    unsigned int res=reso.value;
    switch(res){
      
      case 26775:
      lcd.print("Zero");
      break;
      case 12495:
      lcd.print("One");
      break;
      case 6375:
      lcd.print("Two");
      break;
      case 31365:
      lcd.print("Three");
      break;
      case 4335:
      lcd.print("Four");
      break;
      case 14535:
      lcd.print("Five");
      break;
      case 23205:
      lcd.print("Six");
      break;
      case 17085:
      lcd.print("Seven");
      break;
      case 19125:
      lcd.print("Eight");
      break;
      case 21165:
      lcd.print("Nine");
      break;
      default:
      lcd.print("Invalid!");
      break;
      
    }
    
    ir.resume();
    delay(1000);
    lcd.clear();
    lcd.setCursor(6,0);
    
  }
  
}
