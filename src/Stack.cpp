// Noah Bennett - Stack.cpp

#include "Stack.h"
#include "Node.h"

// default constructor
template <typename T>
Stack<T>::Stack()
:List_Base<T>() {}

// Stack copy constructor
template <typename T>
Stack<T>::Stack(const Stack & stack) 
:List_Base<T>(stack) {}

// Stack deconstructor
template <typename T>
Stack<T>::~Stack() {}

template <typename T>
const Stack<T> &Stack<T>::operator= (const Stack &rhs) {
  if(this == &rhs) {
    return *this;
  } else {
    this->size_ = rhs.size_;
    this->head_ = new Node<T>(rhs.head_);
    return *this;
  }
}

template <typename T>
void Stack<T>::push(T element) {
  Node<T> *top = new Node<T>();
  top->data = element;
  top->next = this->head_;
  this->head_ = top;
  this->size_ += 1;
}

template <typename T>
void Stack<T>::pop() {
  if(this->is_empty()) {
    throw Stack::empty_exception();
  } else {
    Node<T> *top = new Node<T>();
    top = this->head_;
    this->head_ = this->head_->next;
  }
  this->size_ -= 1;
}

template <typename T>
void Stack<T>::clear() {
  delete this->head_;
  this->head_ = new Node<T>();
  this->size_ = 0;
}

