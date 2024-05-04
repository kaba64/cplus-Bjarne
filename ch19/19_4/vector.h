#pragma once
#include <string>
#include <initializer_list>
#include <memory>

template<typename T,typename A = std::allocator<T>> class vector{
public:
  vector();
  explicit vector(size_t s,T value=T{});
  vector(std::initializer_list<T> lst);
  vector(const vector& src);                         /*copy constructor*/
  vector& operator =(const vector& src);             /*copy assignment*/
  vector(vector&& src);                              /*move constructor*/
  vector& operator =(vector&& src);                  /*move assignment*/
  T operator [](size_t i)const;                 /*get rvalu*/
  T& operator [](size_t i);                     /*to get lvalue*/
  T& at(size_t i);
  const T& at(size_t i)const;
  size_t size()const{return sz;}
  T get(size_t i)const{return elem[i];}
  void set(size_t n,T v){elem[n]=v;}
  void reserve(size_t newalloc);
  size_t capacity()const;
  void resize(size_t newsize,T def=T{});
  void push_back(T d);
  void print_vector(const std::string& name)const;
  ~vector();
private:
  A alloc;
  size_t sz;
  T* elem;
  size_t space;
};

#include "vector.hpp"
