#ifndef _MENU_ENTRY_MINUTI_H
#define _MENU_ENTRY_MINUTI_H

#include "menu_entry_int.h"

namespace idipaolo {
	
	class MenuEntryMinuti : public MenuEntryInt {
		
		public:
			MenuEntryMinuti(Menu * menu,int * retVal);
			
			virtual void updateLcd();
		
		
	};
	
}

#endif
