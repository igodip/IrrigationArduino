#ifndef _MENU_ENTRY_SECONDI_H
#define _MENU_ENTRY_SECONDI_H

#include "menu_entry_int.h"

namespace idipaolo {
	
	class MenuEntrySecondi : public MenuEntryInt {
		
		public:
			MenuEntrySecondi(Menu * menu,int * retVal);
			
			virtual void updateLcd() const;
		
		
	};
	
}

#endif
