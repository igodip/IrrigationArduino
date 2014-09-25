#ifndef _MENU_ENTRY_ANNAFFIA_H
#define _MENU_ENTRY_ANNAFFIA_H

#include "menu_entry.h"
#include "ann_strategy.h"

namespace idipaolo {
	
	class MenuEntryAnnaffia : public MenuEntry{
		public:
			MenuEntryAnnaffia(Menu * menu,AnnStrategy * annStrategy);
		
			virtual void onOkPressed();
			
		private:
		
			AnnStrategy * annStrategy;
	};
	
}

#endif