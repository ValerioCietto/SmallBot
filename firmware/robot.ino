#include <Arduino.h>

// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>
#include <Servo.h>

AF_DCMotor motor(1);
AF_DCMotor motor1(2);
AF_DCMotor motor2(3);
AF_DCMotor motor3(4);
//TODO move FORWARD
//TODO move BACKWARD
//TODO turn right
//TODO turn left
void allForward(){
  motor.setSpeed(255);
  motor.run(FORWARD);
  motor1.setSpeed(255);
  motor1.run(BACKWARD);

  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  motor3.setSpeed(255);
  motor3.run(FORWARD);

  delay(1000);
  motor.run(RELEASE);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
}
void allForwardNoStop(){
  motor.setSpeed(255);
  motor.run(FORWARD);
  motor1.setSpeed(255);
  motor1.run(BACKWARD);

  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  motor3.setSpeed(255);
  motor3.run(FORWARD);


}
void stopMotors(){
  motor.run(RELEASE);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
}

void allBackward(){
  motor.setSpeed(255);
  motor.run(BACKWARD);
  motor1.setSpeed(255);
  motor1.run(FORWARD);

  motor2.setSpeed(255);
  motor2.run(FORWARD);
  motor3.setSpeed(255);
  motor3.run(BACKWARD);

  delay(1000);
  motor.run(RELEASE);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
}

void halfTurnSx(){
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  delay(1000);
  motor2.run(RELEASE);
  motor3.run(RELEASE);

}
void halfTurnDx(){
  motor.setSpeed(255);
  motor.run(FORWARD);
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  delay(1000);
  motor.run(RELEASE);
  motor1.run(RELEASE);
}


int contatore;
Servo servo;

void setup() {
  contatore =1;
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");
  Serial1.begin(9600);
  Serial1.println("started listening");
  // turn on servo
  delay(1000);
  servo.attach(9);

  servo.write(90);
  delay(1500);
  //halfTurnSx();
  //allForward();
}

void loop() {

  String cosaDettaDalTerminale = "";
  boolean availableMessage=false;
  if(Serial1.available()){
    cosaDettaDalTerminale = Serial1.readString();
    availableMessage=true;
    Serial.println("terminale 3"+cosaDettaDalTerminale);
  }
  if(Serial.available()){
    cosaDettaDalTerminale = Serial.readString();
    availableMessage=true;
  }
  if(availableMessage){
    Serial.println(cosaDettaDalTerminale);
    if( cosaDettaDalTerminale.indexOf("contatore")!=-1){
      //Serial.println(contatore);
    }
    if( cosaDettaDalTerminale.indexOf("avanti")!=-1){
      //Serial.println("sto andando avanti");
      allForward();
    }
    if( cosaDettaDalTerminale.indexOf("indietro")!=-1 ){
      //Serial.println("sto andando indietro");
      allBackward();
    }
    if( cosaDettaDalTerminale.indexOf("destra")!=-1){
      //Serial.println("sto andando destra");
      halfTurnDx();
    }
    if( cosaDettaDalTerminale.indexOf("sinistra")!=-1){
      //Serial.println("sto andando sinistra");
      halfTurnSx();
    }
    if( cosaDettaDalTerminale.indexOf("stop")!=-1){
      //Serial.println("sto andando sinistra");
      stopMotors();
    }
    if( cosaDettaDalTerminale.indexOf("forward")!=-1){
      //Serial.println("sto andando sinistra");
      allForwardNoStop();
    }
    if( cosaDettaDalTerminale.indexOf("servoright")!=-1){
      //Serial.println("sto andando sinistra");
      servo.write(60);
      delay(600);
      Serial.println("servoright received");

    }
    if( cosaDettaDalTerminale.indexOf("servocenter")!=-1){
      //Serial.println("sto andando sinistra");
      servo.write(90);
        delay(600);
      Serial.println("servocenter received");

    }
    if( cosaDettaDalTerminale.indexOf("servoleft")!=-1){
      //Serial.println("sto andando sinistra");
      servo.write(120);
        delay(600);
      Serial.println("servoLeft received");
    }


  }
}
