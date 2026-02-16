//L298 Pins
int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;

int ENA = 6;   // PWM
int ENB = 5;   // PWM

//Potentiometer
int potPin = A0;

// PID Variables
float Kp = 2.0;     // Proportional gain
float Ki = 0.01;    // Integral gain
float Kd = 1.0;     // Derivative gain

float setPoint = 512;   // Balanced point (middle of pot)

float error = 0;
float previousError = 0;
float integral = 0;
float derivative = 0;

int motorOutput = 0;

unsigned long lastTime = 0;
float dt = 0;

// Motor Control Function
void moveForward(int speedVal)
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, speedVal);
  analogWrite(ENB, speedVal);
}

void moveBackward(int speedVal)
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, speedVal);
  analogWrite(ENB, speedVal);
}

void stopMotors()
{
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

//Setup
void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(potPin, INPUT);

  lastTime = millis();
}

// Loop
void loop()
{
  unsigned long currentTime = millis();
  dt = (currentTime - lastTime) / 1000.0;
  lastTime = currentTime;

  int potValue = analogRead(potPin);  // 0 to 1023

  // Error calculation
  error = setPoint - potValue;

  // Integral part
  integral = integral + (error * dt);

  // Derivative part
  derivative = (error - previousError) / dt;

  // PID Output
  float pidValue = (Kp * error) + (Ki * integral) + (Kd * derivative);

  previousError = error;

  // Convert PID output to motor speed
  motorOutput = abs((int)pidValue);

  // Limit speed
  if (motorOutput > 255)
    motorOutput = 255;

  // Dead zone (balance zone)
  if (abs(error) < 10)
  {
    stopMotors();
  }
  else
  {
    // If error is positive -> robot tilted forward -> move forward
    if (pidValue > 0)
    {
      moveForward(motorOutput);
    }
    // If error is negative -> robot tilted backward -> move backward
    else
    {
      moveBackward(motorOutput);
    }
  }

  delay(10);
}
