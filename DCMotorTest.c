#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorNone, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorNone, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"	 //Include file to "handle" the Bluetooth messages.

void initializeRobot()
{
  return;
}

task main()
{
  initializeRobot();

  waitForStart();

  while (true)
  {
    getJoystickSettings(joystick);
    //motor[motorD] = joystick.joy1_y2 / 128.0 * 100;
    //motor[motorE] = joystick.joy1_y1 / 128.0 * 100;
    int motorSpd = 0;
    if (joy1Btn(4))
      motorSpd = 25;
    else if (joy1Btn(2))
      motorSpd = -25;
    motor[motorD] = motorSpd;
    motor[motorE] = motorSpd;
    motor[motorF] = motorSpd;
    motor[motorG] = motorSpd;
  }
}
