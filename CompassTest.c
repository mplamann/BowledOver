#pragma config(Sensor, S4,     sCompass,       sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "rdpartyrobotcdr-v2.4/drivers/HTMC-driver.h"

task main()
{
  while (true)
  {
    nxtDisplayCenteredTextLine(0, "%d", HTMCreadHeading(sCompass));
    HTMCsetTarget(sCompass, 0);
    int heading = HTMCreadRelativeHeading(sCompass);
    if (heading >= 90)
    {
      PlaySound(soundBeepBeep);
      wait10Msec(100);
    }
  }
}
