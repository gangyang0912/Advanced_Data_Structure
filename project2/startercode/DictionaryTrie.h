/**************************************************************************
 *
 *													Kening Zhang, Gang Yang
 *													CSE 100, fall 17
 *													10/29/2017
 *													cs100fje	  cs100fiy
 *
 *								Assignment 2
 * Filename: DictionaryTrie
 * Description: use the Multiway Trie to store the words in the dictionary.
 * And we need to declare the previate and public variable and method
 *
 *************************************************************************/


/**
 *  CSE 100 PA2 C++ Autocomplete
 *  Authors: Jor-el Briones, Christine Alvarado
 */

#ifndef DICTIONARY_TRIE_H
#define DICTIONARY_TRIE_H
#define LETTERS 26

#include <vector>
#include <string>

/**
 *  The class for a dictionary ADT, implemented as a trie
 *  You may implement this class as either a mulit-way trie
 *  or a ternary search trie, but you must use one or the other.
 *
 */
class DictionaryTrie
{
public:

  /* Create a new Dictionary that uses a Trie back end */
  DictionaryTrie();

  /* Insert a word with its frequency into the dictionary.
   * Return true if the word was inserted, and false if it
   * was not (i.e. it was already in the dictionary or it was
   * invalid (empty string) */
  bool insert(std::string word, unsigned int freq);

  /* Return true if word is in the dictionary, and false otherwise */
  bool find(std::string word) const;

  /* Return up to num_completions of the most frequent completions
   * of the prefix, such that the completions are words in the dictionary.
   * These completions should be listed from most frequent to least.
   * If there are fewer than num_completions legal completions, this
   * function returns a vector with as many completions as possible.
   * If no completions exist, then the function returns a vector of size 0.
   * The prefix itself might be included in the returned words if the prefix
   * is a word (and is among the num_completions most frequent completions
   * of the prefix)
   */
  std::vector<std::string>
  predictCompletions(std::string prefix, unsigned int num_completions);

  /* Destructor */
  ~DictionaryTrie();

private:

  /* set a Node class */
  class Node{
    public:

	  /* set the variable */
	  bool word;
	  unsigned int frequency;
	  std::string dict;

      Node* children[LETTERS+1];

	  /* initialize the Node */
	  Node(unsigned int freq, bool b): word(b),frequency(freq){
		for (int i =0; i<LETTERS+1; i++)
    	{
	      children[i]= nullptr;
        }
	  }
  };

  /* create the root pointer */
  Node* root;

  static void deleteNode( DictionaryTrie::Node* node);
  // Add your own data members and methods here
};

#endif // DICTIONARY_TRIE_H
