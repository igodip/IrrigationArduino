#include "menu_entry_minuti.h"
#include "constants.h"

namespace idipaolo {
	
	MenuEntryMinuti::MenuEntryMinuti(Menu * menu) :
		MenuEntryInt(menu,0,59){
		
	}
	
	void MenuEntryMinuti::updateLcd() {
		
		this->menu->lcd->clear();
		this->menu->lcd->setCursor(0,0);
		this->menu->lcd->print(STR_MINUTES);
		this->menu->lcd->setCursor(0,1);
		this->menu->lcd->print(this->getCurrentValue());
		
	}

}