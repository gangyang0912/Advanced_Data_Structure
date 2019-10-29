/******************************************************************************
 *
 *														Kening Zhang, Gang Yang
 *														CSE 100, fall 17
 *														10/30/2017
 *
 *								Assignment 2						
 * Filename: DictionaryTrie
 * Description: use the Multiway Trie to store the words in the dictionary. We 
 * will insert the words and find the words with their frequency. Also, we
 * should implement the predictCompletions to return the vector containing 
 * the num-completions most frequent legal completions
 *
 *****************************************************************************/


#include "util.h"
#include "DictionaryTrie.h"
#include <queue>
#define LETTERS 26
using namespace std;
/* Create a new Dictionary that uses a Trie back end */
DictionaryTrie::DictionaryTrie(){
    root = new Node(0,false);

}

/* Insert a word with its frequency into the dictionary.
 * Return true if the word was inserted, and false if it
 * was not (i.e. it was already in the dictionary or it was
 * invalid (empty string) */
bool DictionaryTrie::insert(std::string word, unsigned int freq)
{
		/* check whether the word is valid */
		if (word[0]== ' '|| (int)word[0]<(int)'a'||(int)word[0]>(int)'z')
				return false;

		Node* curr= root;
		std::string dict;

        /* use loop to extract the letter */
		for (unsigned int i = 0; i< word.length(); i++)
		{
			char character = word[i];
			dict += word[i];
			int position;
			/* check if the character exists */
			if (character == ' ')
			  position = LETTERS;
			else
			{
			  position = (int)character - (int)'a';
			  if (position>LETTERS-1 || position < 0)
				return false;
			}
			/* the character is not inserted yet */
			if (curr->children[position]== nullptr)
			{
				/* check if i is less than the word length-1 */
				if (i < word.length()-1)
				{
				  /* middle characters of the word */
				  curr->children[position]=new Node(0,false);
				  /* to instert the string and rest the pointer*/
				  curr->children[position]->dict=dict;
				  curr = curr-> children[position];
				}
				else 
				{
				  /* insert the the new node if i is equal to length-1 */
				  curr->children[position]=new Node(freq,true);	
				  curr->children[position]->dict=word;
				  return true;
				}									
				
			}

			/* the character is already inserted */
			else
			{
				/* check if i is the last node*/
				if (i< word.length()-1)
					curr = curr->children[position];
				else
				{
					/* check the boolean value of the word */
					if (curr-> children[position]-> word == true)
					{
						/* update the frequency */
						if (freq > curr->children[position]->frequency)
							curr-> children[position]->frequency = freq;
						return false;
					}
					else
					{
						/* set the new frequency */
						curr->children[position]->frequency =freq;
						curr->children[position]->word = true;
						return true;
					}
				}
			}
		}
		return false;
		
}
  // left with the cases those characters already exist
  // decide if the insertion is successful on the word indicator 


/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryTrie::find(std::string word) const
{
		Node* curr= root;
		/* use the loop to extract the character to find the word */
		for (unsigned int i = 0; i< word.length(); i++)
		{
				char character = word[i];
				int position;

				/* check if the character exists */
				if (character == ' ')
						position = LETTERS;
				else
				{
						position = (int)character - (int)'a';
			  			if (position>LETTERS-1 || position < 0)
								return false;

				}

				/* check if the children's position is null */
				if (curr->children[position] == nullptr)
				{
						return false;
				}
				else
				{
						/* find the word if i is equal to length-1 */
						if (i == word.length()-1)
						{	
								return curr->children[position]->word;
						}

						curr = curr->children[position];
				}	    
		}
		return false;
}


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
std::vector<std::string> DictionaryTrie::predictCompletions
						(std::string prefix, unsigned int num_completions)
{
		/* declare the variable */
		std::vector<std::string> words;
		std::queue<Node*> que;
		std::priority_queue< std::pair <unsigned int, Node* >> pque;
		/* check whether the word is valid */
		if ( prefix[0]== ' '|| (int)prefix[0]<(int)'a'||(int)prefix[0]>(int)'z')
				return words;
		Node* curr= root;

		/* extract the character from the prefix */
		for (unsigned int i = 0; i< prefix.length(); i++)
		{

				char character = prefix[i];
				int position;

				/* check if the chaaracter is a blank */
				if (character == ' ')
						position = LETTERS;
				else
				{
						position = (int)character - (int)'a';
			  			if (position>LETTERS-1 || position < 0)
								return words;

				}

				/* check if the position in children is null */
				if (curr->children[position] == nullptr)
				{
						/* print out the message */
						cout << "Invalid input.";
						cout << "Please retry with correct input "<< endl;
						return words;
				}
				else
				{
						curr = curr->children[position];
				}	    
		}

		/* put the current node into the queue */
		que.push( curr);

		/* check that the queu is empty or not */
		while (que.empty()== false)
		{
				Node* now = que.front();

				/* remove the first element */
				que.pop();

				/* check that word exists */
				if ( now->word == true)
				{
						std::pair<unsigned int, Node*> pairNode(now->frequency,now);
						pque.push(pairNode);
				}

				/* use the loop to check the position of child */
				for( int i =0; i< LETTERS+1; i++)
				{
						if (now->children[i] != nullptr)
						{
								que.push(now->children[i]);
						}
				}
		}
		/* check if the number of words found is less than num_completions */
		if (num_completions > pque.size())
		{
				num_completions = pque.size();
		}

		/* put the priority of pque put back to the word */
		for (unsigned int i =0; i< num_completions; i++)
		{
				std::pair<unsigned int, Node*> found = pque.top();
				pque.pop();
				words.push_back(found.second->dict);
		}

		return words;
}

/* Destructor */
DictionaryTrie::~DictionaryTrie(){
  deleteNode(root);
}

void DictionaryTrie::deleteNode( DictionaryTrie::Node* node)
{
  /* use the loop to delete the nood */
  for (int i =0; i<LETTERS+1; i++)
  {

	/* check the character is not null */
    if (node->children[i] != nullptr)
	{ 
	  deleteNode(node->children[i]);
	}
  }
  delete node;

}
