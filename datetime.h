#ifndef _DATE_TIME_H
#define _DATE_TIME_H

#include "arduino.h"

//Date class
class Date {
public:
	uint8_t dayOfWeek;
	uint8_t day;
	uint8_t month;
	uint16_t year;
	
};

//Time class
class Time {
public:
	uint8_t seconds;
	uint8_t minutes;
	uint8_t hours;

        bool operator<(const Time & obj) const {
          
          if(this->hours < obj.hours){
            return true;
          }
          
          if(this->minutes < obj.minutes) {
            return true;
          }
          
          if(this->seconds < obj.minutes){
            return true;
          } 
          
          return false;
        }
        
        bool operator>(const Time & obj) const{
          
          return obj < (*this);
        }
		
		
          
};

//DateTime class
class DateTime : public Time, public Date{
        //bool operator>
};

#endif
