#include "menu_entry_secondi.h"

namespace idipaolo {
	
	MenuEntrySecondi::MenuEntrySecondi(Menu * menu) :
		MenuEntryInt(menu,0,59) {
		
	}
	
	void MenuEntrySecondi::updateLcd() {
		
		this->menu->lcd->clear();
		this->menu->lcd->setCursor(0,0);
		this->menu->lcd->print("Secondi");
		this->menu->lcd->setCursor(0,1);
		this->menu->lcd->print(this->getCurrentValue());
		
	}

}