// Noah Bennett - Fixed_Array.inl

// return array's current size
template <typename T, size_t N>
inline
size_t Fixed_Array <T, N>::size (void) const {
  return this->size_;
}
