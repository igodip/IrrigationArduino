#ifndef ANN_STRATEGY
#define ANN_STRATEGY

#include <LiquidCrystal.h>

namespace idipaolo {
	
	class AnnStrategy {
		public:
			
			AnnStrategy(LiquidCrystal * lcd){
				this->lcd = lcd;
			}
			
			virtual void init() const = 0;
			virtual void annaffia() const = 0;
		
		protected:
		
			LiquidCrystal  * lcd;
	};
	
}

#endif