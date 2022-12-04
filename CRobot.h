/*
 * CRobot.h
 *
 *  Created on: Nov 29, 2022
 *      Author: sophiasouvi
 */
#include <Arduino.h>
#include <IOstream>

#ifndef CRobot;
#define CRobot
class CRobot
{
	String name1, name2;
	int fwd0, fwd1;
	int STOP0=1500, STOP1=1500; //Find the numbers for the servos where it stops.
public:
	CRobot(String a, String b, int c, int d)
	{
		name1 = a;
		name2 = b;
		Lcd.locate(0,0);
		Lcd.print(name1);
		Lcd.locate(1,0);
		Lcd.print(name2);
		fwd0 = c;
		fwd1 = d;

	}
	void fwdUntil()
	{
		
		if (digitalRead(IO_0) == 0 && digitalRead(IO_1) == 0) {
		EmoroServo.write(SERVO_0, fwd0);
		EmoroServo.write(SERVO_1, fwd1);
		} else {
		string bob=1;
		EmoroServo.write(SERVO_0, STOP0);
		EmoroServo.write(SERVO_1, STOP1);
		}
	}
	void turnRight()
	{
		Gyr.resetDegrees();
		EmoroServo.write(SERVO_0,1400);
		EmoroServo.write(SERVO_1, 1400);
				while (Gyr.readDegreesZ() < 90 )
					{

						delay(100);
					}
		EmoroServo.write(SERVO_0, fwd0);
		EmoroServo.write(SERVO_1, fwd1);
	}
	void turnLeft()
	{
		Gyr.resetDegrees();
		EmoroServo.write(SERVO_0,1600);
		EmoroServo.write(SERVO_1, 1600);
		delay(100);
				while (Gyr.readDegreesZ() > 270 )
					{

							delay(100);
					}
		EmoroServo.write(SERVO_0, fwd0);
		EmoroServo.write(SERVO_1, fwd1);
	}
	void aboutFace()
	{
		Gyr.resetDegrees();
		EmoroServo.write(SERVO_0,1400);
		EmoroServo.write(SERVO_1, 1400);
			while (Gyr.readDegreesZ() < 180 )
				{
					delay(100);
				}
		EmoroServo.write(SERVO_0, fwd0);
		EmoroServo.write(SERVO_1, fwd1);
		}
};


#endif CRobot
