#include <iostream>
#include <exception>
#include <limits>
#include <algorithm>
#include "vector.h"

int reasonable_size = std::numeric_limits<int>::max();
/*Constructor of vector_rep*/
template<typename T,typename A> vector_rep<T,A>::vector_rep(const A& a,int n){
  try{
    if(n<0 || n>=reasonable_size){
      std::string message = n<0?"Size of the vector cannot be negative":"Size of the vector is too large";
      throw std::length_error(message);
    }
    alloc=a;
    sz=n;
    elem=alloc.allocate(n);
    space=n;
  }catch(const std::exception& e){
    std::cerr<<e.what()<<"\n";
    alloc=a;
    sz=n;
    elem=nullptr;
    space=n;
  }
}
/*Move constructor for vector_rep*/
template<typename T,typename A> vector_rep<T,A>::vector_rep(vector_rep<T,A>&& other):
  alloc(std::move(other.alloc)), sz(other.sz), elem(other.elem), space(other.space) {
  other.sz = 0;
  other.elem = nullptr;
  other.space = 0;
}
/*Move assignment operator for vector_rep*/
template<typename T,typename A> vector_rep<T,A> & vector_rep<T,A>::operator=(vector_rep<T,A>&& other) {
  if (this != &other) {
    if (elem) {
      std::destroy(elem,elem+space);
      alloc.deallocate(elem,space);
    }
    alloc = std::move(other.alloc);
    sz = other.sz;
    elem = other.elem;
    space = other.space;
    
    other.sz = 0;
    other.elem = nullptr;
    other.space = 0;
  }
  return *this;
}
/*Default constructor*/
template<typename T,typename A> vector<T,A>::vector(): r(A{},0){}
/*Constructor*/
template<typename T,typename A> vector<T,A>::vector(int s,T value): r(A{}, s){
  if(r.elem!=nullptr)
    std::uninitialized_fill(r.elem,&r.elem[r.sz],value); /*initialize elements*/
}
/*list constructor*/
template<typename T,typename A> vector<T,A>::vector(std::initializer_list<T> lst):
  r(A{}, lst.size()){
  std::uninitialized_copy(lst.begin(),lst.end(),r.elem);
}
/*copy constructor*/
template<typename T,typename A> vector<T,A>::vector(const vector<T,A>& src):r(src.r.alloc, src.r.sz){
  std::uninitialized_copy(src.r.elem,src.r.elem+src.r.sz,r.elem);
}
/*copy assignment*/
template<typename T,typename A> vector<T,A>& vector<T,A>::operator =(const vector<T,A>& src){
  if(&src==this)
    return *this;
  if(src.r.sz<=r.space){
    std::copy(src.r.elem,src.r.elem+src.r.sz,r.elem);
    r.sz=src.r.sz;
    return *this;
  }
  vector_rep<T,A> b{A{},src.r.sz};
  std::uninitialized_copy(src.r.elem,src.r.elem +src.r.sz, b.elem);
  std::destroy(r.elem,r.elem+r.space);
  std::swap(r.alloc, b.alloc);
  std::swap(r.sz, b.sz);
  std::swap(r.space,b.space);
  std::swap(r.elem,b.elem);
  return *this;
}
/*move assignment*/
template<typename T,typename A> vector<T,A> & vector<T,A>::operator=(vector<T,A>&& src){
  if (this != &src) {
    r = std::move(src.r);
  }
  return *this;
}
/*get rvalu*/
template<typename T,typename A> T vector<T,A>::operator [](int i)const{
  return r.elem[i];
}
/*get lvalue*/
template<typename T,typename A> T& vector<T,A>::operator [](int i){
  return r.elem[i];
}
/*get lvalue with range check*/
template<typename T,typename A> T& vector<T,A>::at(int i){
  if(i<0 || i>=r.sz)
    throw std::out_of_range("Index out of range");
  return r.elem[i];
}
/*get rvalue with range check*/
template<typename T,typename A> std::optional<T> vector<T,A>::at(int i)const{
  if(i<0 || i>=r.sz){
    std::cerr << "Index out of range\n";
    return std::nullopt;
  }
  return r.elem[i];
}
template<typename T,typename A> void vector<T,A>::reserve(int newalloc){

  if(newalloc<=r.space){
    return;
  }
  vector_rep<T,A> b{r.alloc,newalloc};
  std::uninitialized_move(r.elem,r.elem +r.sz, b.elem);
  std::destroy(r.elem,r.elem+r.space);
  std::swap(r.alloc, b.alloc);
  std::swap(r.space,b.space);
  std::swap(r.elem,b.elem);
}
template<typename T,typename A> void vector<T,A>::resize(int newsize,T def){
  int oldSize{r.sz};
  reserve(newsize);
  if(oldSize<r.sz){
    std::fill(r.elem+oldSize,r.elem+r.sz,def); /*initialize added elements to def*/
  }
  r.sz=newsize;
}
/*Reference std::move: https://en.cppreference.com/w/cpp/algorithm/move*/
template<typename T,typename A> vector<T,A>::iterator vector<T,A>::erase(iterator p){
  if(p==end())
    return p;
  std::move(p+1,end(),p);          /*moves elements from [p+1,end()) to a range begining at p*/
  std::destroy_at(r.elem+r.sz-1);
  --r.sz;
  return p;
}
/*Reference for move_backward: https://en.cppreference.com/w/cpp/algorithm/move_backward*/
template<typename T,typename A> vector<T,A>::iterator vector<T,A>::insert(iterator p,const T& val){
  int index = p-begin();
  if(size()==capacity()){
    reserve(size()==0?8:2*size());
    std::cout<<"hi\n";
  }
  p = index+begin();
  std::move_backward(p,end(),end()+1);
  *(begin()+index) = val;
  ++r.sz;
  return p;
}
template<typename T,typename A> void vector<T,A>::push_back(T d){
  if(r.space==0)
    reserve(8);
  else if(r.sz==r.space)
    reserve(2*r.space);
  std::construct_at(&r.elem[r.sz],d);
  ++r.sz;
}
template<typename T,typename A> void vector<T,A>::print_vector(const std::string& name)const{
  for(int i=0;i<r.sz;++i){
    std::cout<<name<<"["<<i<<"] = "<<r.elem[i]<<"\t";
    if(i==r.sz-1 || (i+1)%3==0)
      std::cout<<"\n";
  }
}

template<typename T,typename A> vector<T,A>::~vector(){}
