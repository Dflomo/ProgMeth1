/*************************************
 * Derek Florimonte
 * 909422688
 * dflomo@gmail.com
 * Cygwin g++ (4.8.3)
 *************************************/
#include "queue.h"

Queue:: Queue(){
	Front = NULL;
	Back = NULL;
	count = 0;
};

Queue:: Queue(int a){
	Front = new Node(a);
	Back = Front;
	count++;
};

Queue:: ~Queue(){
	Node * temp;
	while(Front != NULL){
		temp = Front;
		Front = Front->next;
		delete temp;
		count--;
	}	

};

//*****************GETSIZE**************
int Queue:: getSize(){
	return count;
};

//********************ENQUEUE******************
void Queue:: Enqueue(int a){

	count++;
	if(Front == NULL){
		Front = new Node(a);
		Back = Front;
	}
	else{
		Back->next = new Node(a);
		Back = Back->next;
	}
};

//*******************DEQUEUE*******************
int Queue:: Dequeue(){
	int tempNum = Front->data;
	Node * temp = Front;

	if(Front != NULL){
		temp = Front;
		Front = Front->next;
		
		delete temp;
		count--;
	}
	return tempNum;
};

int Queue :: getFront(){

	return Front->data;

};

