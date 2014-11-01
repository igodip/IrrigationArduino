#ifndef _MENU_VEDI_ORA
#define _MENU_VEDI_ORA

#include "menu_entry.h"
#include "ds3231.h"

namespace idipaolo {
	
	class MenuVediOra : public MenuEntry {
		
		public:
			MenuVediOra(Menu * menu,DS3231 * ds3231);
			
			virtual void updateLcd() ;
			
			virtual void onOkPressed();
			
		protected:
		
			DS3231 * ds3231;
	
	};
}

#endif