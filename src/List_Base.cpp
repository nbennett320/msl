// Noah Bennett - List_Base.cpp

#include "List_Base.h"

extern "C" {
  #include "string.h"
}

// default constructor
template <typename T>
List_Base<T>::List_Base()
:size_(0),
head_(new Node<T>()) {}

// initialize with size 
template <typename T>
List_Base<T>::List_Base(size_t size)
:size_(size),
head_(new Node<T>()) {}

// copy constructor 
template <typename T>
List_Base<T>::List_Base(const List_Base<T> &list)
:size_(list.size_),
head_(new Node<T>()) {
  this->head_ = list.head_;
}

template <typename T>
List_Base<T>::~List_Base() {
  delete this->head_;
}
