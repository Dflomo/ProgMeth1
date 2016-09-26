/*************************************
 * Derek Florimonte
 * 909422688
 * dflomo@gmail.com
 * Cygwin g++ (4.8.3)
 *************************************/
#ifndef __NO_OP_ITEM_H__
#define __NO_OP_ITEM_H__

#include "map_item.h"

class NoOpItem : public MapItem {
	public:

		//Constructor
		NoOpItem();
		//Virtual Constructor
		virtual ~NoOpItem();
		//tick - no function
		void tick();

		private:
};

#endif