#pragma config(Sensor, S1,     HTSMUX,              sensorLowSpeed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: LEGOUS-SMUX-test1.c 48 2011-02-13 20:35:38Z xander $
 */

/**
 * LEGOUS-driver.h provides an API for the Lego US sensor.  This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 * - 0.2: More comments
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 2.00 AND HIGHER.
 * Xander Soldaat (mightor_at_gmail.com)
 * 25 November 2009
 * version 0.2
 */

#include "drivers/HTSMUX-driver.h"
#include "drivers/LEGOUS-driver.h"

// The sensor is connected to the first port
// of the SMUX which is connected to the NXT port S1.
// To access that sensor, we must use msensor_S1_1.  If the sensor
// were connected to 3rd port of the SMUX connected to the NXT port S4,
// we would use msensor_S4_3

// Give the sensor a nice easy to use name
const tMUXSensor LEGOUS = msensor_S1_1;

task main () {
  int dist = 0;

  nxtDisplayCenteredTextLine(0, "Lego");
  nxtDisplayCenteredBigTextLine(1, "US");
  nxtDisplayCenteredTextLine(3, "SMUX Test");
  nxtDisplayCenteredTextLine(5, "Connect SMUX to");
  nxtDisplayCenteredTextLine(6, "S1 and US sensor");
  nxtDisplayCenteredTextLine(7, "to SMUX Port 1");
  wait1Msec(2000);

  eraseDisplay();
  nxtDisplayTextLine(0, "Lego US Sensor");

  while(true) {
    // Read the current distance detected.
    dist = USreadDist(LEGOUS);

    // display the info from the sensor
    nxtDisplayTextLine(3, "Dist:  %3d cm", dist);
    wait10Msec(50);
  }
}

/*
 * $Id: LEGOUS-SMUX-test1.c 48 2011-02-13 20:35:38Z xander $
 */
