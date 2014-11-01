#ifndef _MENU_IMPOSTA_ALARM_MIN_H
#define _MENU_IMPOSTA_ALARM_MIN_H

#include "menu_entry_minuti.h"
#include "alarm_rw.h"

namespace idipaolo {
	
	class MenuImpostaAlarmMin : public MenuEntryMinuti {
		
		public:
			MenuImpostaAlarmMin(Menu * menu,Alarm * alarm);
		
			virtual void onOkPressed();
			
		private:
			Alarm * alarm;
	};
	
}

#endif