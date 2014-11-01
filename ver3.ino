
// include the library code:
#include <config.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>

#include "ds3231.h"
#include "pins.h"
#include "keyboard.h"
#include "menu.h"
#include "alarm.h"
#include "menu_entry.h"
#include "menu_entry_secondi.h"
#include "menu_entry_annaffia.h"
#include "menu_imposta_secondi.h"
#include "menu_imposta_min.h"
#include "menu_imposta_ora.h"
#include "menu_imposta_alarm_sec.h"
#include "menu_imposta_alarm_min.h"
#include "menu_imposta_alarm_ora.h"
#include "menu_entry_ora.h"
#include "menu_vedi_ora.h"
#include "menu_vedi_alarm.h"
#include "ann1_strategy.h"
#include "alarm_rw.h"

#undef DEBUG

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(PIN_LCD_RESET,
                  PIN_LCD_ENABLE, 
                  PIN_LCD_D4,
                  PIN_LCD_D5,
                  PIN_LCD_D6,
                  PIN_LCD_D7);
//Rtc
DS3231 rtc;

//Alarm
idipaolo::Alarm alarm;

idipaolo::Keyboard keyboard(PIN_BACKWARD,
							PIN_OK,
							PIN_FORWARD);

idipaolo::Menu menu;

idipaolo::Ann1Strategy ann1Strategy(&lcd);

//Lvl 1
idipaolo::MenuEntry menuVediOra(&menu,"Vedi ora");
idipaolo::MenuEntry menuImpostaOra(&menu,"Imposta ora");
idipaolo::MenuEntryAnnaffia menuAnnaffia(&menu,&ann1Strategy);
idipaolo::MenuEntry menuVediAlarm(&menu,"Vedi timer");
idipaolo::MenuEntry menuImpostaAlarm(&menu,"Imposta timer");

//Lvl 2 Imposta ora
idipaolo::MenuEntry menuImpostaSecondi(&menu,"Imposta sec.");
idipaolo::MenuEntry menuImpostaMinuti(&menu,"Imposta min.");
idipaolo::MenuEntry menuImpostaOre(&menu,"Imposta ore");
idipaolo::MenuEntry menuImpostaOraInd(&menu,"Indietro");

//Lvl 3 ImpostaOre
idipaolo::MenuImpostaOra menuSetOra(&menu,&rtc);

//Lvl 3 Imposta Min
idipaolo::MenuImpostaMin menuSetMin(&menu,&rtc);

//Lvl 3 Imposta sec
idipaolo::MenuImpostaSecondi menuSetSec(&menu,&rtc);

//Lvl 2 VediOra
idipaolo::MenuVediOra menuOra(&menu,&rtc);

//Lvl 2 VediAlarm
idipaolo::MenuVediAlarm menuAlarm(&menu,&alarm);

//Lvl 2 Imposta Alarm
idipaolo::MenuEntry menuImpostaSecAlarm(&menu,"Imposta sec.");
idipaolo::MenuEntry menuImpostaMinAlarm(&menu,"Imposta min.");
idipaolo::MenuEntry menuImpostaOreAlarm(&menu,"Imposta ore");
idipaolo::MenuEntry menuImpostaIndAlarm(&menu,"Indietro");

//Lvl 3 Imposta Ore alarm
idipaolo::MenuImpostaAlarmOra menuSetAlarmOra(&menu,&alarm);

//Lvl 3 Imposta Min alarm
idipaolo::MenuImpostaAlarmMin menuSetAlarmMin(&menu,&alarm);

//Lvl 3 Imposta Sec Alarm
idipaolo::MenuImpostaAlarmSec menuSetAlarmSec(&menu,&alarm);

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
	
	/**
		Read alarm
	**/
	
	idipaolo::AlarmRW::readAlarm(0,alarm);
	
	/**
		Start Menu
	**/

	//1st level
	menuAnnaffia.setNext(&menuVediOra);
	menuVediOra.setNext(&menuImpostaOra);
	menuImpostaOra.setNext(&menuVediAlarm);
	menuVediAlarm.setNext(&menuImpostaAlarm);
	menuImpostaAlarm.setNext(&menuAnnaffia);
	
	menuAnnaffia.setPrev(&menuImpostaAlarm);
	menuImpostaOra.setPrev(&menuVediOra);
	menuVediOra.setPrev(&menuAnnaffia);
	menuVediAlarm.setPrev(&menuImpostaOra);
	menuImpostaAlarm.setPrev(&menuVediAlarm);
	
	//2nd level Ora
	menuVediOra.setOk(&menuOra);
	
	menuOra.setPrev(&menuVediOra);
	menuOra.setNext(&menuVediOra);
	
	//2nd level Timer
	
	menuVediAlarm.setOk(&menuAlarm);
	menuAlarm.setPrev(&menuVediAlarm);
	menuAlarm.setNext(&menuVediAlarm);
	
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
	
	//3rd level Imposta minuti
	menuImpostaMinuti.setOk(&menuSetMin);
	
	//3rd level Imposta Secondi
	menuImpostaSecondi.setOk(&menuSetSec);
	
	//3rd level Imposta Ore
	menuImpostaOre.setOk(&menuSetOra);
	
	//2nd level Imposta allarme
	menuImpostaAlarm.setOk(&menuImpostaOreAlarm);
	menuImpostaIndAlarm.setOk(&menuImpostaAlarm);
	
	menuImpostaOreAlarm.setNext(&menuImpostaMinAlarm);
	menuImpostaMinAlarm.setNext(&menuImpostaSecAlarm);
	menuImpostaSecAlarm.setNext(&menuImpostaIndAlarm);
	menuImpostaIndAlarm.setNext(&menuImpostaOreAlarm);
	
	menuImpostaOreAlarm.setPrev(&menuImpostaIndAlarm);
	menuImpostaMinAlarm.setPrev(&menuImpostaOreAlarm);
	menuImpostaSecAlarm.setPrev(&menuImpostaMinAlarm);
	menuImpostaIndAlarm.setPrev(&menuImpostaSecAlarm);
	
	//3rd level Imposta minuti alarm
	menuImpostaMinAlarm.setOk(&menuSetAlarmMin);
	
	//3rd level Imposta sec alarm
	menuImpostaSecAlarm.setOk(&menuSetAlarmSec);
	
	//3rd level Imposta ore alarm
	menuImpostaOreAlarm.setOk(&menuSetAlarmOra);
	
	/**
		End Menu
	**/

	//Config menu
	menu.lcd = &lcd;
	menu.keyboard = &keyboard;
	
	menu.setCurrentMenuItem(&menuVediOra);

	delay(1000);

}

/**
  LOOP
**/

uint8_t check_counter = 0;
//const uint8_t scarto_max_sec = 10;

void loop(){
	
	keyboard.check_keys();
	
	//TODO:Migliorare il controllo
	if(check_counter == 70){
		
		Time time = rtc.getDateTime();
		if(time.hours == alarm.hours && time.minutes == alarm.minutes){
			
			ann1Strategy.annaffia();
			
		}
		
		check_counter = 0;
	}
  
	check_counter++;
	delay(300);
  
}
