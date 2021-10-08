#pragma once

#include "Array.h"

template <typename T>
class Matrix {
  public:
  typedef T type;

  // constructor
  Matrix(u32, u32);

  Matrix(T *, u32, u32);

  ~Matrix(void);

  void fill(T);

  void transpose(void);

  void __matmul__(Matrix<T> *);

  void set(T, u32, u32);

  void set_range(T, u32, u32, u32, u32);

  void add_at(T, u32, u32);

  void add_to_range(T, u32, u32, u32, u32);

  void multiply_at(double, u32, u32);

  void multiply_to_range(double, u32, u32, u32, u32);

  T at(u32, u32);

  void scale(double, double);

  void print(void);

  T **data(void);

  T *to_c_array(void);

  Array<T> *to_array(void);

  private:

  T **M;

  u32 x, y;

  u32 size;

};
