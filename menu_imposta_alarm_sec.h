#ifndef _MENU_IMPOSTA_ALARM_SEC_H
#define _MENU_IMPOSTA_ALARM_SEC_H

#include "menu_entry_secondi.h"
#include "alarm_rw.h"

namespace idipaolo {
	
	class MenuImpostaAlarmSec : public MenuEntrySecondi {
		
		public:
			MenuImpostaAlarmSec(Menu * menu,Alarm * alarm);
		
			virtual void onOkPressed();
			
		private:
			Alarm * alarm;
	
	};

}

#endif