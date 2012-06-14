#pragma config(Sensor, S1,     DTMP,                sensorAnalogInactive)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/**
 * DTMP-driver.h provides an API for the Dexter Industries Temperature Probe.  This program
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
 * 13 June 2010
 * version 0.1
 */

#include "drivers/DTMP-driver.h"

task main() {
  float temp;
  byte state = 0;

  nxtDisplayTextLine(0, "Dexter Industries");
  nxtDisplayCenteredBigTextLine(1, "T Probe");
  nxtDisplayCenteredTextLine(3, "Test 1");
  nxtDisplayCenteredTextLine(5, "Connect sensor");
  nxtDisplayCenteredTextLine(6, "to S1");
  wait1Msec(2000);
  eraseDisplay();

  nxtDisplayTextLine(0, "Dexter Industries");
  nxtDisplayCenteredTextLine(7, "< switch scale >");
  //loop to read temp
  while (true) {
    switch(nNxtButtonPressed) {
      // If the right button is pressed, cycle through the scales
      case kRightButton:
        if (++state > 2)
          state = 0;
        while (nNxtButtonPressed != kNoButton) EndTimeSlice();
        break;

        // If the left button is pressed, cycle through the scales in reverse
      case kLeftButton:
        if (--state < 0)
          state = 2;
        // debounce the button
        while (nNxtButtonPressed != kNoButton) EndTimeSlice();
        break;
    }


    nxtDisplayCenteredBigTextLine(1, "Temp:");
    switch(state) {
      // if state: 0, display temp in degrees celcius
      case 0: DTMPreadTemp(DTMP, temp);
              nxtDisplayCenteredBigTextLine(3, "%4.2f", temp);
              nxtDisplayCenteredBigTextLine(5, "Celcius");
              break;

      // if state: 1, display temp in Fahrenheit
      case 1: DTMPreadTempF(DTMP, temp);
              nxtDisplayCenteredBigTextLine(3, "%4.2f", temp);
              nxtDisplayCenteredBigTextLine(5, "Fahrenh.");
              break;

      // if state: 2, display temp in Kelvin
      case 2: DTMPreadTempK(DTMP, temp);
              nxtDisplayCenteredBigTextLine(3, "%4.2f", temp);
              nxtDisplayCenteredBigTextLine(5, "Kelvin");
              break;
    }
    wait1Msec(10);
  }
}
