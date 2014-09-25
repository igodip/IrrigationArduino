#include "menu_entry_int.h"

namespace idipaolo {
	
	MenuEntryInt::MenuEntryInt(Menu * menu,int min_int,int max_int,int * retVal)
	{
		
		current_value = min_int;
		this->min_int = min_int;
		this->max_int = max_int;
		this->ret_val = retVal;
		this->menu = menu;
	
	}
	
	void MenuEntryInt::onBackPressed(){
		
		--current_value;
		
		if(current_value < min_int)
			current_value = max_int;
		
		this->updateLcd();
	}
	
	void MenuEntryInt::onOkPressed(){
		
		*ret_val = current_value;
		//this->menu->setCurrentMenuEntry()
		
	}
	
	void MenuEntryInt::onForwardPressed(){
		++current_value;
		
		if(current_value > max_int)
			current_value = min_int;
		
		this->updateLcd();
	}
	
	void MenuEntryInt::updateLcd() const{
		this->menu->lcd->clear();
		this->menu->lcd->print(current_value);
	}
	
	int MenuEntryInt::getCurrentValue() const {
		return current_value;
		
	}
	
	
}