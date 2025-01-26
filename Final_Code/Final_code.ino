int in1 = 9;
int in2 = 8;
int in3 = 7;
int in4 = 6;
int enA = 10;
int enB = 11;
int speeda = 100;
int speedb = 100;

int trigpinF = 2;
int echopinF = 3;

int trigpinL = A0;
int echopinL = A1;

int trigpinR = A2;
int echopinR = A3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
  pinMode(trigpinF,OUTPUT);
  pinMode(echopinF,INPUT);
  pinMode(trigpinL,OUTPUT);
  pinMode(echopinL,INPUT);
  pinMode(trigpinR,OUTPUT);
  pinMode(echopinR,INPUT);
  
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  long durationF, distanceF;
  digitalWrite(trigpinF,HIGH);
  delay(1);
  digitalWrite(trigpinF,LOW);
  durationF=pulseIn(echopinF,HIGH);
  distanceF=(durationF/2)/29.1;
  Serial.print("DistanceF:");
  Serial.print(distanceF);
  Serial.print("CM");

  long durationL, distanceL;
  digitalWrite(trigpinL,HIGH);
  delay(1);
  digitalWrite(trigpinL,LOW);
  durationL=pulseIn(echopinL,HIGH);
  distanceL=(durationL/2)/29.1;
  Serial.print(" DistanceL:");
  Serial.print(distanceL);
  Serial.print("CM ");

  long durationR, distanceR;
  digitalWrite(trigpinR,HIGH);
  delay(1);
  digitalWrite(trigpinR,LOW);
  durationR=pulseIn(echopinR,HIGH);
  distanceR=(durationR/2)/29.1;
  Serial.print("DistanceR:");
  Serial.print(distanceR);
  Serial.println("CM ");


  // if (distanceF>30){speed = 255;}
  // if (distanceF<30){speed = map(distanceF,0,30,0,255);}
  // Serial.print(speed);
  if( (distanceR<5 && distanceL>=5 && distanceF>=5) || (distanceL>15 && distanceR<9 && distanceF<5) || (distanceL<5 && distanceR>=5 && distanceF>=5) || (distanceR>15 && distanceL<9 && distanceF<=5) || (distanceF>=5 && distanceL<=18 && distanceL>=5 && distanceR>=5) || (distanceF<=3 ||distanceF>1000) || (distanceF<=5 && distanceR<=7 && distanceL<=7) || (distanceL<=3 || distanceL>1000) || (distanceR<=3 || distanceR>1000)  )
    {
  if (distanceR<5 && distanceL>=5 && distanceF>=5)  { left();
                                    }
  else if (distanceL>15 && distanceR<9 && distanceF<5)  {  
                                      left();
                                      delay(500);
                                      forward();
                                      delay(400);
                                      Serial.print(" L ");
                                    }
  if (distanceL<5 && distanceR>=5 && distanceF>=5)  { right();
                                    }
  else if (distanceR>15 && distanceL<9 && distanceF<=5)  {  
                                      right();
                                      delay(500);
                                      forward();
                                      delay(400);
                                      Serial.print(" R ");
                                    }                                                                      
  if (distanceF>=5 && distanceL<=18 && distanceL>=5 && distanceR>=5)  { forward();
                                    }
  if (distanceF<=3 || distanceF>1000){
                      Serial.print(" B ");
                      backward();
                      delay(200);                  
                      if(distanceR>distanceL){right();
                                              delay(500);}
                      if(distanceL>distanceR){left();
                                              delay(500);} 
                      }                         
                            
  if (distanceL<=3 || distanceL>1000){right();
                      delay(30);} 
  if (distanceR<=3 || distanceR>1000){left();
                      delay(30);}
  if (distanceF<=5 && distanceR<=7 && distanceL<=7){
                                                    right();
                                                    delay(900);
                                                    Serial.print(" U ");
                                                  }                                                                                           
    }else{
      Serial.print(" D ");
      forward();
      delay(10);
    }                                  

                                    
  // if (distanceF>7 && distanceL>12 && distanceR>12)  { delay(450);
  //                                                     left();
  //                                                     delay(450);
  //                                                     forward();
  //                                                     delay(600);
  //                                    }
  // if (distanceF<5 && distanceL<12)  {
  //                                      right();
  //                                      delay(450);
  //                                      forward();
  //                                      delay(600);
  //                                    }

  // backward();
  // delay(2000);
  // forward();
  // delay(2000);


}
void backward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  Serial.println(" backward");
  analogWrite(enA,speeda);
  analogWrite(enB,speedb);

}
void forward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  Serial.println(" forward");
  analogWrite(enA,speeda);
  analogWrite(enB,speedb);

}
void right() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  Serial.println(" right");
  analogWrite(enA,speeda);
  analogWrite(enB,speedb);

}
void left() { 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  Serial.println(" left");
  analogWrite(enA,speeda);
  analogWrite(enB,speedb);

}
void stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.println(" stop");
 }