// Noah Bennett - List_Base.h

#ifndef _LIST_BASE_H_
#define _LIST_BASE_H_

#include <cstring>
#include "Node.h"

template <typename T>
class List_Base {
  public:
  typedef T type;

  // default constructor
  List_Base (void);
  
  /**
   * Initializing constructor.
   *
   * @param[in]      size        Initial size
   */
  List_Base (size_t size);

  /**
   * Copy constructor
   *
   * @param[in]     list         The source list.
   */
  List_Base (const List_Base &list);

  // deconstructor
  ~List_Base (void);

  protected:

  // current size
  size_t size_;

  Node<T> * head_;

};

#endif
