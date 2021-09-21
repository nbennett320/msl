// Noah Bennett - util.h
// defines util and util::pemdas namespaces

#ifndef _UTIL_H_
#define _UTIL_H_

#include "Array.h"
#include "Stack.h"
#include "String.h"

namespace util {

  // check if is a math operator +-*/%^
  bool is_math_symbol (char sym);

  // check if char is parenthese ()
  bool is_parenthese (char sym);

  // check if String is parenthese ()
  bool is_parenthese (String sym);

  // check if is a symbol: +-*/%^()
  bool is_symbol (String sym);

  // count num of char occurences in str
  int count_occurences (String str, char ch);

  namespace pemdas {

    // return true if has higher operator precedence
    bool has_higher_precedence (char l_sym, char r_sym);

    // return true if has lower operator precedence
    bool has_lower_precedence (char l_sym, char r_sym);

    // calculate operator precedence
    int calc_operator_precedence (char sym);
  }
}

#endif
