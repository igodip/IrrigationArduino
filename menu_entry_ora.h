#ifndef _MENU_ENTRY_ORA
#define _MENU_ENTRY_ORA

#include "menu_entry.h"
#include "ds3231.h"

namespace idipaolo {
	
	class MenuEntryOra : public MenuEntry {
		
		public:
			MenuEntryOra(Menu * menu);
			
			virtual void updateLcd() ;
			
			virtual void onOkPressed();
			
		private:
		
			DS3231 ds3231;
	
	};
}

#endif