/***************************************************************************
 *
 *                                                  Kening Zhang, Gang Yang
 *						    CSE 100, fall 17
 *						    10/11/2017
 *						    cs100fje      cs100fiy
 *
 *				   Assignment 1	
 * Filename: main.cpp
 * Description: first the function will initialize the data of the tree, and 
 * check the argument and the opened file. Then we need to creat a BST and 
 * add name string. Also, we will set the value of tree size and height. 
 * Finally, the user will get the information whether the name is in the 
 * string
 *
 * 
 ***************************************************************************/

#include "BST.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include<fstream>
#include<string>

/**
 *  IMPORTANT!! DO NOT CHANGE THE LINES THAT DO I/O BELOW.
 *
 *  Note that size, height, and name are local variables in main that you 
 *  should update accordingly. Also note that actor/actress names will be 
 *  in all caps, last name followed by first name 
 *  (except in odd cases, eg. "50 CENT" and "ICE-T")
 */

using namespace std;

int main(int argc, char* argv[])
{
    //Size of tree should be stored in local variable size.
    //Height of tree should be stored in local variable height.
    //Input name will be stored in a string name
    unsigned int size = 0;
    unsigned int height = 0;
    std::string name = "";
  
    //Check for Arguments
    if(argc != 2){
        cout << "Invalid number of arguments.\n" 
             << "Usage: ./main <input filename>.\n";
        return -1;
    }
  
    //Open file 
    ifstream in;
    in.open(argv[1]);

    
  
    //Check if input file was actually opened
    if(!in.is_open()) 
    {
        cout<< "Invalid input file. No file was opened. Please try again.\n";
        return -1;
    }
	else {
	  
        // Follow the comments below to add code:
        
        // TODO: Create a new BST here
	BST<string> tree;
        
        while (getline(in, name)) {
            // TODO: add the name string to the BST
		tree.insert(name);	    
            
        }

        // TODO: Get the height of the BST and store it in height
	height=tree.height();
        // TODO: Get the size of the BST and store it in size
	size=tree.size();
        // DO NOT CHANGE THE LINES BELOW
        cout << "Size of tree: " << size << endl;
        cout << "Height of tree: " << height << endl;

        char prompt = 'y';
        while (prompt != 'n') {
            cout << "Enter actor/actress name: " << endl;
            getline(cin, name);
            
            // TODO: Change the if statment to check is name is in the BST
	    BSTIterator<string> findIt= tree.find(name);
	    auto empty = tree.end();

	    // name is in the tree
            if (findIt != empty && *(findIt)== name) {
                cout << name << " found!" << endl;
            }

	    // name is not in the tree
            else {
                cout << name << " NOT found" << "\n";
            }
            cout << "Search again? (y/n)" << endl;
            cin >> prompt;  // Get the first character
            // Then ignore until newline
            cin.ignore( numeric_limits <streamsize> ::max(), '\n' );  
        }
        in.close();

    }
    return 0;

}
