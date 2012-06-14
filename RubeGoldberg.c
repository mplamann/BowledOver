#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S2, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S3,     sound,          sensorSoundDB)
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

#include "Victory.c"
const int SOUND_THRESHOLD = 95;
const int DRIVE_TIME = 5000;

void rotateAtPower(int rotatePower);

task main()
{
  while (SensorValue[sound] > 200)
  {}
  wait1Msec(1000);
  //PlaySound(soundBeepBeep);
  wait1Msec(200);
  while ((SensorValue[sound] < SOUND_THRESHOLD) || (SensorValue[sound] > 100))
  {
    writeDebugStreamLine("%d",SensorValue[sound]);
  }
  writeDebugStreamLine("%d",SensorValue[sound]);


  servo[flag] = 0;
    float theta = 0;
    float magnitude = 30;

    theta += PI/4;

    int xPower = magnitude * cos(theta);
    int yPower = magnitude * sin(theta);
      motor[motorWest] = yPower;
      motor[motorEast] = yPower;
      motor[motorNorth] = xPower;
      motor[motorSouth] = xPower;
      wait1Msec(DRIVE_TIME/2);
      motor[motorWest] = 0;
      motor[motorEast] = 0;
      motor[motorNorth] = 0;
      motor[motorSouth] = 0;
      PlaySound(soundBeepBeep);
      wait1Msec(2400);
      motor[motorWest] = yPower;
      motor[motorEast] = yPower;
      motor[motorNorth] = xPower;
      motor[motorSouth] = xPower;
      wait1Msec(DRIVE_TIME/2);
  StartTask(victory);
  wait1Msec(500);
  rotateAtPower(100);
  wait1Msec(3000);
  rotateAtPower(0);
}

void rotateAtPower(int rotatePower)
{
  motor[motorWest] = rotatePower;
  motor[motorEast] = -rotatePower;
  motor[motorNorth] = rotatePower;
  motor[motorSouth] = -rotatePower;
}
