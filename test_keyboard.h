#ifndef _TEST_KEYBOARD_H
#define _TEST_KEYBOARD_H

#include "keyboard_observer.h"

namespace idipaolo {
	
	class TestKeyboard : public KeyboardObserver {
		public:
			
			void onBackPressed();
			void onOkPressed();
			void onForwardPressed();
		
	};

}

#endif