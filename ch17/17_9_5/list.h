#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

class Link{
public:
  Link(const std::string nameIn,Link* prevIn=nullptr,Link* succIn=nullptr);
  std::string name()const;
  ~Link();
  /*Data members*/
  std::string namep;
  Link* prev;
  Link* succ;
};

/*Insert n before p; return n*/
Link* insert(Link* p,Link* n);
/*Insert n after p; return n*/
Link* add(Link* p,Link* n);
/*remove p from list; return p's successor*/
Link* erase(Link* p);
Link* find(Link* p, const std::string& s);
void print_all(Link* p);
