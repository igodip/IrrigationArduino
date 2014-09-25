#ifndef _MENU_ENTRY_INT_H
#define _MENU_ENTRY_INT_H

#include "menu_entry.h"

namespace idipaolo {
	
	class MenuEntryInt : public MenuItem {
		
		public:
			
			MenuEntryInt(Menu * menu,int min_int,int max_int,int * retVal);
			
			void onBackPressed();
			void onOkPressed();
			void onForwardPressed();
			
			//Da rimuovere!
			void updateLcd() const;
			
			int getCurrentValue() const;
		
		protected:
			int * ret_val;
			Menu * menu;
		
		private:
			
			int current_value;
			int min_int;
			int max_int;
	};

}

#endif