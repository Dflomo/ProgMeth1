/*************************************
 * Derek Florimonte
 * 909422688
 * dflomo@gmail.com
 * Cygwin g++ (4.8.3)
 *************************************/
#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "node.h"
#include <string>
#include <iostream>

using namespace std;

//QUEUE CLASS BEGINs
template <typename T>
class Queue{

	public:

		//Constructor
		Queue();
		//Destructor
		~Queue();

		//Accessors
		int size() const;
		bool isEmpty() const;
		T front() const;

		//Mutators
		void enqueue(T);
		T dequeue();

	private:
		Node<T> * Front;
		Node<T> * Back;
		int count;
};
//QUEUE CLASS ENDS

//Constructor
template <typename T>
Queue<T>:: Queue(){
	Front = NULL;
	Back = NULL;
	count = 0;
}

//Destructor
template <typename T>
Queue<T>:: ~Queue(){
	while(!isEmpty()){
		dequeue();
	}
}

//ENQUEUE - allows user to input a data type into the queue
template <typename T>
void Queue<T>:: enqueue(const T data){

	count++;
	if(Front == NULL){
		Front = new Node<T> (data);
		Back = Front;
	}
	else{
		Back->next = new Node<T>(data);
		Back = Back->next;
	}
}

//DEQUEUE - allows the user to delete the last element in the queue, and returns the data
template <typename T>
T Queue<T>:: dequeue(){
	T qReturn;

	Node<T> * temp = Front;

	if(Front == NULL){
		return T();
	}
	else{
		Front = Front->next;
		qReturn = temp->data;
		delete temp;
		count--;
		temp = NULL;
	}
	return qReturn;
}

//ISEMPTY - allows the user to see if the queue is empty, returns true or false
template <typename T>
template <typename T>
bool Queue<T>::isEmpty() const{

	return count == 0;

}

//FRONT - allows the user to access the data of the first element in the queue
template <typename T>
T Queue<T>:: front() const{

	return Front->data;

}

//SIZE - allows user to see the full size of the queue
template <typename T>
int Queue<T>:: size() const{
	return count;
}

#endif