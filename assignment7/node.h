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

//CLASS NODE BEGINS
template <typename T>
class Node{
	public: 
		//Overloaded Constructor
		Node(T);

		T data;
		Node <T>* next;
};
//CLASS NODE ENDS

//NODE Constructor
template <typename T>
Node<T>:: Node(T a){
	next = NULL;
	data = a;
}

#endif