Self-Balancing Robot Controller using Arduino Uno + L298 Motor Driver (Proteus Simulation)

Components Used

Arduino Uno

L298 Motor Driver IC / Module

DC Motors x2

Battery/DC Source (Motor Supply)

5V Supply for Arduino + Driver logic

Potentiometer (used as tilt/angle input simulation)

Resistors (if required)

Wires + Ground terminals

Pin Connections
Potentiometer (Tilt Input Simulation)
Pot Pin	Connection
Left pin	+5V
Middle pin	A0 (Arduino)
Right pin	GND
L298 to Arduino Connections
L298 Pin	Arduino Pin	Function
IN1	D8	Left motor direction
IN2	D9	Left motor direction
IN3	D10	Right motor direction
IN4	D11	Right motor direction
ENA	D5 (PWM)	Left motor speed
ENB	D6 (PWM)	Right motor speed
Power Connections

L298 VCC (Logic) → +5V

L298 VS (Motor supply) → Battery (7V-12V)

L298 GND → Common ground

Arduino GND → Common ground

Motor terminals connected to OUT1/OUT2 and OUT3/OUT4

Working Explanation

A real self-balancing robot requires a gyro sensor like MPU6050, but Proteus does not provide it easily.

So in this simulation, a potentiometer is used as a virtual tilt sensor:

When pot is turned left/right, Arduino reads analog angle value.

Arduino applies balancing logic (PID-like correction).

Motors speed up in forward or reverse direction to maintain balance.

This simulates how a self-balancing robot behaves.

How to Simulate in Proteus

Open the Proteus project (.pdsprj)

Double click Arduino Uno

Load the HEX file in Program File

Ensure power is properly connected:

Arduino gets +5V

L298 gets both +5V logic and motor supply

Ensure all grounds are common

Run simulation

Rotate potentiometer:

Motors should respond by moving forward/backward

How to Upload Code in Arduino IDE

Open Arduino IDE

Select:

Board: Arduino Uno

Correct COM port

Paste code into new sketch

Click Verify

Click Upload
