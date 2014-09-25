#ifndef _MENU_ENTRY_H_
#define _MENU_ENTRY_H_

#include "keyboard_observer.h"
#include "menu_item.h"
#include "menu.h"

namespace idipaolo {
	
	class Menu;
	
	class MenuEntry : public MenuItem {
		
		public:
			
			MenuEntry(Menu * menu,char * msg);
			MenuEntry(Menu * menu,char * msg,MenuItem * next, MenuItem * prev);
			
			MenuItem * getNext() const;
			MenuItem * getPrev() const;
			MenuItem * getOk() const;
			
			void setNext(MenuItem * next);
			void setPrev(MenuItem * prev);
			void setOk(MenuItem * ok);
			
			virtual void onBackPressed() ;
			virtual void onForwardPressed();
			virtual void onOkPressed();
			
			virtual void updateLcd() const;
			
		protected:
		
			Menu * menu;
			char * msg;
			
		private:
		
			MenuItem * next;
			MenuItem * prev;
			MenuItem * ok;
			
			
			
	
	};

}

#endif