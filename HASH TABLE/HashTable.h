//  HashTable.h
//  27802-AycaElifAktas
//
//  Created by AYÇA ELÝF on 16.12.2022.
//



#ifndef HASHTABLE_H

#define HASHTABLE_H


#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*****************************************************************
Templated HashTable class
It is templated to make the compression operation general.
*****************************************************************/


template<class Key,class Code>
class HashTable
{
public:

	HashTable(const Code & notfound, int size = 256);  //constructor
	HashTable(const HashTable & rhs) : hasharray(rhs.hasharray) ,tableSize(rhs.tableSize), ITEM_NOT_FOUND(rhs.ITEM_NOT_FOUND) {}      //  Copy constructor

	void makeEmpty(); //makes the hash table empty
	int hash(const Key & obj); // hash function that hashes the object according to its Key value to hash table.
     Code find(const Key & obje);//find function according to given Key it returns its Code value.
	void insert(const Key & element , const Code & x);//insert a {key,code} pair to the hash table.
	void remove(const Key & elt);//remove function removes the {key,code} pair from hash table according to its Key value.

	


	enum EntryType {ACTIVE, EMPTY, DELETED};

private:

/*****************************************************************
Below struct is for keeping information on Hash table objects.
*****************************************************************/

	struct HashEntry
	{
		Key key;   //storing Key data
		Code code;  // storing Code that corrosponds to key data
		EntryType info;  // info about cell

		HashEntry(const Key & d = Key(), Code  c = Code(), EntryType i = EMPTY)
            : key(d), code(c), info(i){}
    };

	vector<HashEntry> hasharray;
	const Code ITEM_NOT_FOUND;
	int tableSize;


    int findPos(const Key & object);//private function that finds the position of {key,code} pair according to Key value.
	bool isActive(int) const;// private function that returns true if a cell in hashtable is  ACTIVE.
	int nextPrime(int n);//Function to find the next prime nearest to integer n number.
	bool isPrime(int n);//function return true if integer n is prime.

};

#include "HashTable.cpp"

#endif /* HASHTABLE_H */

