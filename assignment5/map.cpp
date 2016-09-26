#include "map.h"
#include "map_item.h"


Map:: Map(){
	size = 0;
	items = NULL;
}

Map:: Map(int userSize){
	Map:: size = userSize;
		
		this->items = new MapItem[size*size];
		for(int i = 0; i < size*size; i++){
			this->items[i].setType('E');
		}
	
}

Map:: ~Map(){

		delete [] items;	
}

int Map:: getSize(){
	return size;
}

MapItem Map:: getMapItem(int xCoord, int yCoord){
	return items[(size*(xCoord)) + (yCoord)].getType();

}

void Map:: build(int xCoord, int yCoord, char userBuildCode){
	items[(size*(xCoord)) + (yCoord)].setType(userBuildCode);

}







ifstream& operator >> (ifstream& mapInput, Map& map){
	map = new Map();
	char userBuildCode;
	mapInput >> userBuildCode;
	map.size = userBuildCode;
	
	if(map.size <= 0){

	}
	else if(!mapInput.eof()){

		for (int i = 0; i < (map.size*map.size); i++){

			//To check if there is any of these test cases
			//If file input is anything other than the designated characters
			//input the next character.
			mapInput >> userBuildCode;
			if(userBuildCode == '5'){
				mapInput >> userBuildCode;
			}
			else if(userBuildCode == ' ' || userBuildCode == '\n'){
				mapInput >> userBuildCode;
				mapInput >> userBuildCode;
			}

			map.items[i].setType(userBuildCode);
		}	
	}
	
	return mapInput;
}







ofstream& operator << (ofstream& mapFileOut, const Map& map){
string mapChars;
// string mapSize = to_string(map.size);
	mapFileOut << map.size << endl;
		// mapFileOut << mapSize << endl;
		for (int i = 0; i < (map.size*map.size); i++){
			mapChars = map.items[i].getType();

			mapFileOut << mapChars << ' ';
		}	
	return mapFileOut;
}








ostream& operator << (ostream& mapOutput, const Map& map){

	if(map.size <= 0){

	}
	else{
		for (int i = 0; i < (map.size*map.size); i++){

			mapOutput << map.items[i].getType() << " ";

			//Holy Shit a Modulus
			if(((i+1) % map.size) == 0){
				mapOutput << endl;
			}
		}	
		mapOutput << endl;
	}

	return mapOutput;
}

