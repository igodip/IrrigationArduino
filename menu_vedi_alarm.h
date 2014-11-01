#ifndef _MENU_VEDI_ALARM
#define _MENU_VEDI_ALARM

#include "menu_entry.h"
#include "alarm.h"

namespace idipaolo {

	class MenuVediAlarm : public MenuEntry{

		public:
			MenuVediAlarm(Menu* menu,Alarm * alarm);

			virtual void updateLcd();

			virtual void onOkPressed();

		private:
			Alarm * alarm;

	};

}

#endif