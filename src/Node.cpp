// Noah Bennett - Node.cpp

#include "Node.h"

template <typename T>
Node<T>::Node()
:data(),
next(nullptr) {}

template <typename T>
Node<T>::Node(T data)
:data(data),
next(nullptr) {}

template <typename T>
Node<T>::Node(T data, const Node<T> next)
:data(data),
next(new Node<T>()) {
  this->data = data;
  this->next = next;
}

template <typename T>
Node<T>::Node(const Node &node)
:data(node.data),
next(new Node<T>()) {}

template <typename T>
Node<T>::~Node() {}

template <typename T>
const Node<T> &Node<T>::operator= (const Node<T> &rhs) {
  if(this == &rhs) {
    return *this;
  } else {
    this->data = rhs.data;
    this->next = rhs.next;
    return *this;
  }
}


