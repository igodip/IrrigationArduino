#include "menu_imposta_secondi.h"

namespace idipaolo {
	MenuImpostaSecondi::MenuImpostaSecondi(Menu * menu,DS3231 * rtc) : 
		MenuEntrySecondi(menu){
		
		this->rtc = rtc;
		
	}
		
	void MenuImpostaSecondi::onOkPressed() {
		
		this->rtc->setSeconds(this->getCurrentValue());
		this->menu->goBack();
	
	}
}