/* ============================================
DS3231 device library code is placed under the MIT license
Copyright (c) 2014 Di Paolo Igor

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
===============================================
*/

#ifndef _DS3231_H_
#define _DS3231_H_

#include "I2Cdev.h"
#include "datetime.h"

#define BCD2DEC(ARG) ((ARG & 0xF) + ((ARG & 0xF0) >> 4)*10)
#define DEC2BCD(ARG) ((ARG%10) | ((ARG/10) << 4))


#define SECONDS_FROM_1970_TO_2000 946684800
#define INVALID_STATE 255

// i2c slave address of the DS3231 chip
#define DS3231_I2C_ADDR             0x68

// timekeeping registers
#define DS3231_TIME_CAL_ADDR        0x00 //7 bytes
#define DS3231_ALARM1_ADDR          0x07 //
#define DS3231_ALARM2_ADDR          0x0B
#define DS3231_CONTROL_ADDR         0x0E
#define DS3231_STATUS_ADDR          0x0F
#define DS3231_AGING_OFFSET_ADDR    0x10
#define DS3231_TEMPERATURE_ADDR     0x11

//request addr
#define DS3231_RA_SECONDS           0x00
#define DS3231_RA_MINUTES           0x01
#define DS3231_RA_HOURS             0x02
#define DS3231_RA_DAY               0x03
#define DS3231_RA_DATE              0x04
#define DS3231_RA_MONTH             0x05
#define DS3231_RA_YEAR              0x06

//Alarm 1
#define DS3231_RA_AL1_SECONDS		0x07
#define DS3231_RA_AL1_MINUTES		0x08
#define DS3231_RA_AL1_HOURS		0x09
#define DS3231_RA_AL1_DAY	        0x0A //Day or date

//Alarm 2
#define DS3231_RA_AL2_MINUTES		0x0B
#define DS3231_RA_AL1_HOURS	        0x0C
#define DS3231_RA_AL1_DAY	        0x0D //Day or date

//Seconds 
#define DS3231_SECONDS_MASK	        0x7F

//Minutes
#define DS3231_MINUTES_MASK	        0x7F

//Hours
#define DS3231_HOURS_MODE_BIT       6 // 0 = 24-hour mode, 1 = 12-hour mode
#define DS3231_HOURS_AMPM_BIT       5 // 2nd HOURS_10 bit if in 24-hour mode
#define DS3231_HOURS_10_BIT         4
#define DS3231_HOURS_1_BIT          3
#define DS3231_HOURS_1_LENGTH       4
#define DS3231_HOURS_MASK	    0x1F

//Day
#define DS3231_DAY_MASK				0x07

//Date
#define DS3231_DATE_MASK			0x3F

//Month
#define DS3231_MONTH_MASK			0x1F

//Year
#define DS3231_YEAR_CENTURY_MASK		0x80 //Last bit in month byte
#define DS3231_YEAR_CENTURY_MASK_BIT	7
#define DS3231_YEAR_MASK				0xFF

// control register bits
#define DS3231_A1IE     0x01	//Alarm 1 Interrupt Enable
#define DS3231_A2IE     0x02	//Alarm 2 Interrupt Enable
#define DS3231_INTCN    0x04	//Interrupt Control
#define DS3231_RS		0x18	//Rate Select
#define DS3231_CONV		0x20	//Convert Temperature
#define DS3231_BBSQW	0x40	//Battery-Backed Square-Wave Enable
#define DS3231_EOSC		0x80	//Enable Oscillator

// status register bits
#define DS3231_STATUS_A1F      0x1
#define DS3231_STATUS_A2F      0x2
#define DS3231_STATUS_OSF      0x80

class DS3231 {

private:

	uint8_t devAddr;
	
	uint8_t buffer[7];

	bool mode12;

	int interruptPin;

protected:
	//void setAlarm(int num, const DateTime & date,const RtcCallback & callback, const int intPin);

public:
	DS3231();
	DS3231(uint8_t address);

	void initialize();
    bool testConnection();
	
	//Seconds
	uint8_t getSeconds();
	void setSeconds(uint8_t seconds) ;

	//Minutes
	uint8_t getMinutes() ;
	void setMinutes(uint8_t minutes);

	//Hours
	uint8_t getHours12() ;
	void setHours12(uint8_t hours);

	//HoursMode
	uint8_t getMode12() ;
	void setMode12(uint8_t mode);
    
	//Day
	uint8_t getDayOfWeek();
	void setDayOfWeek(uint8_t day);

	//Days
	//uint8_t

    //Month
    uint8_t getMonth();
    void setMonth(uint8_t month);

	//Year
	uint8_t getYear();
	void setYear(uint8_t year);

	//Date
	DateTime getDateTime();
	void setDateTime(DateTime date);

	//Alarms
	//void setAlarm1(const DateTime & date,const RtcCallback & callback);
	//void setAlarm2(const DateTime & date,const RtcCallback & callback);
	
	void unsetAlarm1();
	void unsetAlarm2();

	void setInterruptPin(const int interruptPin);
	int getInterruptPin() const;


	//Aging Offset


};

#endif
