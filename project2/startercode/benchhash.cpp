/************************************************************************
 *
 *												Kening zhang, Gang Yang
 *												CSE 100, fall 17
 *												10/29/2017
 *												cs100fje	  cs100fiy
 *												
 *							Assignment 2
 * Filename: benchhash.cpp
 * Parameter: 
 * 				string dicfile: the file to get words from
 * 				unsigned int num_words: length of hashTable
 * Description: Compare the run time efficiency of two different 
 * 				hash function by calculating the average collision and 
 * 				the max number of collision for each insert into hash
 * 				table		
 ***********************************************************************/
#include<string>
#include<iostream>
#include<fstream>
#include<cmath>
#include "util.h"
#include "DictionaryTrie.h"
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"
#define BIT 31
#define HIT 50
using namespace std;


// Source:textbook 5.2.3 https://stepik.org/lesson/31712/step/3?unit=11896
static unsigned int hashValue1
			(const std::string key, const unsigned int size){
    unsigned int val = 0;
    for(unsigned int i = 0; i < key.length(); i++) 
	{
        val += (unsigned int)(key[i]); 
		// cast each character of key to unsigned int
    }
    return (val%size);                        
	// return the sum over all characters in key and mode size
}
 
// Source: Online 
// https://www.cs.cmu.edu/~adamchik/15-121/lectures/Hashing/hashing.html
static unsigned int hashValue2
			(const std::string key, const unsigned int size){
    unsigned int val = 0;
	unsigned int length = key.length();
    for(unsigned int i = 0; i < length; i++) 
	{
        val += (((unsigned int)key[i])*pow(BIT,(length-1-i))); 
		// s.charAt(0) * 31n-1 + s.charAt(1) * 31n-2 + ... + s.charAt(n-1)
    }
    return (val%size);                        
	// return the sum over all characters in key mode size
}




int main(int argc, char** argv) 
{

  // Test Case to check if hash function works
  // Simple case
  /*
  std::string s1("abc");
  if(hashValue1(s1,50)==44)
  {
    cout<<"Success in hashValue1"<< endl;
  }
  else
  {
	cout<< "Fail in hashValue1" << endl;
  }

  if(hashValue2(s1,50)==4)
  {
    cout<<"Success in hashValue2"<< endl;
  }
  else
  {
	cout<< "Fail in hashValue2" << endl;
  }
  cout<< hashValue1(s1,50)<<endl;
  cout<< hashValue2(s1,50)<<endl;
  */




  // Test Case2 to check if hash function works for empty space
  /*
  std::string s2("I I");
  if(hashValue1(s2,50)==28)
  {
    cout<<"Success in hashValue1"<< endl;
  }
  else
  {
	cout<< "Fail in hashValue1" << endl;
  }

  if(hashValue2(s2,50)==18)
  {
    cout<<"Success in hashValue2"<< endl;
  }
  else
  {
	cout<< "Fail in hashValue2" << endl;
  }
  cout<< hashValue1(s2,50)<<endl;
  cout<< hashValue2(s2,50)<<endl;
  */





  // Test Case3 to check if hash function works for long string
  /*
  std::string s3("ARASHIBENCHHASH");
  if(hashValue1(s3,50)==34)
  {
    cout<<"Success in hashValue1"<< endl;
  }
  else
  {
	cout<< "Fail in hashValue1" << endl;
  }

  if(hashValue2(s3,50)==21)
  {
    cout<<"Success in hashValue2"<< endl;
  }
  else
  {
	cout<< "Fail in hashValue2" << endl;
  }
  cout<< hashValue1(s3,50)<<endl;
  cout<< hashValue2(s3,50)<<endl;
  */



  if (argc!=3)
	return false;
  // get the file name and number of words from input parameters
  std::string dictfile = argv[1];
  unsigned int num_words = atoi(argv[2]);
  // string to store the words got form dictionary
  std::vector<std::string> stringArray;
  // initialize the array to store the count and collision to zeros
  std::vector<unsigned int> countArray1(2*num_words,0);
  std::vector<unsigned int> hitCount1(HIT,0);

  std::vector<unsigned int> countArray2(2*num_words,0);
  std::vector<unsigned int> hitCount2(HIT,0);
  // int to store the max of collision
  unsigned int max1=0;
  unsigned int max2=0;

  //open the file and check validity
  ifstream in;
  in.open(dictfile);
  if ( in.is_open()== false )
  {
    cout<<"Can Not open file, please retry."<<endl;
  	return false;
  }
  // load the dictionary to vector
  Utils::load_vector(stringArray, in ,num_words);
  in.close();

  // iterate the string vector to count the frequency
  for (unsigned int j=0; j<num_words; j++)
  {
	// get the hashvalue
	unsigned int value1 = hashValue1(stringArray[j],2*num_words);
	unsigned int value2 = hashValue2(stringArray[j],2*num_words);
	
	// increase the count in the array
	countArray1[value1]++;
	// find the max
	if (max1 < countArray1[value1])
		max1= countArray1[value1];


	countArray2[value2]++;
	if (max2 <= countArray2[value2])
	{
		max2= countArray2[value2];
    }
  }

  // iterate the count vector
  for (unsigned int k=0; k<2*num_words;k++)
  {
	// sum up the collision to make a list
	for (unsigned int j =0;j< max1+1; j++)
	{
      if (countArray1[k]==j)
	  {
	    hitCount1[j]++;
		break;
      }
	}
  }
  // same for the second vector
  for (unsigned int k=0; k<2*num_words;k++)
  {
	for (unsigned int j =0;j< max2+1; j++)
	{
    if (countArray2[k]==j)
	  {
	    hitCount2[j]++;
        break;
	  }
	}
  }


  //Hash Function1
  // print number of slot
  cout<<"Printing the statistics for HashFunction1 with hash table size "
		  << 2*num_words << endl;
  cout<< "#hits"<<'\t'<<"#slots receiving the #hits"<< endl;
  for (unsigned int i =0;i< max1+1; i++)
  {
		  cout<< i <<'\t' << hitCount1[i]<< endl;
  } 
  unsigned int count1 =0;
  for(unsigned int i =1; i<max1+1;i++ )
  {
		  unsigned int perSum= (1+i)*i/2; 
		  //count the sum from 1 to i
		  count1 = count1 + perSum* hitCount1[i];
  }
  // get the average collision
  float ave1= (float)count1/num_words;
  cout << "The average number of steps"
		  << "for a successful serach for hashfunction1: " << ave1<< endl;

  cout << "The worst case steps that would be needed to find a word is "
		  << max1 << endl;


  // Hash Function2 
  // print number of slot
  cout<<"Printing the statistics for HashFunction2 with hash table size "
		  << 2*num_words << endl;
  cout<< "#hits"<<'\t'<<"#slots receiving the #hits"<< endl;
  for (unsigned int i =0;i< max2+1; i++)
  {
		  cout<< i <<'\t' << hitCount2[i]<< endl;
  } 

  // count the average
  unsigned int count2 =0;
  for(unsigned int i =1; i<max2+1;i++ )
  {
		  unsigned int perSum= (2+i)*i/2; //count the sum from 2 to i
		  count2 = count2 + perSum* hitCount2[i];
  }
  // get the average collision
  float ave2= (float)count2/num_words;
  cout << "The average number of steps"
		  << "for a successful serach for hashfunction2: " << ave2 << endl;

  cout << "The worst case steps that would be needed to find a word is "
		  << max2 << endl;
  
}
