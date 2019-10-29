/***************************************************************************
 *
 *						Kening Zhang, Gang Yang
 *						CSE 100, fall 17
 *						10/11/2017
 *						cs100fje      cs100fiy
 *
 * 				Assignment 1
 * Filename: testBST.cpp					
 * Description: test the case of the BST
 *
 ***************************************************************************/



#include "BST.hpp"
#include "BSTIterator.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

/**
 * A test driver for the BST int class and class template.
 * PA1 CSE 100 2017
 * Based on code by Christine Alvarado
 * TODO: Add more tests
 */
int main() {
	/* Create an STL vector of some ints */
	/*test*/
	for (int i=0; i<4;i++)
	{
		vector<int> v;
		// default test
		if (i==0)
		{		
			cout<< "----------TEST 1--------"<< endl;						
			v.push_back(3);
			v.push_back(4);
			v.push_back(1);
			v.push_back(100);
			v.push_back(-33);
		}

		// ADD MORE TESTS HERE.  You might also want to change what is input
		// in vector v
		if (i==1)
		{
			cout<< "----------TEST 2--------"<< endl;	
			v.push_back(3);
			v.push_back(2);
			v.push_back(1);
			v.push_back(9);
			v.push_back(5);
			v.push_back(100);
			v.push_back(81);
			v.push_back(121);
			v.push_back(1000);

		}
		//Test empty case of find
		if (i==2)
		{
			cout<< "----------TEST 3--------"<< endl;	
		}
		//More node to test for the successor method
		if (i==3)
		{
			cout<< "----------TEST 4--------"<< endl;	
			v.push_back(78);
			v.push_back(45);
			v.push_back(56);
			v.push_back(97);
			v.push_back(34);
			v.push_back(89);
			v.push_back(88);
			v.push_back(95);
			v.push_back(-3);
			v.push_back(100);
			v.push_back(81);
			v.push_back(121);
			v.push_back(10);
		}
		/* UNCOMMENT THE LINES BELOW TO TEST THE TEMPLATE-BASED 
                 * ITERATOR */


		// Test the template version of the BST  with ints 
		BST<int> btemp;
		for (int item : v) {
			// The auto type here is the pair 
			// of BSTIterator<int>, bool
			cout << "Inserting " << item 
			<< " into the int template-based BST..."<< endl;
			auto p = btemp.insert(item);
			if (*(p.first) != item) {
				cout << "Wrong iterator returned.  "
				     << "Expected " << item << " but got " 
				     << *(p.first) << endl;
				return -1;
			}
			if (!p.second) 
			{
				cout << "Wrong boolean returned. "
					<<"Expected true but got " 
			        	<< p.second << endl;
				return -1;
			}
		cout << "success!" << endl;
		}
	

		// Now test finding the elements we just put in
		for (int item: v) {
			cout << "Finding " << item << "...." << endl;
			BSTIterator<int> foundIt = btemp.find(item);
			if (*(foundIt) != item) {
				cout << 
		"incorrect value returned.  Expected iterator pointing to "
				<< item << " but found iterator pointing to " 
				<< *(foundIt) 
				<< endl;
				return -1;
			}
			cout << "success!" << endl;
		}



		// Test the iterator: The iterator should give an in-order 
		// traversal

		// Sort the vector, to compare with inorder iteration on the 
		// BST
		sort(v.begin(),v.end());

		cout << "traversal using iterator..." << endl;
		auto vit = v.begin();
		auto ven = v.end();

		// This is equivalent to BSTIterator<int> en = btemp.end();
		auto en = btemp.end();

		//This is equivalent to BST<int>::iterator it = btemp.begin();
		auto it = btemp.begin();
		for(; vit != ven; ++vit) {
			if(! (it != en) ) {
				cout << *it << "," << *vit 
				<< ": Early termination of BST iteration." 
				<< endl;
				return -1;

			}
			cout << *it << endl;
			if(*it != *vit) {
				cout << *it << "," << *vit 
				<< ": Incorrect inorder iteration of BST." 
				<< endl;
				return -1;
			}
			++it;
		}
		cout << "success!" << endl;

		}

		cout << "success!" << endl;
		cout << "All tests passed!" << endl;
		return 0;
	}
