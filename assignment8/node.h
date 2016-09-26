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
		//Default Constructor
		Node();
		//Overloaded Constructor
		Node(T);
		//Deconstructor
		~Node();

		T data;
		Node <T>* left;
		Node <T>* right;
};
//CLASS NODE ENDS

//NODE Default Constructor
template <typename T>
Node<T>:: Node(){
	left = NULL;
	right = NULL;
	
}

//NODE Overloaded Constructor
template <typename T>
Node<T>:: Node(T a){
	left = NULL;
	right = NULL;
	data = a;
}

template <typename T>
Node<T>:: ~Node(){
	delete right;
	delete left;
	right = NULL;
	left = NULL;
}

#endif