#ifndef _MENU_H
#define _MENU_H

#include "menu_item.h"
#include "keyboard.h"
#include <LiquidCrystal.h>

namespace idipaolo {
	
	class MenuItem;
	
	class Menu {
	
		public:
			Menu();
			
			
			LiquidCrystal * lcd;
			Keyboard * keyboard;
			
			void setCurrentMenuItem(MenuItem * menuItem);
			
			MenuItem * getCurrentMenuItem() const;
			
			void goBack();
			void updateLcd() const;
			
		protected:
			
			MenuItem * currentEntry;
			//MenuEntry * rootEntry;
			MenuItem * previousEntry;
			
			
	};

}

#endif