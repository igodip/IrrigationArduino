#include "alarm_rw.h"

namespace idipaolo {
	
	void AlarmRW::readAlarm(uint8_t pos,Alarm & alarm) {
		
		uint8_t alarmSize = sizeof(alarm);
		
		for(uint16_t i = 0;i < alarmSize; ++i){

			 *((char*)&alarm + i) = EEPROM.read(EE_ALARMS + i);

		}
		

	}

	void AlarmRW::writeAlarm(uint8_t pos,const Alarm & alarm){

		uint8_t alarmSize = sizeof(alarm);
		
		for(uint16_t i = 0;i < alarmSize;++i){

			EEPROM.write(EE_ALARMS+i,*((char*)&alarm + i));
		}
		

		
		
	}
}