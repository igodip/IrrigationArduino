#include "menu_vedi_ora.h"
#include "arduino.h"

#undef DEBUG

namespace idipaolo {
	
	MenuVediOra::MenuVediOra(Menu * menu,DS3231 * ds3231) :
		MenuEntry(menu,""){
		
		this->ds3231 = ds3231;
		
	}
	
	void MenuVediOra::updateLcd() {
		this->menu->lcd->clear();
		this->menu->lcd->setCursor(0,0);
		
		#ifdef DEBUG
			Serial.println("Connessione all' RTC");
		#endif
		
		
		DateTime time = this->ds3231->getDateTime();
		
		#ifdef DEBUG
			Serial.print(time.hours);
			Serial.print(":");
			Serial.print(time.minutes);
			Serial.print(":");
			Serial.println(time.seconds);
		#endif
		
		//TODO:Orribile ma temporaneo
		if(time.hours < 10)
			this->menu->lcd->print(0);
		
		this->menu->lcd->print(time.hours);
		this->menu->lcd->print(":");
		
		if(time.minutes < 10)
			this->menu->lcd->print(0);
		this->menu->lcd->print(time.minutes);
		this->menu->lcd->print(":");
		
		if(time.seconds < 10)
			this->menu->lcd->print(0);
		this->menu->lcd->print(time.seconds);
		
	}
	
	void MenuVediOra::onOkPressed() {
		this->updateLcd();
	}

}