/********************************************************************
 *
 *											Kening Zhang, Gang Yang
 *											CSE 100, fall 17
 *											10/29/2017
 *											cs100fje	  cs100fiy
 *
 *								Assignment 2
 * Filename: DictionaryBST.cpp
 * Description: use a balanced binary search tree to store the words
 * in the dictionary. Also, we need to insert and find the words 
 * through set
 *******************************************************************/


#include "util.h"
#include "DictionaryBST.h"
#include <set>

/* Create a new Dictionary that uses a BST back end */
DictionaryBST::DictionaryBST(){
	myset = std::set<std::string>();
}

/* Insert a word into the dictionary. */
bool DictionaryBST::insert(std::string word)
{
	/* use C++ set to insert word */
	std::pair<std::set<std::string>::iterator,bool> ret;
	ret= myset.insert(word);

	/* check if the word insert successfully */
	if( ret.second == false)
		return false;
	else
		return true;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryBST::find(std::string word) const
{

	/* check whether we find the word */
	if (myset.find(word) == myset.end())
		return false;
	else
		return true;
}

/* Destructor */
DictionaryBST::~DictionaryBST(){	
}
