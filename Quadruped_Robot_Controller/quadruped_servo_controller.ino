#include <Servo.h>

// -------- SERVO OBJECTS --------
Servo servoFL_HIP;   // Front Left Hip
Servo servoFL_KNEE;  // Front Left Knee

Servo servoFR_HIP;   // Front Right Hip
Servo servoFR_KNEE;  // Front Right Knee

Servo servoBL_HIP;   // Back Left Hip
Servo servoBL_KNEE;  // Back Left Knee

Servo servoBR_HIP;   // Back Right Hip
Servo servoBR_KNEE;  // Back Right Knee


// -------- PIN CONNECTIONS (FROM YOUR CIRCUIT) --------
// PA0 to PA7 = Digital 22 to 29
#define FL_HIP_PIN   22
#define FL_KNEE_PIN  23

#define FR_HIP_PIN   24
#define FR_KNEE_PIN  25

#define BL_HIP_PIN   26
#define BL_KNEE_PIN  27

#define BR_HIP_PIN   28
#define BR_KNEE_PIN  29


// -------- DEFAULT STANDING ANGLES --------
// Adjust these if your robot is not straight
int FL_HIP_STAND  = 90;
int FL_KNEE_STAND = 90;

int FR_HIP_STAND  = 90;
int FR_KNEE_STAND = 90;

int BL_HIP_STAND  = 90;
int BL_KNEE_STAND = 90;

int BR_HIP_STAND  = 90;
int BR_KNEE_STAND = 90;


// -------- SPEED CONTROL --------
int stepDelay = 15;   // smaller = faster movement


// -------- FUNCTION: Smooth Move Servo --------
void moveServoSmooth(Servo &s, int startAngle, int endAngle)
{
  if (startAngle < endAngle)
  {
    for (int pos = startAngle; pos <= endAngle; pos++)
    {
      s.write(pos);
      delay(stepDelay);
    }
  }
  else
  {
    for (int pos = startAngle; pos >= endAngle; pos--)
    {
      s.write(pos);
      delay(stepDelay);
    }
  }
}


// -------- FUNCTION: Stand Position --------
void stand()
{
  servoFL_HIP.write(FL_HIP_STAND);
  servoFL_KNEE.write(FL_KNEE_STAND);

  servoFR_HIP.write(FR_HIP_STAND);
  servoFR_KNEE.write(FR_KNEE_STAND);

  servoBL_HIP.write(BL_HIP_STAND);
  servoBL_KNEE.write(BL_KNEE_STAND);

  servoBR_HIP.write(BR_HIP_STAND);
  servoBR_KNEE.write(BR_KNEE_STAND);

  delay(500);
}


// -------- FUNCTION: Sit Position --------
void sit()
{
  servoFL_KNEE.write(120);
  servoFR_KNEE.write(120);
  servoBL_KNEE.write(120);
  servoBR_KNEE.write(120);

  delay(500);
}


// -------- FUNCTION: Lift Leg (Knee Up) --------
void liftFrontLeft()
{
  servoFL_KNEE.write(60);
}

void liftFrontRight()
{
  servoFR_KNEE.write(60);
}

void liftBackLeft()
{
  servoBL_KNEE.write(60);
}

void liftBackRight()
{
  servoBR_KNEE.write(60);
}


// -------- FUNCTION: Place Leg Down --------
void placeFrontLeft()
{
  servoFL_KNEE.write(FL_KNEE_STAND);
}

void placeFrontRight()
{
  servoFR_KNEE.write(FR_KNEE_STAND);
}

void placeBackLeft()
{
  servoBL_KNEE.write(BL_KNEE_STAND);
}

void placeBackRight()
{
  servoBR_KNEE.write(BR_KNEE_STAND);
}


