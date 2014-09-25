#include "menu_entry_ora.h"
#include "arduino.h"

#define DEBUG

namespace idipaolo {
	
	MenuEntryOra::MenuEntryOra(Menu * menu) :
		MenuEntry(menu,""){
		
	}
	
	void MenuEntryOra::updateLcd() {
		this->menu->lcd->clear();
		this->menu->lcd->setCursor(0,0);
		
		#ifdef DEBUG
			Serial.println("Connessione all' RTC");
		#endif
		
		
		DateTime time = ds3231.getDateTime();
		
		#ifdef DEBUG
			Serial.print(time.hours);
			Serial.print(":");
			Serial.print(time.minutes);
			Serial.print(":");
			Serial.println(time.seconds);
		#endif
		
		this->menu->lcd->print(time.hours);
		this->menu->lcd->print(":");
		this->menu->lcd->print(time.minutes);
		this->menu->lcd->print(":");
		this->menu->lcd->print(time.seconds);
		
	}
	
	void MenuEntryOra::onOkPressed() {
		this->updateLcd();
	}

}