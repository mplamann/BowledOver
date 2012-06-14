#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S2, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     compass,        sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     motorWest,     tmotorNormal, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motorNorth,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C1_1,     motorEast,     tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     motorSouth,    tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S2_C2_1,     motorH,        tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S2_C2_2,     motorI,        tmotorNormal, openLoop)
#pragma config(Servo,  srvo_S2_C3_1,    flag,                 tServoStandard)
#pragma config(Servo,  srvo_S2_C3_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S2_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C3_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"
#include "Guile.c"
#include "rdpartyrobotcdr-v2.4/drivers/HTMC-driver.h"
const int THRESHOLD = 15;

void rotateAtPower(int rotatePower);

task main()
{

  //HTMCsetTarget(compass,0);

  servo[flag] = 0;

  waitForStart();   // wait for start of tele-op phase

  while (true)
  {
    getJoystickSettings(joystick);

    int xJoy = 0;
    int yJoy = 0;
    int rotatePower = 0;

    if (abs(joystick.joy1_x1) > THRESHOLD)
      xJoy = joystick.joy1_x1 * 100 / 128.0;
    if (abs(joystick.joy1_y1) > THRESHOLD)
      yJoy = joystick.joy1_y1 * 100 / 128.0;
    float theta = 0;
    if (xJoy == 0)
      theta = (yJoy > 0 ? PI/2 : 3*PI/2);
    else
      theta = atan((float)yJoy/xJoy);
    if (xJoy < 0)
      theta += PI;

    float magnitude = sqrt(pow(xJoy,2) + pow(yJoy,2));

    theta += PI/4;
    //theta += PI*HTMCreadRelativeHeading(compass) / 180.0;

    int xPower = magnitude * cos(theta);
    int yPower = magnitude * sin(theta);

    if (abs(joystick.joy1_x2) > THRESHOLD)
      rotatePower = joystick.joy1_x2 * 100 / 128.0;

    if (rotatePower == 0)
    {
      motor[motorWest] = yPower;
      motor[motorEast] = yPower;
      motor[motorNorth] = xPower;
      motor[motorSouth] = xPower;
    }
    else
    {
      rotateAtPower(rotatePower);
    }

    if (joy1Btn(10) && !bSoundActive)
      PlaySoundFile("pirateHQ.rso");
    if (joy1Btn(9) && !guileRunning)
    {
      StartTask(guile);
    }

    if (joy1Btn(1))
      servo[flag] -= 2;
    else if (joy1Btn(3))
      servo[flag] += 2;
  }
}

void rotateAtPower(int rotatePower)
{
  motor[motorWest] = rotatePower;
  motor[motorEast] = -rotatePower;
  motor[motorNorth] = rotatePower;
  motor[motorSouth] = -rotatePower;
}
