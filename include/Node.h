// Noah Bennett - Node.h

#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>

template <typename T>
class Node {
  public:
  typedef T type;

  // default constructor
  Node (void);

  // constructor with initial data
  Node (T data);

  // constructor with next
  Node (T data, const Node next);

  // copy constructor
  Node (const Node &node);

  // destructor
  ~Node (void);

  const Node & operator= (const Node &rhs);

  T data;

  Node<T> * next;

};

#include "Node.cpp"

#endif
