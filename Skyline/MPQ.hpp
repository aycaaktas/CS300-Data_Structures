//
//  MPQ.hpp
//  27802-AycaElifAktas
//
//  Created by AYÇA ELİF on 6.12.2022.
//

#ifndef MPQ_hpp
#define MPQ_hpp

#include <stdio.h>
#include <string>
#include<iostream>
#include <vector>
using namespace std;


/*
This struct is the one that that I use to store the label and value of the buildings.
My main Heap vector in the MPQ class stores nodempq type variables.
*/

struct nodempq
{
    
    int yheight;
    int label;
 
    
    
    nodempq ()
    {}
    
    nodempq( const int & y , const int & lab )
    : yheight(y), label(lab)
    {}
    
    
    
    
    
};


/*
This struct is the one that I use to record every information about the coordinates from the input file.
I use a heapcoordinates that stores node variables in the main.cpp that enables for me to store every info on the coordinates in to the array.

*/


struct node
{
    
    int xcoord;
    int label;
	int height;
   string side;
    
    
    node ()
    {}
    
    node( const int & xco , const int & lab , const int& h, const string& s)
    : xcoord(xco), label(lab),height(h), side(s)
    {}
    
    
};

/*
Class MPQ that stands for Modified Priority Queues.
It has two vectors in its private fields. 
One vector called Heap is my main Heap structure. 
Location Array keeps track of  each building's position on the Heap vector as a value.And each index reprsents the label's of the buildings.
And an additional int variable to keep track of number of buildings I have in my main Heap vector.
*/

class MPQ{
    
    
private:
    
    int numberofbuldings;
    vector<int>Location;
    vector<nodempq>Heap;
    
    
    
    
public:
    
   
    ~MPQ(); // destructor
	MPQ(int size);  // parametric constructor
	void insert(const nodempq & building); 
	void percolatedownn(int index); 
	void percolateup(int index);
	int remove(const nodempq & building);
    bool IsEmpty();
    int getmax();
    void skyline(const vector<node> & coordinates);
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};










#endif /* MPQ_hpp */
