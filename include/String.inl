// Noah Bennett - String.inl

// count the length of the array of chars passed
// to assignment operator
int inline String::countLength(const char * val) {
  int len = 0;
  while(val[len]) len++;
  return len;
}

// return array's current size
size_t inline String::size (void) const {
  return this->size_;
}