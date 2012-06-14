#pragma config(Sensor, S1,     HTPB,                sensorI2CCustom9V)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: HTPB-exp6b.c 48 2011-02-13 20:35:38Z xander $
 */

/**
 * HTPB-driver.h provides an API for the HiTechnic Protoboard.  This is program 6b
 * for the HTPB experimenter's kit.
 *
 * Changelog:
 * - 0.1: Initial release
 *
 * Credits:
 * - Big thanks to HiTechnic for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 2.00 AND HIGHER.
 * Xander Soldaat (mightor_at_gmail.com)
 * 07 May 2010
 * version 0.1
 */

#include "drivers/HTPB-driver.h"

ubyte buttonmask = 0;

task main() {
  // The data to be written: 0x30 = 110000 binary,
  // makes B4,B5 digital ports outputs.
  HTPBsetupIO(HTPB, 0x30);

  while(true) {
    // Turn off all outputs
    HTPBwriteIO(HTPB, 0x00);

    eraseDisplay();
    nxtDisplayTextLine(2, "running");

    wait1Msec(random(5000) + 5000);

    // Turn on a random LED
    if(random(1) > 0) {
      HTPBwriteIO(HTPB, 0x10);
      buttonmask = 0x01;
    } else {
      HTPBwriteIO(HTPB, 0x20);
      buttonmask = 0x02;
    }

    time1[T1] = 0;

    while (HTPBreadIO(HTPB, 0xF3) != buttonmask) {
      wait1Msec(5);
    }

    eraseDisplay();
    nxtDisplayTextLine(2, "%d", time1[T1]);

    while (HTPBreadIO(HTPB, 0xF3) != 0x03) {
      wait1Msec(5);
    }
  }
}

/*
 * $Id: HTPB-exp6b.c 48 2011-02-13 20:35:38Z xander $
 */
