/****************************************************************************
 *
 *                                                  Kening Zhang, Gang Yang
 *                                                  CSE 100, fall 17
 *                                                  10/11/2017
 *                                                  cs100fje      cs100fiy
 *
 *                                   Assignment 1
 * Filename: BSTNode.hpp
 * Description: first set the filed of the node, and initialize the node. 
 * Then implement the successor of the node
 *
 ****************************************************************************/

#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>


/** Starter code for PA1, CSE 100 2017
 * This code is based on code by
 * Christine Alvarado and Paul Kube.
 * ADD YOUR NAME AS AN AUTHOR HERE
 */

template<typename Data>
class BSTNode {

public:

  Data const data;   // the const Data in this node.
  BSTNode<Data>* left;
  BSTNode<Data>* right;
  BSTNode<Data>* parent;


  /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
  BSTNode(const Data & d);




  /** Return the successor of this BSTNode in a BST, or 0 if none.
   ** PRECONDITION: this BSTNode is a node in a BST.
   ** POSTCONDITION:  the BST is unchanged.
   ** RETURNS: the BSTNode that is the successor of this BSTNode,
   ** or 0 if there is none.
   */ // TODO
  BSTNode<Data>* successor(); 



}; 


// Function definitions
// For a templated class it's easiest to just put them in the same file as 
// the class declaration

template <typename Data>
BSTNode<Data>::BSTNode(const Data & d) : data(d), left(0), right(0),
								 parent(0){}



/* Return a pointer to the BSTNode that contains the item that is 
 * sequentially next in the tree */
template <typename Data>
BSTNode<Data>* BSTNode<Data>::successor()
{
	// create a pointer for the successor
	BSTNode<Data> * successor;

	// check the existence of the node
	if (this==nullptr)
		return nullptr;
	
	// check the existence of right node
	if (right != nullptr)
	{
		// set the right as the successor
		successor= right;

		// use loop to find the smallest node data that is larger 
		// than the current node 
		while (successor->left != nullptr)
		{
			successor= successor->left;

		}
	}

	// there doesn't exist the right node
	else
	{

		// check the exitence of the parent node
		if (parent != nullptr) 
		{

			// set the current node as successor
			successor= this;

			// check whether successor is equal to its parent's 
			// right node
			while ( successor->parent->right == successor)
			{
				
				// check the null pointer
				if (successor->parent == nullptr)
				{	
					return nullptr;
				}

				// set the new successor
				successor= successor->parent;
				if (successor->parent == nullptr)
				{	
					return nullptr;
				}

			}
			successor=successor->parent;
		}
		// the successor does not exist
		else
		{
			successor = nullptr;
		}
	}
	return successor;

}

/** Overload operator<< to print a BSTNode's fields to an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
  stm << '[';
  stm << std::setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << std::setw(10) << n.parent; // address of its parent
  stm << "; l:" << std::setw(10) << n.left;   // address of its left child
  stm << "; r:" << std::setw(10) << n.right;  // address of its right child
  stm << "; d:" << n.data;                    // its data field
  stm << ']';
  return stm;
}

#endif // BSTNODE_HPP
