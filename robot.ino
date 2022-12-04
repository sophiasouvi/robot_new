#include "Arduino.h"
#include "CRobot.h"

//The setup function is called once at startup of the sketch
CRobot larry("Christian", "Sophia", 1625, 1350);

void setup()
{
// Add your initialization code here
	//DECLARE OUR OBJECT

	//INITIALIZE SENSORS
		InitEmoro();
		Lcd.init();
		Ultrasonic.attach(GPP_0);
		pinMode(IO_0,INPUT_PULLUP);
		pinMode(IO_1,INPUT_PULLUP);

    //ATTACH THE **RIGHT** SERVO
			EmoroServo.attach(SERVO_0);

    //ATTACH THE **LEFT** SERVO
			EmoroServo.attach(SERVO_1);

   //INITIALIZE SWITCHES
			InitSwitch();


}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here

	larry.fwdUntil();
	delay(500)


}

