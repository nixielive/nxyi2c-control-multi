/**
 * @file nxyi2c_host_template.ino
 * @author Takeshi Mori
 * @brief A sample of each tube given a different lighting pattern
 * 
 * @copyright Copyright (c) 2021 Takeshi Mori All Rights reserved.
 * 
 */
#include <Wire.h>
#include "from_nxyi2c_default.h"

// configuration
#define I2CADDR(INDEX) (21+INDEX)
const unsigned short TUBES_COUNT = 5;

// globals
unsigned short g_displayNumber;
NXYI2C_CMD g_cmd;

void sendCommand(const int dest_addr, const NXYI2C_CMD cmd)
{
  Wire.beginTransmission(dest_addr);
  Wire.write((unsigned char *)(&cmd), sizeof(cmd));
  Wire.endTransmission();
}

void setup()
{
  Wire.begin();

  // set patterns to NXYI2C
  g_cmd.command = nxyi2c_set_pattern;

  // Please wait until the NXYI2C self-check process is complete
  delay(10000);

  g_cmd.value = nxyi2c_pattern_show;
  sendCommand(I2CADDR(0), g_cmd);
  g_cmd.value = nxyi2c_pattern_fade_in;
  sendCommand(I2CADDR(1), g_cmd);
  g_cmd.value = nxyi2c_pattern_fade_out;
  sendCommand(I2CADDR(2), g_cmd);
  g_cmd.value = nxyi2c_pattern_fade_change;
  sendCommand(I2CADDR(3), g_cmd);
  g_cmd.value = nxyi2c_pattern_from_cloud;
  sendCommand(I2CADDR(4), g_cmd);

  // set duration of pattern
  g_cmd.command = nxyi2c_set_duration;
  g_cmd.value = 800;
  for (unsigned short index = 0; index < TUBES_COUNT; index++) {
    sendCommand(I2CADDR(index), g_cmd);
  }

  g_displayNumber = 0;
}

void loop()
{
  // put your main code here, to run repeatedly:

  // set display number
  g_cmd.command = nxyi2c_set_number;
  g_cmd.value = g_displayNumber;
  for (unsigned short index = 0; index < TUBES_COUNT; index++) {
    sendCommand(I2CADDR(index), g_cmd);
  }

  // start pattern
  g_cmd.command = nxyi2c_start; // value won't be used by start command
  for (unsigned short index = 0; index < TUBES_COUNT; index++) {
    sendCommand(I2CADDR(index), g_cmd);
  }
  g_displayNumber++;
  if (g_displayNumber > 9) {
    g_displayNumber = 0;
  }
  delay(1000);
}
