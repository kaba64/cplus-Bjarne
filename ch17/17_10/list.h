#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

class Link{
public:
  Link(const std::string nameIn,Link* prevIn=nullptr,Link* succIn=nullptr);
  std::string name()const{return namep;}
  void setName(const std::string nameIn){namep=nameIn;}
  Link* next()const { return succ; }
  Link* previous()const { return prev; }
  /*Insert n before this; return n*/
  Link* insert(Link* n);
  /*Insert n after this; return n*/
  Link* add(Link* n);
  /*remove p from list; return p's successor*/
  Link* erase(Link* p);
  Link* find(const std::string& s);
  Link* advance(int n)const;
  void print_all()const;
  ~Link();
private:
  std::string namep;
  Link* prev;
  Link* succ;
};
