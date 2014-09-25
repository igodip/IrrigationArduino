#include "menu_entry_annaffia.h"
#include "arduino.h"

#undef DEBUG

namespace idipaolo {
	
	MenuEntryAnnaffia::MenuEntryAnnaffia(Menu * menu,AnnStrategy * annStrategy):
		MenuEntry(menu,"Inizia ad Ann.")
	{
		this->annStrategy = annStrategy;
	}
	
		//Sequenza

	void MenuEntryAnnaffia::onOkPressed(){
		
		#ifdef DEBUG
			Serial.println("Inizio annaffiatura");
		#endif
		
		this->annStrategy->annaffia();
		
		this->menu->setCurrentMenuItem(this);

	}
  

}