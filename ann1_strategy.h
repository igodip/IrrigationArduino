#ifndef ANN1_STRATEGY
#define ANN1_STRATEGY

#include "ann_strategy.h"

namespace idipaolo {
	
	class Ann1Strategy : public AnnStrategy {
		public:
		
			Ann1Strategy(LiquidCrystal * lcd);
			
			virtual void init() const;
			virtual void annaffia() const;
		
	};

}

#endif