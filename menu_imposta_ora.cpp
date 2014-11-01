#include "menu_imposta_ora.h"

namespace idipaolo {
	MenuImpostaOra::MenuImpostaOra(Menu * menu,DS3231 * rtc) :
		MenuEntryOra(menu){
		
		this->rtc = rtc;
		
	}
		
	void MenuImpostaOra::onOkPressed() {
		
		this->rtc->setHours(this->getCurrentValue());
		this->menu->goBack();
	
	}
}