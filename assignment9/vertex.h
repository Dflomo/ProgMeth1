/*************************************
 * Derek Florimonte
 * 909422688
 * dflomo@gmail.com
 * Cygwin g++ (4.8.3)
 *************************************/
#ifndef __VERTEX_H_
#define __VERTEX_H_

#include <vector>

using namespace std;

class Vertex{

	public:
		Vertex(char);

		void addEdge(char);
		char getLabel();
		const vector<char> getEdges();
		
	private:
		vector<char> edges;
		char label;

};

#endif