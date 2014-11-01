#include "menu_imposta_alarm_sec.h"

namespace idipaolo {
	
	MenuImpostaAlarmSec::MenuImpostaAlarmSec(Menu * menu,Alarm * alarm):
		MenuEntrySecondi(menu){
		
		this->alarm = alarm;
		
	}
	
	void MenuImpostaAlarmSec::onOkPressed() {
		
		alarm->seconds = this->getCurrentValue();
		AlarmRW::writeAlarm(0,*alarm);
		
		this->menu->goBack();
	
	}

}