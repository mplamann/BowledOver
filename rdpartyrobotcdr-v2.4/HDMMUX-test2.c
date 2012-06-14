#pragma config(Sensor, S1,     HDMMUX,              sensorI2CCustomFastSkipStates)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: HDMMUX-test2.c 49 2011-04-27 13:00:05Z xander $
 */

/**
 * HDMMUX-driver.h provides an API for the Holit Data Systems Motor MUX. This program
 * demonstrates how to use that API to control the motors attached to the MUX.
 *
 * Changelog:
 * - 0.1: Initial release
 * - 0.2: Removed common.h from list of includes
 *
 * Credits:
 * - Big thanks to Holit Data Systems for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 2.00 AND HIGHER.
 * Xander Soldaat (mightor_at_gmail.com)
 * 14 February 2011
 * version 0.2
 */

#include "drivers/HDMMUX-driver.h"


task main () {
  long encA  = 0;
  long encB  = 0;
  long encC  = 0;

  long timer = 0;

  ubyte motorStatus = 0;
  string motorAstatus;
  bool done = false;

  eraseDisplay();

  // Initialise all the internal variables
  HDMMUXinit();

  // Reset the encoders.  This can be done individually or all at once.
  // You should do this at the start of your program.
  HDMMotorEncoderResetAll(HDMMUX);

  // You can specify the type of braking that should be used when the motors
  // are sent the stop command.  The default is to use brake.
  HDMMotorSetBrake(mmotor_S1_1);

  // Specify a motor 1 to run for 2.5 seconds.
  HDMMotorSetTimeTarget(mmotor_S1_1, 2.50);

  // Tell the motors to start moving.
  HDMMotor(mmotor_S1_1, 50);

  // Reset the timer
  time1[T1] = 0;
  // Give the motor time to get started
  wait1Msec(50);
  while (!done) {
    // Retrieve the motor-MUX's status info and encoder counts
		HDMMUXreadStatus(HDMMUX, motorStatus, encA, encB, encC);

		// Use the HDMMotorBusy() function to see if a motor is busy or idle.
	  motorAstatus = HDMMotorBusy(mmotor_S1_1) ? "busy" : "idle";
		if (!HDMMotorBusy(mmotor_S1_1) && timer == 0) {
		  timer = time1[T1];
		  nxtDisplayTextLine(0,"Time: %dms", timer);
		  done = true;
		}

		// Display the info.
		nxtDisplayTextLine(6, "B: %5d (%s)", encB, motorAstatus);
    EndTimeSlice();
  }
  wait1Msec(5000);
}

/*
 * $Id: HDMMUX-test2.c 49 2011-04-27 13:00:05Z xander $
 */
