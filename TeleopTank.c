#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S1,     ,                    sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     rightDrive,    tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     leftDrive,     tmotorNormal, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C2_1,    rightWing,            tServoStandard)
#pragma config(Servo,  srvo_S1_C2_2,    rightArm,             tServoStandard)
#pragma config(Servo,  srvo_S1_C2_3,    leftWing,             tServoStandard)
#pragma config(Servo,  srvo_S1_C2_4,    leftArm,              tServoStandard)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

int lastBeep = 0;
int delay = 100;

void initializeRobot()
{
  return;
}

void operateWheels()
{
  float leftDrivePower = 0;
  float rightDrivePower = 0;
  if (abs(joystick.joy1_y1) > 15)
  {
    leftDrivePower = joystick.joy1_y1*100.0/128.0;
  }
  if (abs(joystick.joy1_y2) > 15)
    rightDrivePower = joystick.joy1_y2*100.0/128.0;
  motor[leftDrive] = leftDrivePower;
  motor[rightDrive] = rightDrivePower;
}

void operateLift()
{
  int leftArmValue = ServoValue[leftArm];
  int rightArmValue = ServoValue[rightArm];
  if (joy1Btn(6))
{
  leftArmValue++;
  rightArmValue--;
  }
  if (joy1Btn(8))
  {
    leftArmValue--;
    rightArmValue++;
  }
  servo[leftArm] = leftArmValue;
  servo[rightArm] = rightArmValue;
}

void operateBeep()
{
  if (nPgmTime/10 - lastBeep > delay && joy1Btn(1))
  {
    PlayImmediateTone(random(3000),delay/4);
    lastBeep = nPgmTime/10;
  }
}

task main()
{
  initializeRobot();

  waitForStart();

  while (true)
  {
    getJoystickSettings(joystick);
    operateWheels();
    operateBeep();
    operateLift();
    }
}