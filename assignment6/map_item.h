/*************************************
 * Derek Florimonte
 * 909422688
 * dflomo@gmail.com
 * Cygwin g++ (4.8.3)
 *************************************/
#ifndef __MAP_ITEM_H__
#define __MAP_ITEM_H__

#include <iostream>

#include "queue.h"

using namespace std;

class MapItem{
	public:

		//Constructor
		MapItem();
		//Virtual Destructor used by other items
		virtual ~MapItem();
		//Virtual tick(), used to update other items
		virtual void tick() = 0;

};

#endif