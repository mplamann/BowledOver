#pragma config(Sensor, S1,     TIR,                 sensorI2CCustomFastSkipStates)
#pragma config(Motor,  motorA,          VERTICAL,      tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  motorB,          HORIZONTAL,    tmotorNormal, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: TIR-test2.c 65 2011-09-06 13:52:43Z xander $
 */

/**
 * TIR-driver.h provides an API for the Dexter Industries Thermal Infrared Sensor.  This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 *
 * Credits:
 * - Big thanks to Dexter Industries for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 2.00 AND HIGHER.
 * Xander Soldaat (mightor_at_gmail.com)
 * 10 June 2011
 * version 0.1
 */


#include "drivers/TIR-driver.h"

float data[200];

task main () {
  int X = 0;

  memset(data, 0, sizeof(data));
  TIRresetSensor(TIR);
  nxtDisplayCenteredTextLine(0, "Dexter Industries");
  nxtDisplayCenteredTextLine(1, "Thermal Infrared");
  nxtDisplayCenteredTextLine(3, "Test 1");
  nxtDisplayCenteredTextLine(5, "Connect sensor");
  nxtDisplayCenteredTextLine(6, "to S1");
  wait1Msec(2000);

	eraseDisplay();

  // set emissivity for light skin
  TIRsetEmissivity(TIR, TIR_EM_SKIN_LIGHT);

  nMotorEncoderTarget[VERTICAL] = 200;
	motor[VERTICAL] = -20;
	while((nMotorRunState[VERTICAL] != runStateIdle) && (nMotorRunState[VERTICAL] != runStateHoldPosition)) EndTimeSlice();
	nMotorEncoderTarget[HORIZONTAL] = 360;
	motor[HORIZONTAL] = 20;
	while((nMotorRunState[HORIZONTAL] != runStateIdle) && (nMotorRunState[HORIZONTAL] != runStateHoldPosition)) EndTimeSlice();
	wait1Msec(500);
	nMotorEncoder[HORIZONTAL] = 0;
	nMotorEncoder[VERTICAL] = 0;
	PlaySound(soundBeepBeep);
	while(bSoundActive) EndTimeSlice();
  for (int i = 0; i < 80; i++) {
    wait1Msec(500);
    X = 0;
    memset(data, 0, sizeof(data));
	  nMotorEncoderTarget[HORIZONTAL] = 720;
	  motor[HORIZONTAL] = -40;
	  time1[T1] = 0;
	  while((nMotorRunState[HORIZONTAL] != runStateIdle) && (nMotorRunState[HORIZONTAL] != runStateHoldPosition)) {
	    data[X] = TIRreadObjectTemp(TIR);
	    X++;
	    wait1Msec(20);
	  }
    nxtDisplayBigTextLine(1, "X: %d", X);
	  nxtDisplayBigTextLine(3, "T: %d", time1[T1]);
	  nMotorEncoderTarget[VERTICAL] = 5;
	  motor[VERTICAL] = 20;

	  nMotorEncoderTarget[HORIZONTAL] = 720;
	  motor[HORIZONTAL] = 60;

	  for (int j = 0; j < 200; j++) {
	    if (data[j] != 0) {
	      writeDebugStream("%3.2f,", data[j]);
	      wait1Msec(5);
	    }
	  }
	  writeDebugStreamLine("");

	  while((nMotorRunState[HORIZONTAL] != runStateIdle) && (nMotorRunState[HORIZONTAL] != runStateHoldPosition))
	    EndTimeSlice();
	}
  bFloatDuringInactiveMotorPWM = true;
  wait1Msec(10);
}

/*
 * $Id: TIR-test2.c 65 2011-09-06 13:52:43Z xander $
 */
