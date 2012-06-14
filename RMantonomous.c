#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Hubs,  S2, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S4,     compass,        sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     rSholder,      tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorLift,     tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     rbCollector,   tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     lSholder,      tmotorNormal, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C2_1,     lDrive,        tmotorNormal, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C2_2,     rDrive,        tmotorNormal, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    rFinger,              tServoStandard)
#pragma config(Servo,  srvo_S1_C2_2,    lFinger,              tServoStandard)
#pragma config(Servo,  srvo_S1_C2_3,    rWrist,               tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C2_4,    lWrist,               tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C2_5,    rElbow,               tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C2_6,    lElbow,               tServoContinuousRotation)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define TURN_RIGHT
#include "ManTonomousBase.c"
