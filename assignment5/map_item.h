#ifndef _MAPITEM_H_
#define _MAPITEM_H_

#include <sstream>
#include <fstream>
#include <string>
#include <iostream>


using namespace std;

class MapItem{
	public:

		MapItem();
		MapItem(char);

		//Accessors
		char getType();

		//Mutators
		void setType(char);

		//Overloaded
		friend ifstream& operator >> (ifstream&, MapItem&);
		friend ostream& operator << (ostream&, const MapItem&);

	private:
	
		char type;

};

#endif