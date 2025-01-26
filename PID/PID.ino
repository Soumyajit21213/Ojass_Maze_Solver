int in1 = 9;
int in2 = 8;
int in3 = 7;
int in4 = 6;
int enA = 10;
int enB = 11;

int trigpinF = A4;
int echopinF = A5;

int trigpinL = A0;
int echopinL = A1;

int trigpinR = A2;
int echopinR = A3;

float kp = 10.0;
float kd = 0.1;
float ki = 0.00;

long previousTime = 0;
float ePreviousF = 0;
float ePreviousLR = 0;
float eIntegralF = 0;
float eIntegralLR = 0;

long durationF, distanceF;
long durationL, distanceL;
long durationR, distanceR;

void setup() {
  Serial.begin(9600);

  pinMode(trigpinF, OUTPUT);
  pinMode(echopinF, INPUT);
  pinMode(trigpinL, OUTPUT);
  pinMode(echopinL, INPUT);
  pinMode(trigpinR, OUTPUT);
  pinMode(echopinR, INPUT);
  
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
}

void loop() {
  updateDistances();

  float uF = pidControllerF();
  float uLR = pidControllerLR();

  moveMotor(uF, uLR);
  
}

void updateDistances() {
  // Front distance
  digitalWrite(trigpinF, HIGH);
  delay(1);
  digitalWrite(trigpinF, LOW);
  durationF = pulseIn(echopinF, HIGH);
  distanceF = (durationF / 2) / 29.1;
  // Serial.print("DistanceF: ");
  // Serial.print(distanceF);
  // Serial.print(" CM ");

  // Left distance
  digitalWrite(trigpinL, HIGH);
  delay(1);
  digitalWrite(trigpinL, LOW);
  durationL = pulseIn(echopinL, HIGH);
  distanceL = (durationL / 2) / 29.1;
  // Serial.print("DistanceL: ");
  // Serial.print(distanceL);
  // Serial.print(" CM ");

  // Right distance
  digitalWrite(trigpinR, HIGH);
  delay(1);
  digitalWrite(trigpinR, LOW);
  durationR = pulseIn(echopinR, HIGH);
  distanceR = (durationR / 2) / 29.1;
  // Serial.print("DistanceR: ");
  // Serial.println(distanceR);
  // Serial.print(" CM ");
}

float pidControllerF() {
  long currentTime = micros();
  float deltaT = ((float)(currentTime - previousTime)) / 1.0e6;

  // Calculate error based on front distance (goal is 3 cm)
  float e = distanceF - 3;
  float eDerivative = (e - ePreviousF) / deltaT;
  eIntegralF += e * deltaT;

  // PID control output
  float u = (kp * e) + (kd * eDerivative) + (ki * eIntegralF);

  // Map output speed based on distance (clamped between 0 and 150)
  float speed = map(constrain(distanceF, 0, 15), 3, 15, 0, 150);

  if (distanceF < 3) {
    speed = -abs(speed);  // Negative speed for reverse
  }

  previousTime = currentTime;
  ePreviousF = e;

  return speed;
}

float pidControllerLR() {
  long currentTime = micros();
  float deltaT = ((float)(currentTime - previousTime)) / 1.0e6;

  // Error based on difference between left and right distances
  float e = distanceR - distanceL;
  float eDerivative = (e - ePreviousLR) / deltaT;
  eIntegralLR += e * deltaT;

  // PID control output for correction
  float u = (kp * e) + (kd * eDerivative) + (ki * eIntegralLR);

  // Map 'u' to a range between -30 and 30
  u = map(constrain(u, -150, 150), -150, 150, -90, 90);

  previousTime = currentTime;
  ePreviousLR = e;

  return u;
}


void moveMotor(float uF, float uLR) {
  int speedA = uF; // Start with the forward speed for the left motor
  int speedB = uF; // Start with the forward speed for the right motor

  if (uLR > 0) {
    // If the right distance is greater, increase the left motor's speed
    speedA += uLR;
  } else if (uLR < 0) {
    // If the left distance is greater, increase the right motor's speed
    speedB -= uLR; // Add the absolute value of uLR to the right motor speed
  }

  Serial.print("SpeedA: ");
  Serial.print(speedA);
  Serial.print("   SpeedB: ");
  Serial.println(speedB);
  delay(100);

  // Control left motor (Motor A)
  if (speedA > 0) {
    // Move forward
    analogWrite(enA, speedA);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  } else {
    // Move backward
    analogWrite(enA, -speedA);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }

  // Control right motor (Motor B)
  if (speedB > 0) {
    // Move forward
    analogWrite(enB, speedB);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  } else {
    // Move backward
    analogWrite(enB, -speedB);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
}

