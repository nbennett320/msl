// Noah Bennett - Array.inl

// return array's current size
template <typename T>
inline
size_t Array <T>::size (void) const {
  return this->size_;
}

// returns array's max size
template <typename T>
inline
size_t Array <T>::max_size (void) const {
  return this->max_size_;
}
