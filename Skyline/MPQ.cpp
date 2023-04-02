//
//  MPQ.cpp
//  27802-AycaElifAktas
//
//  Created by AYÇA ELİF on 6.12.2022.
//

#include "MPQ.hpp"


/*
Parametric constructor to set the number of builngs to 0.
Sets the each vector's size according to the number of building that I take from the input.txt file. 
I add plus one because the buildings will start from index 1.
*/
MPQ::MPQ(int size)
{
	 numberofbuldings=0;
	 nodempq default(-1,-1);
	 vector<nodempq>temp1(size+1,default);
	 vector<int>temp2(size+1,-1);

	 Heap=temp1;
	 Location=temp2;

}
/*
Destructor.
Because I don't have dynamic memmory allocation I only set the number of buildings to 0.
*/
MPQ::~MPQ()
{
  numberofbuldings=0;
}

/*
  Is Empty function returns true if the heap is empty otherwise returns false.
*/

bool MPQ::IsEmpty()
{
	

	if(numberofbuldings==0)
		return true;
	else
		return false;
}

/*
 Insert function inserts building element that it takes from the parameter as "building".
 It inserts into function while not protecting the Heap properties.
 As the Heap that I am forming is Max Heap , it inserts with the rules of max heap.
 Also while inserting it updates the Location of the building in the Location vector.
*/


void MPQ::insert(const nodempq & building)
{

	int hole=++numberofbuldings;
	for(;hole>1 && building.yheight > Heap[hole/2].yheight;hole/=2)
	{

		Heap[hole]=Heap[hole/2];
		int loc=Heap[hole].label;
		Location[loc]=hole;
		
	}

	Heap[hole]=building;
	int loc2 = Heap[hole].label;
	Location[loc2]=hole;
	

}

/*
Percolte down is a function that I use after removing an element from the Heap.
The purpose of it is to help protect the Heap properties after removing a building.
It percolates down the element at "index" if the childs height is greater than itself.
Also while shifting the elements inside the Heap it tracks and changes their "position values" in the Location vector.

*/


void MPQ:: percolatedownn( int index )
{
    
    int child;
    nodempq temp= Heap[index];
    for(;(2*index ) <= numberofbuldings ;index=child)
    {
        child= (2*index);
        if(child != numberofbuldings  && Heap[child].yheight < Heap[child+1].yheight)
		{
            child++;
        }
        
        if(Heap[child].yheight > temp.yheight)
        {
            Heap[index] = Heap[child];
			int looc=Heap[index].label;
			Location[looc]=index;
        }
        else
            break;
          
    }
	Heap[index]=temp;
	int loooc = Heap[index].label;
	Location[loooc]=index;
    
    
}

/*
Percolte up is a function that I use after removing an element from the Heap.
The purpose of it is to help protect the Heap properties after removing a building.
It percolates up the element at "index" if the parent's height is smaller than itself.
Also while shifting the elements inside the Heap it tracks and changes their "position values" in the Location vector.

*/
void MPQ:: percolateup( int index )
{
    
    
    nodempq temp= Heap[index];
    for(;index > 1 && Heap[index/2].yheight < temp.yheight;index/=2)
    {
     
   
            Heap[index] = Heap[index/2];
			int locc=Heap[index].label;
			Location[locc]=index;
       
          
    }
	Heap[index]=temp;
	int loccc=Heap[index].label;
	Location[loccc]=index;
    
    
}

/*
It removes the building from the Heap. 
I take the building to be removed from the paramter as a "building".
And returns the item to be removed's height value.


*/

int MPQ::remove(const nodempq& building )
{
	
	if(!IsEmpty() && Location[building.label] != -1 )  //If the Heap is already empty it does not do any remove operations and returns -1.
	{
		int indexremove;
	    indexremove=Location[building.label];
	    nodempq parent = Heap[indexremove/2];

		/*
		If the item to be removed is the last item in the Heap than it only updates the size of Heap.
		We can no longer reach the last element of the Heap so logically Heap shrinks and we delete the last item.
		*/

	   if(indexremove==numberofbuldings) 
	   {
		numberofbuldings=numberofbuldings-1;
	    Location[building.label]=-1;
	   }
       else //Otherwise it stores the last item of the Heap to the index at the item to be removed exists. And logically deletes the item.
	   {

	      Heap[indexremove]=Heap[numberofbuldings--];
	      Location[building.label]=-1;
	      Location[Heap[indexremove].label]=indexremove;

		 //After that to protect the heap properties we  check whether the item to be removed's parent is grater or smaller then the new item we put instead of the item to be removed.
	      if( indexremove != 1 && Heap[indexremove].yheight > parent.yheight)
	      {
		   percolateup(indexremove);
	      }
	      else
	      {
		   percolatedownn(indexremove);
	      }
    
       }
	  return building.yheight;
  }
	  return -1;
}

// Returns the current maximum height of the Heap if not empty.

int MPQ::getmax()
{
	if(IsEmpty())
	{
		return 0;
	}
	else
	{
		return Heap[1].yheight;
	}

}



/*
Main function that I swep across all the coordinates and do the insert and remove opreations according to the "side" of the coordinates.
While inserting and deleting if the current maximum height of the skyline changes that it prints the x-coordinate where it changes and the changed current maximum height.
*/
void MPQ::skyline(const vector<node> & coordinates)
{
	  int maxbefore;
	  int maxafter;

	  maxbefore=getmax();

	 if(coordinates[0].xcoord !=0)
	 {
	     cout<<0<<" "<<0<<endl;
	 }

	 nodempq element;
	for(int i=0;i<coordinates.size();i++)
	{
		 
		  element.label=coordinates[i].label;
		  element.yheight=coordinates[i].height;


		if( coordinates[i].side == "left")
		{
		  
		  insert(element);

		}
		if( coordinates[i].side == "right")
		{
          remove(element);
		}

		 maxafter=getmax();  // gets the current max after remove and insert operations


	    if( i != coordinates.size()-1 && coordinates[i].xcoord != coordinates[i+1].xcoord )
		 {
             if(maxafter != maxbefore) //print out if there is a change in the height
	       	{
			  cout<<coordinates[i].xcoord<<" "<<maxafter<<endl;  //prints out the coordinate where the maximum height changes and maximum height
			  maxbefore=getmax();  // updates the maxbefore
		    }

		 }
		if(i == coordinates.size()-1)
		{
			 if(maxafter != maxbefore) //print out if there is a change in the height
	       	{
			  cout<<coordinates[i].xcoord<<" "<<maxafter<<endl; //prints out the coordinate where the maximum height changes and maximum height
			  maxbefore=getmax(); // updates the maxbefore
		    }
		}
    
	}

}


