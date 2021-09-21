// Noah Bennett - Array.cpp

#include "Array.h"
#include "Array_Base.h"

extern "C" {
  #include "string.h"
  #include "kout.h"
}

template <typename T>
Array<T>::Array(void)
:Array_Base<T>(), 
max_size_(0) {}

template <typename T>
Array<T>::Array(size_t length)
:Array_Base<T>(length),
max_size_(length) {}

template <typename T>
Array<T>::Array(size_t length, T fill)
:Array_Base<T>(length, fill),
max_size_(length) {}

// copy constructor
template <typename T>
Array<T>::Array(const Array<T> & arr)
:Array_Base<T>(arr),
max_size_(arr.max_size_) {}

// copy assignment operator
template <typename T>
const Array<T> & Array<T>::operator= (const Array<T> & rhs) {
  if(this == &rhs) {
    return *this;
  } else {
    this->size_ = rhs.size_;
    this->max_size_ = rhs.max_size_;
    this->data_ = this->deep_copy(rhs);
    return *this;
  }
}

// array square bracket accessor
template <typename T>
T & Array<T>::operator[] (size_t index) {
  try {
    // std::cout <<"trying"<<std::endl;
    if(index < this->size_) {
      // T res = this->data_[index];
      // std::cout <<"size: "<<this->size_<<std::endl;
      // std::cout <<"index: "<< index <<std::endl;

      return this->data_[index];
    } else {
      kprintf("Index out of range at: " + index);
    }
  } catch(size_t e) {
    kprintf("Index out of range at: " + index);
  }
}

// read only
template <typename T>
const T & Array<T>::operator[] (size_t index) const {
  if(index < this->size_) {
    return this->data_[index];
  } else {
    kprintf("Index out of range at: " + index);
  }
}

template <typename T>
T Array<T>::get(size_t index) const {
  if(index < this->size_) {
    return this->data_[index];
  } else {
    kprintf("Index out of range at: " + index);
  }
}

template <typename T>
void Array<T>::set(size_t index, T value) {
  if(index < this->size_) {
    this->data_[index] = value;
  } else {
    kprintf("Index out of range at: " + index);
  }
}

template <typename T>
void Array<T>::shrink(void) {
  T *data_copy = this->deep_copy();
  this->calc_size();
  this->max_size_ = this->size_;
  this->data_ = data_copy;
}

template <typename T>
void Array<T>::resize(size_t new_size) {
  if(new_size == this->size_) {
    // size will not be changed
    return;
  } else if(new_size > this->size_) {
    // handle if new size is greater than current size
    T *data_copy = new T[new_size];
    for(int i = 0; i < new_size; i++) {
      data_copy[i] = this->data_[i];
    }
    this->size_ = new_size;
    this->max_size_ = new_size > this->max_size_ ? new_size : this->max_size_;
    this->data_ = data_copy;
  } else {
    // handle new size is less than current size
    T *data_copy = new T[new_size];
    for(int i = 0; i < new_size; i++) {
      data_copy[i] = this->data_[i];
    }
    this->size_ = new_size;
    this->data_ = data_copy;
  }
}

template  <typename T>
int Array<T>::find(T value) const {
  for(int i = 0; i < this->size_; i++) {
    if(this->data_[i] == value) {
      return i;
    } else {
      continue;
    }
  }
  return -1;
}

template <typename T>
int Array<T>::find(T val, size_t start) const {
  if(start < 0) {
    kprintf("Index cannot be less than zero: " + start);
  } if(start >= this->size_) {
    kprintf("Index out of range at: " + start);
  } else {
    for(int i = start; i < this->size_; i++) {
      if(this->data_[i] == val) {
        return i;
      } else {
        continue;
      }
    }
    return -1;
  }
}

template <typename T>
bool Array<T>::operator == (const Array & rhs) const {
  if(this == &rhs) {
    return true;
  } else if((this->size_ == rhs.size_) && (this->max_size_ == rhs.max_size_)) {
    for(int i = 0; i < this->size_; i++) {
      if(this->data_[i] == rhs.data_[i]) {
        continue;
      } else {
        return false;
      }
    }
    return true;
  } else {
    return false;
  }
}

template <typename T>
bool Array<T>::operator != (const Array & rhs) const {
  if(this == &rhs) {
    return false;
  } else if((this->size_ == rhs.size_) && (this->max_size_ == rhs.max_size_)) {
    for(int i = 0; i < this->size_; i++) {
      if(this->data_[i] == rhs.data_[i]) {
        continue;
      } else {
        return true;
      }
    }
    return false;
  } else {
    return true;
  }
}

template <typename T>
void Array<T>::fill(T value) {
  for(int i = 0; i < this->max_size_; i++) {
    this->data_[i] = value;
  }
}

template <typename T>
void Array<T>::reverse(void) {
  for(int i = 0; i < this->size_ / 2; i++) {
    T temp = this->data_[i];
    this->data_[i] = this->data_[this->size_ - 1 - i];
    this->data_[this->size_ - 1 - i] = temp;
  }
}

template <typename T>
Array<T> Array<T>::slice(size_t begin) const {
  try {
    size_t end = this->size_;
    if(begin > end) {
      // start index greater than current size
      throw begin;
    } else if(begin < 0) {
      throw begin;
    } else {
      Array<T> *arr = new Array<T>(this->max_size_);
      for(int i = begin, j = 0; i < end; i++, j++) {
        arr->data_[j] = this->data_[i];
      }
      arr->shrink();
      return *arr;
    }
  } catch(size_t e) {
    kprintf("Index out of range at: %d", e);
  }
}

template <typename T>
Array<T> Array<T>::slice(size_t begin, size_t end) const {
  try {
    if(this->size_ < end) {
      throw end;
    } else if(begin < 0) {
      throw begin;
    } else {
      Array<T> *arr = new Array<T>(this->max_size_);
      for(int i = begin, j = 0; i < this->size_; i++, j++) {
        arr->data_[j] = this->data_[i];
      }
      arr->shrink();
      return *arr;
    }
  } catch(size_t e) {
    kprintf("Index out of range at: %d", e);
  } 
}

// util methods:
// calculate the current size of the array for cases where
// it might need to be recalculated
template <typename T>
void Array<T>::calc_size(void) {
  try {
    int new_size_ = 0;
    while(this->data_[new_size_]) {
      if(new_size_ >= this->max_size_) {
        break;
      } else {
        new_size_ += 1;
      }
    }
    this->size_ = new_size_;
  } catch(...) {
    kprintf("Index out of range.");
  }
}
