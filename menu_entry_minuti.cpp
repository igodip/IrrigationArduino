#include "menu_entry_minuti.h"

namespace idipaolo {
	
	MenuEntryMinuti::MenuEntryMinuti(Menu * menu,int * retVal) :
		MenuEntryInt(menu,0,59,retVal){
		
	}
	
	void MenuEntryMinuti::updateLcd() const {
		
		this->menu->lcd->clear();
		this->menu->lcd->setCursor(0,0);
		this->menu->lcd->print("Minuti");
		this->menu->lcd->setCursor(1,0);
		this->menu->lcd->print(this->getCurrentValue());
		
	}

}