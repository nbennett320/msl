// Noah Bennett - String.h
// Define a String class from Array class

#ifndef _STRING_H_
#define _STRING_H_

#include <ostream>
#include "Array.h"
#include "Stack.h"

class String : public Array<char> {
  public:

  // construct string from char array
  String(const char * val);

  // construct string from string
  String(const String & str);

  // construct string from array of chars
  String(const Array<char> & arr);

  // assignment operator from string
  String & operator= (const String & rhs);

  // assignment operator from array of chars
  String & operator= (const Array<char> & rhs);

  // addition operator to concat string
  String & operator+ (const String & rhs);

  // addition operator to concat string (for chars)
  String & operator+ (const char & rhs);

  explicit operator bool() const;

  // bracket accessor 
  char & operator[] (size_t index);

  // bracket accessor, read only
  const char & operator[] (size_t index) const;

  // handle ostreams, std::cout << operator
  friend std::ostream & operator<< (std::ostream & os, const String & str);

  /**
   * Locate the specified character in the array. The index of the first
   * occurrence of the character is returned. If the character is not
   * found in the array, then -1 is returned.
   *
   * @param[in]        ch        Character to search for
   * @return           Index value of the character
   * @retval           -1        Character not found
   */
  int find(char ch) const;

  /**
   * This version allows you to specify the start index of the search. If
   * the start index is not within the range of the array, then the
   * std::out_of_range exception is thrown.
   *
   * @param[in]       ch                   Character to search for
   * @param[in]       start                Index to begin search
   * @return          Index value of first occurrence
   * @retval          -1                   Character not found
   * @exception       std::out_of_range    Invalid index
   */
  int find(char ch, size_t start) const;

  // equality comparison operator
  bool operator== (const String & rhs) const;

  // inequality comparison operator
  bool operator!= (const String & rhs) const;

  // slice of string from index
  String substring(size_t begin) const;

  // slice of String from and to index
  String substring(size_t begin, size_t end) const;

  // split string into array of individual chars
  Array<char> split(void);

  // split string into array of substrings, 
  // breaking on occurences of param
  Array<String*> split(char ch);

  // parse for integer value contained by string
  int parseInt(void);

  // replace all occurences of target with the ch
  String replaceAll(char target, char ch);

  // get char at specified index
  // (alias for str.get(index))
  char charAt(size_t index) const;

  char * toCharArray(void);

  // append another string
  String concat(String str);

  // append a character
  String concat(char ch);

  // return the number of characters in the string
  size_t size(void) const;

  // cast and append a number
  // String concat(int num);
  
  private:

  // count the length of an array of chars, used 
  // to determine the size of a string being constructed
  int countLength (const char * val);

};

#include "String.inl"
#include "String.cpp"
#endif
