/*
 * 
 * 
 * https://github.com/tyhenry/CheapStepper
 * 
 * 
 */
#include <Servo.h>
#include <CheapStepper.h>

Servo base;//  base
Servo elb;//  elbow
Servo wrist;//  wrist
Servo fung;//  fingers
CheapStepper bae(10,11,12,13);//  base
const int some=8;
const int dv = 750;

void setup(){

    bae.setRpm(18);
    base.attach(2);
    elb.attach(3);
    wrist.attach(4);
    fung.attach(5);
    Serial.begin(9600);
    pinMode(7,INPUT_PULLUP);
    base.write(0);
    elb.write(0);
    wrist.write(0);
    fung.write(0);

}

void loop(){

    if(digitalRead(7)==HIGH){

        bae.moveDegreesCCW(45);
        d();
        come();
        d();
        ilike();
        d();
        go();
        d();
        bae.moveDegreesCW(90);
        d();
        come();
        d();
        allyssa();
        d();
        go();
        d();
        bae.moveDegreesCCW(45);//end of 1
        d();
        d();//divider
        bae.moveDegreesCW(45);
        d();
        come();
        d();
        ilike();
        d();
        go();
        d();
        bae.moveDegreesCCW(90);
        d();
        come();
        d();
        allyssa();
        d();
        go();
        d();
        bae.moveDegreesCW(45);//end of 2
        d();//done

    }

}

void d(){delay(dv);}
void ilike(){fung.write(90);}
void allyssa(){fung.write(0);}
void come(){

  base.write(90);
  elb.write(-90);
  wrist.write(30);
      
}
void go(){

  base.write(0);
  elb.write(0);
  wrist.write(0);

}
