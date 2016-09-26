#include "queue.h"
template <typename T>
Queue<T>:: Queue(){
	Front = NULL;
	Back = NULL;
	count = 0;
}

template <typename T>
Queue<T>:: ~Queue(){
	if(Front == NULL){
		delete Front;
		delete Back;
	}
}

//*****************GETSIZE**************
template <typename T>
int Queue<T>:: size(){
	return count;
}

//********************ENQUEUE******************
template <typename T>
void Queue<T>:: enqueue(const T &a){

	count++;
	if(Front == NULL){
		Front = new Node(a);
		Back = Front;
	}
	else{
		Back->next = new Node(a);
		Back = Back->next;
	}
}

//*******************DEQUEUE*******************
template <typename T>
int Queue<T>:: dequeue(){

	Node * temp = Front;

	if(Front == NULL){
		delete temp;
	}
	else{
		Front = Front->next;
		return temp->data;
		delete temp;
		count--;
	}
}

template <typename T>
bool Queue<T>::isEmpty(){

	return count == 0;

}

template <typename T>
int Queue<T>:: front(){

	return Front;

}

