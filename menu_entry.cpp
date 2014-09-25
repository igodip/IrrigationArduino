#include "menu_entry.h"

namespace idipaolo {

	MenuEntry::MenuEntry(Menu * menu, char* msg){
		this->menu = menu;
		this->msg = msg;
		this->setNext(NULL);
		this->setPrev(NULL);
		this->setOk(NULL);
	}

	MenuEntry::MenuEntry(Menu * menu,char* msg,MenuItem * next, MenuItem * prev){
		this->menu = menu;
		this->setNext(next);
		this->setPrev(prev);
		this->msg = msg;
	}
	
	void MenuEntry::setNext(MenuItem * menuEntry) {
		this->next = menuEntry;
	}

	void MenuEntry::setPrev(MenuItem * menuEntry) {
		this->prev = menuEntry;
	}
	
	void MenuEntry::setOk(MenuItem * menuEntry){
		this->ok = menuEntry;
	}
	
	MenuItem * MenuEntry::getNext() const {
		return next;
	}
	
	MenuItem * MenuEntry::getPrev() const {
		return prev;
	}	
	
	MenuItem * MenuEntry::getOk() const {
		return ok;
	}
	
	void MenuEntry::onOkPressed(){
		if(this->getOk() != NULL){
			this->menu->setCurrentMenuItem(this->getOk());
		}
	}
	
	void MenuEntry::onBackPressed(){
		
		if(this->getPrev() != NULL){
			this->menu->setCurrentMenuItem(this->getPrev());
		}
		
	}
	
	void MenuEntry::onForwardPressed(){
		
		if(this->getNext() != NULL){
			this->menu->setCurrentMenuItem(this->getNext());
		}
		
	}
	
	void MenuEntry::updateLcd() {
		this->menu->lcd->clear();
		this->menu->lcd->setCursor(0,0);
		this->menu->lcd->print(msg);
	}
	


}