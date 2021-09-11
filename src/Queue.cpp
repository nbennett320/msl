// Noah Bennett - Queue.cpp

#include <stdexcept>
#include "Queue.h"

// default constructor
template <typename T>
Queue<T>::Queue(void)
:List_Base<T>(),
tail_(nullptr) {}

// copy constructor
template <typename T>
Queue<T>::Queue(const Queue & queue)
:List_Base<T>(queue),
tail_(queue.tail_) {}

// Queue deconstructor
template <typename T>
Queue<T>::~Queue() {
  delete this->tail_;
}

template <typename T>
void Queue<T>::enqueue (T element) {
  Node<T> *node = new Node<T>();
  node->data = element;
  if(this->tail_ == nullptr) {
    this->head_ = this->tail_ = node;
  } else {
    this->tail_->next = node;
    this->tail_ = node;
  }
  this->size_ += 1;
}

template <typename T>
void Queue<T>::dequeue() {
  if(this->head_ == nullptr) {
    throw Queue::empty_exception();
  } else {
    Node<T> *node = new Node<T>();
    this->head_ = this->head_->next;
    if(this->head_ == nullptr) {
      this->tail_ = nullptr;
    }
  }
  this->size_ -= 1;
}

// operator =
template <typename T>
const Queue<T> &Queue<T>::operator= (const Queue & rhs) {
  if(this == &rhs) {
    return *this;
  } else {
    this->head_ = rhs.head_;
    this->tail = rhs.tail;
    this->size_ = this->size_;
    return *this;
  }
}

template <typename T>
void Queue<T>::clear() {
  Node<T> *node = new Node<T>();
  this->head_ = node;
  this->tail = this->head_;
  this->size_ = 0;
}
