// Noah Bennett - Queue.h

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <cstring>
#include <exception>
#include "List_Base.h"

/**
 * @class Queue
 *
 * Basic queue for abitrary elements.
 */
template <typename T>
class Queue : public List_Base<T> {
  public:
  typedef T type;

  /**
   * @class empty_exception
   *
   * Exception thrown to indicate the queue is empty.
   */
  class empty_exception : public std::exception {
  public:
    // Default constructor.
    empty_exception (void)
    :std::exception() {}

    /**
     * Initializing constructor.
     *
     * @param[in]      msg         Error message.
     */
    empty_exception (const char * msg)
    :std::exception (msg) {}
  };

  // Default constructor.
  Queue (void);

  // Copy constructor.
  Queue (const Queue & s);

  /// Destructor.
  ~Queue (void);

  /**
   * Assignment operator
   *
   * @param[in]      rhs           Right-hand side of operator
   * @return         Reference to self
   */
  const Queue & operator= (const Queue & rhs);

  /**
   * Push a new \a element onto the queue. The element is inserted
   * before all the other elements in the list.
   *
   * @param[in]      element       Element to add to the list
   */
  void enqueue (T element);

  /**
   * Remove the top-most element from the queue.
   *
   * @exception      empty_exception    The queue is empty.
   */
  void dequeue (void);

  /**
   * Get the top-most element on the queue. If there are no element 
   * on the queue, then the queue_is_empty exception is thrown.
   *
   * @return         Element on top of the queue.
   * @exception      empty_exception    The queue is empty
   */
  T tail (void) const;

  /**
   * Get the top-most element on the queue. If there are no element 
   * on the queue, then the queue_is_empty exception is thrown.
   *
   * @return         Element on top of the queue.
   * @exception      empty_exception    The queue is empty
   */
  T head (void) const;

  /**
   * Test if the queue is empty
   *
   * @retval         true          The queue is empty
   * @retval         false         The queue is not empty
   */
  bool is_empty (void) const;

  /**
   * Number of element on the queue.
   *
   * @return         Size of the queue.
   */
  size_t size (void) const;

  // Remove all elements from the queue.
  void clear (void);

  private:

  Node<T> *tail_;

};

#include "Queue.inl"

#endif
