#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <string>
#include <iostream>
#include "node.h"

using namespace std;

class Queue{
	public:

		Queue();				//Constructor
		~Queue();				//Deconstructor

		//Accessors
		int front();
		bool isEmpty();
		int size();

		//Mutators
		void enqueue(int);		
		int dequeue();
	private:

		Node * beginning;
		Node * end;
		int count;
	
};

#endif
