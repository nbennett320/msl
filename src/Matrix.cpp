#include "Matrix.h"
#include "mmath.h"

template<typename T >
Matrix<T>::Matrix(u32 x, u32 y):
M(new T*[x]),
x(x),
y(y),
size(x * y)
{
  for(u32 i = 0; i < x; i++) {
    this->M[i] = new T[y];
  }
}

template<typename T >
Matrix<T>::~Matrix() 
{
  delete[] this->M;
}

template<typename T>
void Matrix<T>::fill(T val) 
{
  for(u32 i = 0; i < x; i++) {
    for(u32 j = 0; j < y; j++) {
      this->M[i][j] = val;
    }
  }
}

template<typename T>
void Matrix<T>::transpose() 
{
  T *MT = new Matrix(y, x);

  for(u32 i = 0; i < x; i++) {
    for(u32 j = 0; j < y; j++) {
      MT[i][j] = this->M[j][i];
    }
  }
  
  this = MT;
}

template<typename T>
void Matrix<T>::__matmul__(Matrix<T> *B) 
{
  Matrix<T> *C = new Matrix<T>(x, y);
  u32 i, j, k;
  for(i = 0; i < x; i++) {
    for(j = 0; j < y; j++) {
      C->set(0, i, j);
      for(k = 0; k < mmath::min(x, y); k++) {
        T val = C->at(i, j) + this->at(i, k) * B->at(k, j);
        C->set(val, i, j);
      }
    }
  }
  
  for(u32 i = 0; i < x; i++) {
    for(u32 j = 0; j < y; j++) {
      this->M[i][j] = C->at(i, j);
    }
  }
}

template<typename T>
void Matrix<T>::set(T val, u32 i, u32 j) 
{
  if(i < x && j < y) this->M[i][j] = val;
}

template<typename T>
void Matrix<T>::set_range(T val, u32 i0, u32 i1, u32 j0, u32 j1) 
{
  for(u32 i = i0; i < i1; i++) {
    for(u32 j = j0; j < j1; j++) {
      this->set(val, i, j);
    }
  }
}

template<typename T>
void Matrix<T>::add_at(T val, u32 i, u32 j) 
{
  if(i < x && j < y) this->M[i][j] += val;
}

template<typename T>
void Matrix<T>::add_to_range(T val, u32 i0, u32 i1, u32 j0, u32 j1) {
  for(u32 i = i0; i < i1; i++) {
    for(u32 j = j0; j < j1; j++) {
      this->add_at(val, i, j);
    }
  }
}

template<typename T>
void Matrix<T>::multiply_at(double val, u32 i, u32 j) {
  if(i < x && j < y) this->M[i][j] *=  ( ( this->M[i][j] * val ) / ( 255 ) );
}

template<typename T>
void Matrix<T>::multiply_to_range(double val, u32 i0, u32 i1, u32 j0, u32 j1) {
  for(u32 i = i0; i < i1; i++) {
    for(u32 j = j0; j < j1; j++) {
      this->multiply_at(val, i, j);
    }
  }
}

template<typename T>
T Matrix<T>::at(u32 i, u32 j) {
  if(i < x && j < y) return this->M[i][j];
  else return -1;
}

template<typename T>
void Matrix<T>::scale(double x_factor, double y_factor) {
  Matrix<T> *diag = new Matrix<T>(x, y);
  diag->fill(0);

  for(u32 i = 0; i < (x); i+=x_factor) {
    for(u32 j = 0; j < (y); j+=y_factor) {
      this->set(x_factor, i, j);
    }
  }
}

template<typename T>
T *Matrix<T>::to_c_array() 
{
  T *data = new T[size];

  for(u32 i = 0; i < x; i++) {
    for(u32 j = 0; j < y; j++) {
      data[i*y + j] = this->M[i][j];
    }
  }

  return data;
}

template<typename T>
Array<T> *Matrix<T>::to_array() 
{
  T *data = new T[size];

  for(u32 i = 0; i < x; i++) {
    for(u32 j = 0; j < y; j++) {
      data[i*y + j] = this->M[i][j];
    }
  }

  return new Array<T>(data);
}

template<typename T>
T **Matrix<T>::data() 
{
  return this->M;
}
