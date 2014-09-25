#include "test_keyboard.h"
#include "arduino.h"

namespace idipaolo {
	
	void TestKeyboard::onBackPressed() {
		Serial.println("Back pressed");
	}
	
	void TestKeyboard::onOkPressed(){
		Serial.println("Ok pressed");
	}
	
	void TestKeyboard::onForwardPressed(){
		Serial.println("Forward pressed");
	}


}