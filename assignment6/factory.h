/*************************************
 * Derek Florimonte
 * 909422688
 * dflomo@gmail.com
 * Cygwin g++ (4.8.3)
 *************************************/
#ifndef __FACTORY_H__
#define __FACTORY_H__

#include "map_item.h"

class Factory : public MapItem{
	public:

		//Constructor
		Factory();
		//Virtual Destructor (MapItem Deconstructor)
		virtual ~Factory();

		//tick - updates the production and produced queues
		void tick();
		//produceItem - puts an item into queue (integer for now)
		void produceItem(int);
		//getProducedItem- returns the last queued item and dequeues
		int getProducedItem();
		//productionCount - returns the size of the production queue
		int productionCount();
		//producedCount - returns the size of the produced queue
		int producedCount();

	private:

		int countSinceLastProduced;
		Queue * production;
		Queue * produced;

};

#endif
