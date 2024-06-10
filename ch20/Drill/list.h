#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <memory>
#include <iterator>

template<typename T,typename A = std::allocator<T>>class list{
public:
  class iterator;
  class const_iterator;
  list();
  list(int num,T value=T{});
  list(std::initializer_list<T> lst);
  list(const list& src);                         /*copy constructor*/
  list& operator =(const list& src);             /*copy assignment*/
  iterator begin(){return iterator(head,this);}
  const_iterator begin()const{return const_iterator(head, this);}
  iterator end(){return iterator(tail,this);}
  const_iterator end()const{return const_iterator(tail,this);}
  iterator insert(iterator p,const T& value);   /*Insert value after p*/
  iterator erase(iterator p);                   /*erase the element pointing by p*/
  void push_back(const T& value);
  void push_front(const T& value);
  void pop_front();                             /*remove the first element*/
  void pop_back();                              /*remove the last element*/
  void clear();
  void display()const;
  ~list();
private:
  struct Node {
    T val;
    Node* prev;
    Node* next;
    Node(T valIn={}) : val(valIn), prev(nullptr), next(nullptr) {}
  };
  Node* head;
  Node* tail;
  size_t size;
  /*References:
    https://en.cppreference.com/w/cpp/memory/allocator
    https://en.cppreference.com/w/cpp/memory/allocator_traits*/
  using NodeAllocator = typename std::allocator_traits<A>::rebind_alloc<Node>;
  NodeAllocator alloc;
  Node* createNode(const T& value) {
    Node* node = alloc.allocate(1);
    std::allocator_traits<NodeAllocator>::construct(alloc, node, value);
    return node;
  }
  void destroyNode(Node* node) {
    std::allocator_traits<NodeAllocator>::destroy(alloc, node);
    alloc.deallocate(node, 1);
  }
};

#include "list.hpp"
