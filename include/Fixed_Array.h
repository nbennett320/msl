// Noah Bennett - Fixed_Array.h

#ifndef _FIXED_ARRAY_
#define _FIXED_ARRAY_

#include "Array.h"

/**
 * @class Fixed_Array
 *
 * Implementation of a fixed size array, i.e., one that is not
 * resizeable. It is derived from Array so it can inherit of 
 * the Array class's methods.
 */
template <typename T, size_t N>
class Fixed_Array : public Array_Base<T> {
  public:
  /// Default constructor.
  Fixed_Array(void);

	/**
	 * Copy constructor.
	 *
	 * @param[in]      arr        Source array
	 */
  Fixed_Array(const Fixed_Array<T, N> & arr);
	
    // COMMENT This method should be removed since it was part of the bad design.

  /**
   * Initializing constructor. The source array can be of any size
   * as long as they are of the same type.
   *
   * @param[in]      arr        Source array
   */
  template <size_t M>
  Fixed_Array(const Fixed_Array<T, M> & arr);

  /**
   * Initializing constructor. Fills the contents of the 
   * array with the specified \a fill value.
   *
   * @param[in]      fill       The file value.
   */
  Fixed_Array(T fill);

  // Destructor.
  ~Fixed_Array(void);

  size_t size(void) const;

  // /**
  //  * Assignment operator
  //  *
  //  * @param[in]      rhs        Right-hand side of operator.
  //  */
  // const Fixed_Array & operator= (const Fixed_Array<T, N> & rhs);

  // /**
  //  * Assignment operator
  //  *
  //  * @param[in]      rhs        Right-hand side of operator.
  //  */
  // template <size_t M>
  // const Fixed_Array & operator= (const Fixed_Array<T, M> & rhs);
};

#include "Fixed_Array.inl"
#endif
