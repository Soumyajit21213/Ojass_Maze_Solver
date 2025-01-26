// HardwareSerial mySerial(0);

int trigpinF = 40;
int echopinF = 37;

int trigpinL = 42;
int echopinL = 41;

int trigpinRF = 20;
int echopinRF = 21;

int trigpinLF = 44;
int echopinLF = 43;

int trigpinR = A0;
int echopinR = A1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);  //Set the baud rate to your Bluetooth module.
  pinMode(trigpinF,OUTPUT);
  pinMode(echopinF,INPUT);
  pinMode(trigpinL,OUTPUT);
  pinMode(echopinL,INPUT);
  pinMode(trigpinRF,OUTPUT);
  pinMode(echopinRF,INPUT);
  pinMode(trigpinLF,OUTPUT);
  pinMode(echopinLF,INPUT);
  pinMode(trigpinR,OUTPUT);
  pinMode(echopinR,INPUT);

 
}

void loop() {
  // put your main code here, to run repeatedly:

//   long durationL, distanceL;
// digitalWrite(trigpinL,HIGH);
// delay(1);
// digitalWrite(trigpinL,LOW);
// durationL=pulseIn(echopinL,HIGH);
// distanceL=(durationL/2)/29.1;
// mySerial.print(" DistanceL:");
// mySerial.print(distanceL);
// mySerial.print("CM  ");

// long durationLF, distanceLF;
// digitalWrite(trigpinLF,HIGH);
// delay(1);
// digitalWrite(trigpinLF,LOW);
// durationLF=pulseIn(echopinLF,HIGH);
// distanceLF=(durationLF/2)/29.1;
// mySerial.print("DistanceLF:");
// mySerial.print(distanceLF);
// mySerial.print("CM  ");

// long durationF, distanceF;
// digitalWrite(trigpinF,HIGH);
// delay(1);
// digitalWrite(trigpinF,LOW);
// durationF=pulseIn(echopinF,HIGH);
// distanceF=(durationF/2)/29.1;
// mySerial.print("DistanceF:");
// mySerial.print(distanceF);
// mySerial.print("CM  ");

// long durationRF, distanceRF;
// digitalWrite(trigpinRF,HIGH);
// delay(1);
// digitalWrite(trigpinRF,LOW);
// durationRF=pulseIn(echopinRF,HIGH);
// distanceRF=(durationRF/2)/29.1;
// mySerial.print("DistanceRF:");
// mySerial.print(distanceRF);
// mySerial.println("CM");



long durationR, distanceR;
digitalWrite(trigpinR,HIGH);
delay(1);
digitalWrite(trigpinR,LOW);
durationR=pulseIn(echopinR,HIGH);
distanceR=(durationR/2)/29.1;
Serial.print("DistanceR:");
Serial.print(distanceR);
Serial.println("CM ");
}

