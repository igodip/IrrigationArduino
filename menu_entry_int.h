#ifndef _MENU_ENTRY_INT_H
#define _MENU_ENTRY_INT_H

#include "menu_entry.h"
#include "arduino.h"

namespace idipaolo {
	
	class MenuEntryInt : public MenuItem {
		
		public:
			
			MenuEntryInt(Menu * menu,uint8_t min_int,uint8_t max_int);
			
			void onBackPressed();
			virtual void onOkPressed();
			void onForwardPressed();
			
			//Da rimuovere!
			virtual void updateLcd();
			
			uint8_t getCurrentValue() const;
		
		protected:
			Menu * menu;
		
		private:
			
			uint8_t current_value;
			uint8_t min_int;
			uint8_t max_int;
	};

}

#endif