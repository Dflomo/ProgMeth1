/*************************************
 * Derek Florimonte
 * 909422688
 * dflomo@gmail.com
 * Cygwin g++ (4.8.3)
 *************************************/
#include "factory.h"

//Constructor
Factory:: Factory(){
	countSinceLastProduced = 0;
	production = NULL;
	produced = NULL;
};

//Deconstructor
Factory:: ~Factory(){


		delete production;
		delete produced;
		production = NULL;
		produced = NULL;

};


void Factory:: tick(){

	int transitionProd;
	countSinceLastProduced++;
	if(production == NULL){
		countSinceLastProduced = 0;
	}
	else if(countSinceLastProduced == production->getFront()){
		transitionProd = production->Dequeue();
		countSinceLastProduced = 0;

		if(produced == NULL){
			produced = new Queue();
			produced->Enqueue(transitionProd);
		}
		else{
			produced->Enqueue(transitionProd);
		}
	}
	

};

void Factory:: produceItem(int nextProd){
	if(production == NULL){
		production = new Queue();
		production->Enqueue(nextProd);
	}
	else{
		production->Enqueue(nextProd);
	}
};
		
int Factory:: getProducedItem(){
	
	if(produced == NULL){
		return -1;
	}
	else{
		return produced->getFront();
		
	}
};
		
int Factory:: productionCount(){
	if(production == NULL){
		return 0;
	}
	else{
		return production->getSize();
	}
};

int Factory:: producedCount(){
	if(produced == NULL){
		return 0;
	}
	else{
		return produced->getSize();
	}
};