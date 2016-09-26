/*************************************
 * Derek Florimonte
 * 909422688
 * dflomo@gmail.com
 * Cygwin g++ (4.8.3)
 *************************************/
#ifndef __GRAPH_H_
#define __GRAPH_H_

#include "vertex.h"
#include <iostream>

using namespace std;

class Graph{

	public:
		//Default Constructor
		// Graph();

		//Destructor
		~Graph();

		//Accessors
		int vertexCount() const;		//retruns the amount of vertices present
		bool vertexExists(char);		//Searches for a vertex
		bool pathExists(char, char);	//Searches for a path between two points
		int getIndex(char);				//Searches for the correct vertex, and returns its index

		//Mutators
		void addEdge(char, char);		//creates an edge between two points
		void addVertex(char);			//creates a new vertex
		void depthSearch(Vertex);		//recursively calls in order to do a complete search of the list

		
	private:
		vector<Vertex> vertices;
		vector<Vertex> visitedNode;
		
};

#endif