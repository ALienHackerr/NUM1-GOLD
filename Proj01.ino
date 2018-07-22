#include "pitches.h"
#include "timings.h"
bool isAllowed=false;
String a;
int notes1[63]={D4,D4,E4,D4,E4,D4,E4,G4,A4,A4,B4,A4,E4,E4,E4,D4,E4,G4,D4,D4,E4,D4,E4,G4,G4,B4,B4,A4,A4,A4,A4,B4,A4,E4,G4,G4,A4,G4,G4,A4,B4,A4,G4,A4,B4,A4,G4,B4,CS5,E5,DS5,DS5,CS5,B4,A4,G4,A4,B4,A4,G4,G4,A4,G4};
//int notes2[]=;
//int notes3[]=;
String lyrics1[63]={"Al-","most ","hea-","ven, ","West ","Vir-","gin-","ia\n","Blue ","Ridge ","Moun-","tains, ","She-","nan-","do-","ah ","Ri-","ver\n","Life ","is ","old ","there, ","ol-","der ","than ","the ","trees\n","Youn-","ger ","than ","the ","moun-","tains, ","blo-","wing ","like ","a ","breeze\n\n"};
//String lyrics2[]=;
//String lyrics3[]=;
int timings1[63]={et,et,etx};
//int timings2[]={};
//int timings3[]={};

void setup() {
  
  Serial.begin(9600);
  pinMode(3,INPUT);
  pinMode(8,OUTPUT);
  Serial.println("Welcome to the karaoke.Push the button to activate the karaoke.\n");
  
}

void loop() {
  
  int buttonState=digitalRead(3);
  
  if(buttonState==HIGH && isAllowed==false){
    
    isAllowed=true;
    Serial.println("You just turned on the karaoke!Enter your song of choice.");
    
    }
  
  if(Serial.available()>0 && isAllowed==true){
    
    a=Serial.readString();

    if(isAllowed=true){
      
      if(a=="exit")check();
      else verse(8);
      
    }
  
  }
  
}

void verse(int PIN){
  
  if(a=="country roads"){

    for(int x=0;x<63;x++){
      tone(PIN,notes1[x],500);Serial.print(lyrics1[x]);delay(600);
    }
    
    }
  else if(a=="hej monika"){
    
    Serial.println('b');
    
    }
  else if(a=="something else"){
    
    Serial.println('c');
    
    }
  else{
    
    Serial.println("Invalid song!Please try again.");
    
    }

}

void check(){
  
  isAllowed=false;
  Serial.println("\nKaraoke exited.Push the button to reactivate the karaoke.");
  
  }
