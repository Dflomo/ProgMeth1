/*************************************
 * Derek Florimonte
 * 909422688
 * dflomo@gmail.com
 * Cygwin g++ (4.8.3)
 *************************************/
#ifndef __RESIDENTIAL_H__
#define __RESIDENTIAL_H__

#include "map_item.h"


class Residential: public MapItem{
	public:

		//Constructor
		Residential();
		//Virtual Deconstructor (MapItem Deconstructor)
		virtual ~Residential();

		//Tick will update the collected taxes
		void tick();
		//Collects taxes, and return a double amount
		double collectTaxes();

	private:
		int capacity;
		double taxRevenue;

};

#endif