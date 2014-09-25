#ifndef _KEYBOARD_OBSERVER_H
#define _KEYBOARD_OBSERVER_H

#include "keyboard.h"

namespace idipaolo {

	enum Key {
		KEY_BACK,
		KEY_OK,
		KEY_FORWARD
	};

	class KeyboardObserver {
		
		public:
			virtual void onBackPressed() = 0;
			virtual void onOkPressed() = 0;
			virtual void onForwardPressed() = 0;
		
		
	};
	
	
}

#endif