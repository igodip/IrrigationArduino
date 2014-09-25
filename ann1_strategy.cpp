#include "ann1_strategy.h"
#include "arduino.h"

#define DEBUG

namespace idipaolo {
	
	const int numAnnaffiatoi = 9;
	const int annaffiatoi[numAnnaffiatoi] = {53,52,51,50,49,48,47,46,45};
	const int pompa = 44;
	//const int tempoTotale = 1170000 ; // secondi
	const int tPerAnnaffiatoio = 60000; //30s

	int currSequenza = -1;

	// 0 spento
	// 1 acceso

	const int numSequenza = 17;
	const int sequenza[numSequenza][numAnnaffiatoi +1] = { {0,0,0,0,0,0,0,0,0,0},
														   {1,0,0,0,0,0,0,0,0,1},
														   {1,1,0,0,0,0,0,0,0,1},
														   {0,1,0,0,0,0,0,0,0,1},
														   {0,1,1,0,0,0,0,0,0,1},
														   {0,0,1,0,0,0,0,0,0,1},
														   {0,0,1,1,0,0,0,0,0,1},
														   {0,0,0,1,0,0,0,0,0,1},
														   {0,0,0,1,1,0,0,0,0,1},
														   {0,0,0,0,1,0,0,0,0,1},
														   {0,0,0,0,1,1,0,0,0,1},
														   {0,0,0,0,0,1,0,0,0,1},
														   {0,0,0,0,0,1,1,0,0,1},
														   {0,0,0,0,0,0,1,0,0,1},
														   {0,0,0,0,0,0,1,0,1,1},
														   {0,0,0,0,0,0,0,0,1,1},
														   {0,0,0,0,0,0,0,0,0,0} } ;

	#define PUMP_MILLISECONDS      5000//140000
	#define PUMP_INTERVAL          1000

	const unsigned long durataSequenza[numSequenza] = {10000,PUMP_MILLISECONDS,PUMP_INTERVAL,PUMP_MILLISECONDS,PUMP_INTERVAL,PUMP_MILLISECONDS,PUMP_INTERVAL,PUMP_MILLISECONDS,PUMP_INTERVAL,PUMP_MILLISECONDS,PUMP_INTERVAL,PUMP_MILLISECONDS,PUMP_INTERVAL,PUMP_MILLISECONDS,PUMP_INTERVAL,PUMP_MILLISECONDS,1000};

	const char* messaggi[numSequenza] = {"Avvio ...       ",
										 "Pompa 1         ",
										 "Passo a Pompa 2 ",
										 "Pompa 2         ",
										 "Passo a Pompa 3 ",
										 "Pompa 3         ",
										 "Passo a Pompa 4 ",
										 "Pompa 4         ",
										 "Passo a Pompa 5 ",
										 "Pompa 5         ",
										 "Passo a Pompa 6 ",
										 "Pompa 6         ",
										 "Passo a Pompa 7 ",
										 "Pompa 7         ",
										 "Passo a Pompa 9 ",
										 "Pompa 9         ",
										 "Concluso.       "};
	
	Ann1Strategy::Ann1Strategy(LiquidCrystal * lcd):
		AnnStrategy(lcd)
	{
	
	}
	
	void Ann1Strategy::init() const {
		
		#ifdef DEBUG
			Serial.println("Inizializzazione annaffiatoi");
		#endif
		
		//Reset rele pompa
		pinMode(pompa,OUTPUT);
		digitalWrite(pompa,HIGH);

		//Reset rele innaffiatoi
		for(int i = 0;i < numAnnaffiatoi; i++){
			pinMode(annaffiatoi[i],OUTPUT); 
			digitalWrite(annaffiatoi[i],HIGH);
		}
		
	}
	
	void Ann1Strategy::annaffia() const {
		
		#ifdef DEBUG
			Serial.println("Inizio annaffiatura");
		#endif
		
		for(int i = 0; i < numSequenza;i++){
			
			this->lcd->setCursor(0, 0);
			this->lcd->print(messaggi[i]);
			
			digitalWrite(pompa,!sequenza[i][numAnnaffiatoi]); //La pompa la accendo
			
			for(int j = 0; j < numAnnaffiatoi;j++){
			  digitalWrite(annaffiatoi[j],!sequenza[i][j]);
			}
			delay(durataSequenza[i]);
		}
	}
	
}