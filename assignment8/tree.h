/*************************************
 * Derek Florimonte
 * 909422688
 * dflomo@gmail.com
 * Cygwin g++ (4.8.3)
 *************************************/
#ifndef __TREE_H__
#define __TREE_H__

#include "node.h"
#include <string>
#include <iostream>

using namespace std;

//***************TREE CLASS BEGINS***************
template <typename T>
class Tree{

	public:

		//Constructor
		Tree();
		//Destructor
		~Tree();

		//Accessors
		bool contains(T) const;
		bool isEmpty() const;

		bool isFull()const;
		bool isfullFunction(Node<T>*)const;

		int height() const;
		int heightFunction(Node<T>*) const;

		void preorder()const;
		void inorder()const;
		void postorder()const;
		void preorderFunction(Node<T>*) const;
		void inorderFunction(Node<T>*) const;
		void postorderFunction(Node<T>*) const;

		//Mutators
		void insert(T);

		void remove(T);
		void removeFunction(Node<T>*);
	private:
		Node<T> * root;
};
//***************TREE CLASS ENDS***************

//TREE Default Constructor
template <typename T>
Tree<T>:: Tree(){
	root = NULL;

}

//TREE Destructor
template <typename T>
Tree<T>:: ~Tree(){
	delete root;
}

//INSERT - Allows user to insert value into the appropriate space on the tree
template <typename T>
void Tree<T>:: insert(T newInfo){
	Node<T>* nodeParent = root;
	Node<T>* nodeCurr = root;
	
	if(root == NULL){
		root = new Node<T>(newInfo);
	}
	else{
		while(nodeCurr != NULL){
			nodeParent = nodeCurr;
			if(newInfo > nodeCurr->data){
				nodeCurr = nodeCurr->right;
			}
			else{

				nodeCurr = nodeCurr->left;
			}
		}

		if(newInfo < nodeParent->data){
			nodeParent->left = new Node<T>(newInfo);
		}
		else{
			nodeParent->right = new Node<T>(newInfo);
		}

	}
}

//REMOVE - Recursively deletes sepcificed node, and reorganizes appropriately
template <typename T>
void Tree<T>:: remove(T oldInfo){
	root = NULL;
	//Got stuck... I tried to remove recursively
// 	Node<T>* itemToBeDeleted = root;

// 	if(contains(oldInfo)){
// 		while(itemToBeDeleted != NULL){
// 			if(itemToBeDeleted->data == oldInfo){
// 				removeFunction(itemToBeDeleted);
// 			}
// 			else{
// 				if(oldInfo > itemToBeDeleted->data){
// 					itemToBeDeleted = itemToBeDeleted->right;
// 				}
// 				else{
// 					itemToBeDeleted = itemToBeDeleted->left;
// 				}
// 			}
// 		}
// 	}
// 	else{
// 		cout << "Does not contain the data you wish to remove" << endl;
// 	}
}

//Supplement(REMOVE) - Allows Recursive calls for the remove function
template <typename T>
void Tree<T>::removeFunction(Node<T> * oldInfo){

  // Node<T>* tempPtr = oldInfo;
  // if (oldInfo == root){
  //   delete root;
  //   root = NULL;
  // }
  // //Deletes a Leaf
  //   if ((oldInfo->left == NULL) && (oldInfo->right == NULL)){
  //     delete oldInfo;
  //     oldInfo = NULL;
  //   }
  //   else if ((oldInfo->right != NULL) && (oldInfo->left == NULL)){
  //     tempPtr = oldInfo;
  //     oldInfo = oldInfo->right;
  //     delete tempPtr;
  //   }
  //   else if ((oldInfo->right == NULL) && (oldInfo->left != NULL)){
  //     tempPtr = oldInfo;
  //     oldInfo = oldInfo->left;
  //     delete tempPtr;
  //   }
  //   else{
 
  //     Node<T>* checkPtr = oldInfo->right;
  //     if(checkPtr->left != NULL){
  //     checkPtr = checkPtr->left;
  //     }
  //     else{

  //     	checkPtr = checkPtr->right;
  //       oldInfo->data = checkPtr->data;
  //     }
  //     checkPtr = NULL;
  // }
}
	


//CONTAINS - Allows users to check if a value exists in the tree
template <typename T>
bool Tree<T>:: contains(T key) const{
	bool found = false;
	Node<T>* nodeCurr = root;

	if(root == NULL){
		return false;
	}


	while(nodeCurr != NULL){
		if(nodeCurr->data == key){
			found = true;
			nodeCurr = NULL;
		}
		else{
			if(key > nodeCurr->data){
				nodeCurr = nodeCurr->right;
			}
			else{
				nodeCurr = nodeCurr->left;
			}
		}
	}

	return found;
}

//Supplement(PREORDER) - Allows recursive printing of the tree
template <typename T>
void Tree<T>:: preorderFunction(Node<T>* rootCurr) const{
	if(rootCurr != NULL){
		cout << rootCurr->data << " ";
		preorderFunction(rootCurr->left);
		preorderFunction(rootCurr->right);
	}
}

//Supplement(PREORDER) - Allows recursive printing of the tree
template <typename T>
void Tree<T>:: inorderFunction(Node<T>* rootCurr) const{
	if(rootCurr != NULL){
		inorderFunction(rootCurr->left);
		cout << rootCurr->data << " ";
		inorderFunction(rootCurr->right);
	}
}

//Supplement(PREORDER) - Allows recursive printing of the tree
template <typename T>
void Tree<T>:: postorderFunction(Node<T>* rootCurr) const{
	if(rootCurr != NULL){
		postorderFunction(rootCurr->left);
		postorderFunction(rootCurr->right);
		cout << rootCurr->data << " ";
	}
}

//PREORDER - Prints the tree in a Preorder Format
template <typename T>
void Tree<T>:: preorder() const{
	preorderFunction(root);
}

//INORDER - Prints the tree in a Inorder Format
template <typename T>
void Tree<T>:: inorder() const{
	inorderFunction(root);
}

//POSTORDER - Prints the tree in a Postorder Format
template <typename T>
void Tree<T>:: postorder() const{
	postorderFunction(root);
}

//ISEMPTY - Allows the user to check if the tree is empty
template <typename T>
bool Tree<T>::isEmpty() const{
	return root == NULL;
}

//ISFULL - Allows the user to check if the tree is full
template <typename T>
bool Tree<T>::isFull() const{
	return isfullFunction(root);
	
}

//Supplement(ISFULL) - Allows for recursive iteration through the tree to check fullness
template <typename T>
bool Tree<T>::isfullFunction(Node<T>* rootCurr) const{

	if (rootCurr->left != NULL && rootCurr->right != NULL){
		return (isfullFunction(rootCurr->left) && isfullFunction(rootCurr->right));
	}
	else if(rootCurr->left == NULL && rootCurr->right == NULL){
		return true;
	}
	else{
		return false;
	}

}

//HEIGHT - Allows the user to check the tree's height
template <typename T>
int Tree<T>:: height() const{
	return heightFunction(root);
}

//Supplement(HEIGHT) - Allows for recursively counting the heights of the left and right
//						trees, an implementation of the formula given 
template <typename T>
int Tree<T>:: heightFunction(Node<T>* rootCurr) const{
	if(rootCurr == NULL){
		return 0;
	}
	else{
		if(heightFunction(rootCurr->left) > heightFunction(rootCurr->right)){
			return (1+ heightFunction(rootCurr->left)); 
		}
		else{
			return (1+ heightFunction(rootCurr->right));
		}
	}
}

#endif