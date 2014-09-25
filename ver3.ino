//TODO:inserire test



// include the library code:
#include <config.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>

#include "ds3231.h"
#include "pins.h"
#include "keyboard.h"
#include "menu.h"
#include "menu_entry.h"
#include "menu_entry_secondi.h"
#include "menu_entry_annaffia.h"
#include "menu_entry_ora.h"
#include "ann1_strategy.h"

#define DEBUG

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(PIN_LCD_RESET,
                  PIN_LCD_ENABLE, 
                  PIN_LCD_D4,
                  PIN_LCD_D5,
                  PIN_LCD_D6,
                  PIN_LCD_D7);



idipaolo::Keyboard keyboard(PIN_BACKWARD,
							PIN_OK,
							PIN_FORWARD);

idipaolo::Menu menu;

idipaolo::Ann1Strategy ann1Strategy(&lcd);

idipaolo::MenuEntry menuImpostaOra(&menu,"Imposta ora");

idipaolo::MenuEntry menuImpostaSecondi(&menu,"Imposta sec.");
idipaolo::MenuEntry menuImpostaMinuti(&menu,"Imposta min.");
idipaolo::MenuEntry menuImpostaOre(&menu,"Imposta ore");
idipaolo::MenuEntry menuImpostaOraInd(&menu,"Indietro");

idipaolo::MenuEntry menuVediOra(&menu,"Vedi ora");
idipaolo::MenuEntrySecondi menuSeconds(&menu,NULL);
//idipaolo::Menu
idipaolo::MenuEntryAnnaffia menuAnnaffia(&menu,&ann1Strategy);
idipaolo::MenuEntryOra menuOra(&menu);
							

/**
  SETUP

**/
void setup() {  

	#ifdef DEBUG
		Serial.begin(9600);
		Serial.println("Start");
	#endif 

	// set up the LCD's number of columns and rows: 
	lcd.begin(16, 2);
	// Print a message to the LCD.
	lcd.print("Avvio ...");
	
	//I2c
	Wire.begin();
	
	//init pompa
	ann1Strategy.init();
	
	//1st level
	menuAnnaffia.setNext(&menuVediOra);
	menuVediOra.setNext(&menuImpostaOra);
	menuImpostaOra.setNext(&menuAnnaffia);
	
	menuAnnaffia.setPrev(&menuImpostaOra);
	menuImpostaOra.setPrev(&menuVediOra);
	menuVediOra.setPrev(&menuAnnaffia);
	
	//2nd level Ora
	menuVediOra.setOk(&menuOra);
	
	menuOra.setPrev(&menuVediOra);
	menuOra.setNext(&menuVediOra);
	
	
	//2nd level ImpostaOra
	menuImpostaOra.setOk(&menuImpostaOre);
	menuImpostaOraInd.setOk(&menuImpostaOra);
	
	menuImpostaOre.setNext(&menuImpostaMinuti);
	menuImpostaMinuti.setNext(&menuImpostaSecondi);
	menuImpostaSecondi.setNext(&menuImpostaOraInd);
	menuImpostaOraInd.setNext(&menuImpostaOre);
	
	menuImpostaOre.setPrev(&menuImpostaOraInd);
	menuImpostaMinuti.setPrev(&menuImpostaOre);
	menuImpostaSecondi.setPrev(&menuImpostaMinuti);
	menuImpostaOraInd.setPrev(&menuImpostaSecondi);
	
	
	
	//Config menu
	menu.lcd = &lcd;
	menu.keyboard = &keyboard;
	
	menu.setCurrentMenuItem(&menuVediOra);
	//ann1Strategy.annaffia();

	delay(1000);

}

/**
  LOOP
**/
void loop(){
	
	keyboard.check_keys();
  
  delay(500);
  
}
