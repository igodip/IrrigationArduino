#include "menu_imposta_min.h"

namespace idipaolo {
	
	MenuImpostaMin::MenuImpostaMin(Menu * menu,DS3231 * rtc):
		MenuEntryMinuti(menu){
		
		this->rtc = rtc;
		
	}
	
	void MenuImpostaMin::onOkPressed() {
		
		this->rtc->setMinutes(this->getCurrentValue());
		this->menu->goBack();
	
	}

}