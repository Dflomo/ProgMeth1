/*************************************
 * Derek Florimonte
 * 909422688
 * dflomo@gmail.com
 * Cygwin g++ (4.8.3)
 *************************************/
#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "node.h"
#include <stddef.h>

using namespace std;

class Queue{

	public:
		Queue();
		explicit Queue(int);
		~Queue();

		int getSize();
		void Enqueue(int);
		int Dequeue();
		int getFront();

	private:
		Node * Front;
		Node * Back;
		int count;

};

#endif