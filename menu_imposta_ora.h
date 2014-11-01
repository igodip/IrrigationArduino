#ifndef _MENU_IMPOSTA_ORA_H
#define _MENU_IMPOSTA_ORA_H

#include "menu_entry_ora.h"
#include "DS3231.h"

namespace idipaolo {
	
	class MenuImpostaOra : public MenuEntryOra {
		
		public:
			MenuImpostaOra(Menu * menu,DS3231 * rtc);
			
			virtual void onOkPressed();
		
		private:
			
			DS3231 * rtc;
		
	};

}

#endif