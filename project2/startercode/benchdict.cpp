/************************************************************************
 *
 *												Kening zhang, Gang Yang
 *												CSE 100, fall 17
 *												10/29/2017
 *												cs100fje	  cs100fiy
 *												
 *							Assignment 2
 * Filename: benchdict.cpp
 * Parameter:
 * 			int min:      the starting words number to run the funtion
 * 			int stepSize: the increasing words number for the iteration
 * 						  of the function
 * 		    int iterateTime: the number of loop of operation
 * 		    string filename: the file to load the words from
 * Description: Compare the run time efficiency of find of BST, HashTable 
 * 				and Dictionary Trie with changing size of words				
 ***********************************************************************/
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<set>
#include<cstdlib>
#include "util.h"
#include "DictionaryTrie.h"
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"
#define TIME 30 // number of iteration to get average time
#define HUNDRED 100 // vector length
using namespace std;


int main(int argc, char** argv)
{
  // check if the input parameter is valid
  if (argc !=5)
  {
	cout<< "Please enter min step iterateTime filename"<< endl;
  	return false;
  }
  int min = atoi(argv[1]);
  int stepSize= atoi(argv[2]);
  int iterateTime = atoi(argv[3]);
  

  cout<< "DictionaryTrie"<< endl;
  for (int i =0; i < iterateTime; i++)
  {
	// Create a new Trie
    DictionaryTrie *dt=new DictionaryTrie();
    std::vector<std::string> words; // vector to store the words

	// check if the file is valid
    ifstream in;
    in.open( argv[4]);
	if ( in.is_open()== false )
    {
	  cout<<"Can Not open file, please retry."<<endl;
	  return false;
    }
	// load dictsize from input file to trie
	int dictsize = min+ i*stepSize ;
	Utils::load_dict(*dt, in, dictsize);
	// load 100 words from input file to vector
	Utils::load_vector(words, in, HUNDRED);
	in.close();
	
	// calculate time to find 100 words
	long long aveTime=0;
	for (int k=0; k< TIME; k++)
	{
	  Timer t;
	  t.begin_timer();
	  for(int j = 0; j< HUNDRED; j++)
	  {
	    	dt->find(words[j]);
      }
      long long oneTime= t.end_timer();
	  aveTime+=oneTime;
	}
	// get the average time of 30 time
	aveTime= aveTime/TIME;
	cout<< dictsize <<'\t' << aveTime <<endl;
	delete dt;
  }	


  cout<< "DictionaryBST"<< endl;
  for (int i =0; i < iterateTime; i++)
  {
	// Create a new BST
    DictionaryBST *bst=new DictionaryBST();
    std::vector<std::string> words;

    ifstream in;
    in.open( argv[4]);
    if ( in.is_open()== false )
    {
	  cout<<"Can Not open file, please retry."<<endl;
  	  return false;
    }
	// load dictsize from input file to BST
	int dictsize = min+ i*stepSize ;
	Utils::load_dict(*bst, in, dictsize);
	
	// load 100 words from input file to vector
	Utils::load_vector(words, in, HUNDRED);
	in.close();
	

	long long aveTime=0;
	for (int k=0; k< TIME; k++)
	{
	  Timer t;
	  t.begin_timer();
	  for(int j = 0; j< HUNDRED; j++)
	  {
	    	bst->find(words[j]);
      }
      long long oneTime= t.end_timer();
	  aveTime+=oneTime;
	}
	// get the average run time of 30 times
	aveTime= aveTime/TIME;
	cout<< dictsize <<'\t' << aveTime <<endl;
	delete bst;
  }	


  cout<< "DictionaryHashtable"<< endl;
  for (int i =0; i < iterateTime; i++)
  {
	// Create a new HT
    DictionaryHashtable *ht=new DictionaryHashtable();
    std::vector<std::string> words;

    ifstream in;
    in.open( argv[4]);
    if ( in.is_open()== false )
    {
	cout<<"Can Not open file, please retry."<<endl;
	return false;
    } 
	int dictsize = min+ i*stepSize ;
	Utils::load_dict(*ht, in, dictsize);
	// load 100 words to vector
	Utils::load_vector(words, in, HUNDRED);
	in.close();
	

	long long aveTime=0;
	for (int k=0; k< TIME; k++)
	{
	  Timer t;
	  t.begin_timer();
	  for(int j = 0; j< HUNDRED; j++)
	  {
	      ht->find(words[j]);
      }
      long long oneTime= t.end_timer();
	  aveTime+=oneTime;
	}
	// get the average time of 30 times
	aveTime= aveTime/TIME;
	cout<< dictsize <<'\t' << aveTime <<endl;
	delete ht;
  }	

  return true;
  
}

