#include "menu.h"

namespace idipaolo {
	
	Menu::Menu(){
		
		this->currentEntry = NULL;
		this->previousEntry = NULL;
		
	}
	
	void Menu::setCurrentMenuItem(MenuItem * menuItem){
		
		this->previousEntry = this->currentEntry;
		this->currentEntry = menuItem;
		
		this->keyboard->removeObserver(previousEntry);
		this->keyboard->addObserver(currentEntry);
		
		this->updateLcd();
		
	}
	
	void Menu::updateLcd() const{
		this->getCurrentMenuItem()->updateLcd();
	}
	
	MenuItem * Menu::getCurrentMenuItem() const {
		
		return currentEntry;
		
	}
	
	void Menu::goBack() {
	
		this->setCurrentMenuItem(previousEntry);
		
	}

}