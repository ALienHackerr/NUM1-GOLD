#include <LiquidCrystal.h>
#include <IRremote.h>

const int irpin = 10, rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
IRrecv ir(irpin);
decode_results reso;

void setup() {
  
  Serial.begin(9600);
  ir.enableIRIn();
  lcd.begin(16,2);
  
}

void loop() {
  
  if(ir.decode(&reso)){
    
    unsigned int res=reso.value;
    switch(res){
      
      case 41565:
      lcd.print("CH-");
      break;
      case 25245:
      lcd.print("CH");
      break;
      case 57885:
      lcd.print("CH+");
      break;
      case 8925:
      lcd.print("Previous");
      break;
      case 765:
      lcd.print("Next");
      break;
      case 49725:
      lcd.print("Play/Pause");
      break;
      case 57375:
      lcd.print("-");
      break;
      case 43095:
      lcd.print("+");
      break;
      case 36975:
      lcd.print("EQ");
      break;
      case 26775:
      lcd.print("0");
      break;
      case 39015:
      lcd.print("100+");
      break;
      case 45135:
      lcd.print("200+");
      break;
      case 12495:
      lcd.print("1");
      break;
      case 6375:
      lcd.print("2");
      break;
      case 31365:
      lcd.print("3");
      break;
      case 4335:
      lcd.print("4");
      break;
      case 14535:
      lcd.print("5");
      break;
      case 23205:
      lcd.print("6");
      break;
      case 17085:
      lcd.print("7");
      break;
      case 19125:
      lcd.print("8");
      break;
      case 21165:
      lcd.print("9");
      break;
      default:
      lcd.print("null");
      break;
      
    }
    
    irrecv.resume();
    delay(1000);
    lcd.clear();
    
  }
  
}
