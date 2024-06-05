#pragma once
#include <string>
#include <initializer_list>
#include <memory>
#include <optional>

template<typename T,typename A = std::allocator<T>> struct vector_rep{

  A alloc;
  int sz;
  T* elem;
  int space;
  vector_rep(const A& a,int n);
  ~vector_rep(){alloc.deallocate(elem,space);}
  vector_rep(vector_rep&& other);                       /*Move constructor*/
  vector_rep& operator=(vector_rep&& other);            /*Move assignment operator for vector_rep*/
  vector_rep(const vector_rep&) = delete;
  vector_rep& operator=(const vector_rep&) = delete;
};

template<typename T,typename A = std::allocator<T>> class vector{
public:
  using size_type  = unsigned long;
  using value_type = T;
  using iterator   = T*;
  using	const_iterator   = const T*;

  iterator begin(){return r.elem;}
  iterator end(){return r.elem+r.sz;}
  
  vector();
  explicit vector(int s,T value=T{});
  vector(std::initializer_list<T> lst);
  vector(const vector& src);                         /*copy constructor*/
  vector& operator =(const vector& src);             /*copy assignment*/
  vector(vector&& src): r(std::move(src.r)){}        /*move constructor*/
  vector& operator=(vector&& src);                   /*move assignment*/
  T operator [](int i)const;                         /*get rvalu*/
  T& operator [](int i);                             /*get lvalue*/
  T& at(int i);
  std::optional<T> at(int i)const;
  T get(int i)const{return r.elem[i];}
  void set(int n,T v){r.elem[n]=v;}
  size_type size()const{return r.sz;}
  size_type capacity()const{return r.space;}
  void resize(int newsize,T def=T{});
  void push_back(T d);
  void reserve(int newalloc);
  void print_vector(const std::string& name)const;
  ~vector();
private:
  vector_rep<T,A> r;
};

#include "vector.hpp"
