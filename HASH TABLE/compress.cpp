// compress.cpp
//  27802-AycaElifAktas
//
//  Created by AYÇA ELÝF on 16.12.2022.
// 


#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "HashTable.h"

using namespace std;

int main() 
{

	ifstream input("compin");
	ofstream output("compout");
	
	int notfound = -1;
	int i;
/********************************************************************
Intilize the Hash Table make the size 8192. Because as indicated
in the Homework file there will be at max 4092 string entires to 
the Hash Table but to make the Hash Table half full at max we initlize
its size to 8196.Lastly fill the Hash Table with first 256 charchters of ASCII table.
*********************************************************************/
    HashTable<string,int> table(notfound, 8192);

	for ( i = 0; i < 256; i++) 
	{
		string newst=string(1,char(i));
        table.insert(newst, i);
		
    }


/********************************************************************
The main algorithm; If the charchter that has been read from the file is already
in the Hash Table then he program countinies and takes another charchter next to previous.
If the string now is not found in the Hash Table then compress the previous string.
And add the current string to the Hash Table.
*********************************************************************/



	char ch;
	string current="";
	string prev="";
	streampos oldpos;  //old position of the string

	while(input.get(ch))
	{
	
		  current=current +ch;
		  int found= table.find(current);
		  if (found != notfound)
		  {
			    prev=current;  // previous string
				oldpos = input.tellg(); //previous position
                continue;
          }
		  else
		  {
			
			if ( i < 4096)
			{
				output << table.find(prev) << " "; //compress the previous string
			    table.insert(current,i); //insert the current string to Hash Table
			    i++; 
			}
			input.seekg(oldpos); //get the input to previous location
			current="";
	        prev="";

		  }

	}


	output << table.find(prev) << " ";

	input.close();
	output.close();
	return 0;
}