// -------- FUNCTION: WALK FORWARD CYCLE --------
void walkForward()
{
  // STEP 1: Lift Front Left + Back Right
  liftFrontLeft();
  liftBackRight();
  delay(200);

  // Move hips forward
  servoFL_HIP.write(70);
  servoBR_HIP.write(70);
  delay(200);

  // Place them down
  placeFrontLeft();
  placeBackRight();
  delay(200);

  // STEP 2: Lift Front Right + Back Left
  liftFrontRight();
  liftBackLeft();
  delay(200);

  // Move hips forward
  servoFR_HIP.write(110);
  servoBL_HIP.write(110);
  delay(200);

  // Place them down
  placeFrontRight();
  placeBackLeft();
  delay(200);

  // Reset hips back to stand position
  servoFL_HIP.write(FL_HIP_STAND);
  servoFR_HIP.write(FR_HIP_STAND);
  servoBL_HIP.write(BL_HIP_STAND);
  servoBR_HIP.write(BR_HIP_STAND);

  delay(200);
}


// -------- FUNCTION: WALK BACKWARD --------
void walkBackward()
{
  // STEP 1: Lift Front Left + Back Right
  liftFrontLeft();
  liftBackRight();
  delay(200);

  // Move hips backward
  servoFL_HIP.write(110);
  servoBR_HIP.write(110);
  delay(200);

  // Place down
  placeFrontLeft();
  placeBackRight();
  delay(200);

  // STEP 2: Lift Front Right + Back Left
  liftFrontRight();
  liftBackLeft();
  delay(200);

  // Move hips backward
  servoFR_HIP.write(70);
  servoBL_HIP.write(70);
  delay(200);

  // Place down
  placeFrontRight();
  placeBackLeft();
  delay(200);

  // Reset hips
  servoFL_HIP.write(FL_HIP_STAND);
  servoFR_HIP.write(FR_HIP_STAND);
  servoBL_HIP.write(BL_HIP_STAND);
  servoBR_HIP.write(BR_HIP_STAND);

  delay(200);
}


// -------- FUNCTION: TURN LEFT --------
void turnLeft()
{
  liftFrontRight();
  liftBackRight();
  delay(200);

  servoFR_HIP.write(60);
  servoBR_HIP.write(60);
  delay(200);

  placeFrontRight();
  placeBackRight();
  delay(200);

  liftFrontLeft();
  liftBackLeft();
  delay(200);

  servoFL_HIP.write(120);
  servoBL_HIP.write(120);
  delay(200);

  placeFrontLeft();
  placeBackLeft();
  delay(200);

  stand();
}


// -------- FUNCTION: TURN RIGHT --------
void turnRight()
{
  liftFrontLeft();
  liftBackLeft();
  delay(200);

  servoFL_HIP.write(60);
  servoBL_HIP.write(60);
  delay(200);

  placeFrontLeft();
  placeBackLeft();
  delay(200);

  liftFrontRight();
  liftBackRight();
  delay(200);

  servoFR_HIP.write(120);
  servoBR_HIP.write(120);
  delay(200);

  placeFrontRight();
  placeBackRight();
  delay(200);

  stand();
}


// -------- SETUP --------
void setup()
{
  servoFL_HIP.attach(FL_HIP_PIN);
  servoFL_KNEE.attach(FL_KNEE_PIN);

  servoFR_HIP.attach(FR_HIP_PIN);
  servoFR_KNEE.attach(FR_KNEE_PIN);

  servoBL_HIP.attach(BL_HIP_PIN);
  servoBL_KNEE.attach(BL_KNEE_PIN);

  servoBR_HIP.attach(BR_HIP_PIN);
  servoBR_KNEE.attach(BR_KNEE_PIN);

  stand();
}


// -------- LOOP --------
void loop()
{
  // Walk forward 5 steps
  for (int i = 0; i < 5; i++)
  {
    walkForward();
  }

  delay(1000);

  // Turn right
  for (int i = 0; i < 3; i++)
  {
    turnRight();
  }

  delay(1000);

  // Walk backward 5 steps
  for (int i = 0; i < 5; i++)
  {
    walkBackward();
  }

  delay(1000);

  // Turn left
  for (int i = 0; i < 3; i++)
  {
    turnLeft();
  }

  delay(1000);

  // Sit and stop
  sit();
  delay(2000);

  stand();
  delay(2000);
}

