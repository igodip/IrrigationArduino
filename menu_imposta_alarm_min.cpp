#include "menu_imposta_alarm_min.h"

namespace idipaolo {
	
	MenuImpostaAlarmMin::MenuImpostaAlarmMin(Menu * menu,Alarm * alarm):
		MenuEntryMinuti(menu){
		
		this->alarm = alarm;
		
	}
	
	void MenuImpostaAlarmMin::onOkPressed() {
		
		alarm->minutes = this->getCurrentValue();
		AlarmRW::writeAlarm(0,*alarm);
		
		this->menu->goBack();
	
	}

}

