/*  DaemonBite Arcade Encoder
 *  Author: Mikael Norrgård <mick@daemonbite.com>
 *
 *  Copyright (c) 2020 Mikael Norrgård <http://daemonbite.com>
 *  
 *  GNU GENERAL PUBLIC LICENSE
 *  Version 3, 29 June 2007
 *  
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *  
 */

#include "Gamepad.h"

const char *gp_serial = "Daemonbite Arcade";

Gamepad_ Gamepad;           // Set up USB HID gamepad
bool usbUpdate = false; 


uint8_t  axis = 0x0f;
uint8_t  axisPrev = 0x0f;

uint16_t buttons = 0;
uint16_t buttonsPrev = 0;

void setup() 
{
  // Axis
  DDRF  &= ~B11110000; // Set A0-A3 as inputs

  // Buttons
  DDRD  &= ~B00011111; // Set PD0-PD4 as inputs

  Gamepad.reset();

}

void loop() 
{

    // Read axis and button inputs (bitwise results in a 1 when button/axis pressed)
    axis = (PINF & B11110000);
    buttons = (PIND & B00011111);

         
    // Has axis inputs changed?
    if(axis != axisPrev)
    {
        // UP + DOWN = UP, SOCD (Simultaneous Opposite Cardinal Directions) Cleaner
        if(axis & B10000000)
          Gamepad._GamepadReport.Y = -1;
        else if(axis & B01000000)
          Gamepad._GamepadReport.Y = 1;
        else
          Gamepad._GamepadReport.Y = 0;
        // UP + DOWN = NEUTRAL
        //Gamepad._GamepadReport.Y = ((axes & B01000000)>>6) - ((axes & B10000000)>>7);
      
      // LEFT + RIGHT = NEUTRAL  
      Gamepad._GamepadReport.X = ((axis & B00010000)>>4) - ((axis & B00100000)>>5);       
      axisPrev = axis;
      usbUpdate = true;
    }
  
    // Has button inputs changed?
    if(buttons != buttonsPrev)
    {
      Gamepad._GamepadReport.buttons = buttons;
      buttonsPrev = buttons;
      usbUpdate = true;
    }

    // Should gamepad data be sent to USB?
    if(usbUpdate)
    {
      Gamepad.send();
      usbUpdate = false;
    }
 
}
