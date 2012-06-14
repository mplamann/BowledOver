#pragma config(Sensor, S1,     HTSMUX,              sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: HTIRS-SMUX-test1.c 48 2011-02-13 20:35:38Z xander $
 */

/**
 * HTIRS-driver.h provides an API for the HiTechnic IR Seeker.  This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 * - 0.2: More comments
 *
 * Credits:
 * - Big thanks to HiTechnic for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 2.00 AND HIGHER.
 * Xander Soldaat (mightor_at_gmail.com)
 * 25 November 2009
 * version 0.2
 */

#include "drivers/HTSMUX-driver.h"
#include "drivers/HTIRS-driver.h"

// The sensor is connected to the first port
// of the SMUX which is connected to the NXT port S1.
// To access that sensor, we must use msensor_S1_1.  If the sensor
// were connected to 3rd port of the SMUX connected to the NXT port S4,
// we would use msensor_S4_3

// Give the sensor a nice easy to use name
const tMUXSensor HTIRS = msensor_S1_1;

task main () {
  int _dir = 0;
	int dcS1, dcS2, dcS3, dcS4, dcS5 = 0;

  nxtDisplayCenteredTextLine(0, "HiTechnic");
  nxtDisplayCenteredBigTextLine(1, "IR Seekr");
  nxtDisplayCenteredTextLine(3, "SMUX Test");
  nxtDisplayCenteredTextLine(5, "Connect SMUX to");
  nxtDisplayCenteredTextLine(6, "S1 and IRS to");
  nxtDisplayCenteredTextLine(7, "SMUX Port 1");
  wait1Msec(2000);

  while(true) {
    eraseDisplay();
    // read all of the sensors' values at once,
    // exit the app if an error occurs
    if (! HTIRSreadAllStrength(HTIRS, dcS1, dcS2, dcS3, dcS4, dcS5)) {
      nxtDisplayTextLine(4, "ERROR!!");
      wait1Msec(2000);
      StopAllTasks();
    }

    // read the direction from which the signal is coming,
    // exit the app if an error occurs
    _dir = HTIRSreadDir(HTIRS);
    if (_dir < 0) {
      nxtDisplayTextLine(4, "ERROR!!");
      wait1Msec(2000);
      StopAllTasks();
    }

    // display the info from the sensor
    nxtDisplayTextLine(0,"HT IR Seeker");
    nxtDisplayTextLine(2, "dir: %d", _dir);
    nxtDisplayTextLine(3, "S1: %3d", dcS1);
    nxtDisplayTextLine(4, "S2: %3d", dcS2);
    nxtDisplayTextLine(5, "S3: %3d", dcS3);
    nxtDisplayTextLine(6, "S4: %3d", dcS4);
    nxtDisplayTextLine(7, "S5: %3d", dcS5);
    wait10Msec(100);
  }
}

/*
 * $Id: HTIRS-SMUX-test1.c 48 2011-02-13 20:35:38Z xander $
 */
