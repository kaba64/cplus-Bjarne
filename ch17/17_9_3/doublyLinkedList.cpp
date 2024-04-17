#include <iostream>
#include <exception>
#include <string>

class Link{
public:
  Link(const std::string nameIn,Link* prevIn=nullptr,Link* succIn=nullptr):
    namep(nameIn),prev(prevIn), succ(succIn){std::cout<<"Constructor : "<<nameIn<<"\n";}
  std::string name()const{return namep;}
  ~Link() {
    std::cout << "Destructor : " << namep << "\n";
    if (prev != nullptr) {
      std::cout << "1\n";
      prev->succ = nullptr;
      std::cout<<"prev : "<<reinterpret_cast<uintptr_t>(prev)<<"\n";
      delete prev;
    }
    if (succ != nullptr) {
      std::cout << "2\n";
      succ->prev = nullptr;
      std::cout<<"succ : "<<reinterpret_cast<uintptr_t>(succ)<<"\n";
      delete succ;
    }
  }
  /*Data members*/
  std::string namep;
  Link* prev;
  Link* succ;
};

/*Insert n before p*/
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

int main(int argc,char** argv){
  Link* norse_gods = new Link{"Thor"};
  std::cout<<"norse_gods : "<<reinterpret_cast<uintptr_t>(norse_gods)<<"\n";
  std::cout<<"\n";
  norse_gods = insert(norse_gods,new Link{"Odin"});
  std::cout<<"norse_gods : "<<reinterpret_cast<uintptr_t>(norse_gods)<<"\n";
  std::cout<<"\n";
  norse_gods = insert(norse_gods,new Link{"Freia"});
  std::cout<<"norse_gods : "<<reinterpret_cast<uintptr_t>(norse_gods)<<"\n";
  std::cout<<"\n";
  delete norse_gods;
  return 0;
}
