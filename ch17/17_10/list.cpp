#include "list.h"

Link::Link(const std::string nameIn,Link* prevIn,Link* succIn):
  namep(nameIn),prev(prevIn), succ(succIn){}

/*Insert n before this; return : |doubly_linked_list| |n| |this| */
Link* Link::insert(Link* n){
  if(n==nullptr) return this;
  n->succ=this; /*this comes after n*/
  /*This is from doubly-linked list graph when 
    the prev is not nullptr and puts it to correct value!*/
  if(prev!=nullptr)
    prev->succ=n;
  n->prev=prev;
  prev=n;
  return n;
}

/*Insert n after this; return n : |this| |n| |doubly_linked_list|*/ 
Link* Link::add(Link* n){
  Link* temp{nullptr};
  try{
    if(n==nullptr){
      temp=this;
      throw std::runtime_error("The link* n is a null pointer");
    }
  }catch(const std::exception& e){
    std::cerr<<"Error : "<<e.what()<<"\n";
    return temp;
  }
  n->prev=this; /*n comes after this*/
  if(succ!=nullptr)
    succ->prev=n;
  n->succ=succ;
  succ=n;
  return n;
}

/*remove p from list; return p's successor*/
Link* Link::erase(Link* p){

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

Link* Link::find(const std::string& s){

  Link* p{this};
  while (p!=nullptr) {
    if (p->name() == s)
      return p;
    p = p->succ;
  }
  return nullptr;
}

/* move n positions in list; return nullptr for "not found"                                                                        
   positive n moves forward, negative backward*/
Link* Link::advance(int n)const{
  Link* p{succ->prev};
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

void Link::print_all()const{
  Link* p {succ->prev};
  std::cout << "{ ";
  while (p) {
    std::cout << p->name();
    if ((p=p->succ))
      std::cout << ", ";
  }
  std::cout << " }\n";
}

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
