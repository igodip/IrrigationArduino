#ifndef _MENU_ENTRY_ORA_H
#define _MENU_ENTRY_ORA_H

#include "menu_entry_int.h"

namespace idipaolo {
	
	class MenuEntryOra : public MenuEntryInt {
		
		public:
		
			MenuEntryOra(Menu * menu);
			
			virtual void updateLcd();
	};
	
}

#endif