// Noah Bennett - Stack.inl

// size
template <typename T>
inline
size_t Stack<T>::size (void) const {
  return this->size_;
}

// top
template <typename T>
inline
T Stack<T>::top() const {
  return this->head_->data;
}

// is_empty
template <typename T>
inline
bool Stack<T>::is_empty() const {
  return (this->head_ == nullptr);
}
