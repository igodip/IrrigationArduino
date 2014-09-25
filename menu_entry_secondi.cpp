#include "menu_entry_secondi.h"

namespace idipaolo {
	
	MenuEntrySecondi::MenuEntrySecondi(Menu * menu,int * retVal) :
		MenuEntryInt(menu,0,59,retVal) {
		
	}
	
	void MenuEntrySecondi::updateLcd() const {
		
		this->menu->lcd->clear();
		this->menu->lcd->setCursor(0,0);
		this->menu->lcd->print("Secondi");
		this->menu->lcd->setCursor(0,1);
		this->menu->lcd->print(this->getCurrentValue());
		
	}

}