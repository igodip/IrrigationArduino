#ifndef _ALARM_RW_H
#define _ALARM_RW_H

#include "arduino.h"
#include "constants.h"
#include "alarm.h"
#include <EEPROM.h>

namespace idipaolo {
	
	class AlarmRW {
		public:
			
			static void readAlarm(uint8_t pos,Alarm & alarm);
			static void writeAlarm(uint8_t pos,const Alarm & alarm);
		
	};
	
}

#endif