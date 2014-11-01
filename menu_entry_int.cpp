#include "menu_entry_int.h"

namespace idipaolo {
	
	MenuEntryInt::MenuEntryInt(Menu * menu,uint8_t min_int,uint8_t max_int)
	{
		
		current_value = min_int;
		this->min_int = min_int;
		this->max_int = max_int;
		this->menu = menu;
	
	}
	
	void MenuEntryInt::onBackPressed(){
		
		--current_value;
		
		if(current_value > max_int)
			current_value = max_int;
		
		this->updateLcd();
	}
	
	void MenuEntryInt::onOkPressed(){
		
		//*ret_val = current_value;
		//this->menu->setCurrentMenuEntry()
		
	}
	
	void MenuEntryInt::onForwardPressed(){
		++current_value;
		
		if(current_value > max_int)
			current_value = min_int;
		
		this->updateLcd();
	}
	
	void MenuEntryInt::updateLcd() {
		this->menu->lcd->clear();
		this->menu->lcd->print(current_value);
	}
	
	uint8_t MenuEntryInt::getCurrentValue() const {
		return current_value;
		
	}
	
	
}