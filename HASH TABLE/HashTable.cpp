//  HashTable.cpp
//  27802-AycaElifAktas
//
//  Created by AYÇA ELÝF on 16.12.2022.
//




#include "HashTable.h"

/******************************************************
Constructs the HashTable. Intilizes the value of private field notFound that is taken in main.cpp.
Makes the size of table prime and initilazes both vector size and tableSize private field object.
Initilizes all elements in the Hash table info field to 
EMPTY using makeEmpty() function.
*******************************************************/

/*Begin: code taken from 9-Hashtables2.ppt and updated by Ayça Aktaþ*/
template<class Key,class Code>
HashTable<Key,Code>::HashTable(const Code & notfound,int size)
	 : hasharray(nextPrime(size)),tableSize(nextPrime(size)), ITEM_NOT_FOUND(notfound)
{
	makeEmpty();

}
/*End: code taken from 9-Hashtables2.ppt and updated by Ayça Aktaþ*/

/******************************************************
Returns true if integer n is prime number.
*******************************************************/


/*Begin: code taken from 8-Hashtables.ppt and updated by Ayça Aktaþ*/
template<class Key,class Code>
bool HashTable<Key,Code>::isPrime(int n)
{
	if(n==2 || n==3)
	{
		return true;
	}
	if(n==1 || n%2==0)
	{
		return false;
	}

	for(int i=3;i*i <=n;i+=2)
	{
		if(n%i==0)
		{
			return false;
		}
	}


	return true;
}
/*End: code taken from 8-Hashtables.ppt and updated by Ayça Aktaþ*/

/******************************************************
Returns the prime number  that is closest to integer n.
*******************************************************/

/*Begin: code taken from 8-Hashtables.ppt and updated by Ayça Aktaþ*/
template<class Key,class Code>
int HashTable<Key,Code>::nextPrime(int n)
{
	if(n%2==0)
	{
		n++;
	}

	for(;!isPrime(n);n+=2)
	  ;

	return n;

}
/*End: code taken from 8-Hashtables.ppt and updated by Ayça Aktaþ*/


/******************************************************
Makes the hash table logically empty. Suceedes this by initilazing 
each cell of HashTable "info" field to EMPTY.
*******************************************************/

template <class Key, class Code>
void HashTable<Key, Code>::makeEmpty()
{
    
    for (int i = 0; i < hasharray.size(); i++) {
        hasharray[i].info = EMPTY;
    }
}

/******************************************************
Returns TRUE if the object that is in the "pos" spot on 
HashTable is ACTIVE.
*******************************************************/

/*Begin: code taken from 9-Hashtables2.ppt and updated by Ayça Aktaþ*/
template <class Key, class Code>
bool HashTable<Key, Code>::isActive(int pos) const 
{
    
    return hasharray[pos].info == ACTIVE;
}
/*End: code taken from 9-Hashtables2.ppt and updated by Ayça Aktaþ*/


/******************************************************
Hash function that hashes the strings to integers.
Using Horner's method.Returns the position that "obj" must be 
placed in HashTable.
*******************************************************/

/*Begin: code taken from 8-Hashtables.ppt and updated by Ayça Aktaþ*/
template <class Key, class Code>
int HashTable<Key, Code>::hash(const Key & obj)
{

	int hashVal=0;

	for(int i=0;i<obj.length();i++)
	{
		hashVal= 37 * hashVal + obj[i];

	}
	hashVal= hashVal % tableSize;

	if(hashVal<0)
	{
		hashVal = hashVal + tableSize ;
	}

    return hashVal;

}
/*End: code taken from 8-Hashtables.ppt and updated by Ayça Aktaþ*/

/******************************************************
Function that returns the position of element 
represented by "object" Key value on the Hash Table.
must be placed in or "object" is found.
*******************************************************/

/*Begin: code taken from 9-Hashtables2.ppt and updated by Ayça Aktaþ*/
template <class Key, class Code>
int HashTable<Key, Code>::findPos(const Key & object)
{
	
	int p = hash(object);
	while( hasharray[p].info != EMPTY && hasharray[p].key != object)
	{
		p++;
		if(p>=hasharray.size())
		{
			p -= hasharray.size();
		}
	}
	return p;

}
/*End: code taken from 9-Hashtables2.ppt and updated by Ayça Aktaþ*/


/******************************************************
Function returns the Code value of the object with "obje"
Key value from the HashTable. If item not found it returns 
the ITEM_NOT_FOUND.
*******************************************************/

/*Begin: code taken from 9-Hashtables2.ppt and updated by Ayça Aktaþ*/
template<class Key, class Code>
Code HashTable<Key, Code>::find(const Key & obje) 
{

	int currentpos = findPos(obje);
	if(isActive(currentpos))
	{
		return hasharray[currentpos].code;
	}
	return ITEM_NOT_FOUND;
}
/*End: code taken from 9-Hashtables2.ppt and updated by Ayça Aktaþ*/


/******************************************************
Function inserts the {key,code} pair into the Hash Table.
*******************************************************/


/*Begin: code taken from 9-Hashtables2.ppt and updated by Ayça Aktaþ*/
template <class Key, class Code>
void HashTable<Key, Code>::insert(const Key & element, const Code & x)
{


	int currentpos=findPos(element);
	if(isActive(currentpos))
	{
		return;
	}

	hasharray[currentpos] =HashEntry(element,x,ACTIVE);

}
/*End: code taken from 9-Hashtables2.ppt and updated by Ayça Aktaþ*/

/******************************************************
Function removes the {key,code} pair from the Hash Table 
according to its Key value.
*******************************************************/


/*Begin: code taken from 9-Hashtables2.ppt and updated by Ayça Aktaþ*/
template <class Key, class Code>
void  HashTable<Key, Code>::remove(const Key & elt)
{

	int currentpos=findPos(elt);
	if(isActive(currentpos))
	{
		hasharray[currentpos].info= DELETED;
	}
}
/*End: code taken from 9-Hashtables2.ppt and updated by Ayça Aktaþ*/

