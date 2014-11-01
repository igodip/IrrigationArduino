#include "menu_vedi_alarm.h"
#include "arduino.h"

namespace idipaolo {


	MenuVediAlarm::MenuVediAlarm(Menu * menu,Alarm * alarm) :
		MenuEntry(menu,""){
		
		this->alarm = alarm;
		
	}

	void MenuVediAlarm::updateLcd() {
		this->menu->lcd->clear();
		this->menu->lcd->setCursor(0,0);
		
		Time * time = this->alarm;
		
		#ifdef DEBUG
			Serial.print(time->hours);
			Serial.print(":");
			Serial.print(time->minutes);
			Serial.print(":");
			Serial.println(time->seconds);
		#endif
		
		//Orribile ma temporaneo
		if(time->hours < 10)
			this->menu->lcd->print(0);
		
		this->menu->lcd->print(time->hours);
		this->menu->lcd->print(":");
		
		if(time->minutes < 10)
			this->menu->lcd->print(0);
		this->menu->lcd->print(time->minutes);
		this->menu->lcd->print(":");
		
		if(time->seconds < 10)
			this->menu->lcd->print(0);
		this->menu->lcd->print(time->seconds);
		
	}
	
	void MenuVediAlarm::onOkPressed() {
		this->updateLcd();
	}
}
