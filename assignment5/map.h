#ifndef _MAP_H_
#define _MAP_H_

#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include "map_item.h"

using namespace std;

class Map{
	public:
		Map();
		explicit Map(int);
		~Map();

		//Accessors
		int getSize();
		MapItem getMapItem(int, int);

		//Mutators
		void build(int, int, char);

		//Overloaded
		friend ifstream& operator >> (ifstream&, Map&);
		friend ofstream& operator << (ofstream&, const Map&);
		friend ostream& operator << (ostream&, const Map&);

	
	private:

		int size;
		MapItem * items;
	
};


#endif
