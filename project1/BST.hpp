/****************************************************************************
 *
 *                                                   Kening Zhang, Gang Yang
 *			      			     CSE 100, fall 17
 *						     10/11/2017
 *				                     cs100fje      cs100fiy
 *
 * 				Assignment 1
 * Filename: BST.hpp
 * Description: set the field of BST and set the data of this field.Then 
 * write the method to insert or find the node. Then we need to find the 
 * first data and check whether the tree is empty
 * 			
 ***************************************************************************/

#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <iostream>

template<typename Data>
class BST {

public:

  /** define iterator as an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
      This is inlined because it is trivial.
   */
  BST() : root(nullptr), isize(0),iheight(0) {}


  /** Default destructor.
      Delete every node in this BST.
  */
  ~BST();

  /** Given a reference to a Data item, insert a copy of it in this BST.
   *  Return a pair where the first element is an iterator 
   *  pointing to either the newly inserted element or the element 
   *  that was already in the BST, and the second element is true if the 
   *  element was newly inserted or false if it was already in the BST.
   * 
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. (should not use ==, >, <=, >=)  
   */
  std::pair<iterator, bool> insert(const Data& item);


  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or pointing past
   *  the last node in the BST if not found.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. (should not use ==, >, <=, >=).  For the reasoning
   *  behind this, see the assignment writeup.
   */
  iterator find(const Data& item) const;

  
  /** Return the number of items currently in the BST.
   */ 
  unsigned int size() const;
  
  /** Return the height of the BST.
      height of a tree starts with root at height 0
   */ 
  unsigned int height() const;


  /** Return true if the BST is empty, else false.
   */ // TODO
  bool empty() const;

  /** Return an iterator pointing to the first (smallest) item in the BST.
   */ 
  iterator begin() const;

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const;


private:

  /** Pointer to the root of this BST, or 0 if the BST is empty */
  BSTNode<Data>* root;
  
  /** Number of Data items stored in this BST. */
  unsigned int isize;

  /** Height to trace in BST*/
  unsigned int iheight;

  /** Find the first element of the BST
   * Helper function for the begin method above.
   */ 
  static BSTNode<Data>* first(BSTNode<Data>* root);

  /** do a postorder traversal, deleting nodes
   */
  static void deleteAll(BSTNode<Data>* n);
 };


// ********** Function definitions ****************


/** Default destructor.
    Delete every node in this BST.
*/
template <typename Data>
BST<Data>::~BST() {
  deleteAll(root);
}


/** Given a reference to a Data item, insert a copy of it in this BST.
 *  Return a pair where the first element is an iterator pointing to either 
 *  the newly inserted
 *  element or the element that was already in the BST, and the second 
 *  element is true if the 
 *  element was newly inserted or false if it was already in the BST.
 * 
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=)  
 */
template <typename Data>
std::pair<BSTIterator<Data>, bool> BST<Data>::insert(const Data& item) {
	// TODO
	// REPLACE THE LINE BELOW
	
	// intialize the newNode and set the crrent height to 0
	BSTNode<Data>* newNode = new BSTNode<Data>(item);
	unsigned int currHeight=0;

	//check if root pointer is null
	if (root == nullptr)
	{
		
		// set the root and increase the node number
		root=newNode;
		isize++;
		return std::pair<BSTIterator<Data>, bool>
			(BSTIterator<Data>(newNode), true);
	}

	// set the node as current node
	BSTNode<Data>* current = root;

	// check the data of isert node
	while ((current->data < item || item < current->data))
	{

		// check that the current data and the insert data
		if(item< current-> data)
		{

			// check whether have the left node
			if (current->left == nullptr)
			{

				// set the left node and increase the 
				// hieght and node number
				current->left = newNode;
				currHeight++;
				isize++;
				if (currHeight> iheight)
				{
					iheight=currHeight;
				}

				newNode->parent=current; 
				return  std::pair<BSTIterator<Data>, bool>
					(BSTIterator<Data>(newNode), true);

			}	
				
			// current node has a left node
			else 
			{
				current = current->left;
				currHeight++;
			}
		}

		// the current data is smaller than the insert data
		else
		{

			// check the right node
			if (current->right == nullptr)
			{

				// set the right node and increase 
				// the node size and height
				current->right = newNode;
				newNode->parent=current;
				isize++;
				currHeight++;

				// compare the height to see if it's 
				// the highest children
				if (currHeight> iheight)

				{
					iheight=currHeight;
				}
				return  std::pair<BSTIterator<Data>, bool>
					(BSTIterator<Data>(newNode), true);

			}

			// right node exists	
			else 
			{
				current = current->right;
				currHeight++;
			}
	
		}
	}
	// the node is already in the tree, delete the allocated space
	delete newNode;
	return std::pair<BSTIterator<Data>, bool>(
			BSTIterator<Data>(current), false);

}


/** Find a Data item in the BST.
 *  Return an iterator pointing to the item, or pointing past
 *  the last node in the BST if not found.
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=).  For the reasoning
 *  behind this, see the assignment writeup.
 */
template <typename Data>
BSTIterator<Data> BST<Data>::find(const Data& item) const
{
	// TODO
	
	// check the existence of the root
	if (root == nullptr)
	{
		return end();
	}

	// set the current node
	BSTNode<Data>* current = root;

	// compare the data of current node and the node we need to find
	while ((current->data < item || item < current->data))
	{

		if(item< current-> data)
		{
			
			// set the left node to current data if item is less 
			// than current data
			current = current->left;

			if (current == nullptr)
				return end();
		}

		else
		{

			// set the right node to current data if 
			// item is larger than current data
			current = current->right;

			if (current == nullptr)
				return end();

		}
	}
	//find the node and return
	return BSTIterator<Data>(current);
}

  
/** Return the number of items currently in the BST.
 */ 
template <typename Data>
unsigned int BST<Data>::size() const
{
  return isize;
}

/** Return the height of the BST.
 */
template <typename Data> 
unsigned int BST<Data>::height() const
{
  return iheight;
}


/** Return true if the BST is empty, else false.
 */ 
template <typename Data>
bool BST<Data>::empty() const
{
  // TODO
  if (isize ==0)
    return true;
  else
    return false;
}

/** Return an iterator pointing to the first (smallest) item in the BST.
 */ 
template <typename Data>
BSTIterator<Data> BST<Data>::begin() const
{
  return BSTIterator<Data>(first(root));
}

/** Return an iterator pointing past the last item in the BST.
 */
template <typename Data>
BSTIterator<Data> BST<Data>::end() const
{
  return BSTIterator<Data>(nullptr);
}

/** Find the first element of the BST
 * Helper function for the begin method above.
 */ 
template <typename Data>
BSTNode<Data>* BST<Data>::first(BSTNode<Data>* root)
{
  // TODO
 
  // check the existence of root
  if (root == nullptr)
  {
    return root;
  }

  // set the temp node to root's left node and check the existence
  BSTNode<Data> *temp = root->left;
  if (temp == nullptr)
  {
    return root;
  }

  // use loop to find the first node
  while (temp->left)
  {
    temp= temp->left;
  }
  return temp;
}

/** do a postorder traversal, deleting nodes
 */
template <typename Data>
void BST<Data>::deleteAll(BSTNode<Data>* n)
{
	//check if root exists
	if (n!= nullptr)
	{
		// check if the left node exists
		if(n-> left != nullptr)
		{
			// recursively call deleteAll on left node
			deleteAll(n->left);
		}
		// check if the right node exists
		if(n-> right != nullptr)
		{
			deleteAll(n->right);
		}
		// delete the node itself
		delete n;
	}
}



#endif //BST_HPP
