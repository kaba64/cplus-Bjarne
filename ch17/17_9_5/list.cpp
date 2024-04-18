#include "list.h"

Link::Link(const std::string nameIn,Link* prevIn,Link* succIn):
  namep(nameIn),prev(prevIn), succ(succIn){}
std::string Link::name()const{return namep;}
Link::~Link() {
  if (prev != nullptr) {
    prev->succ = nullptr;
    delete prev;
  }
  if (succ != nullptr) {
    succ->prev = nullptr;
    delete succ;
  }
}

/*Insert n before p; return : |doubly_linked_list| |n| |p|*/
Link* insert(Link* p,Link* n){
  if(n==nullptr) return p;
  if(p==nullptr) return n;
  n->succ=p; /*p comes after n*/
  /*This is from doubly-linked list graph when 
    the prev is not nullptr and puts it to correct value!*/
  if(p->prev!=nullptr)
    p->prev->succ=n;
  n->prev=p->prev;
  p->prev=n;
  return n;
}

/*Insert n after p; return n : |p| |n| |doubly_linked_list|*/ 
Link* add(Link* p,Link* n){
  Link* temp{nullptr};
  try{
    if(n==nullptr){
      temp=p;
      throw std::runtime_error("The link* n is a null pointer");
    }
    if(p==nullptr){
      temp=n;
      throw std::runtime_error("The link* p is a null pointer");
    }
  }catch(const std::exception& e){
    std::cerr<<"Error : "<<e.what()<<"\n";
    return temp;
  }
  n->prev=p; /*n comes after p*/
  if(p->succ!=nullptr)
    p->succ->prev=n;
  n->succ=p->succ;
  p->succ=n;
  return n;
}

/*remove p from list; return p's successor*/
Link* erase(Link* p){

  try{
    if(p==nullptr)
      throw std::runtime_error("The link* p is a null pointer");
  }catch(const std::exception& e){
    std::cerr<<"Error : "<<e.what()<<"\n";
    return nullptr;
  }
  if(p->succ!=nullptr)
    p->succ->prev=p->prev;
  if(p->prev!=nullptr)
    p->prev->succ=p->succ;
  return p->succ;
}

Link* find(Link* p, const std::string& s){
  while (p!=nullptr) {
    if (p->name() == s)
      return p;
    p = p->succ;
  }
  return nullptr;
}

/* move n positions in list; return nullptr for "not found"                                                                        
   positive n moves forward, negative backward*/
Link* advance(Link* p, int n){
  if (p==nullptr)
    return nullptr;
  while (n>0) {
    --n;
    if (p->succ)
      p = p->succ;
    else
      return nullptr;
  }
  while (n<0) {
    ++n;
    if (p->prev)
      p = p->prev;
    else
      return nullptr;
  }
  return p;
}

void print_all(Link* p){
  std::cout << "{ ";
  while (p) {
    std::cout << p->name();
    if ((p=p->succ))
      std::cout << ", ";
  }
  std::cout << " }\n";
}
