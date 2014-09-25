#ifndef _MENU_ITEM_H
#define _MENU_ITEM_H

#include "keyboard_observer.h"

namespace idipaolo {
	
	class MenuItem : public KeyboardObserver {
		
		public:
			virtual void updateLcd() = 0;
	};

}

#endif