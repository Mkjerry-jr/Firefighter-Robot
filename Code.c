# Firefighter-Robot

#define enA 10 // Enable1 L298 Pin enA
#define in1 9  // Motor1 L298 Pin in1
#define in2 8  // Motor1 L298 Pin in2
#define in3 7  // Motor2 L298 Pin in3
#define in4 6  // Motor2 L298 Pin in4
#define enB 5  // Enable2 L298 Pin enB
#define ir_R A3
#define ir_F A1
#define ir_L A2
#define servo A4
#define pump A5

int Speed = 160; // Write The Duty Cycle 0 to 255 Enable for Motor Speed
int s1, s2, s3;

void setup() {
  Serial.begin(9600); // Start serial communication at 9600bps
  pinMode(ir_R, INPUT); // Declare fire sensor pin as input
  pinMode(ir_F, INPUT); // Declare fire sensor pin as input
  pinMode(ir_L, INPUT); // Declare fire sensor pin as input
  pinMode(enA, OUTPUT); // Declare as output for L298 Pin enA
  pinMode(in1, OUTPUT); // Declare as output for L298 Pin in1
  pinMode(in2, OUTPUT); // Declare as output for L298 Pin in2
  pinMode(in3, OUTPUT); // Declare as output for L298 Pin in3
  pinMode(in4, OUTPUT); // Declare as output for L298 Pin in4
  pinMode(enB, OUTPUT); // Declare as output for L298 Pin enB
  pinMode(servo, OUTPUT);
  pinMode(pump, OUTPUT);

  for (int angle = 90; angle <= 140; angle += 5) {
    servoPulse(servo, angle);
  }
  for (int angle = 140; angle >= 40; angle -= 5) {
    servoPulse(servo, angle);
  }
  for (int angle = 40; angle <= 95; angle += 5) {
    servoPulse(servo, angle);
  }

  analogWrite(enA, Speed); // Set Motor1 Speed
  analogWrite(enB, Speed); // Set Motor2 Speed

  delay(500);
}

void loop() {
  s1 = analogRead(ir_R);
  s2 = analogRead(ir_F);
  s3 = analogRead(ir_L);

  // Debugging sensor readings
  Serial.print("Sensor A0 (Right): ");
  Serial.print(s1);
  Serial.print("\tSensor A1 (Front): ");
  Serial.print(s2);
  Serial.print("\tSensor A2 (Left): ");
  Serial.println(s3);

  delay(50);

  //=============================================================
  // Auto Control
  //=============================================================
  if (s1 < 250) {
    Serial.println("Right IR detected fire.");
    Stop();
    digitalWrite(pump, HIGH);
    for (int angle = 90; angle >= 40; angle -= 3) {
      servoPulse(servo, angle);
    }
    for (int angle = 40; angle <= 90; angle += 3) {
      servoPulse(servo, angle);
    }
  } else if (s2 < 350) {
    Serial.println("Front IR detected fire.");
    Stop();
    digitalWrite(pump, HIGH);
    for (int angle = 90; angle <= 140; angle += 3) {
      servoPulse(servo, angle);
    }
    for (int angle = 140; angle >= 40; angle -= 3) {
      servoPulse(servo, angle);
    }
    for (int angle = 40; angle <= 90; angle += 3) {
      servoPulse(servo, angle);
    }
  } else if (s3 < 250) {
    Serial.println("Left IR detected fire.");
    Stop();
    digitalWrite(pump, HIGH);
    for (int angle = 90; angle <= 140; angle += 3) {
      servoPulse(servo, angle);
    }
    for (int angle = 140; angle >= 90; angle -= 3) {
      servoPulse(servo, angle);
    }
  } else if (s1 >= 251 && s1 <= 700) {
    Serial.println("Right IR no fire detected, adjusting.");
    digitalWrite(pump, LOW);
    backward();
    delay(100);
    turnRight();
    delay(200);
  } else if (s2 >= 251 && s2 <= 800) {
    Serial.println("Front IR no fire detected, moving forward.");
    digitalWrite(pump, LOW);
    forward();
  } else if (s3 >= 251 && s3 <= 700) {
    Serial.println("Left IR no fire detected, adjusting.");
    digitalWrite(pump, LOW);
    backward();
    delay(100);
    turnLeft();
    delay(200);
  } else {
    Serial.println("No fire detected, stopping.");
    digitalWrite(pump, LOW);
    Stop();
  }
  delay(10);
}

void servoPulse(int pin, int angle) {
  int pwm = (angle * 11) + 500; // Convert angle to microseconds
  digitalWrite(pin, HIGH);
  delayMicroseconds(pwm);
  digitalWrite(pin, LOW);

  delay(50); // Refresh cycle of servo
}

void forward() { // Corrected forward motion
  digitalWrite(in1, HIGH); // Right Motor forward Pin
  digitalWrite(in2, LOW);  // Right Motor backward Pin
  digitalWrite(in3, HIGH); // Left Motor forward Pin
  digitalWrite(in4, LOW);  // Left Motor backward Pin
}

void backward() { // Corrected backward motion
  digitalWrite(in1, LOW);  // Right Motor forward Pin
  digitalWrite(in2, HIGH); // Right Motor backward Pin
  digitalWrite(in3, LOW);  // Left Motor forward Pin
  digitalWrite(in4, HIGH); // Left Motor backward Pin
}

void turnRight() { // Turn Right
  digitalWrite(in1, LOW);  // Right Motor forward Pin
  digitalWrite(in2, HIGH); // Right Motor backward Pin
  digitalWrite(in3, HIGH); // Left Motor forward Pin
  digitalWrite(in4, LOW);  // Left Motor backward Pin
}

void turnLeft() { // Turn Left
  digitalWrite(in1, HIGH); // Right Motor forward Pin
  digitalWrite(in2, LOW);  // Right Motor backward Pin
  digitalWrite(in3, LOW);  // Left Motor forward Pin
  digitalWrite(in4, HIGH); // Left Motor backward Pin
}

void Stop() { // Stop motion
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
