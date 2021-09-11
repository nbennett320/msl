// Noah Bennett - Array_Base.inl
// print and deep copy methods for Array_Base, 
// pasted here for cleanliness in Array_Base.cpp

// handle print with string separators
template <typename T>
void Array_Base <T>::print_base(std::string sep) {
  for(int i = 0; i < this->size_; i++) {
    std::cout << this->data_[i];
    if((i + 1) < this->size_) {
      std::cout << sep;
    }
  }
}

// handle print with char separators
template <typename T>
void Array_Base <T>::print_base(char sep) {
  for(int i = 0; i < this->size_; i++) {
    std::cout << this->data_[i];
    if((i + 1) < this->size_) {
      std::cout << sep;
    }
  }
}

// print with default separator, ", "
template <typename T>
void Array_Base <T>::print() {
  this->print(", ", true);
}

// print with default separator, ", "
template <typename T>
void Array_Base <T>::print(bool show_brackets) {
  this->print(", ", show_brackets);
}

template <typename T>
void Array_Base <T>::print(std::string sep) {
  this->print(sep, true);
}

template <typename T>
void Array_Base <T>::print(char sep) {
  this->print(sep, true);
}

template <typename T>
void Array_Base <T>::print(std::string sep, bool show_brackets) {
  if(show_brackets) std::cout << "[ ";
  this->print_base(sep);
  if(show_brackets) std::cout << " ]";
  std::cout << std::endl;
}

template <typename T>
void Array_Base <T>::print(char sep, bool show_brackets) {
  if(show_brackets) std::cout << "[ ";
  this->print_base(sep);
  if(show_brackets) std::cout << " ]";
  std::cout << std::endl;
}

// deep_copy methods:
// return a deep copy of data from Array provided
template <typename T>
T * Array_Base <T>::deep_copy(const Array_Base & arr) {
  T * data_copy_ = new T[arr.size_];
  for(int i = 0; i < arr.size_; i++) {
    data_copy_[i] = arr[i];
  }
  return data_copy_;
}

// return a deep copy of data from Array provided
template <typename T>
T * Array_Base <T>::deep_copy(void) {
  T * data_copy_ = new T[this->size_];
  for(int i = 0; i < this->size_; i++) {
    data_copy_[i] = this->data_[i];
  }
  return data_copy_;
}

// return a deep copy of data
template <typename T>
T * Array_Base <T>::deep_copy(const T * data, size_t size) {
  T * data_copy_ = new T [size];
  for(int i = 0; i < size; i++) {
    data_copy_[i] = data[i];
  }
  return data_copy_;
}
