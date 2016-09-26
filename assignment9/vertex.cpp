/*************************************
 * Derek Florimonte
 * 909422688
 * dflomo@gmail.com
 * Cygwin g++ (4.8.3)
 *************************************/
#include "vertex.h"

//Default constructor
Vertex::Vertex(char a){
	label = a;
	
}

//Destructor
Vertex:: ~Vertex(){
	for(int i = 0; i < edges.size()){
    edges.pop_back();
  }
}

//ADDEDGE - creates a new edge to symbolize the connectons of vertices
void Vertex::addEdge(char a){
	edges.push_back(a);
}

char Vertex::getLabel(){
	return label;
}

const vector<char> Vertex::getEdges(){
	return edges;
}