/*
    Copyright 2009 Tom Parker

    This file is part of the Tumanako EVD5 BMS.

    The Tumanako EVD5 BMS is free software: you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public License as
    published by the Free Software Foundation, either version 3 of the License,
    or (at your option) any later version.

    The Tumanako EVD5 BMS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with the Tumanako EVD5 BMS.  If not, see 
    <http://www.gnu.org/licenses/>.
*/

/** 
 * How long to make ADC measurements for, see adc(). This is the high byte only, so multiply by 256.
 * Fosc is 2MHz, and we divide that by 4 and 4 again to get 12.5kHz, multiply by 0x5000 to get 163ms.
 * //  TODO create an EVD5.h?
 */
#define ADC_TIME 0x50

void tx(unsigned char c);
void txByte(unsigned char b);
void txShort(unsigned short i);

void sleep(unsigned char time);

void writeEEPROM(unsigned char address, unsigned char value);
unsigned char readEEPROM(unsigned char address);

unsigned short adc(unsigned char c);

#define green(time) RA5 = 1; RC2 = 0; sleep(time); RA5 = 0
#define red(time) RC2 = 1; RA5 = 0; sleep(time); RC2 = 0
#define crlf() tx(10); tx(13)

#define BIN(x) \
( ((0x##x##L & 0x00000001L) ? 0x01 : 0) \
| ((0x##x##L & 0x00000010L) ? 0x02 : 0) \
| ((0x##x##L & 0x00000100L) ? 0x04 : 0) \
| ((0x##x##L & 0x00001000L) ? 0x08 : 0) \
| ((0x##x##L & 0x00010000L) ? 0x10 : 0) \
| ((0x##x##L & 0x00100000L) ? 0x20 : 0) \
| ((0x##x##L & 0x01000000L) ? 0x40 : 0) \
| ((0x##x##L & 0x10000000L) ? 0x80 : 0))
