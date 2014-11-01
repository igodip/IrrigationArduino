#ifndef _MENU_IMPOSTA_ALARM_ORA_H
#define _MENU_IMPOSTA_ALARM_ORA_H

#include "menu_entry_ora.h"
#include "alarm_rw.h"

namespace idipaolo {
	
	class MenuImpostaAlarmOra : public MenuEntryOra {
		
		public:
			MenuImpostaAlarmOra(Menu * menu,Alarm * alarm);
		
			virtual void onOkPressed();
			
		private:
			Alarm * alarm;
	
	};

}

#endif