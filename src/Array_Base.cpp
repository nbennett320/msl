// Noah Bennett - Array_Base.cpp

#include "Array_Base.h"
#include "String.h"

extern "C" {
  #include "kout.h"
}

// default constructor
template <typename T>
Array_Base <T>::Array_Base (void)
:size_(0),
data_(nullptr) {}

// constructor with array size
template <typename T>
Array_Base<T>::Array_Base(size_t length)
:size_(length), 
data_(new T[length]) {}

// template <>
// Array_Base<String>::Array_Base(size_t length)
// :size_(length), 
// data_(new String(length)) {}

// fill constructor
template <typename T>
Array_Base <T>::Array_Base(size_t length, T fill)
:size_(length), 
data_(new T[length]) {
  for(int i = 0; i < this->size_; i++) {
    this->data_[i] = fill;
  }
}

// copy constructor
template <typename T>
Array_Base<T>::Array_Base(const Array_Base<T> & arr)
:size_(arr.size_), 
data_(new T[arr.size_]) {
  for(int i = 0; i < arr.size_; i++) {
    this->data_[i] = arr.data_[i];
  }
}

// copy constructor
// template <>
// Array_Base<String>::Array_Base(const Array_Base<String> & arr)
// :size_(arr.size_), 
// data_(new String(arr.size_)) {
//   for(int i = 0; i < arr.size_; i++) {
//     this->data_[i] = arr.data_[i];
//   }
// }

template <typename T>
Array_Base<T>::~Array_Base() {
  delete [] this->data_;
}

template <typename T>
T Array_Base<T>::get(size_t index) const {
  if(index < this->size_) {
    return this->data_[index];
  } else {
    kprintf("Index out of range at: " + index);
  }
}

template <typename T>
void Array_Base<T>::set(size_t index, T value) {
  if(index < this->size_) {
    this->data_[index] = value;
  } else {
    kprintf("Index out of range at: " + index);
  }
}
