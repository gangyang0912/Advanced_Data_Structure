/**********************************************************************
 *
 *											Kening Zhang, Gang Yang
 *											CSE 100, fall 17
 *											10/29/2017
 *											cs100fje	  cs100fiy
 *
 *							Assignment 2
 * Filename: DictionaryHashtable.cpp
 * Description: use a hashtable data structure to store the words in 
 * the dictionary. And we should use the unordered_set to find and 
 * insert the words.
 **********************************************************************/ 


#include "util.h"
#include "DictionaryHashtable.h"
#include <unordered_set>

/* Create a new Dictionary that uses a Hashset back end */
DictionaryHashtable::DictionaryHashtable(){
	my_unordered_set = std::unordered_set<std::string>();
}

/* Insert a word into the dictionary. */
bool DictionaryHashtable::insert(std::string word)
{

	/* use an C++ unordered_set to insert the words */
	std::pair<std::unordered_set<std::string>::iterator, bool> ret;
	ret = my_unordered_set.insert(word);

	/* check if insert successfully */
	if(ret.second == false)
		return false;
	else
		return true;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryHashtable::find(std::string word) const
{

	/* check if we find the word */
	if(my_unordered_set.find(word) == my_unordered_set.end())
		return false;
	else
		return true;
}

/* Destructor */
DictionaryHashtable::~DictionaryHashtable(){

}
