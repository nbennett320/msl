// Noah Bennett - Queue.inl

// size
template <typename T>
inline
size_t Queue<T>::size() const {
  return this->size_;
}

// tail
template <typename T>
inline
T Queue<T>::tail() const {
  return this->tail_->data;
}

// head
template <typename T>
inline
T Queue<T>::head() const {
  return this->head_->data;
}

// is_empty
template <typename T>
inline
bool Queue<T>::is_empty() const {
  return (this->head_ == nullptr);
}
