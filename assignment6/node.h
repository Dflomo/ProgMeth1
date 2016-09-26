/*************************************
 * Derek Florimonte
 * 909422688
 * dflomo@gmail.com
 * Cygwin g++ (4.8.3)
 *************************************/
#ifndef __NODE_H__
#define __NODE_H__

#include <stddef.h>

using namespace std;

class Node{
	public: 
		Node(int);

		int data;
		Node * next;
};

#endif