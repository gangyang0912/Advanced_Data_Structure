/*****************************************************************************
 *
 *                                                   Kening Zhang, Gang Yang
 *						     CSE 100, fall 17
 *						     10/11/2017
 *						     cs100fje      cs100fiy
 *
 *				Assignment 1
 * Filename: BSTIterator.hpp
 * Description: set the filed and the method of the BSTIterator class, and 
 * write the operator of increment and dereference. And last we need to check 
 * whether the other is equal to the calling object
 *
 ****************************************************************************/


#ifndef BSTITERATOR_HPP
#define BSTITERATOR_HPP
#include "BSTNode.hpp"
#include <list>
#include <iterator>


// Notice this class extends the std::iterator class.
template<typename Data>
class BSTIterator : public std::iterator<std::input_iterator_tag,Data> {

private:

  BSTNode<Data>* curr;

public:

  /** Constructor.  Use the argument to initialize the current BSTNode
   *  in this BSTIterator.
   */ 
  BSTIterator(BSTNode<Data>* curr);

  Data operator*() const;
  
  /** Pre-increment operator. */
  BSTIterator<Data>& operator++();

  /** Post-increment operator. */
  BSTIterator<Data> operator++(int);

  /** Equality test operator. */
  bool operator==(BSTIterator<Data> const & other) const;

  /** Inequality test operator. */ 
  bool operator!=(BSTIterator<Data> const & other) const;

};

  /** Constructor.  Use the argument to initialize the current BSTNode
   *  in this BSTIterator.
   */ 
template<typename Data>
BSTIterator<Data>::BSTIterator(BSTNode<Data>* curr) {
	
	this->curr = curr;
}

/** Dereference operator. */
template<typename Data>
Data BSTIterator<Data>::operator*() const {
  return curr->data;
}
  
/** Pre-increment operator. */
template<typename Data>
BSTIterator<Data>& BSTIterator<Data>::operator++() {
  // Call the successor method of the BSTNode pointed to by curr.
  curr = curr->successor();
  return *this;
}

/** Post-increment operator. */
template<typename Data>
BSTIterator<Data> BSTIterator<Data>::operator++(int) {
  BSTIterator before = BSTIterator(curr);
  ++(*this);
  return before;
}

/** Equality test operator. */ 
// TODO
template<typename Data>
bool BSTIterator<Data>::operator==(BSTIterator<Data> const & other) const {
  // TODO
  // Notice that other is a reference and not a pointer, thus it cannot 
  // be null
  // Return true if other is equal to the calling object
  // Two iterators are equal if they point to the same BSTNode in the 
  // same BST  
	
	// check that the calling object is equal to the 
	// other compared iterator
	if (this->curr == other.curr )
		return true;
	else
  		return false;

}

/** Inequality test operator. */ 
template<typename Data>
bool BSTIterator<Data>::operator!=(BSTIterator<Data> const & other) const {
  // TODO
  // Notice that other is a reference and not a pointer, thus it cannot 
  // be null
  // Return true if other is NOT equal to the calling object
  // Two iterators are equal if they point to the same BSTNode in the 
  // same BST
  
 	// check that the calling object is equal to the other iterator
	if (this->curr == other.curr )
		return false;
	else
  		return true;
}


#endif //BSTITERATOR_HPP
