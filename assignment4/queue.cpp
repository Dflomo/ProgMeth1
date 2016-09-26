#include "queue.h"


Queue :: Queue(){
	beginning = NULL;
	end = NULL;
	count = 0;
}


Queue :: ~Queue(){
	if (beginning == NULL){
	delete beginning;
	delete end;
	}
}

void Queue :: enqueue(int x){

	if(beginning == NULL){
		beginning = new Node;
		beginning->value = x;
		beginning->next = end; 
		count = 1;
	}
	else if(count == 1){
		Node * tempPtr = new Node;
		tempPtr->value = x;
		tempPtr->next = end;
		beginning->next = tempPtr;
		count++;
	}
	else{

		Node * tempPtr = new Node;
		Node * ptrPtr = beginning;

		while(ptrPtr.next != end){
			ptrPtr = ptrPtr->next;
		}
			
		ptrPtr = tempPtr; 
		ptrPtr->next = end;


	}


}

int Queue :: dequeue(){
	
	int valueDeleted = beginning.value;
	Node * tempPtr = beginning;
	delete tempPtr;

	return valueDeleted; 
}

int Queue :: front(){
	return beginning->value;
}

bool Queue :: isEmpty(){

	if(beginning == NULL){
		return true;
	}
	else{
		return false;
	}
}

int Queue :: size(){

	return count;

};


