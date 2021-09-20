// Noah Bennett - Array_Base.h

#ifndef _ARRAY_BASE_H_
#define _ARRAY_BASE_H_

// include size_t
#include <cstring>
#include <iostream>

/**
 * @class Array_Base
 * 
 * Base class for arrays.
 */
template <typename T>
class Array_Base {
  public:
  typedef T type;

  // Default constructor.
  Array_Base(void);

  /**
   * Initializing constructor.
   *
   * @param[in]      length        Initial size
   */
  Array_Base(size_t length);

  /**
   * Initializing constructor.
   *
   * @param[in]      length        Initial size
   * @param[in]      fill          Initial value for each element
   */
  Array_Base(size_t length, T fill);

  /**
   * Copy constructor
   *
   * @param[in]     arr         The source array.
   */
  Array_Base(const Array_Base & arr);

  // Destructor.
  ~Array_Base(void);

  /**
   * Get the character at the specified index. If the \a index is not within
   * the range of the array, then std::out_of_range exception is thrown.
   *
   * @param[in]       index                 Zero-based location
   * @return          Character at \index
   * @exception       std::out_of_range     Invalid index value
   */  
  virtual T get(size_t index) const;

  /** 
   * Set the character at the specified \a index. If the \a index is not
   * within range of the array, then std::out_of_range exception is 
   * thrown.
   *
   * @param[in]       index                 Zero-based location
   * @param[in]       value                 New value for character
   * @exception       std::out_of_range     Invalid \a index value
   */
  virtual void set(size_t index, T value);

  /**
   * Print the contents of the array.
   */
  virtual void print(void);

  /**
   * Print the contents of the array.
   */
  virtual void print(bool show_brackets);

  /**
   * Print the contents of the array, with string separator passed as parameter.
   */
  virtual void print(std::string sep);

  /**
   * Print the contents of the array, with char separator passed as parameter.
   */
  virtual void print(char sep);

    /**
   * Print the contents of the array, with string separator passed as parameter.
   * Brackets optionally printed.
   */
  virtual void print(std::string sep, bool show_brackets);

  /**
   * Print the contents of the array, with char separator passed as parameter.
   * Brackets optionally printed.
   */
  virtual void print(char sep, bool show_brackets);

  protected: 

  // data
  T * data_;

  // current size
  size_t size_;

  // friend class List_Base<T>;

  // deep copy data from Array class
  T * deep_copy(const Array_Base & arr);

  // deep copy data from self
  T * deep_copy(void);

  // deep copy data from pointer
  T * deep_copy(const T * data, size_t size);

  virtual void print_base(std::string sep);
  
  virtual void print_base(char sep);

};

#include "Array_Base.inl"
#endif
