//  decompress.cpp
//  27802-AycaElifAktas
//
//  Created by AY«A EL›F on 29.12.2022.
// 



/***********************************************************************
Decompression algorithm that decompresses a file that contains integer
data type (representing codes of the strings)into string data type.
************************************************************************/


#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/***********************************************************************
Function that deletes the dynamic memory allocation that has been allocated 
while reading the file and storing strings into dynamic strings
in the dictionary vector.
************************************************************************/

void deletearray(vector<string*> & svector)
{
	for(int h=0;h<svector.size();h++)
  {
	  delete svector[h];
	  svector[h]=nullptr;
  }
}

/***********************************************************************
Main function.
************************************************************************/


int main() 
{

	
    ifstream input("compout");
	ofstream output("decompout");

/************************************************************************
Vector "codes" contain the codes of the strings that has been read 
from the compout.txt file.
*************************************************************************/

	vector<int>codes;
	int k;
	while (!input.eof()) 
	{
        input>>k;
        codes.push_back(k);
    }
	codes.pop_back();

/************************************************************************
Vector "dictionary" will contain the string of the codes that has been read 
from the compout.txt file. But first we initilize the vector to contain 
the strings of the first 256 ASCII charchters.I choose to store dynamic strings
instead of normal strings beacuse the strings can be too big depending on the test case.
Size of vector is 4096 because as indicated in the homework file the max strings 
that we need to work with is 4096.
*************************************************************************/

    vector<string*>dictionary(4096,nullptr);
	int i;
	for (i = 0; i < 256; i++) 
	{
        dictionary[i]= new string(1,char(i));
		
    }
/************************************************************************
Always decompress the first code of the codes vector if the code is
smaller than 4096.It is part of the algorithm.
*************************************************************************/

	if( codes[0]<4096)
	{
		output<<*dictionary[codes[0]];
	}
	
/************************************************************************
For all codes in the compout.txt file if the code is smaller than 4096 decompress it.
If the string that corrosponds to the code is not in the dictionary output 
the prevoisly decoded string + previosly decoded strings first charchter.
Also add this new string to the dictionary.
If the string that corrosponds to the code is in the dictionary output 
the prevoisly decoded string + current strings first charchter.
Also add this new string to the dictionary.
This the algorithm to decompress the compout.txt file that contains integer codes.
*************************************************************************/

  for(int j=1;j<codes.size();j++)//for all codes 
  {
	  if( codes[j]<4096)// perform decompression if code is smaller than 4096
	  {
		   
		    if(dictionary[codes[j]] == nullptr)  // if string that corrosponds to code[j] is not in the dictionary
	        {
	    
				string prevdecoded =*dictionary[codes[j-1]]; // previosly decoded string
				string newentry=prevdecoded + prevdecoded.substr(0,1);
				dictionary[i]=new string;
				*dictionary[i]=newentry; 
				output<<newentry;
				i++; // updating the position on the dictionary vector.

	        } 
			else //if string that corrosponds to code[j] is in the dictionary
			{

				string prevdecoded =*dictionary[codes[j-1]]; // previosly decoded string
				string current=*dictionary[codes[j]]; //current string
				string newentry=prevdecoded + current.substr(0,1);
				dictionary[i]=new string;
				*dictionary[i]=newentry; 
				output<<current;
				i++; // updating the position on the dictionary vector.

			}
	   }
  }

 deletearray(dictionary);//deleting the dynamic memory allocation on the dictionary vector.

 input.close();
 output.close();

  return 0;
}
