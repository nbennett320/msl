// Noah Bennett - String.cpp
// Define a String class from Array class

// #include <stdlib.h>
// #include <exception>
#include "String.h"
#include "util.h"

String::String(const char * val = nullptr) 
:Array<char>(this->countLength(val)) {
  for(int i = 0; i < this->size_; i++) {
    this->data_[i] = val[i];
  }
}

String::String(const String & str)
:Array<char>(str.size_) {
  for(int i = 0; i < this->size_; i++) {
    this->data_[i] = str.data_[i];
  }
}

String::String(const Array<char> & arr)
:Array<char>(arr.size()) {
  for(int i = 0; i < this->size_; i++) {
    this->data_[i] = arr[i];
  }
}

String & String::operator= (const String & rhs) {
  if(this == &rhs) {
    return *this;
  } else {
    this->size_ = rhs.size_;
    for(int i = 0; i < rhs.size(); i++) {
      this->data_[i] = rhs.charAt(i);
    }
    return *this;
  }
}

String & String::operator= (const Array<char> & rhs) {
  this->size_ = rhs.size();
  this->data_ = this->deep_copy();
  return *this;
}

String & String::operator+ (const String & rhs) {
  int cat_size = this->size_ + rhs.size();
  String cat_str = String(cat_size);
  for(int i = 0; i < this->size_; i++) {
    cat_str.set(i, this->data_[i]);
  }
  for(int i = this->size_; i < cat_size; i++) {
    cat_str.set(i, rhs.charAt(i - this->size_));
  }
  *this = cat_str;
  return *this;
}

String & String::operator+ (const char & rhs) {
  int cat_size = this->size_ + 1;
  String cat_str = String(cat_size);
  for(int i = 0; i < this->size_; i++) {
    cat_str.set(i, this->data_[i]);
  }
  cat_str.set(this->size_, rhs);
  *this = cat_str;
  return *this;
}

String::operator bool() const {
  return (this->size_ > 0);
}

char & String::operator[] (size_t index) {
  if(index < this->size_) {
    return this->data_[index];
  } else {
    kprintf("Index out of range at: %d", index);
  }
}

const char & String::operator[] (size_t index) const {
  if(index < this->size_) {
    return this->data_[index];
  } else {
    kprintf("Index out of range at: %d", index);
  }
}

// void & operator<< (String::String stream, const String & str) {
//   for(int i = 0; i < str.size(); i++) {
//     kprintf("%c", str.charAt(i));
//   }
// }

int String::find(char ch) const {
  for(int i = 0; i < this->size_; i++) {
    if(this->data_[i] == ch) {
      return i;
    } else {
      continue;
    }
  }
  return -1;
}

int String::find(char ch, size_t start) const {
  if(start < 0) {
    kprintf("Index cannot be less than zero: %d", start);
  } if(start >= this->size_) {
    kprintf("Index out of range at: %d", start);
  } else {
    for(int i = start; i < this->size_; i++) {
      if(this->data_[i] == ch) {
        return i;
      } else {
        continue;
      }
    }
    return -1;
  }
}

bool String::operator== (const String & rhs) const {
  if(this == &rhs) {
    return true;
  } else if((this->size_ == rhs.size_)) {
    for(int i = 0; i < this->size_; i++) {
      if(this->data_[i] == rhs.data_[i]) {
        continue;
      } else {
        return false;
      }
    }
    return true;
  } else {
    return false;
  }
}

bool String::operator!= (const String & rhs) const {
  if(this == &rhs) {
    return false;
  } else if((this->size_ == rhs.size_)) {
    for(int i = 0; i < this->size_; i++) {
      if(this->data_[i] == rhs.data_[i]) {
        continue;
      } else {
        return true;
      }
    }
    return false;
  } else {
    return true;
  }
}

String String::substring(size_t begin) const {
  size_t end = this->size_;
  if(begin > end) {
    // start index greater than current size
    kprintf("Index out of range at: %d", begin);
    return NULL;
  } else if(begin < 0) {
    kprintf("Index out of range at: %d", begin);
    return NULL;
  } else {
    String *str = new String(this->size_);
    for(int i = begin, j = 0; i < end; i++, j++) {
      str->data_[j] = this->data_[i];
    }
    return *str;
  }
}

String String::substring(size_t begin, size_t end) const {
  if(this->size_ < end) {
    kprintf("Index out of range at: %d", end);
    return NULL;
  } else if(begin < 0) {
    kprintf("Index out of range at: %d", end);
    return NULL;
  } else {
    String *str = new String(end - begin);
    for(int i = begin, j = 0; i < str->size(); i++, j++) {
      str->data_[j] = this->data_[i];
    }
    return *str;
  }
}

Array<char> String::split() {
  return Array<char>(*this);
}

// split string for each occurence of character
Array<String*> String::split(char ch) {
  Array<String*> tokens = Array<String*>(256);
  int cursor = 0;
  String *token = new String("");
  for(int i = 0; i < this->size_; i++) {
    if(this->data_[i] != ch) {
      // if does not match target
      if(i == this->size_ - 1) {
        // if last iteration
        token = new String(token->concat(this->data_[i]));
        tokens[cursor] = token;
        break;
      } else {
        token = new String(token->concat(this->data_[i]));
      }
    } else {
      //
      if(token->size() > 0) {
        // terminate/close token
        tokens[cursor] = new String(*token);
      }
      // reset token
      *token = "";
      cursor++;
    }
  }
  tokens.shrink();
  return tokens;
}

int String::parseInt() {
  int num = 0;
  bool isNegative = this->data_[0] == '-';
  for(int i = 0; i < this->size(); i++) {
    if(i == 0 && isNegative) {
      continue;
    } else if(((int) this->data_[i] >= 48) && ((int) this->data_[i] <= 57)) {
      num = num * 10 + ((int) this->data_[i] - 48);
    } else {
      kprintf("String cannot be parsed as integer.");
    }
  }
  return isNegative ? (-1 * num) : num; 
}

String String::replaceAll(char target, char ch) {
  String *str = new String("");
  int new_len = this->size_ - util::count_occurences(*this, ch);
  for(int i = 0; i < new_len; i++) {
    if(this->data_[i] == target) {
      str->data_[i] = ch;
    } else {
      str->data_[i] = this->data_[i];
    }
  }
  return *str;
}

char String::charAt(size_t index) const {
  return this->get(index);
}

char * String::toCharArray() {
  char *cstr = new char[this->size_];
  for(int i = 0; i < this->size_; i++) {
    cstr[i] = this->data_[i];
  }
  return cstr;
}

// concatenate string
String String::concat(String str) {
  int cat_size = this->size_ + str.size();
  String cat_str = String(cat_size);
  for(int i = 0; i < this->size_; i++) {
    cat_str.set(i, this->data_[i]);
  }
  for(int i = this->size_; i < cat_size; i++) {
    cat_str.set(i, str.charAt(i - this->size_));
  }
  return cat_str;
}

// concatenate char
String String::concat(char ch) {
  int cat_size = this->size_ + 1;
  String cat_str = String(cat_size);
  for(int i = 0; i < this->size_; i++) {
    cat_str.set(i, this->data_[i]);
  }
  cat_str.set(this->size_, ch);
  return cat_str;
}
