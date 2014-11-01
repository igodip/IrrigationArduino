#ifndef _MENU_IMPOSTA_MIN_H
#define _MENU_IMPOSTA_MIN_H

#include "DS3231.h"
#include "menu_entry_minuti.h"

namespace idipaolo {
	
	class MenuImpostaMin : public MenuEntryMinuti {
		
		public:
			MenuImpostaMin(Menu * menu,DS3231 * rtc);
		
			virtual void onOkPressed();
			
		private:
		
			DS3231 * rtc;
		
		
	};
	
}

#endif