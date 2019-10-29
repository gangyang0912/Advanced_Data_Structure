/*******************************************************************************
 *
 *														Kening Zhang, Gang Yang
 *														CSE 100, fall 17
 *														10/30/2017
 *														cse100fje	  cs100fiy
 *
 *									Assignment 2
 * Filename: test.cpp
 * Description: test the three structure, BST, hashtable and trie. Then test the
 * auto-complete in DictionaryTrie									
 *
 ******************************************************************************/


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
#define LETTERS 26
using namespace std;


int main(int argc, char** argv)
{

  //Initialize words
  vector<std::string> words;
  vector<string>::iterator wit;
  vector<string>::iterator wen;
  //initialize nonwords
  set<string> nope;
  set<string>::iterator nit;
  set<string>::iterator nen;

  //Initialize data structures
  DictionaryBST d_bst;
  DictionaryHashtable d_ht;
  DictionaryTrie dt;
  int t_bst, t_ht, tt;

  words.push_back("harry");
  words.push_back("sriram");
  words.push_back("cse");
  words.push_back("crucio");
  words.push_back("autocomplete");
  // Put invalid words
  words.push_back(" ");
  words.push_back("A");
  words.push_back("e73");
  words.push_back("araShi");

  
  
  cout << "Inserting into Dictionaries..." << endl;

  wit = words.begin();
  wen = words.end();
  for(; wit != wen; ++wit)
  {
		  cout << "Inserting: \"" << *wit << "\"... ";
		  t_bst = d_bst.insert(*wit);
		  t_ht = d_ht.insert(*wit);
		  tt = dt.insert(*wit, 1);
		  if(!t_bst)
		  {
				  cout << "failed for DictionaryBST... ";
		  }
		  if(!t_ht)
		  {
				  cout << "failed for DictionaryHashset... ";
		  }
		  if(!tt)
		  {
				  cout << "failed for DictionaryTrie... ";
		  }
		  if(t_bst && t_ht && tt)
		  {
				  cout << "PASSED! :D ";
		  }
		  cout << endl;
  }

  cout << endl << "Re-inserting elements that were";
	cout << "just inserted into Dictionaries..." << endl;

  wit = words.begin();
  wen = words.end();
  for(; wit != wen; ++wit)
  {
		  cout << "Inserting: \"" << *wit << "\"... ";
		  t_bst = d_bst.insert(*wit);
		  t_ht = d_ht.insert(*wit);
		  tt = dt.insert(*wit, 0);
		  if(t_bst)
		  {
				  cout << "failed for DictionaryBST... ";
		  }
		  if(t_ht)
		  {
				  cout << "failed for DictionaryHashset... ";
		  }
		  if(tt)
		  {
				  cout << "failed for DictionaryTrie... ";
		  }
		  if(!t_bst && !t_ht && !tt)
		  {
				  cout << "PASSED! :D ";
		  }
		  cout << endl;
  }

  cout << endl;

 
  //Initialize data structures
  DictionaryBST d_bst2;
  DictionaryHashtable d_ht2;
  DictionaryTrie dt2;
  
  cout << "Finding in Dictionaries..." << endl;


  // load freq_dict to BST
  ifstream in;
  in.open("freq_dict.txt");
  if ( in.is_open()== false )
  {
		cout<<"Can Not open file to BST, please retry."<<endl;
		return false;
  }
  Utils::load_dict(d_bst2, in);
  in.close();



  // load freq_dict to HashTable
  in.open("freq_dict.txt");
  Utils::load_dict(d_ht2, in);
  if ( in.is_open()== false )
  {
		cout<<"Can Not open file to Hashtable, please retry."<<endl;
		return false;
  }
  in.close();



  // load freq_dict to trie
  in.open("freq_dict.txt");
  Utils::load_dict(dt2, in);
  if ( in.is_open()== false )
  {
		cout<<"Can Not open file to Trie, please retry."<<endl;
		return false;
  }
  in.close();

  // find Invalid words ib vector
  vector<std::string> mywords;
  mywords.push_back("a a a");
  mywords.push_back(" ");
  mywords.push_back("zhejiang");
  mywords.push_back("zugg");
  mywords.push_back("zheng");
  mywords.push_back("zornn");
  mywords.push_back(" ");
  mywords.push_back("A");
  mywords.push_back("e73");
  mywords.push_back("araShi");


  // find the word using iterator
  vector<string>::iterator curr;
  vector<string>::iterator end;
  curr = mywords.begin();
  end = mywords.end();
  for(; curr != end; ++curr)
  {
		  t_bst=d_bst2.find(*curr);
		  tt= dt2.find(*curr);
		  t_ht=d_ht2.find(*curr);

			// check if FIND function return false
		  cout<<"Testing BST "<< endl;
		  if (t_bst == false)
		  {
				  cout<< "PASSED " << *curr << endl;
		  }
		  else
				  cout << "failed "<< *curr << endl;

		  cout<<"Testing HashTable ";
		  if (t_ht == false)
		  {
				  cout<< "PASSED " << *curr << endl;
		  }
		  else
				  cout << "failed "<< *curr << endl;


		  cout<< "Testing Dictionary Trie ";
		  if(tt== false)
		  {
				  cout<< "PASSED " << *curr << endl;
		  }
		  else
				  cout << "failed "<< *curr << endl;

  }

  // Valid string
  vector<std::string> mywords2;
  mywords2.push_back("zz");
  mywords2.push_back("a a");
  mywords2.push_back("zzz");
  mywords2.push_back("choices like");
  mywords2.push_back("zz top");
  mywords2.push_back("moved back from");
  mywords2.push_back("did nt pass the");

	// set iterator to the begining of the vector
  curr=mywords2.begin();
  end = mywords2.end();
  for(; curr != end; ++curr)
  {
	
	    t_bst=d_bst2.find(*curr);
		  tt= dt2.find(*curr);
		  t_ht=d_ht2.find(*curr);
			// check if the FIND function return true
		  cout<<"Testing BST "<<endl;
		  if (t_bst == true)
		  {
				  cout<< "PASSED " << *curr << endl;
		  }
		  else
				  cout << "failed "<< *curr << endl;

		  cout<<"Testing HashTable ";
		  if (t_ht == true)
		  {
				  cout<< "PASSED " << *curr << endl;
		  }
		  else
				  cout << "failed "<< *curr << endl;

		  cout<< "Testing Dictionary Trie ";
		  if(tt== true)
		  {
				  cout<< "PASSED " << *curr << endl;
		  }
		  else
				  cout << "failed "<< *curr << endl;
  }



  // Test for predict completion
  // Initialize data structures
  DictionaryTrie dt3;

  cout << "Testing Predict Completion in Dictionaries..." << endl;

  in.open("smalldictionary.txt");
  if ( in.is_open()== false )
  {
		cout<<"Can Not open file smalldictionary, please retry."<<endl;
		return false;
  }
  Utils::load_dict(dt3, in);
  in.close();
	// Call function and store the vector returned
  cout<< "Predict Completion of Smalldictionary"<< endl;
  std::vector<std::string> myvector= dt3.predictCompletions(" ",2);

	// Check Trie
  if ( myvector.empty())
	cout<< "Can not find the string "<< endl;
  else
  {
  	wit = myvector.begin();
  	wen = myvector.end();
  	cout<< "result is "<< endl;
  	for(; wit != wen; ++wit)
  	{		
      cout<< *wit<< endl;
    }
  }




  // Initialize dictionary for predic completion
  DictionaryTrie dt4;

	// load file
  in.open("shuffled_freq_dict.txt");
  if ( in.is_open()== false )
  {
		cout<<"Can Not open file shuffled_freq_dict, please retry."<<endl;
		return false;
  }
  Utils::load_dict(dt4, in);
  in.close();

	// Call function for vectors to save the result
  cout<< "Predict Completion of shuffled_freq_dict"<< endl;
  myvector= dt4.predictCompletions("ab",10);

	// check if the vector returned is empty
  if ( myvector.empty())
  cout<< "Can not find the string "<< endl;
  else
  {
		wit = myvector.begin();
    wen = myvector.end();
    cout <<"result is "<< endl;
    //print out the vector
		for(; wit != wen; ++wit)
    {  	
      cout<< *wit<< endl;
    }
  }   
  return 0;
}
