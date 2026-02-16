Self-Balancing Robot Controller using Arduino Uno (Proteus Simulation)

Components Used

1. Arduino Uno
2. L298 Motor Driver IC / Module
3. DC Motors x2
4. Battery/DC Source (Motor Supply)
5. 5V Supply for Arduino + Driver logic
6. Potentiometer (used as tilt/angle input simulation)
7. Resistors (if required)
8. Wires + Ground terminals

Pin Connections

Pot Pin	Connection(Potentiometer)

Left pin - +5V, 
Middle pin - A0 (Arduino), 
Right pin	- GND

L298 to Arduino Connections

IN1	- D8 - Left motor direction, 
IN2	- D9	- Left motor direction, 
IN3 -	D10	- Right motor direction, 
IN4 -	D11	- Right motor direction, 
ENA	- D5 (PWM)	- Left motor speed, 
ENB	- D6 (PWM)	- Right motor speed, 


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

1. Open the Proteus project (.pdsprj)

2. Double click Arduino Uno

3. Load the HEX file in Program File

4. Ensure power is properly connected:

5. Arduino gets +5V

6. L298 gets both +5V logic and motor supply

7. Ensure all grounds are common

8. Run simulation

9. Rotate potentiometer:
Motors should respond by moving forward/backward

How to Upload Code in Arduino IDE

1. Open Arduino IDE

2. Select:
Board: Arduino Uno

3. Correct COM port

4. Paste code into new sketch

5. Click Verify

6. Click Upload
