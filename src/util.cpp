// Noah Bennett - util.cpp

#include "util.h"
#include "Array.h"

bool util::is_math_symbol(char sym) {
  String symbols = "+-*/%^";
  for(int i = 0; i < symbols.size(); i++) {
    if(symbols[i] == sym) {
      return true;
    } else {
      continue;
    }
  }
  return false;
}

bool util::is_parenthese(char sym) {
  String symbols = "()";
  for(int i = 0; i < symbols.size(); i++) {
    if(symbols[i] == sym) {
      return true;
    } else {
      continue;
    }
  }
  return false;
}

bool util::is_parenthese(String sym) {
  if(sym == "(") return true;
  else if(sym == ")") return true;
  else return false;
}

bool util::is_symbol(String sym) {
  String symbols = "+-*/%^()";
  if(sym.size() > 1) {
    return false;
  } else {
    for(int i = 0; i < symbols.size(); i++) {
      if(symbols[i] == sym[0]) {
        return true;
      } else {
        continue;
      }
    }
    return false;
  }
}

int util::count_occurences(String str, char ch) {
  int counter = 0;
  for(int i = 0; i < str.size(); i++) {
    if(str[i]) counter++;
  }
  return counter;
}

// return true if has higher operator precedence
bool util::pemdas::has_higher_precedence(char l_sym, char r_sym) {
  using namespace util::pemdas;
  return (calc_operator_precedence(l_sym) > calc_operator_precedence(r_sym));
}

// return true if has higher operator precedence
bool util::pemdas::has_lower_precedence(char l_sym, char r_sym) {
  using namespace util::pemdas;
  return (calc_operator_precedence(l_sym) <= calc_operator_precedence(r_sym));
}

// calculate operator precedence
int util::pemdas::calc_operator_precedence(char sym) {
  // if((sym == '(') or (sym == ')')) return 4;
  if(sym == '^') return 3;
  if((sym == '*') or (sym == '/')) return 2;
  if((sym == '+') or (sym == '-')) return 1;
  else return 0;
}
