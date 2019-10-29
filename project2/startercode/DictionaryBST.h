/************************************************************************
 *
 *												Kening zhang, Gang Yang
 *												CSE 100, fall 17
 *												10/29/2017
 *												cs100fje	  cs100fiy
 *												
 *							Assignment 2
 * Filename: DictionaryBST.h
 * Description: use a balanced binary search tree to store the words in
 * in the dictionary. And we also need to declare the public and private
 * variables and methods.							
 ***********************************************************************/

/**
 *  CSE 100 PA2 C++ Autocomplete
 *  Authors: Jor-el Briones, Christine Alvarado
 */

#ifndef DICTIONARY_BST_H
#define DICTIONARY_BST_H

#include <string>
#include <set>
/**
 *  The class for a dictionary ADT, implemented as a BST
 * When you implement this class, you MUST use a balanced binary
 * search tree in its implementation.  The C++ set implements 
 * a balanced BST, so we strongly suggest you use that to store 
 * the dictionary.
 */
class DictionaryBST
{
public:

  /* Create a new Dictionary that uses a BST back end */
  DictionaryBST();

  /* Insert a word into the dictionary. */
  bool insert(std::string word);

  /* Return true if word is in the dictionary, and false otherwise */
  bool find(std::string word) const;

  /* Destructor */
  ~DictionaryBST();

private:
  /* use C++ set */
  std::set<std::string> myset;
  // Add your own data members and methods here
};

#endif // DICTIONARY_BST_H
