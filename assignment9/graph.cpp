/*************************************
 * Derek Florimonte
 * 909422688
 * dflomo@gmail.com
 * Cygwin g++ (4.8.3)
 *************************************/
#include "graph.h"

//Default Constructor
// Graph::Graph(){
	
// }

//Deconstructor
 Graph:: ~Graph(){
  for(int i = 0; i < vertices.size()){
    vertices.pop_back();
  }
  for(int i = 0; i < visitedNode.size()){
    visitedNode.pop_back();
  }
 }

//ADDEDGE - creates an edges between two points
void Graph::addEdge(char pointA, char pointB){
	//Creates new point for the first given point
	addVertex(pointA);
  //Creates new point for the second given point
	addVertex(pointB);

	//Iterates through to creates the currently made edges association
	for(int i = 0; i < vertices.size(); i++){
	    if(vertices[i].getLabel() == pointA){
	      vertices[i].addEdge(pointB);
	    }
	}
	
}

//VERTEXCOUNT - return the size of the list, AKA the number of vertices
int Graph::vertexCount() const{
	return vertices.size();
}

bool Graph::vertexExists(char nodeSearch){
	bool found = false;

  	for (int i = 0; i < vertices.size(); i++){
    //If the item is equal to the current vertices' label
  	//then you have found your correct vertex
    if (nodeSearch == vertices[i].getLabel()){
      found = true;
    }
  }

  return found;
}

//PATHEXISTS - searchs for a path to see if it exists, and returns true or false
bool Graph::pathExists(char begin, char end){
	bool pathExists = false;
  
	depthSearch(vertices[getIndex(begin)]);

	for(int i = 0; i < visitedNode.size(); i++){
		if (visitedNode[i].getLabel() == end){
	  		
	  		pathExists = true;

		}
	}
	return pathExists;
}

//ADDVERTEX - creates a vertex and adds it to the stack
void Graph::addVertex(char newPoint){
	//Checks to see if prior existence
  if (!vertexExists(newPoint)){

  	//Creates new point and adds it to the stack
    Vertex v(newPoint);
    vertices.push_back(v);

  }
}

//DEPTHFIRSTSEARCH - searchs along a path until the end, then goes 
//					 back to explore other branches, returns true if
//					 specified vertex exists
void Graph::depthSearch(Vertex current){
  vector<Vertex> adjacent;

  visitedNode.push_back(current);
  vector<char> labels = current.getEdges();  

  //Copies the current edges of the addressed vertice
  for(int i = 0; i < labels.size(); i++){
    adjacent.push_back(vertices[getIndex(labels[i])]);
 
  }
  
  //Searches for the correct path in each vertice stack
  for (int i = 0; i < adjacent.size(); i++){
    bool  visitPresent = false;

    for(int j = 0; j < visitedNode.size(); j++){
      if(adjacent[i].getLabel() == visitedNode[j].getLabel()){
        
        visitPresent = true;

      }
    }

    //Recursively calls depthSearch on the adjacent vertices
    if(visitPresent == false){
      depthSearch(adjacent[i]);
    }
  }
  
}

//INDEXCOUNT - Finds the index user defines, and returns the index
int Graph::getIndex(char indexSearch){
  int index = 0;

  for (unsigned int i = 0; i < vertices.size(); i++){
  	//Compares the label to the search item, returns this item if found
    if(vertices[i].getLabel() == indexSearch){

      index = i;
    
    }
  }

  return index;
}