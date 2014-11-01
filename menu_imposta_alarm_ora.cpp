#include "menu_imposta_alarm_ora.h"

namespace idipaolo {
	
	MenuImpostaAlarmOra::MenuImpostaAlarmOra(Menu * menu,Alarm * alarm):
		MenuEntryOra(menu){
		
		this->alarm = alarm;
		
	}
	
	void MenuImpostaAlarmOra::onOkPressed() {
		
		alarm->hours = this->getCurrentValue();
		AlarmRW::writeAlarm(0,*alarm);
		
		this->menu->goBack();
	
	}

}