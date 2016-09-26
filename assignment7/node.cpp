#include "node.h"

//NODE Constructor
template <typename T>
Node<T>:: Node(int a){
	next = NULL;
	data = a;
}
 