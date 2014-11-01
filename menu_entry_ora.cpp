#include "menu_entry_ora.h"
#include "constants.h"

namespace idipaolo {
	
	MenuEntryOra::MenuEntryOra(Menu * menu) :
		MenuEntryInt(menu,0,23){
		
	}
	
	void MenuEntryOra::updateLcd() {
		
		this->menu->lcd->clear();
		this->menu->lcd->setCursor(0,0);
		this->menu->lcd->print(STR_HOURS);
		this->menu->lcd->setCursor(0,1);
		this->menu->lcd->print(this->getCurrentValue());
		
	}
}
