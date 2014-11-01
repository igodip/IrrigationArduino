#ifndef _MENU_IMPOSTA_SECONDI_H
#define _MENU_IMPOSTA_SECONDI_H

#include "menu_entry_secondi.h"
#include "DS3231.h"

namespace idipaolo {
	
	class MenuImpostaSecondi : public MenuEntrySecondi {
		
		public:
			MenuImpostaSecondi(Menu * menu,DS3231 * rtc);
		
			virtual void onOkPressed();
			
		private:
		
			DS3231 * rtc;
		
		
	};
	
}

#endif