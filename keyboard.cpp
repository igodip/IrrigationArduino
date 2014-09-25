#include "keyboard.h"
#include "arduino.h"

#define DEBUG

namespace idipaolo {
	
	Keyboard::Keyboard(int key_back,
					   int key_ok,
					   int key_forward) 
					   {
		
		pin_key_back = key_back;
		pin_key_ok = key_ok;
		pin_key_forward = key_forward;
		
		pinMode(key_back,INPUT);
		pinMode(key_ok,INPUT);
		pinMode(key_forward,INPUT);
		
		obs_index = -1;
		
	}
	
	void Keyboard::check_keys() const {
		
		#ifdef DEBUG
			Serial.println("check");
			
		#endif
		
		
		if(digitalRead(pin_key_ok) == HIGH){
			
			#ifdef DEBUG
				Serial.println("Ok pressed");
			#endif
			
			
			for(int i = 0; i <= obs_index; ++i){
				observers[i]->onOkPressed();
			}
			

		}
		
		if(digitalRead(pin_key_back) == HIGH){
			
			#ifdef DEBUG
				Serial.println("back pressed");
			
			#endif
			
			for(int i = 0; i <= obs_index; ++i){
				observers[i]->onBackPressed();
			}
			
		}
		
		if(digitalRead(pin_key_forward) == HIGH){
			
			#ifdef DEBUG
				Serial.println("forward pressed");
			
			#endif
			
			for(int i = 0; i <= obs_index; ++i){
				observers[i]->onForwardPressed();
			}

		}
		
		
	}
	
	void Keyboard::addObserver(KeyboardObserver* observer) {
		
		if(obs_index < MAX_OBSERVERS-1) {
			
			#ifdef DEBUG
				
				Serial.println("Aggiunto observer");
				
			#endif
			
			++(this->obs_index);
			observers[obs_index] = observer;
			
		}
		
	}
	
	//TODO: Tofix
	void Keyboard::removeObserver(KeyboardObserver* observer) {
		
		if(obs_index >= 0){
		
			#ifdef DEBUG
				
			Serial.println("Rimosso observer");
				
			#endif
			--obs_index;
			//No need to delete pointer
		}
		
	}
	
	unsigned int Keyboard::getNumObservers() const {
		return obs_index +1;
	}

}