//
//  main.cpp
//  27802-AycaElifAktas
//
//  Created by AYÇA ELİF on 6.12.2022.
//


#include<fstream>
#include<sstream>
#include "MPQ.hpp"
using namespace std;



/*
Percolatedown function that helps the heapcoordinates function to build Heap property.
Size is the current size of the heapcoordinates function.
And index is the position of the element that will be percolated down on the vector.
The algorithm is taken from the lecture slides.
*/


void percolatedown(  int index,int size,vector<node> & heapcoordinates)
{
    
    int child;
    node temp= heapcoordinates[index];
    for(;(2*index +1) < size ;index=child)
    {
        child= (2*index)+1;
        if(child != size-1  && heapcoordinates[child].xcoord < heapcoordinates[child+1].xcoord)
        {
            child++;
        }
        
        if(heapcoordinates[child].xcoord > temp.xcoord)
        {
            heapcoordinates[index] = heapcoordinates[child];
        }
        else
            break;
        
        
    }
	heapcoordinates[index]=temp;
    
    
}

/*
Build heap function is the function that makes a standart vector turn into a Heap structure.
Forms a Max Heap.
Builds Heap properties using percolatedown function.
The algorithm is taken from the lecture slides.
*/

void buildheap(int size ,vector<node> & heapcoordinates)
{
    
    for(int i=size/2; i>=0;i--)
    {
        percolatedown(i,size,heapcoordinates);
    }
    
}


/*
Heapsort function is the function that sorts the Max Heap in ascending order.
The algorithm is taken from the lecture slides.
*/


void heapsort(int size, vector<node> & heapcoordinates)
{
	
    buildheap(size,heapcoordinates);  //Builds the Heap
    
    for(int i =size-1;i>0;i--)
    {
        
		 swap(heapcoordinates[0],heapcoordinates[i]); //Swaps the last and first element
         percolatedown(0,i,heapcoordinates);   //Percolates down the first element
        
       
    }
    
}




int main()
{
    
    //It reads the input from the txt file.
    ifstream in;

    string fName="input.txt";
    in.open(fName.c_str());
    
    string line,linet;
    int nobuldings;
    int xcr,xcl,y;
   

    getline(in,linet);
    stringstream ss(linet);
    ss>>nobuldings;

 

	vector<node> heapcoordinates; //vector to store the all information about the coordinates.
	int j=1;
 
    while( getline(in, line))
    {
        
	
        
        stringstream ss(line);
        ss>>xcl>>y>>xcr;

        node right(xcr,j,y,"right");
        node left(xcl,j,y,"left");
        heapcoordinates.push_back(left);
        heapcoordinates.push_back(right);

		j=j+1;
        
        
        
    }
	int size=heapcoordinates.size();
    heapsort(size,heapcoordinates); //builds the vector as a Heap and sorts it in ascending order
  

   MPQ modifiedprq(nobuldings);  // MPQ variable with the parameter to set the size. "nobuldings" is the variable that we take from the input.txt file and specifes the number of buildings.
   modifiedprq.skyline(heapcoordinates); // main skyline fnc prints out the skyline of the buildings.

    
    return 0;
    
    
    
}
