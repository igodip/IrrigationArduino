#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#include "keyboard_observer.h"

//Maybe linkedList?
#define MAX_OBSERVERS 10

namespace idipaolo {
	
	class KeyboardObserver;
	
	class Keyboard {
		
		public:
			
			Keyboard(int key_back, int key_ok, int key_forward );
			void check_keys() const ;
			
			void addObserver(KeyboardObserver * observer);
			void removeObserver(KeyboardObserver * observer);
			unsigned int getNumObservers() const;
			
		protected:
			
			int pin_key_back;
			int pin_key_ok;
			int pin_key_forward;
			
			//Maybe linkedList?
			KeyboardObserver * observers[MAX_OBSERVERS];
			
			int obs_index;
		
	};

}

#endif