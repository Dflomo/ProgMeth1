#include "map_item.h"

MapItem:: MapItem(){
	type = 'E';
}

MapItem:: MapItem(char buildCode){
	type = buildCode;
}

char MapItem:: getType(){
	return type;
}

void MapItem:: setType(char userBuildCode){
	type = userBuildCode;
}

ifstream& operator >> (ifstream& mapItemInput, MapItem& userItem){
	mapItemInput >> userItem.type;
	return mapItemInput;
}

ostream& operator << (ostream& mapItemOutput, const MapItem& fileItem){
	mapItemOutput << fileItem.type;
	return mapItemOutput;
}


