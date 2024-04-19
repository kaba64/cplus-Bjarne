#include "list.h"

int main(int argc,char** argv){
  Link* norse_gods = new Link{"Thor"};
  norse_gods = norse_gods->insert(new Link{"Odin"});
  norse_gods = norse_gods->insert(new Link{"Zeus"});
  norse_gods = norse_gods->insert(new Link{"Freja"});
  
  Link* greek_gods = new Link{"Hera"};
  greek_gods = greek_gods->insert(new Link{"Athena"});
  greek_gods = greek_gods->insert(new Link{"Mars"});
  greek_gods = greek_gods->insert(new Link{"Poseidon"});

  std::cout<<"\nPrint before making changes\n\n";
  norse_gods->print_all();
  greek_gods->print_all();
  
  Link* p = greek_gods->find("Mars");
  if(p)
    p->setName("Ares");
  
  p = norse_gods->find("Zeus");
  if(p){
    if(p==norse_gods)
      norse_gods = p->next();
    Link* temp = norse_gods->erase(p);
    greek_gods = greek_gods->insert(p);
  }

  std::cout<<"\nPrint after making changes\n\n";
  norse_gods->print_all();
  greek_gods->print_all();
  
  delete norse_gods;
  delete greek_gods;
  return 0;
}
